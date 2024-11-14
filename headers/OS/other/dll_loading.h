/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <functional>
#include <Windows.h>
#include "Core/base/command/handler_commands.h"
#include "Core/base/print.h"

struct LoaderCommandObject {
    std::string name;
    std::string description;
    std::function<void()> command;
};

struct LoaderObject {
    std::string name;
    std::vector<LoaderCommandObject> commands;
    std::function<bool()> loader;
};

class LoadingManager {
    private:
        typedef BOOL (*SpaceDOSLoaderFunction)();
        typedef const char* (*DLLName)();
        typedef const char* (*AddCommandsFunctions)();
        typedef const char* (*AddCommandsNames)(const char* funcName);
        typedef const char* (*AddCommandsDesc)(const char* funcName);
        typedef void (*Command)();

        float currentPhase = 1.0f;
        std::vector<LoaderObject> dllsBools;
        std::map<int, bool> phases;
    public:
        LoadingManager();
        void setup(const std::vector<std::string>& pathes);
        void start();
};
*/