#ifndef _NUM_GUESSING_H
#define _NUM_GUESSING_H

#include <iostream>
#include "Game.h"
#include "Dictionary.h"
#include "Utility.h"

class NumGuessing : public Game{
        Utility utility;
    public:
        NumGuessing();
        NumGuessing(int lang):Game(lang){};
        ~NumGuessing(){};

        std::string play_number_game();
        int get_random_num();
        void get_user_guess(const int& rand_num);
};

#endif //_NUM_GUESSING