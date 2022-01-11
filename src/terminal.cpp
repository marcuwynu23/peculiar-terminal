#include <iostream>
#include <mutex>
#include <cstring>
#include <thread>
#include <vector>
#include "init.h"

using namespace std;

int main()
{	string cmd,initial;
	initial = "title Terminal & color 0A &";
	peculiar::runExe(initial+"cls");
	while(1){
		cout << "$: ";
		getline(cin,cmd);
		if(cmd == "q"){
			exit(0);
		}else{
			string newCmd = peculiar::setCommand(peculiar::getBusyboxCommand(),cmd);
			peculiar::runExe(newCmd);
		}
	}
	return 0;
}