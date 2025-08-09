#ifndef _ROCK_PAPER_SCISSORS_H
#define _ROCK_PAPER_SCISSORS_H

#include <iostream>
#include <array>
#include <random>
#include <map>
#include "Dictionary.h"

class Rock_Paper_Scissors{
    int lang;
    LANGUAGE selected_lang;
    std::string input; 
    std::mt19937_64 engine;
    int player_choice;
    int pc_choice;

    public:
        Rock_Paper_Scissors();
        Rock_Paper_Scissors(int lang):lang(lang){
            selected_lang = (LANGUAGE)lang;
            std::random_device seed_gen;
            engine = std::mt19937_64(seed_gen());
        }
        ~Rock_Paper_Scissors(){}

        std::map<int, std::string> get_hand_map() const;
        void play_RPS(); 
        int get_RandomHand();
        void set_Result(const int player_choice, const int cp_choice);
};

#endif //_ROCK_PAPER_SCISSORS_H