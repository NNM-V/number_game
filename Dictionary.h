#ifndef _DICTIONARY_H
#define _DICTIONARY_H
#include <iostream>
#include <initializer_list>
#include <vector>

enum MESSAGE_KEY{
    EMPTY_INPUT,
    INVALID_INPUT,
};

enum LANGUAGE{
    ENGLISH = 1,
    JAPANESE = 2
};

struct DICTIONARY_VAL{
    LANGUAGE lang;
    std::string text; 
};

struct DICTIONARY_BLOCK_t{
    MESSAGE_KEY key;
    std::vector<DICTIONARY_VAL> values;
};

class DICTIONARY{
    private:
    std::vector<DICTIONARY_BLOCK_t> data;
    public:
    DICTIONARY(std::initializer_list<DICTIONARY_BLOCK_t> var);
    std::string get_value(MESSAGE_KEY key,LANGUAGE lang);
};

extern DICTIONARY dict;

#endif //_LANGUAGE_H