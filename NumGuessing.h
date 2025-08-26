#ifndef _NUM_GUESSING_H
#define _NUM_GUESSING_H

#define _ROCK_PAPER_SCISSORS_H

#include <iostream>
#include <random>
#include "Dictionary.h"

class NumGuessing{
    int lang;
    LANGUAGE selected_lang;
    std::string input;  
    std::mt19937_64 engine;

    public:
        NumGuessing();
        NumGuessing(int lang):lang(lang){
            selected_lang = (LANGUAGE)lang;
            //pick random number number in a range of 1-100
            std::random_device seed_gen;
            engine = std::mt19937_64(seed_gen());
        }
        ~NumGuessing(){}

        void play_NG();
        int get_RandomNum();
};

#endif //_NUM_GUESSING