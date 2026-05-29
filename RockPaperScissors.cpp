#include "RockPaperScissors.h"
using namespace std;
using RPS = RockPaperScissors;

string RPS::play_rps(){
    while(true){
        switch(selected_lang)
        {
            case ENGLISH:
                cout<<"Let's play rock paper scissors!"<<endl;
                break;
            case JAPANESE:
                cout<<"じゃんけんをしましょう!"<<endl;
                break;
            default:
                break;
        }

        //get user input
        int player_hand = get_player_hand();
        //get random number from pc
        int pc_hand = get_random_hand();
        //output player and pc hand
        allocate_hand(player_hand,pc_hand);
        //output result
        show_result(player_hand,pc_hand);
        //ask user for replay
        cout<<dict.get_value(REPLAY,selected_lang)<<endl;
        string tmp = utility.check_valid_string({"y","n","m"});
        if(tmp == "m" || tmp == "n"){
            return tmp;
        } 
    }
}

int RPS::get_player_hand(){
    //input hand
    switch(selected_lang)
    {
        case ENGLISH:
            cout<<"Choose your hand(1:rock 2:scissors 3:paper):"<<endl;
            break;
        case JAPANESE:
            cout<<"出したい手を数字で入力してね (1:ぐー 2:ちょき 3:ぱー):"<<endl;
            break;
        default:
            break;
    }
    //check vailidity
    int hand = utility.check_valid_num({"1","2","3"});
    return hand;    
}

int RPS::get_random_hand(){
    return set_random_num(1,3);
}

map<int, string> RPS::get_handmap() const{
    switch(selected_lang)
    {
        case ENGLISH:
            return {{1, "rock"}, {2, "scissors"}, {3, "paper"}};
        case JAPANESE:
            return {{1, "ぐー"}, {2, "ちょき"}, {3, "ぱー"}};
        default:
            return{};
    }
}

void RPS::allocate_hand(const int player_hand, const int pc_hand){
    //allocate number to a string 
    auto hand_map = get_handmap();
    //find number that matches the user input
    auto itr_player = hand_map.find(player_hand);
    //find number that matches the pc hand
    auto itr_pc = hand_map.find(pc_hand);
    switch(selected_lang)
    {
        case ENGLISH:
            cout<<"Your hand:"<<itr_player->second<<"\n"<<"computer's hand:"<<itr_pc->second<<endl;
            break;
        case JAPANESE:
            cout<<"あなたの手:"<<itr_player->second<<"\n"<<"コンピューターの手:"<<itr_pc->second<<endl;
            break;
        default:
            break;
    }
}

void RPS::show_result(const int player_choice, const int cp_choice){
    //judge the game
    int judge = ((player_choice - cp_choice) + 3) % 3;
    //check the result of rock paper scissors
    switch (judge)
    {
        case 0:
            switch(selected_lang)
            {
                case ENGLISH:
                    cout<<"Draw!"<<endl;
                    break;
                case JAPANESE:
                    cout<<"引き分けだね!"<<endl;
                    break;
                default:
                    break;
            }    
            break;
        case 1:
            switch(selected_lang)
            {
                case ENGLISH:
                    cout<<"Computer Won!"<<endl;
                    break;
                case JAPANESE:
                    cout<<"コンピューターの勝ち!"<<endl;
                    break;
                default:
                    break;
            }    
            break;
        case 2:
            switch(selected_lang)
            {
                case ENGLISH:
                    cout<<"You won!"<<endl;
                    break;
                case JAPANESE:
                    cout<<"君の勝ち!"<<endl;
                    break;
                default:
                    break;
            }     
            break;
        default:
            break;
    }
}
