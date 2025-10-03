#include <iostream>
#include "Dictionary.h"
#include "RockPaperScissors.h"
#include "NumGuessing.h"
#include "Utility.h"
using namespace std;
using RPS = Rock_Paper_Scissors;

int main(){
    cout<<"Choose language/言語を選択してください (1:English 2:日本語):"<<endl;

    Utility utility;
    int tmp = utility.check_Vaild_Num({"1","2"});
    LANGUAGE selected_lang = static_cast<LANGUAGE>(tmp);

    if(selected_lang == 1){
        cout<<"English Selected"<<endl;
    }else if(selected_lang == 2){
        cout<<"日本語が選択されました"<<endl;
    }

    string game;
    while(true){
        if(selected_lang == 1){
            cout<<"Choose game to play (1:Rock Paper Scissors 2:NumberGuessing):"<<endl;;
        }else if(selected_lang == 2){
            cout<<"遊びたいゲームを入力してください(1:じゃんけん 2:数当てゲーム)"<<endl;
        }

        int selected_game = utility.check_Vaild_Num({"1","2"});

        if(selected_game == 1){
            RPS rps(selected_lang);
            string cont = rps.play_RPS();
            if(cont == "m"){
                continue;
            }else if(cont == "n"){
                break;
            }
        }else if(selected_game == 2){
            NumGuessing ng(selected_lang);
            string cont = ng.play_NG();
            if(cont == "m"){
                continue;
            }else if(cont == "n"){
                break;
            }
        }
    }
   
    return 0;
}