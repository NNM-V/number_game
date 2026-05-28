#include "RockPaperScissors.h"
using namespace std;
using RPS = Rock_Paper_Scissors;

string RPS::play_RPS(){
    while(true){
        if(selected_lang == 1){
            cout<<"Let's play rock paper scissors!"<<endl;
        }else if(selected_lang == 2){
            cout<<"じゃんけんをしましょう!"<<endl;
        }
        
        //get user input
        int player_hand = get_PlayerHand();
        //get random number from pc
        int pc_hand = get_RandomHand();
        //output player and pc hand
        set_Hand(player_hand,pc_hand);
        //output result
        set_Result(player_hand,pc_hand);

        cout<<dict.get_value(REPLAY,selected_lang)<<endl;
        Utility utility;
        string tmp = utility.check_Vaild_String({"y","n","m"});
        if(tmp == "m" || tmp == "n"){
            return tmp;
        } 
    }
}

int RPS::get_PlayerHand(){
    //input hand 
    if(selected_lang == 1){
        cout<<"Choose your hand(1:rock 2:scissors 3:paper):"<<endl;
    }else if(selected_lang == 2){
        cout<<"出したい手を数字で入力してね (1:ぐー 2:ちょき 3:ぱー):"<<endl;
    }
    
    Utility utility;
    int hand = utility.check_Vaild_Num({"1","2","3"});
    return hand;
    
}

int RPS::get_RandomHand(){
    return set_RandomNum(1,3);
}

map<int, string> RPS::get_hand_map() const{
    if(selected_lang == 1){
        return {{1, "rock"}, {2, "scissors"}, {3, "paper"}};
    }else if(selected_lang == 2){
        return {{1, "ぐー"}, {2, "ちょき"}, {3, "ぱー"}};
    }
    return{};
}

void RPS::set_Hand(const int player_hand, const int pc_hand){
    //allocate number to a string 
    auto hand_map = get_hand_map();
    //find number that matches the user input
    auto itr_player = hand_map.find(player_hand);
    //find number that matches the pc hand
    auto itr_pc = hand_map.find(pc_hand);

    if(selected_lang == 1){
        cout<<"Your hand:"<<itr_player->second<<"\n"<<"computer's hand:"<<itr_pc->second<<endl;
    }else if(selected_lang == 2){
        cout<<"あなたの手:"<<itr_player->second<<"\n"<<"コンピューターの手:"<<itr_pc->second<<endl;
    }
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
