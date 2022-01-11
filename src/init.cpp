#include <iostream>
#include <mutex>
#include <cstring>
#include <thread>
#include <vector>
#include "init.h"

void peculiar::runExe(std::string value)
{
    std::mutex m;
    std::thread t{[&]
        {
            std::lock_guard<std::mutex> lock{m};
            system(value.c_str());
        }
    };
    t.join();
}
std::vector<std::string> peculiar::str_split(std::string str,std::string del){
    std::vector<std::string> cmdStrArray;
    int start = 0;
    int end = str.find(del);
    while(end!=-1){
        cmdStrArray.push_back(str.substr(start,end-start));
        start = end+del.size();
        end = str.find(del,start);
    }
    cmdStrArray.push_back(str.substr(start,end-start));
    return cmdStrArray;
}


 
std::string peculiar::setCommand(std::vector<std::string> busyboxCmd,std::string cmd)
{
    std::vector<std::string> cmdArr = peculiar::str_split(cmd," ");
    std::string newCommand = "";
    for(int i = 0; i < busyboxCmd.size();i++)
    {
        if (cmdArr[0] == busyboxCmd[i])
        {
            newCommand = "busybox " + cmd;
        }
    }
    if (newCommand == ""){
        return cmd;
    }
    else
    {
       return newCommand;
    }
}

std::vector<std::string> peculiar::getBusyboxCommand()
{
    std::vector<std::string> busyboxCmd = {
        "vi","wget","su","whoami","whois","bash"
        "sh","env","pwd","tar","find","grep"
    };
    return busyboxCmd;
}

