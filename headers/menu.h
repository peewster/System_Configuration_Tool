using namespace std;


void menu_hw()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 6;
	int col2 = 7;
	int col3 = 3;
	int loop=1;
	int men4;
		while(loop==1){
			system("CLS");
			SetConsoleTextAttribute(hStdout, col2);
			cout << "\n\n";
			cout << "    =======================================================" << endl;
			cout << "    ||                                                   ||" << endl;  
			cout << "    ||                 System Configuration              ||" << endl;
			cout << "    ||                      Tool V1.0                    ||" << endl;
			cout << "    ||                                                   ||" << endl;
			cout << "    ||                            by: peewster@gmail.com ||" << endl;
			cout << "    =======================================================" << endl;
			SetConsoleTextAttribute(hStdout, col1);
			cout << "\n    # Hardware Information # \n";  SetConsoleTextAttribute(hStdout, col2); cout
					<< "\n    1) - Show Harddrives."
					<< "\n    2) - Show partitions."
					<< "\n    3) - Show Networking Cards."
					<< "\n    4) - Show CPU information."
					<< "\n    5) - Show Memory information."
					; SetConsoleTextAttribute(hStdout, col3); cout
					<< "\n\n    0) - Return to main menu." << endl << endl; SetConsoleTextAttribute(hStdout, col2); cout
					<< "    Your choice (0..9): ";
						while(!(cin >> men4)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "    Invalid input, try again.";
						cout << "\n    Your choice(0..9): ";
						}
						switch(men4){
							case 1:
								  harddrives();
								  break;
							case 2:
								  partitions();
								  break;
							case 3:
								  networkcards();
								  break;
							case 4:
								  cpuinfo();
								  break;
							case 5:
								  memory();
								  break;
							case 0:
								  return;
						}					
					}	
}

void menu_info(){
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 6;
	int col2 = 7;
	int col3 = 3;
	int loop=1;
	int menu_info;
		while(loop==1){
			system("CLS"); 
			SetConsoleTextAttribute(hStdout, col2);
			cout << "\n\n";
			cout << "    =======================================================" << endl;
			cout << "    ||                                                   ||" << endl;  
			cout << "    ||                 System Configuration              ||" << endl;
			cout << "    ||                      Tool V1.0                    ||" << endl;
			cout << "    ||                                                   ||" << endl;
			cout << "    ||                            by: peewster@gmail.com ||" << endl;
			cout << "    =======================================================" << endl;
			SetConsoleTextAttribute(hStdout, col1);
			cout << "\n\n    # Inforation Gathering #\n"; SetConsoleTextAttribute(hStdout, col2); cout
					<< "\n    1)  - Hardware Information."
					<< "\n    2)  - Show the Windows system info."
					<< "\n    3)  - Show installed Windows updates."
					<< "\n    4)  - Detect/Download Windows updates."
					<< "\n    5)  - Show all installed Software packages."
					<< "\n    6)  - Show the current Network configuration.";SetConsoleTextAttribute(hStdout, col3); cout
					<< "\n\n    0) - Return to main menu." << endl << endl; SetConsoleTextAttribute(hStdout, col2); cout
					<< "    Your choice (0..9): ";
					while(!(cin >> menu_info)){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "   Invalid input, try again.";
					cout << "\n    Your choice(0..9): ";
					 }
					 switch(menu_info){
							case 1:
								  menu_hw();
								  break;
							case 2:
								  systeminfo();
							 	  break;
							case 3:
							   	  updates();
								  break;
							case 4:
								  detectupd();
								  break;
						    case 5:
								  softinst();
								  break;
							case 6:
								  networkconf();
								  break;
							case 0:
								  return;
													
						}					
					}	
}

