#include "NumGuessing.h"
using namespace std;

string NumGuessing::play_number_game(){
    while(true){
        int rand_num = get_random_num();
        //test output
        cout<<rand_num<<endl;
        
        switch(selected_lang)
        {
            case ENGLISH:
                cout<<"Let's play Number guessing game!"<<endl;
                break;
            case JAPANESE:
                cout<<"数当てゲームをしましょう!"<<endl;
                break;
            default:
                break;
        }
        
        get_user_guess(rand_num);

        cout<<dict.get_value(REPLAY,selected_lang)<<endl;
        string tmp = utility.check_valid_string({"y","n","m"});
        if(tmp == "m" || tmp == "n"){
            return tmp;
        } 
    }
}

int NumGuessing::get_random_num(){
    return set_random_num(1,100);
}

void NumGuessing::get_user_guess(const int& rand_num){
    //input hand 
    while(true){
        switch(selected_lang)
        {
            case ENGLISH:
                cout<<"Guess a number between 1~100:"<<endl;
                break;
            case JAPANESE:
                cout<<"1-100の間で数字を選んでね:"<<endl;
                break;
            default:
                break;
        }

        string input; 
        getline(cin,input);
        
        if(input.empty()){
            cout<<dict.get_value(EMPTY_INPUT,selected_lang)<<endl;
        }else{
            try{
                int num = stoi(input);
                cout<<num<<endl;
                if(num<1 || num>100){
                    cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
                    continue;
                }
                if(num>rand_num){
                    switch(selected_lang)
                    {
                        case ENGLISH:
                            cout<<"The number is smaller than "<<num<<endl;
                            break;
                        case JAPANESE:
                            cout<<num<<" よりも小さいです"<<endl;
                            break;
                        default:
                            break;
                    }
                }else if(num<rand_num){
                    switch(selected_lang)
                    {
                        case ENGLISH:
                            cout<<"The number is bigger than "<<num<<endl;
                            break;
                        case JAPANESE:
                            cout<<num<<" よりも大きいです"<<endl;
                            break;
                        default:
                            break;
                    }
                }else if(num==rand_num){
                    switch(selected_lang)
                    {
                        case ENGLISH:
                            cout<<"Correct!!"<<endl;
                            break;
                        case JAPANESE:
                            cout<<"正解!"<<endl;
                            break;
                        default:
                            break;
                    }
                    break;
                }
            }catch(const invalid_argument& e){
                cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
            }catch (const out_of_range& e) {
                cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
            }
        }
    }
}