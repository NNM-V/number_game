#include <iostream>
#include "Dictionary.h"
#include "RockPaperScissors.h"
#include "NumGuessing.h"
#include "ContinueMenu.h"
#include "Utility.h"

using namespace std;
using RPS = Rock_Paper_Scissors;

int main(){
    cout<<"Number game"<<endl;

    cout<<"Choose language/言語を選択してください (1:English 2:日本語):"<<endl;
    Utility utility;
    string lang = utility.check_Vaild_String();
    int tmp = stoi(lang);
    LANGUAGE selected_lang = static_cast<LANGUAGE>(tmp);

    string game;

    if(selected_lang == 1){
        cout<<"English Selected"<<endl;
    }else if(selected_lang == 2){
        cout<<"日本語が選択されました"<<endl;
    }

    while(true){
        if(selected_lang == 1){
            cout<<"Choose game to play (1:Rock Paper Scissors 2:NumberGuessing):"<<endl;;
        }else if(selected_lang == 2){
            cout<<"遊びたいゲームを入力してください(1:じゃんけん 2:数当てゲーム)"<<endl;
        }

        game = utility.check_Vaild_String();
        int selected_game = stoi(game);

        if(selected_game == 1){
            RPS rps(selected_lang);
            char cont = rps.play_RPS();
            if(cont == 'm'){
                continue;
            }else if(cont == 'n'){
                break;
            }
        }else if(selected_game == 2){
            NumGuessing ng(selected_lang);
            char cont = ng.play_NG();
            if(cont == 'm'){
                continue;
            }else if(cont == 'n'){
                break;
            }
        }
    }
   
    return 0;
}