#ifndef SPACEDOS_OTHER_LOGS_H_
#define SPACEDOS_OTHER_LOGS_H_
#include <string>
#include <vector>

class logsManager {
    private:
        struct logsData {
            std::string content, function, stringTime;
        };
        static inline std::vector<std::vector<logsData>> allLogsData;
        static inline std::vector<logsData> currentLogs;

        static void showCurrentLogs();
        static void showFileLogs();
    public:
        static void writeLogs(std::string function, std::string content);
        static void showLogs(const std::vector<std::string>& args);
        static void loadLogs();
        static void saveLogs();
};
#endif