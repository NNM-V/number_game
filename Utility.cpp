#include "Utility.h"
using namespace std;

string Utility::check_Valid(const vector<string>& valid_string){
    string input;
    while(true){
        getline(cin,input);
        auto it = std::find(valid_string.begin(), valid_string.end(), input);
        if(input.empty()){
            cout<<"Select input/空の入力です"<<endl;
        }else if(it == valid_string.end()){
            cout<<"Unexpected input/無効な入力です"<<endl;
        }else{
            return input;
        }
    }
}

int Utility::check_Vaild_Num(const vector<string>& valid_string){
    string num = check_Valid(valid_string);
    return stoi(num);
}

string Utility::check_Vaild_String(const vector<string>& valid_string){
    return check_Valid(valid_string);;
}