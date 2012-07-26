using namespace std;

//Inluded the ping utillity.
void ping()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 2;
	int col4 = 6;
	int col2 = 7;
	int col3 = 4;
	string host;
	string try_again;
	do {
	system("cls");
		cout << endl << endl;
		cout << "Please enter a url or ip to ping: ";
		cin.ignore(256,'\n');
		getline(cin, host);
		host.erase(remove_if(host.begin(), host.end(), IsSpaceOrCR), host.end());
		int reply = system (("ping -n 3 " + host + " >nul").c_str());
		if(reply ==0)
		{
			system("cls");
			cout << endl;SetConsoleTextAttribute(hStdout, col4);
			cout << host; SetConsoleTextAttribute(hStdout, col2); cout << " = ";  SetConsoleTextAttribute(hStdout, col1); cout << "Online!"; SetConsoleTextAttribute(hStdout, col2); cout << endl << endl;
		}

		else {

			system ("cls");
			cout << endl;
			SetConsoleTextAttribute(hStdout, col4);
			cout << host; SetConsoleTextAttribute(hStdout, col2); cout << ": \n\nNo response, possible causes: \n\nnetwork issues, \ninvalid input or "; SetConsoleTextAttribute(hStdout, col4);
			cout << host; SetConsoleTextAttribute(hStdout, col2); cout << " is "; SetConsoleTextAttribute(hStdout, col3); cout << " Offline"<< endl << endl;SetConsoleTextAttribute(hStdout, col2);
			cout << endl;
		}	cout << "Try again?" << endl;
			cout << "\n(Y/y)es or (N/n)o: ";
			cin >> try_again;
} while (try_again=="Y" || try_again=="y" || try_again=="Yes" || try_again=="yes");
}

//Included the traceroute utillity.
void traceroute()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 4;
	int col2 = 6;
	int col3 = 7;
	string user_input;
	string trace_again;
	do {
		system("cls");
		cout << endl;
		cout << "Please enter a url or ip to trace" << endl << endl;
		cout << "URL/IP: ";
		cin.ignore(256,'\n');
		getline(cin, user_input);
		user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		int trace = system(("tracert " + user_input).c_str());
		cout << endl; system("pause");
		if(trace !=0)
		{
			system("cls");
			cout << endl;SetConsoleTextAttribute(hStdout, col2);
			cout << "Please check your input: "; SetConsoleTextAttribute(hStdout, col1); cout << user_input; SetConsoleTextAttribute(hStdout, col3); cout << endl << endl;
			traceroute();
		}
		else 
		{
		cout << "Done." << endl;
		}
		cout << "\nTry again?" << endl;
		cout << "\n(Y)es or (N)o: ";
		cin >> trace_again;
	} while (trace_again=="Y" || trace_again=="Yes" || trace_again=="y" || trace_again=="yes");
}

//Included the nslookup utillity.
void dnslookup()
{
	string user_input, lookup_again;
	do {
	system("cls");
	cout << "\nPlease enter a url or ip to lookup: ";
	cin.ignore(256,'\n');
	getline(cin, user_input);
	user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
	system("cls");
	cout << "\nDigging..." << endl << endl;
	int lookup = system(("nslookup " + user_input).c_str());
		cout << endl;
		cout << "Done." << endl;
		cout << "\nTry again?" << endl;
		cout << "\n(Y)es or (N)o: ";
		cin >> lookup_again;
	} while(lookup_again=="Y" || lookup_again=="Yes" || lookup_again=="y" || lookup_again=="yes");
}

// Include nbtstat
void nbtstat() 
{ 
    string user_input, lookup_again; 
    do { 
    system("cls"); 
    cout << "\nEnter IP: "; 
    cin.ignore(256,'\n'); 
    getline(cin, user_input);
	if ( (user_input <="z" && user_input >="a") || (user_input <="Z" && user_input >="A") ) { 
		system("cls");
		cout << "\nIP adresses do not contain alphas!\n\n";
		system("pause");
		continue;
	} 
    user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
    system("cls"); 
	ifstream nbtstat("C:\\Windows\\sysnative\\nbtstat.exe");
	if( !nbtstat ) {
		system(("C:\\Windows\\System32\\nbtstat.exe -A " + user_input ).c_str());
	} else
    system(("C:\\Windows\\sysnative\\nbtstat.exe -A " + user_input ).c_str()); 
        system("pause");
        cout << "Done." << endl; 
        cout << "\nTry again?" << endl; 
        cout << "\n(Y)es or (N)o: "; 
        cin >> lookup_again; 
    } while(lookup_again=="Y" || lookup_again=="Yes" || lookup_again=="y" || lookup_again=="yes"); 
}

// Search Computer share with Net View

void net_view() {
	string hostname, mount, answer, drive, share, output, open;
	system("cls");
	cout << "Searching for hosts.\n\n";
	system("net view | findstr /B \\\\ "); 
	cout << "\n";
	cout << "Enter Hostname for share lookup: ";
	cin.ignore(256, '\n');
	getline(cin, hostname);
	system("cls");
	int netview = system(("net view \\\\" + hostname ).c_str());
		cout << "\nDo you want to mount a share? (y/n): ";
		cin >> answer;
	if(answer=="y" || answer=="Y") {
		cout << "\nEnter a share point ( m - x ): ";
		cin >> drive;
		cout << "\nEnter the share name to mount: ";
		cin.ignore(256,'\n');
		cin >> share;
		int domount = system(("net use " + drive + ":" + " \\\\" + hostname + "\\" + share).c_str());
		system("cls");
		cout << "Open new share in a new cmd window or an explorer window? \n";
		cout << "c (cmd) or e (explorer): ";
		cin >> open;
		if(open=="c") {
			int newcmd = system(("start cmd /K \"cd /D " + drive + ": \"").c_str());
		} else if(open=="e") {
			int explorer = system(("start explorer " + drive + ": ").c_str());
		} else if(open!="c" || open!="e") {
			system("cls");
			cout << "No valid input detected.\n\n";
			system("pause");
			system("cls");
			cout << "Open new share in a new cmd window or an explorer window? \n";
			cout << "c (cmd) or e (explorer): ";
			cin >> open;
			if(open=="c") {
				int newcmd = system(("start cmd /K \"cd /D " + drive + ": \"").c_str());
			} else if(open=="e") {
				int explorer = system(("start explorer " + drive + ": ").c_str());
			} else if(open!="c" || open!="e") {
				system("cls");
				cout << "\nNo valid input detected, aborting...\n\n";
				system("pause");
				system("cls");
				cout << "\nUnmounting shares.\n";
				int unmount = system(("net use /delete " + drive + ": > NUL").c_str());
				cout << "\n" << drive << ": was unmounted succesfully.\n\n";
				system("pause");
				return;
			}
		}
		system("pause");
		system("cls");
	} else {
		return;
	}
	system("cls");
	cout << "\nUnmounting shares.\n";
	int unmount = system(("net use /delete " + drive + ": > NUL").c_str());
	cout << "\n" << drive << ": was unmounted succesfully.\n\n";
	system("pause");
}