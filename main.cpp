#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    short int userOption;
    string line;
    int lineCount; 
   do{
     cout << "1.Show Cpu info\n 2.Show memory info\n 3.Show Os version\n 4.Exit\n";
     cin >> userOption;
     switch(userOption){
        case 1: {
            ifstream cpuFile("/proc/cpuinfo");
            lineCount = 0; 
            while(getline(cpuFile, line)){
                cout << line << endl;
                lineCount++;
                if(lineCount >= 7) break; 
            }
            cpuFile.close();
            break;
        }
        case 2: {
            ifstream memoryFile("/proc/meminfo");
            lineCount = 0; 
            while(getline(memoryFile, line)){
                cout << line << endl;
                lineCount++;
                if(lineCount >= 3) break; 
            }
            memoryFile.close();
            break;
        }
        case 3: {
            ifstream osVersion("/etc/os-release");
            while(getline(osVersion, line)){
                if(line.find("NAME=") == 0 || line.find("VERSION=") == 0){
                    cout << line << endl;
                }
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
