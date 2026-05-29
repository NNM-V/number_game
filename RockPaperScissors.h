#ifndef _ROCK_PAPER_SCISSORS_H
#define _ROCK_PAPER_SCISSORS_H

#include <iostream>
#include <map>
#include "Game.h"
#include "Dictionary.h"
#include "Utility.h"

class RockPaperScissors : public Game{
        Utility utility;
    public:
        RockPaperScissors(){};
        RockPaperScissors(int lang):Game(lang){};
        ~RockPaperScissors(){};

        std::map<int, std::string> get_handmap() const;
        std::string play_rps(); 
        int get_player_hand();
        int get_random_hand();
        void allocate_hand(const int player_choice, const int cp_choice);
        void show_result(const int player_choice, const int cp_choice);
};

#endif //_ROCK_PAPER_SCISSORS_H