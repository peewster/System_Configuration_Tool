using namespace std;

//Configure the network.
void ifconfig()
{
	string line, IP, NETMASK, GATEW, DNS0, DNS1, answer;
	
	do {
		system("ipconfig | findstr \"(Local Area Connection)\" > C:\\nicinfo.txt");
		char* search = "Local Area Connection";
		int offset;
		ifstream Myfile;
		Myfile.open("C:\\nicinfo.txt");
			if(Myfile.is_open()) {
				while(!Myfile.eof()) {
					getline(Myfile,line);
						if((offset = line.find(search, 0)) != string::npos) {
							cout << "found" << search << endl;
						}
				}
				Myfile.close();
			}else{ 
			system("cls");
			cout << "\nUnable to open nicinfo.txt, need Administrator rights for this action.\n\n" << endl;
			system("pause");
			return;
			}
		remove("C:\\nicinfo.txt");
		system("cls");
		cout << endl;
		cout << "Enter the new ip address. (For example: 192.168.0.2)";
		cout << "\n\nIP: ";
		cin >> IP;

		system("cls");
		cout << "\nEnter the new NETMASK address. (For example: 255.255.255.0)";
		cout << ("\n\nNETMASK: ");
		cin >> NETMASK;
		
		system("cls");
		cout << "\nEnter the new Gateway address. (For example: 192.168.0.1)";
		cout << ("\n\nGateway: ");
		cin >> GATEW;

		system("cls");
		cout << "\nYou Have entered: " << endl;				//Dubble check the user input
		cout << "\nIP ADDRESS: \t\t" + IP;
		cout << "\nNETMASK: \t\t" + NETMASK;
		cout << "\nGATEWAY: \t\t" + GATEW;
		cout << "\n\nIs this correct? (Y/y)es, (N/n)o or (A/a)bort: ";
		cin >> answer;
		}
		while (answer=="N" || answer=="NO" || answer=="No" || answer=="n" || answer=="no");
			if (answer=="A" || answer=="a")
				return;
		
		cout << "\nApplying new networking settings..."; 
		Sleep(1);
		system("cls");

		//Apply the network configuration
		system(string("netsh interface ip set address name=\"Local Area Connection\" static " + IP + " " + NETMASK + " " + GATEW).c_str());
		cout << "\nDone!" << endl << endl;
		system("pause");		
}

// Configure DNS
void dns()
{
	string line, DNS0, DNS1, answer;
	
	do {
		system("ipconfig | findstr \"(Local Area Connection)\" > C:\\nicinfo.txt");
		char* search="Local Area Connection";
		int offset;
		ifstream Myfile;
		Myfile.open("C:\\nicinfo.txt");
			if(Myfile.is_open()) {
				while(!Myfile.eof()) {
					getline(Myfile,line);
						if((offset = line.find(search, 0)) != string::npos) {
							cout << "found" << search << endl;
						}
				}
				Myfile.close();
			}else{ 
			system("cls");
			cout << "\nUnable to open nicinfo.txt, need Administrator rights for this action.\n\n" << endl;
			system("pause");
			return;
			}
		remove("C:\\nicinfo.txt");
		system("cls");
		cout << endl;

		system("cls");
		cout << "\nEnter the new DNS Master Server. (For example: 8.8.8.8)";
		cout << ("\n\nDNS Master Server: ");
		cin >> DNS0;
		
		system("cls");
		cout << "\nEnter the new DNS Secondary Server. (For example: 8.8.4.4)";
		cout << ("\n\nDNS Secondary Server: ");
		cin >> DNS1;

		system("cls");
		cout << "\nYou Have entered: " << endl;				//Dubble check the user input
		cout << "\nDNS MASTER: \t\t" + DNS0;
		cout << "\nDNS SECONDARY: \t\t" + DNS1;
		cout << "\n\nIs this correct? (Y/y)es, (N/n)o or (A/a)bort: ";
		cin >> answer;
		}
		while (answer=="N" || answer=="NO" || answer=="No" || answer=="n" || answer=="no");
			if (answer=="A" || answer=="a")
				return;
		system("cls");

		//Apply the DNS settings
		system(string("netsh interface ipv4 set dns name=\"Local Area Connection\" source=static address=" + DNS0 + " primary").c_str());
		int i = system(string("netsh interface ipv4 add dnsserver name=\"Local Area Connection\" address=" + DNS1 + " index=2").c_str());
		if( i != 0 ){ 
			system("cls");
			cout << "\nThere was  a error while applying the network configurations,\nthis is probably because the default network card has been renamed, sorry.";
		}
		system("cls");
		cout << "DNS Servers are set too: \n1: " + DNS0 + "\n2: " + DNS1 << endl << endl;
		system("pause");		
}

//Configure Network with DHCP
void dhcp()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 6;
	int col2 = 7;

	string user_input;
	system("cls");
	cout << "\nConfigure Network with DHCP?" << endl
		 << "(Y/y)es or (N/n)o: ";
	cin.ignore(256, '\n');
	getline(cin, user_input);
	user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
	if (user_input=="Y" || user_input=="y"){
	system("cls");
	cout << "Configuring Interface to accept DHCP."; 
	int a = system("netsh interface ip set address \"Local Area Connection\" dhcp");
	if ( !a ) {
		int b = system("netsh interface ip set address \"Team1\" dhcp");
	if ( !b ) {
			system("cls");
				cout << "There was an error while applying the new network configuration";
		}
	}
	system("cls");
	cout << "\nRequesting DHCP configuration..." << endl;
	system("ipconfig /release >NUL");
	system("ipconfig /flushdns >NUL");
	system("ipconfig /renew >NUL");
	system("cls"); cout << "\nDone." << endl
		<< "Your New Network configuration is: " << endl << endl; SetConsoleTextAttribute(hStdout, col1);
	system("ipconfig"); cout << endl; SetConsoleTextAttribute(hStdout, col2);
	system("pause");
	} else
		return;
}