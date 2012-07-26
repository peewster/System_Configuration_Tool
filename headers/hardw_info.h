using namespace std;

bool IsSpaceOrCR(char ch) 
{
   return ::isspace(ch) || ch == '\n';
}

//Lists the installed networking cards.
void networkcards() 
{
		system("cls");
		system("color B");
		cout << "\n";
		cout << "Installed Networking Cards: \n\n";
		int sysinf = system("wmic nic get description, Speed | findstr \"Connection Net Gig GIG PCIe GB GBE Speed\"");
		cout << endl;
		cout << "\n " + sysinf << endl;
		system("pause");
}

//Show partitions with size
void partitions()
{
	string line;
		system("cls");
		system("color B");
		int sysinf = system("wmic logicaldisk get Name, Filesystem, Size, VolumeName ");
		cout << endl;
		cout << "\n" + sysinf;
		system("pause");
}

//Shows cpu information
#pragma comment(lib, "user32.lib")

void cpuinfo()
{
  SYSTEM_INFO siSysInfo;
 
   // Copy the hardware information to the SYSTEM_INFO structure. 
   GetSystemInfo(&siSysInfo); 
   printf("  Number of processors: %u\n", 
      siSysInfo.dwNumberOfProcessors); 

	system("cls");
	string answer;
	cout << "\n for VM type (V/v), for PC (P/p): ";
	cin.ignore(256,'\n');
	getline(cin, answer);
	answer.erase(remove_if(answer.begin(), answer.end(), IsSpaceOrCR), answer.end());
	if(answer=="V" || answer=="v") {
		system("cls");
		system("color B");
		system("wmic cpu get Name"); cout << "\n";
		system("wmic cpu get ProcessorId, Revision"); cout << "\n";
		GetSystemInfo(&siSysInfo); 
		printf("Number of processor cores: %u\n\n", 
		siSysInfo.dwNumberOfProcessors);
		system("wmic cpu get Manufacturer, MaxClockSpeed");
		cout << endl;
		system("pause");
	}
	if(answer=="P" || answer=="p") {
		system("color B");
		system("cls");
		system("wmic cpu get Name"); cout << "\n";
		system("wmic cpu get ProcessorId, Revision"); cout << "\n";
		GetSystemInfo(&siSysInfo); 
		printf("Number of processor cores: %u\n", 
		siSysInfo.dwNumberOfProcessors);
		system("wmic cpu get Status ");
		int sysinfo2 = system("wmic cpu get Manufacturer, MaxClockSpeed");
		cout << "\n";
		int sysinfo3 = system("wmic cpu get L2CacheSize, L3Cachesize");
		cout << endl;
		system("pause");
		}
}

//Shows memory information

void memory()
{
#define DIV 1024000;
  MEMORYSTATUSEX statex;
  statex.dwLength = sizeof (statex);
  GlobalMemoryStatusEx (&statex);
	system("cls");
	string answer;
	cout << "\n for VM type (V/v), for PC (P/p): ";
	cin.ignore(256,'\n');
	getline(cin, answer);
	answer.erase(remove_if(answer.begin(), answer.end(), IsSpaceOrCR), answer.end());
	if(answer=="V" || answer=="v") {
		system("cls");
		system("color B");
			std::cout << "System Memory usage: \t\t" << statex.dwMemoryLoad << "%\n";
			std::cout << "System Available Memory: \t" << statex.ullAvailPhys/DIV; cout << " MB \n";
			std::cout << "System Total Memory: \t\t" << statex.ullTotalPhys/DIV; cout << " MB \n";	
			cout << "\n";
			int sysinfo = system("wmic MEMORYCHIP get banklabel, devicelocator, caption, PartNumber, SerialNumber, speed");
			cout << "\n" + sysinfo << endl;
			system("pause");
	}
	if(answer=="P" || answer=="p") {
			system("cls");
			system("color B");
			std::cout << "System Memory usage: \t\t" << statex.dwMemoryLoad << "%\n";
			std::cout << "System Available Memory: \t" << statex.ullAvailPhys/DIV; cout << " MB \n";
			std::cout << "System Total Memory: \t\t" << statex.ullTotalPhys/DIV; cout << " MB \n";	
			cout << "\n";
			int sysinfo = system("wmic MEMORYCHIP get banklabel, devicelocator, caption, PartNumber, speed");
			cout << "\n" + sysinfo << endl;
			system("pause");
	}
}

//Shows disk info
void harddrives() {
		system("cls");
		system("color B");
		cout << "\n";
		int sysinfo = system("wmic diskdrive get Size, Interfacetype");
		cout << "\n";
		int sysinfo1 = system("wmic diskdrive get MediaType, Model, Status");
		cout << "\n";
		system("pause");
}
