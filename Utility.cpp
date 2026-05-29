#include "Utility.h"
using namespace std;

string Utility::check_valid(const vector<string>& valid_string){ 
    while(true){
        string input;
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

int Utility::check_valid_num(const vector<string>& valid_string){
    string num = check_valid(valid_string);
    return stoi(num);
}

string Utility::check_valid_string(const vector<string>& valid_string){
    return check_valid(valid_string);;
}