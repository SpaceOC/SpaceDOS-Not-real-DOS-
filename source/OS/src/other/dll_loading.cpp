/*
#include "OS/OS_info.h"
#include "OS/other/dll_loading.h"
#include "Core/base/utils.h"

LoadingManager::LoadingManager() {}

void LoadingManager::setup(const std::vector<std::string>& pathes) {
    for (std::string path : pathes) {
        const char* dllPath = path.c_str();
        HMODULE hModule = LoadLibraryA(dllPath);
        if (hModule == NULL) {
            std::cerr << "Не удалось загрузить DLL файл." << std::endl;
            FreeLibrary(hModule);
        }

        SpaceDOSLoaderFunction funcLoader = (SpaceDOSLoaderFunction)GetProcAddress(hModule, "__dllLoader");
        DLLName funcName = (DLLName)GetProcAddress(hModule, "dllName");
        AddCommandsFunctions funcCommands = (AddCommandsFunctions)GetProcAddress(hModule, "addCommands_functions");
        if (funcLoader == NULL || funcName == NULL || funcCommands == NULL) {
            std::cerr << "Одна из функций не была найдена в DLL файле." << std::endl;
            FreeLibrary(hModule);
        }
        else {
            std::vector<std::string> functions = core::Utils::split(funcCommands(), ' ');
            AddCommandsDesc addCommandFuncDesc = (AddCommandsDesc)GetProcAddress(hModule, "addCommands_description");
            AddCommandsNames addCommandFuncName = (AddCommandsNames)GetProcAddress(hModule, "addCommands_name");
            std::vector<LoaderCommandObject> a;
            for (int i = 0; static_cast<size_t>(i) < functions.size(); i++) {
                Command command = (Command)GetProcAddress(hModule, functions.at(i).c_str());
                a.push_back({addCommandFuncName(functions.at(i).c_str()), addCommandFuncDesc(functions.at(i).c_str()), command});
            }
            this->dllsBools.push_back({funcName(), a, funcLoader});
        }
    }
}

void LoadingManager::start() {
    for (int i = 0; static_cast<size_t>(i) < dllsBools.size(); i++) {
        phases[i] = dllsBools.at(i).loader();
        if (!phases.at(i)) {
            std::cout << std::endl << "Error! bool function returning false!" << '\n';
            continue;
        }
        for (auto command : dllsBools.at(i).commands) {
            core::HandlerCommands::addCommand(command.name, command.description, command.command);
        }
    }
    currentPhase = 0;
}
*/