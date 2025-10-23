#ifndef _NUM_GUESSING_H
#define _NUM_GUESSING_H

#include <iostream>
#include "Game.h"
#include "Dictionary.h"
#include "Utility.h"

class NumGuessing : public Game{ 
    public:
        NumGuessing();
        NumGuessing(int lang):Game(lang){}
        ~NumGuessing(){}

        std::string play_NG();
        int get_RandomNum();
        void get_UserGuess(const int& rand_num);
};

#endif //_NUM_GUESSING