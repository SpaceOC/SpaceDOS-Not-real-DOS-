/*#include <iostream>

using namespace std;

enum class Check_Status {
    Not_Found_Check = 101,
    OK_Check = 102,
    Incorrect_Check = 103,
    Unknown_Check = 104,
    Bad_Check = 105,
    Unrelease_Check = 106,
    Error_Check = 107,
    Its_Not_Check = 108
};

enum class Input_Status {
    Not_Found_Input = 201,
    OK_Input = 202,
    Incorrect_Input = 203,
    Unknown_Input = 204,
    Bad_Input = 205,
    Unknown_Error_Input = 206,
    Error_Input = 207,
    Its_Not_Input = 208
};

enum class Symbols_Status {
    Not_Found_Symbols = 301,
    OK_Symbols = 302,
    Incorrect_Symbols = 303,
    Unknown_Error_Symbols = 304,
    Error_Symbols = 305
};

enum class Mods_Status {
    Error_Mod = 401,
    OK_Mod = 402,
    Unknown_Error_Mod = 403,
    Not_Found_Mod = 404
};

void SendStatus(int ErrCode, Check_Status status) {
    switch (status) {
        case Check_Status::Not_Found_Check:
            cout << "Error " << ErrCode << ": Check not found" << endl;
            break;
        case Check_Status::OK_Check:
            cout << "Error " << ErrCode << ": OK Check" << endl;
            break;
        case Check_Status::Incorrect_Check:
            cout << "Error " << ErrCode << ": Incorrect Check" << endl;
            break;
        // Добавьте обработку других значений перечисления Check_Status по аналогии
        default:
            cout << "Error " << ErrCode << ": Unknown error" << endl;
            break;
    }
}

void SendStatus(Input_Status status) {
    switch (status) {
        case Input_Status::Not_Found_Input:
            cout << "Error " << 201 << ": Input not found" << endl;
            break;
        case Input_Status::OK_Input:
            cout << "Error " << 202 << ": OK Input" << endl;
            break;
        case Input_Status::Incorrect_Input:
            cout << "Error " << 203 << ": Incorrect Input" << endl;
            break;
        case Input_Status::Incorrect_Input:
            cout << "Error " << 204 << ": Incorrect Input" << endl;
            break;
        case Input_Status::Incorrect_Input:
            cout << "Error " << 205 << ": Incorrect Input" << endl;
            break;
        case Input_Status::Incorrect_Input:
            cout << "Error " << 207 << ": Incorrect Input" << endl;
            break;
        case Input_Status::Incorrect_Input:
            cout << "Error " << 208 << ": Incorrect Input" << endl;
            break;
        default:
            cout << "Error " << 206 << ": Unknown error" << endl;
            break;
    }
}*/