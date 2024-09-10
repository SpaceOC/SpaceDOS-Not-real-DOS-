#include "Core/base/print.h"
#include "Core/base/command/handler_commands.h"
#include "OS/base/commands/settings.h"
#include "OS/base/commands/other.h"
#include "OS/games/RSP.h"
#include "OS/other/time.h"
#include "OS/other/counter.h"
#include "OS/other/logs.h"

extern bool work;

void addCommands() {
    core::handlerCommands HC;
    HC.addCommand("settings", "spaceDOS settings", [&]{ SpaceDOS_Settings(); });
    HC.addCommand("logo", "show SpaceDOS logo", OS_COMMAND_logo);
    HC.addCommand("hello", "hi", OS_COMMAND_hi);
    HC.addCommand("os_info", "show DOS information", OS_COMMAND_dosInfo);
    HC.addCommand("faf", "show all files and folders in the current directory", OS_COMMAND_seeFaF);
    HC.addCommand("rsp", "Rock, Scissors, Paper!", RSP);
    HC.addCommand("counter", {"counter", {"min", "max"}}, counterWithArgs, 0, 2);
    HC.addCommand("work_time", "shows how much time SpaceDOS has been running", printWorkTime);
    HC.addCommand("show_time", "displays the current time and date", printCurrentDate);
    HC.addCommand("exit", "exit SpaceDOS", [&]{ work = false; });
    HC.addCommand("see_f", {"show all files/folders in the current directory", {"type"}}, OS_COMMAND_seeOnlyF, 1, 1);
    HC.addCommand("logs", {"Shows logs", {"type"}}, logsManager::showLogs, 1, 1);
}