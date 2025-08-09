#include "RockPaperScissors.h"

using namespace std;
using RPS = Rock_Paper_Scissors;

map<int, string> RPS::get_hand_map() const{
    if(selected_lang == 1){
        return {{1, "rock"}, {2, "scissors"}, {3, "paper"}};
    }else if(selected_lang == 2){
        return {{1, "ぐー"}, {2, "ちょき"}, {3, "ぱー"}};
    }
    return{};
}

void RPS::play_RPS(){
    if(selected_lang == 1){
        cout<<"Let's play rock paper scissors!"<<endl;
    }else if(selected_lang == 1){
        cout<<"じゃんけんをしましょう!"<<endl;
    }
    //input hand 
    while(true){
        if(selected_lang == 1){
            cout<<"Choose your hand(1:rock 2:scissors 3:paper):"<<endl;
        }else if(selected_lang == 2){
            cout<<"出したい手を数字で入力してね (1:ぐー 2:ちょき 3:ぱー):"<<endl;
        }
        
        getline(cin,input);
        if(input.empty()){
            if(selected_lang == 1){
                cout<<dict.get_value(EMPTY_INPUT,selected_lang)<<endl;
            }else if(selected_lang == 2){
                cout<<dict.get_value(EMPTY_INPUT,selected_lang)<<endl;
            }
        }else if(input != "1" && input != "2" && input != "3"){
            if(selected_lang == 1){
                cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
            }else if(selected_lang == 2){
                cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
            }
        }else{
            break;
        }
    }

    //convert user input string into a number
    int num = stoi(input);
    //allocate number to a string 
    auto player_hand = get_hand_map();
    //find number that matches user input
    auto itr_player = player_hand.find(num);
    player_choice = itr_player->first;
 
    //allocate number pc picked to a string
    auto pc_hand = get_hand_map();
    //find number that matches pc's hand
    int rand_hand = get_RandomHand();
    auto itr_pc = pc_hand.find(rand_hand);
    pc_choice = itr_pc->first;

    if(selected_lang == 1){
        cout<<"Your hand:"<<itr_player->second<<"\n"<<"computer's hand:"<<itr_pc->second<<endl;
    }else if(selected_lang == 2){
        cout<<"あなたの手:"<<itr_player->second<<"\n"<<"コンピューターの手:"<<itr_pc->second<<endl;
    }
    set_Result(player_choice,pc_choice);
}

int RPS::get_RandomHand(){
    //pick random number for cp's hand
    uniform_int_distribution<> dis(1, 3);
    return dis(engine);
}

void RPS::set_Result(const int player_choice, const int cp_choice){
    //check the result of rock paper scizzors
    if(player_choice == cp_choice){
         if(selected_lang == 1){
            cout<<"Draw!"<<endl;
         }else if(selected_lang == 2){
            cout<<"引き分けだね!"<<endl;
         }
    }else if((player_choice == 1 && cp_choice == 2) 
            || (player_choice == 2 && cp_choice == 3)
            || (player_choice == 3 && cp_choice == 1)){
                if(selected_lang == 1){
                    cout<<"You won!"<<endl;
                }else if(selected_lang == 2){
                    cout<<"君の勝ち!"<<endl;
                }        
    }else{
        if(selected_lang == 1){
            cout<<"Computer Won!"<<endl;
        }else if(selected_lang == 2){
            cout<<"コンピューターの勝ち!"<<endl;
        }     
    }
}
