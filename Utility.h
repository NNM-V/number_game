#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>
#include <vector>
#include <algorithm>

class Utility{
    public:
    Utility(){}
    ~Utility(){}
    
    std::string check_Valid(const std::vector<std::string>& valid_string);
    int check_Vaild_Num(const std::vector<std::string>& valid_string);
    std::string check_Vaild_String(const std::vector<std::string>& valid_string);
};

#endif //_UTILITY_H