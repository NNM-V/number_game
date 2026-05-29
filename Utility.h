#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Dictionary.h"

class Utility{
    LANGUAGE selected_lang;
    public:
    Utility(){};
    ~Utility(){};
    
    std::string check_valid(const std::vector<std::string>& valid_string);
    int check_valid_num(const std::vector<std::string>& valid_string);
    std::string check_valid_string(const std::vector<std::string>& valid_string);
};

#endif //_UTILITY_H