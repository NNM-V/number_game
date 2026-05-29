#ifndef _CONT_MENU_H
#define _CONT_MENU_H

#include <iostream>
#include <limits> 
#include "Dictionary.h"

enum class Replay_Action{
    Replay,
    Menu,
    Exit
};

class Continue_Menu{
    int lang;
    LANGUAGE selected_lang;
    
    public:
    Continue_Menu(int lang):lang(lang){
            selected_lang = (LANGUAGE)lang;
        }

    char cont();

    Replay_Action get_replay_action(const std::string& input);
};

#endif //_CONT_MENU_H