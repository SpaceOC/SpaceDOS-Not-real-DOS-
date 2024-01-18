#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <string>
#include "other.h"

// Это самый кринжовый [?] и сырой инструментал для работы с JSON файлами, который ты мог увидеть
// ......................................................

using namespace std;
using namespace filesystem;

class JsonInstrumental {
    public:
        void File_Create_NODATA(path FilePath) {
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
            ifstream file(FilePath);
            if (!file) {
                ofstream data(FilePath);
                if (data) {
                    data << "{";
                    if (!Data.empty() && !MassiveList) {
                        data << "\n\t\"" << Data[0] << "\" : {\n";
                        data << "\t" + Data[1] + "\n";
                        data << "\t}";
                    }
                    if (!Data.empty() && MassiveList) {
                        data << "\n\t\"" << Data[0] << "\" : [\n";
                        data << "\t" + Data[1] + "\n";
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
                    newData += Data[1] + "\n";
                    fileContent.insert(pos + 1, newData);

                    ofstream outFile(FilePath);
                    if (outFile) {
                        outFile << fileContent;
                    }
                }
            }
            file.close();
        }

        void File_Replace_Data(path FilePath, vector<string> Data, bool Name) {

        }
};