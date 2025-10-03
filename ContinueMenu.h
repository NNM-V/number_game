#ifndef _CONT_MENU_H
#define _CONT_MENU_H

#include <iostream>
#include <limits> 
#include "Dictionary.h"

class Continue_Menu{
    int lang;
    LANGUAGE selected_lang;
    
    public:
    Continue_Menu(int lang):lang(lang){
            selected_lang = (LANGUAGE)lang;
        }

    char cont();
};

#endif //_CONT_MENU_H