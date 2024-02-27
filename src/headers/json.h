#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <string>

// Это самый [кринжовый?] и сырой инструментал для работы с JSON файлами, который ты мог увидеть
// ......................................................

using namespace std;
using namespace filesystem;

class JsonInstrumental {
    public:
        void File_Create(path FilePath) {
            ifstream file(FilePath);
            if (!file) {
                ofstream data(FilePath);
                if (data) {
                    data << "{";
                    data << "\n";
                    data << "\n}";
                    data.close();
                }
                else {
                    cout << "Error opening the data file." << '\n';
                }
            }
            else {
                file.close();
            }
        }

        void File_Create(path FilePath, vector<string> Data, bool MassiveList) {
            int i = 1;
            ifstream file(FilePath);
            if (!file) {
                ofstream data(FilePath);
                if (data) {
                    data << "{";
                    if (!Data.empty() && !MassiveList) {
                        data << "\n\t\"" << Data[0] << "\" : {\n";
                        while (i <= (Data.size() - 1)) {
                            data << "\t" + Data[i] + "\n";
                            i++;
                        }
                        data << "\t}";
                    }
                    if (!Data.empty() && MassiveList) {
                        data << "\n\t\"" << Data[0] << "\" : [\n";
                        while (i <= (Data.size() - 1)) {
                            data << "\t" + Data[i] + "\n";
                            i++;
                        }
                        data << "\t]";
                    }
                    data << "\n}";
                    data.close();
                }
                else {
                    cout << "Error opening the data file." << '\n';
                }
            }
            else {
                file.close();
            }
        }

        void File_Add_Data(path FilePath, vector<string> Data, bool Name) {
            int i = 1;
            ifstream file(FilePath);
            string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

            size_t pos = fileContent.find('{');
            if (pos!= string::npos) {
                pos = fileContent.find('\n', pos);
                if (pos!= std::string::npos) {
                    string newData;
                    if (Name) {
                        newData += Data[0] + "\n";
                    }
                    while (i <= (Data.size() - 1)) {
                        newData += Data[i] + "\n";
                        i++;
                    }
                    fileContent.insert(pos + 1, newData);

                    ofstream outFile(FilePath);
                    if (outFile) {
                        outFile << fileContent;
                    }
                }
            }
            file.close();
        }

        void File_Replace_Data(path FilePath, vector<string> Old_Data, vector<string> New_Data, bool Name) {
            int i = 0;
            ifstream file(FilePath);
            string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

            size_t pos = fileContent.find('{');
            if (pos!= string::npos) {
                pos = fileContent.find('\n', pos);
                if (pos!= std::string::npos) {
                    string newData;
                    /*if (Name) {
                        newData += Data[0] + "\n";
                    }
                    while (i <= (Data.size() - 1)) {
                        newData += Data[i] + "\n";
                        i++;
                    }
                    fileContent.replace();*/

                    ofstream outFile(FilePath);
                    if (outFile) {
                        outFile << fileContent;
                    }
                }
            }
            file.close();
        }
};