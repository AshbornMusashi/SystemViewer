#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    short int userOption;
    string line;

   do{
     cout << "1.Show Cpu info\n 2.Show memory info\n 3.Show Os version\n 4.Exit\n";
     cin >> userOption;
     switch(userOption){
        case 1: {
            ifstream cpuFile("/proc/cpuinfo");
            while(getline(cpuFile, line)){
                cout << line << endl;
            }
            cpuFile.close();
            break;
        }
        case 2: {
            ifstream memoryFile("/proc/meminfo");
            while(getline(memoryFile, line)){
                cout << line << endl;
            }
            memoryFile.close();
            break;
        }
        case 3: {
            ifstream osVersion("/etc/os-release");
            while(getline(osVersion, line)){
                cout << line << endl;
            }
            osVersion.close();
            break;
        }
        default:
           cout << "Invalid input\n";
           break;
        }
    }while(userOption != 4);
    return 0;
}   
