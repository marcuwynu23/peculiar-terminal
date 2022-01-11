#include <iostream>
#include <mutex>
#include <cstring>
#include <thread>
#include <vector>

#ifndef __INIT_H__
#define __INIT_H__
#ifdef __cplusplus
extern "C"{
#endif

namespace peculiar{
    void runExe(std::string value);
    std::vector<std::string> str_split(std::string str,std::string del);
    std::string setCommand(std::vector<std::string> busyboxCmd,std::string cmd);
    std::vector<std::string> getBusyboxCommand();
}

#ifdef __cplusplus
}
#endif
#endif 
