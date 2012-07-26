// Windows System Configuration Tool
// Date: 26/07/2012
// By: Peewster

#define NOMINMAX				
#include <windows.h>
#include <WinReg.h>
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <algorithm>
#include <cctype>
#include <direct.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <cstdio>

// custom headers
#include "headers/hardw_info.h"
#include "headers/net_functions.h"
#include "headers/system_info.h"
#include "headers/win_update.h"
#include "headers/configurations.h"
#include "headers/account_control.h"
#include "headers/sys_functions.h"
#include "headers/menu.h"


#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
#define DIV 1024000000;
using namespace std;

int main()
{
	 int loop = 1;
	 int color1 = 2;
	 int color2 = 7;
	 int color3 = 4;
	 int color4 = 6;
	 int color5 = 9;
	 int col3 = 3;
	 int sys;

	 HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 HANDLE hStdout;
	 hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleTitle("System Configuration Tool v1.0");	    //Set's the terminal title.
	 SMALL_RECT windsize = {0, 0, 65, 50};					//Configures the cmd window.
	 SetConsoleWindowInfo(hConsole, TRUE, &windsize);

//Get important information first in notepad
	
		//System Summary
		SetConsoleTextAttribute(hStdout, color5);
		cout << "--- System Summary ---" << endl << endl;
		system("wmic computersystem get name, domain, manufacturer, model");
		cout << "--------------------------------------------------------------" << endl << endl << endl; 
		//cpuinfo
		SetConsoleTextAttribute(hStdout, color1);
		cout << "--- CPU Information ---" << endl << endl;
		system("wmic cpu get Name, ProcessorId, Revision");
		cout << "--------------------------------------------------------------" << endl << endl << endl;
		//memory info
		SetConsoleTextAttribute(hStdout, color2);
		cout << "--- Memory Information ---" << endl << endl;
		system("wmic MEMORYCHIP get banklabel, devicelocator, caption, capacity");
		cout << "-----------------------------------------------" << endl << endl << endl;
		//harddisk info
		SetConsoleTextAttribute(hStdout, col3);
		cout << "--- Harddisk Information ---" << endl << endl;
		system("wmic diskdrive get Size, Status");
		cout << "-----------------------------------------------" << endl << endl << endl;
		//partition info
		SetConsoleTextAttribute(hStdout, color4);
		cout << "--- Partition Information ---" << endl << endl;
		system("wmic partition get DeviceID, Name, Size");
		cout << "-----------------------------------------------------------" << endl << endl << endl;
		system("pause");

    while(loop==1)
	{
			system("CLS");	//Main menu.
			SetConsoleTextAttribute(hStdout, color2);
			cout << "\n\n";
			cout << "    =======================================================" << endl;
			cout << "    ||                                                   ||" << endl;  
			cout << "    ||                 System Configuration              ||" << endl;
			cout << "    ||                      Tool V1.0                    ||" << endl;
			cout << "    ||                                                   ||" << endl;
			cout << "    ||                            by: peewster@gmail.com ||" << endl;
			cout << "    =======================================================" << endl; 
			SetConsoleTextAttribute(hStdout, color4);
			cout << "\n\n    # Main menu # \n";  
			SetConsoleTextAttribute(hStdout, color2);
			cout << "\n    1)  - Information Gathering."
				 << "\n    2)  - Configurations."
				 << "\n    3)  - User Account Control."
				 << "\n    4)  - Networking Utils."
				 << "\n    5)  - Search for files. "
				 << "\n    6)  - Get a cmd command prompt." << endl
				 << "    (type exit to return here.)\n"; 
				 SetConsoleTextAttribute(hStdout, color4); cout
				 << "\n    7)  - Reboot."
				 << "\n    8)  - Shutdown."
				 << "\n    9)  - Log out."; SetConsoleTextAttribute(hStdout, color3); cout
				 << "\n\n    0) - Exit.\n"; SetConsoleTextAttribute(hStdout, color2); cout
				 << endl
				 << "    Your choice (0..9): ";
             
			while (!(cin >> sys)){		//Allow only digits.
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "    Invalid input, try again." << endl;
				cout << "    Your choice (0..9): ";
			}	
			 switch(sys)	//Use user input to use case.
             {
				    case 1:
							menu_info();
							break;
					case 2:
							menu_config();
							break;
					case 3:
							menu_uac();
							break;
					case 4:
							menu_net();
							break;
					case 5:
							finder();
							break;
					case 6: 
							cmd();
							break;
					case 7: 
							reboot();
							break;
					case 8: 
							shutdown();
							break;
					case 9:
							logout();
							break;
					case 0:
							return(0);  
					
			}		
	}
}
