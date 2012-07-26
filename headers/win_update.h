using namespace std;
//Shows the installed Windows updates.
void updates()
{
		ofstream myfile;
		system("cls");
		int sysinf = system("wmic qfe list brief >> %TMP%\winupdates.txt");
		system("notepad %TMP%\winupdates.txt");
		int i = remove("%TMP%\\winupdates.txt");
		if ( !i ) {
			cout << "\nCould not delete winupdates.txt\n\n";
		}
}

//Detect new Windows updates
void detectupd()
{
	system("cls");
	cout << "\n Opening Windows update, choose online check." << endl << endl;
	int i = system("wuapp 2> NUL ");
	if(i != 0){
		int j = system("wupdmgr.exe -z -q > NUL");
		if(j != 0){
			cout << "\nCould not load the Windows Update Manager" << endl;
		}
	}
		system("pause");
}