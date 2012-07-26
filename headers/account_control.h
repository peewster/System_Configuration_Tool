using namespace std;

//Lists the current users including the network users.
void listuser()
{
	system("cls");
	cout << "\nThis users are currently a member of the Administrators group" << endl << endl; 
	system("NET Localgroup Administrators");
	cout << endl;
	system("pause");
}

//Add network user to the admin group.
void adduser()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 2;
	int col2 = 7;
	system("cls"); 
	string user_input, user_input0, answer;

		do {
		system("cls");
		cout << "\nEnter a new username."<< endl;
		cout << "\nUsername: ";
		cin.ignore(256,'\n');
		getline(cin, user_input);
		user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		system("cls");
		cout << "\nEnter users DOMAIN name (for example: WORKGROUP)."<< endl << endl;
		cout << "DOMAIN: ";
		getline(cin, user_input0);
		user_input0.erase(remove_if(user_input0.begin(), user_input0.end(), IsSpaceOrCR), user_input0.end());
		system("cls");
		cout << "\nYou have entered: \n" << endl;
		cout << "Username: \t" + user_input << endl;
		cout << "DOMAIN: \t" + user_input0 << endl;
		SetConsoleTextAttribute(hStdout, col1);
		cout << "\n\n" + user_input0 + "\\" + user_input + " will be ADDED to the Administrators group!" << endl;
		SetConsoleTextAttribute(hStdout, col2);
		cout << "\nIs this correct?\n\n(Y/y)es, (N/n)o or (A/a)bort: ";
		cin >> answer;
		}
			while (answer=="N" || answer=="NO" || answer=="No" || answer=="n" || answer=="no");
			if (answer=="A" || answer=="a")
				return;
		system("cls");
		system(string("NET localgroup Administrators " + user_input0 + " \\"+ user_input + " /add").c_str());
		system("pause");
}
//Add Users on Windows 2k3 servers
void adduser2k3()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 2;
	int col2 = 7;
	system("cls"); 
	string user_input, user_input0, answer;

		do {
		system("cls");
		cout << "\nEnter a new username."<< endl;
		cout << "\nUsername: ";
		cin.ignore(256,'\n');
		getline(cin, user_input);
		user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		system("cls");
		cout << "\nYou have entered: \n" << endl;
		cout << "Username: \t" + user_input << endl;
		SetConsoleTextAttribute(hStdout, col1);
		cout << "\n\n" + user_input + " will be ADDED to the Administrators group!" << endl;
		SetConsoleTextAttribute(hStdout, col2);
		cout << "\nIs this correct?\n\n(Y/y)es, (N/n)o or (A/a)bort: ";
		cin >> answer;
		}
			while (answer=="N" || answer=="NO" || answer=="No" || answer=="n" || answer=="no");
			if (answer=="A" || answer=="a")
				return;
		system("cls");
		system(string("NET localgroup Administrators " + user_input + " /add").c_str());
		system("pause");
}

//Delete users
void deluser()
{
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int col1 = 4;
	int col2 = 7;

	system("cls"); 
	string user_input, user_input0, answer;

		do {
		system("cls");
		cout << "\nEnter username to delete from the Administrators group."<< endl;
		cout << "\nUsername: ";
		cin.ignore(256,'\n');
		getline(cin, user_input);
		user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		system("cls");
		cout << "\nEnter the users DOMAIN name (for example: WORKGROUP).\nOr leave blank if unknown."<< endl << endl;
		cout << "DOMAIN: ";
		getline(cin, user_input0);
		user_input0.erase(remove_if(user_input0.begin(), user_input0.end(), IsSpaceOrCR), user_input0.end());
		system("cls");
		cout << "\nYou have entered: \n" << endl;
		cout << "Username: \t" + user_input << endl;
		cout << "DOMAIN: \t" + user_input0 << endl << endl;
		SetConsoleTextAttribute(hStdout, col1);
		cout << user_input0 + "\\" + user_input + " will be DELETED from the Administrators group!" << endl;
		SetConsoleTextAttribute(hStdout, col2);
		cout << "\nIs this correct?\n\n(Y/y)es, (N/n)o or (A/a)bort: ";
		cin >> answer;
		}
			while (answer=="N" || answer=="NO" || answer=="No" || answer=="n" || answer=="no");
			if (answer=="A" || answer=="a")
				return;
		system("cls");
		system(string("NET localgroup Administrators " + user_input + " /DEL").c_str());
		system("pause");
}