using namespace std;

// Search for files

void finder() {
	string findfile, user_input, lookup_again, edit, line;
	do {
	system("cls");
	cout << "\nSearch for (*=all, Case ins.): ";
	cin.ignore(256,'\n');
	getline(cin, user_input);
	system("cls");
	cout << "\nSearching" << endl << endl;
	int lookup = system(("cd C:\\ && dir /b /S /P \"" + user_input + "\"").c_str());
		cout << endl;
		cout << "Done." << endl;
		cout << "Do you want to edit a file? (y/n): ";
		cin >> edit;
		if(edit=="y" || edit=="Y" || edit=="yes" || edit=="Yes") {
			cout << "Copy paste the complete path: ";
			cin.ignore(256,'\n');
			getline(cin,line);
			int edit = system(("notepad " + line).c_str());
			cout << "\n\n";
			cout << "\nTry again?" << endl;
			cout << "\n(Y)es or (N)o: ";
			cin >> lookup_again;
		} else {
		cout << "\nTry again?" << endl;
		cout << "\n(Y)es or (N)o: ";
		cin >> lookup_again;
		}
	} while(lookup_again=="Y" || lookup_again=="Yes" || lookup_again=="y" || lookup_again=="yes");
}

//open a powershell or cmd commandline

void cmd() {

	system("cls");
	chdir ("C:\\Windows");
	int p = system("powershell");
		if( p != 0 ){
			system("cmd");
		}
}

//reboot system
void reboot() {

	string user_input;
	system("cls");
	cout << "\n Reboot?"
		 << "\n (Y/y)es or (N/n)o: ";
	cin.ignore(256,'\n');
	getline(cin, user_input);
	user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		if(user_input=="Y" || user_input=="y")
			system("shutdown -r -t 2");
		if(user_input=="N" || user_input=="n")
			return;
}

//shutdown system
void shutdown() { 

	string user_input;
	system("cls");
	cout << "\n Shutdown?"
		 << "\n (Y/y)es or (N/n)o: ";
	cin.ignore(256,'\n');
	getline(cin, user_input);
	user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		if(user_input=="Y" || user_input=="y")
			system("shutdown -s -t 2");
		if(user_input=="N" || user_input=="n")
			return;
}
//Log out
void logout(){
	
	string user_input;
	system("cls");
	cout << "\n Log out?"
		 << "\n (Y/y)es or (N/n)o: ";
	cin.ignore(256,'\n');
	getline(cin, user_input);
	user_input.erase(remove_if(user_input.begin(), user_input.end(), IsSpaceOrCR), user_input.end());
		if(user_input=="Y" || user_input=="y")
			system("shutdown -l");
		if(user_input=="N" || user_input=="n")
			return;
}

