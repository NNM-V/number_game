#include <iostream>
#include "Dictionary.h"
#include "RockPaperScissors.h"
#include "NumGuessing.h"
#include "Utility.h"
using namespace std;
using RPS = RockPaperScissors;

int main(){
    Utility utility;

    //User language select
    cout<<"Choose language/言語を選択してください (1:English 2:日本語):"<<endl;
    //1:English 2:Japanese
    //get user input and check vailidity
    int tmp = utility.check_valid_num({"1","2"});
    //get selected language from user input
    LANGUAGE selected_lang = static_cast<LANGUAGE>(tmp);

    switch(selected_lang)
    {
        case ENGLISH:
            cout<<"English Selected"<<endl;
            break;
        case JAPANESE:
            cout<<"日本語が選択されました"<<endl;
            break;
        default:
            break;
    }

    while(true){
         switch(selected_lang)
        {
            case ENGLISH:
                cout<<"Choose game to play (1:Rock Paper Scissors 2:NumberGuessing):"<<endl;;
                break;
            case JAPANESE:
                cout<<"遊びたいゲームを入力してください(1:じゃんけん 2:数当てゲーム)"<<endl;
                break;
            default:
                break;
        }
       
        //get user input and check vailidity
        int selected_game = utility.check_valid_num({"1","2"});
        //1:rockpaperscissors 2:numberguessing
        if(selected_game == 1){
            RPS rps(selected_lang);
            string cont = rps.play_rps();
            //ask user for replay
            if(cont == "m"){
                continue;
            }else if(cont == "n"){
                break;
            }
        }else if(selected_game == 2){
            NumGuessing ng(selected_lang);
            string cont = ng.play_number_game();
            if(cont == "m"){
                continue;
            }else if(cont == "n"){
                break;
            }
        }
    }
   
    return 0;
}