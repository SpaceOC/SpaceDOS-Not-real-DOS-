#ifndef SPACEDOS_OTHER_FAKE_LOADING_H_
#define SPACEDOS_OTHER_FAKE_LOADING_H_

#include <string>
#include <vector>

void fakeLoading(std::vector<char> symbols, std::vector<std::string> messages, long long ms, bool constTime);
void fakeLoadingPercent(std::vector<std::string> messages, long long ms, bool constTime);
//void fakeLoadingBar(std::vector<std::string> messages, long long ms, bool constTime);
//void fakeLoadingPercentAndBar(std::vector<std::string> messages, long long ms, bool constTime);
#endif