void menu_config()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 6;
	int col2 = 7;
	int col3 = 3;
	int loop=1;
	int menu_config;
		while(loop==1){
			system("CLS"); 
			SetConsoleTextAttribute(hStdout, col2);
			cout << "\n\n";
			cout << "    =======================================================" << endl;
			cout << "    ||                                                   ||" << endl;  
			cout << "    ||                 System Configuration              ||" << endl;
			cout << "    ||                      Tool V1.0                    ||" << endl;
			cout << "    ||                                                   ||" << endl;
			cout << "    ||                            by: peewster@gmail.com ||" << endl;
			cout << "    =======================================================" << endl;
			SetConsoleTextAttribute(hStdout, col1);
			cout << "\n\n    # Configurations #\n";SetConsoleTextAttribute(hStdout, col2); cout
					<< "\n    1) - Configure Network Manually."
					<< "\n    2) - Configure DNS servers Manually"
					<< "\n    3) - Configure Network with DHCP."; SetConsoleTextAttribute(hStdout, col3); cout
					<< "\n\n    0) - Return to main menu." << endl << endl; SetConsoleTextAttribute(hStdout, col2); cout
					<< "    Your choice (0..9): ";
					while(!(cin >> menu_config)){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "    Invalid input, try again.";
					cout << "\n    Your choice(0..9): ";
					}
					switch(menu_config){
						case 1:
							  ifconfig();
							  break;
						case 2:
							  dns();
							  break;
						case 3:
							  dhcp();
							  break;
						case 0:
							  return;					
					}					
				}	
}

void menu_uac()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 6;
	int col2 = 7;
	int col3 = 3;
	int loop=1;
	int menu_uac;

		while(loop==1){
			system("CLS"); 
			SetConsoleTextAttribute(hStdout, col2);
			cout << "\n\n";
			cout << "    =======================================================" << endl;
			cout << "    ||                                                   ||" << endl;  
			cout << "    ||                 System Configuration              ||" << endl;
			cout << "    ||                      Tool V1.0                    ||" << endl;
			cout << "    ||                                                   ||" << endl;
			cout << "    ||                            by: peewster@gmail.com ||" << endl;
			cout << "    =======================================================" << endl;
			SetConsoleTextAttribute(hStdout, col1);
			cout << "\n    # User Account Settings #\n"; SetConsoleTextAttribute(hStdout, col2); cout
					 << "\n    1) - Show te current users within the Administrators group."
					 << "\n    2) - Add a user to the Administrators group."
					 << "\n    3) - Add a user to the Administrators group Win2k3."
					 << "\n    4) - Delete a user from the Administrators group."; SetConsoleTextAttribute(hStdout, col3); cout
					 << "\n\n    0) - Return to main menu." << endl << endl; SetConsoleTextAttribute(hStdout, col2); cout
					 << "    Your choice (0..9): ";
						while(!(cin >> menu_uac)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "    Invalid input, try again.";
						cout << "\n    Your choice(0..9): ";
						}
						switch(menu_uac){
							case 1:
								listuser();
					     		     break;
							 case 2:
								 adduser();
									 break;
							 case 3:
								 adduser2k3();
									 break;
							 case 4:
								 deluser();
								 break;
							 case 0:
									return;
						 }					
						}	
}

void menu_net()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 6;
	int col2 = 7;
	int col3 = 3;
	int loop=1;
	int menu_net;
		while(loop==1){
			system("CLS");
			SetConsoleTextAttribute(hStdout, col2);
			cout << "\n\n";
			cout << "    =======================================================" << endl;
			cout << "    ||                                                   ||" << endl;  
			cout << "    ||                 System Configuration              ||" << endl;
			cout << "    ||                      Tool V1.0                    ||" << endl;
			cout << "    ||                                                   ||" << endl;
			cout << "    ||                            by: peewster@gmail.com ||" << endl;
			cout << "    =======================================================" << endl;
			SetConsoleTextAttribute(hStdout, col1);
			cout << "\n    # Networking Tools #\n";  SetConsoleTextAttribute(hStdout, col2); cout
					<< "\n    1) - Ping (Checks with icmp packet requests to see if a host is \"online\"."
					<< "\n    2) - Traceroute (Good way to follow your network packets)."
					<< "\n    3) - DNS Lookup (Gather DNS information)."
					<< "\n    4) - Show nearby computers."
					<< "\n    5) - Use nbtstat."; SetConsoleTextAttribute(hStdout, col3); cout
					<< "\n\n    0) - Return to main menu." << endl << endl; SetConsoleTextAttribute(hStdout, col2); cout
					<< "    Your choice (0..9): ";
						while(!(cin >> menu_net)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "    Invalid input, try again.";
						cout << "\n    Your choice(0..9): ";
						}
						switch(menu_net){
							case 1:
								  ping(); 
								  break;
							case 2:
								  traceroute();
								  break;
							case 3:
								  dnslookup();
				  				  break;
							case 4: 
								  net_view();
								  break;
							case 5:
								  nbtstat();
								  break;
							case 0:
								  return;
						}					
					}	
}
