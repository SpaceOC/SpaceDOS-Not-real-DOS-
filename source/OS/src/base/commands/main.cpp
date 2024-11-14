#include "Core/base/print.h"
#include "Core/base/command/handler_commands.h"
#include "OS/base/commands/settings.h"
#include "OS/base/commands/other.h"
#include "OS/games/RSP.h"
#include "OS/other/time.h"
#include "OS/other/counter.h"
#include "OS/other/logs.h"
#include "OS/games/snake.h"

extern bool work;

void addCommands() {
    core::HandlerCommands::addCommand("settings", "SpaceDOS settings", SpaceDOSSettings::settingsChoice);
    core::HandlerCommands::addCommand("logo", "show SpaceDOS logo", OS_COMMAND_logo);
    core::HandlerCommands::addCommand("hello", "hi", OS_COMMAND_hi);
    core::HandlerCommands::addCommand("os_info", "show SpaceDOS information", OS_COMMAND_dosInfo);
    core::HandlerCommands::addCommand("faf", "show all files and folders in the current directory", OS_COMMAND_seeFaF);
    core::HandlerCommands::addCommand("rsp", "Rock, Scissors, Paper!", RSP);
    core::HandlerCommands::addCommand("counter", {"counter", {"min", "max"}}, counterWithArgs, 0, 2);
    core::HandlerCommands::addCommand("work_time", "shows how much time SpaceDOS has been running", printWorkTime);
    core::HandlerCommands::addCommand("show_time", "displays the current time and date", printCurrentDate);
    core::HandlerCommands::addCommand("off", "exit SpaceDOS", [&]{ work = false; });
    core::HandlerCommands::addCommand("see_f", {"show all files/folders in the current directory", {"type"}}, OS_COMMAND_seeOnlyF, 1, 1);
    core::HandlerCommands::addCommand("logs", {"shows logs", {"type"}}, LogsManager::showLogs, 1, 1);
    core::HandlerCommands::addCommand("snake", "snake game", snakeGameStart);
}