using namespace std;
//Shows the system information.
void systeminfo()			
{
		system("cls");
		int sysinf = system("systeminfo > %TEMP%\\sysinfo.txt");
		 if(sysinf != 0) {
			cout << "Error while reading the system information";
		 }
		system(" notepad %TEMP%\\sysinfo.txt ");
		system(" del %TEMP%\\sysinfo.txt ");
}

//Shows the installed Software.
void softinst()			
{
		system("cls");
		cout << "Indexing...";
		int sysinf = system("wmic product list status > %TMP%\\software.txt");
		system("notepad %TMP%\\software.txt");
		system("del %TMP%\\software.txt");
		system("cls");
}

//Shows the current network configuration.
void networkconf()
{
	system("cls");
		int sysinf = system("netsh interface ip show config");
		cout << sysinf << endl;
		system("pause");
}
