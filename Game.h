#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <array>
#include <random>
#include "Dictionary.h"

class Game{
    private:
        int lang;
        std::random_device seed_gen;
        std::mt19937_64 engine;
    protected:
        LANGUAGE selected_lang;
        int set_random_num(int min, int max){
            //pick random number for cp's hand
            std::uniform_int_distribution<> dis(min, max);
            return dis(engine);
        }
    public:
        Game(){};
        Game(int lang)
            :lang(lang),
            selected_lang(static_cast<LANGUAGE>(lang)),
            engine(seed_gen()){}
        virtual ~Game(){}
};

#endif //_GAME_H