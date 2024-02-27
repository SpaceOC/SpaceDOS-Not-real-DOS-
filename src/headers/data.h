#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;

void CreateFolders();

void CreateLogFile();

void CheckAddons();

void CreateDataFile();
void CreateDataFile(path FilePath, vector<string> VarNames, vector<string> VarVar);

void ReadDataFile();
void ReadDataFile(string VarName, string& GetVar);
void ReadDataFile(string VarName, string& GetVar, path FilePath);

void EditData(const string& field, const string& value);
void EditData(const string& field, const string& value, const path FilePath, const path TempFilePath);
