#include "Utility.h"

using namespace std;

string Utility::check_Vaild_String(){
     while(true){
        getline(cin,lang);
        if(lang.empty()){
            cout<<"Select input/空の入力です"<<endl;
        }else if(lang != "1" && lang != "2"){
            cout<<"Unexpected input/無効な入力です"<<endl;
        }else{
            break;
        }
    }
    return lang;
}
