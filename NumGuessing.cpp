#include "NumGuessing.h"
using namespace std;

string NumGuessing::play_NG(){
    while(true){
        int rand_num = get_RandomNum();
        //test output
        cout<<rand_num<<endl;
        
        if(selected_lang == 1){
            cout<<"Let's play Number guessing game!"<<endl;
        }else if(selected_lang == 2){
            cout<<"数当てゲームをしましょう!"<<endl;
        }
        
        get_UserGuess(rand_num);

        cout<<dict.get_value(REPLAY,selected_lang)<<endl;
        Utility utility;
        string tmp = utility.check_Vaild_String({"y","n","m"});
        if(tmp == "m" || tmp == "n"){
            return tmp;
        } 
    }
}

int NumGuessing::get_RandomNum(){
    uniform_int_distribution<> dis(1, 100);
    return dis(engine);
}

void NumGuessing::get_UserGuess(const int& rand_num){
    //input hand 
    while(true){
        if(selected_lang == 1){
            cout<<"Guess a number between 1~100:"<<endl;
        }else if(selected_lang == 2){
            cout<<"1-100の間で数字を選んでね:"<<endl;
        }
        
        getline(cin,input);
        if(input.empty()){
            cout<<dict.get_value(EMPTY_INPUT,selected_lang)<<endl;
        }else{
            try{
                int num = stoi(input);
                if(num<1 || num>100){
                    cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
                    continue;
                }
                if(num>rand_num){
                    if(selected_lang == 1){
                        cout<<"The number is smaller than "<<num<<endl;
                    }else if(selected_lang == 2){
                        cout<<num<<" よりも小さいです"<<endl;
                    }
                }else if(num<rand_num){
                    if(selected_lang == 1){
                        cout<<"The number is bigger than "<<num<<endl;
                    }else if(selected_lang == 2){
                        cout<<num<<" よりも大きいです"<<endl;
                    }
                }else if(num==rand_num){
                    if(selected_lang == 1){
                        cout<<"Correct!!"<<endl;
                    }else if(selected_lang == 2){
                        cout<<"正解!"<<endl;
                    }
                    break;
                }
            }
            catch(const invalid_argument& e){
                cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
            }catch (const std::out_of_range& e) {
                cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
            }
        }
    }
}