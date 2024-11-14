#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "OS/other/fake_loading.h"

void fakeLoading(std::vector<char> symbols, std::vector<std::string> messages, long long ms, bool constTime) {
    int index = 0;

    for (int messageCount = 0; static_cast<size_t>(messageCount) <= (messages.size() - 1); messageCount++) {
        if (messageCount > 0) std::cout << std::string(messages.at(messageCount - 1).length() + 5, '\b');
        int t = (!constTime ? (messageCount * 2) : 0);
        for (int i = 0; i < 3 + t; i++) {
            std::cout << messages.at(messageCount) + " " << symbols.at(index);
            std::cout.flush();
            index = (index + 1) % 4;
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            std::cout << std::string(messages.at(messageCount).length() + 5, '\b');
        }
        std::cout << std::string(messages.at(messageCount).length() + 5, ' ');
    }

    std::cout << std::string(messages.back().length() + 5, '\b');
    std::cout << "SpaceDOS launched successfully!\n";
}

void fakeLoadingPercent(std::vector<std::string> messages, long long ms, bool constTime) {
    float max = 0.0f;
    for (int i = 0; static_cast<size_t>(i) <= messages.size() - 1; i++) {
        int t = (!constTime ? (i * 2) : 0);
        max += 3 + t;
    }
    float curPercent = 1 / max;
    std::string temp;

    for (int messageCount = 0; static_cast<size_t>(messageCount) <= (messages.size() - 1); messageCount++) {
        if (messageCount > 0) std::cout << std::string(temp.length(), '\b');
        int t = (!constTime ? (messageCount * 2) : 0);
        for (int i = 0; i < 3 + t; i++) {
            float percent = (curPercent * 100);
            temp = messages.at(messageCount) + " " + std::to_string(static_cast<int>(percent)) + "%";
            std::cout << temp;
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            std::cout << std::string(temp.length(), '\b');
            curPercent += 1 / max;
        }
        std::cout << std::string(temp.length(), ' ');
    }

    std::cout << std::string(temp.length(), '\b');
    std::cout << "SpaceDOS launched successfully!\n";
}