#include <iostream>
#include "Dictionary.h"
#include "RockPaperScissors.h"
#include "NumGuessing.h"

using namespace std;
using RPS = Rock_Paper_Scissors;

int main(){
    cout<<"Number game"<<endl;
    string lang;
    
    while(true){
        cout<<"Choose language/言語を選択してください (1:English 2:日本語):"<<endl;
        getline(cin,lang);
        if(lang.empty()){
            cout<<"Select input/空の入力です"<<endl;
        }else if(lang != "1" && lang != "2"){
            cout<<"Unexpected input/無効な入力です"<<endl;
        }else{
            break;
        }
    }

    int tmp = stoi(lang);
    LANGUAGE selected_lang;
    selected_lang = static_cast<LANGUAGE>(tmp);

    string game;

    if(selected_lang == 1){
        cout<<"English Selected"<<endl;
    }else if(selected_lang == 2){
        cout<<"日本語が選択されました"<<endl;
    }

    while(true){
        if(selected_lang == 1){
            cout<<"Choose game to play (1:Rock Paper Scissors 2:NumberGuessing):"<<endl;
        }else if(selected_lang == 2){
            cout<<"遊びたいゲームを入力してください(1:じゃんけん 2:数当てゲーム)"<<endl;
        }
        getline(cin,game);
        if(game.empty()){
            cout<<dict.get_value(EMPTY_INPUT,selected_lang)<<endl;
        }else if(game != "1" && game != "2"){
            cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
        }else{
            break;
        }
    }

    int selected_game = stoi(game);

    if(selected_game == 1){
        RPS rps(selected_lang);
        rps.play_RPS();
    }else if(selected_game == 2){
        NumGuessing ng(selected_lang);
        ng.play_NG();
    }
    return 0;
}