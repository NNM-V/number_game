#ifndef _ROCK_PAPER_SCISSORS_H
#define _ROCK_PAPER_SCISSORS_H

#include <iostream>
#include <map>
#include "Game.h"
#include "Dictionary.h"
#include "Utility.h"

class Rock_Paper_Scissors : public Game{
    public:
        Rock_Paper_Scissors(){};
        Rock_Paper_Scissors(int lang):Game(lang){}
        ~Rock_Paper_Scissors(){}

        std::map<int, std::string> get_hand_map() const;
        std::string play_RPS(); 
        int get_PlayerHand();
        int get_RandomHand();
        void set_Hand(const int player_choice, const int cp_choice);
        void set_Result(const int player_choice, const int cp_choice);
};

#endif //_ROCK_PAPER_SCISSORS_H