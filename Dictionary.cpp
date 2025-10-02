#include "Dictionary.h"

using namespace std;

DICTIONARY::DICTIONARY(std::initializer_list<DICTIONARY_BLOCK_t> var){
    for(DICTIONARY_BLOCK_t val : var){
        data.push_back(val);
    }
}

string DICTIONARY::get_value(MESSAGE_KEY key,LANGUAGE lang){
    string str;
    for(auto d : data){
        if(d.key == key){
            for(auto v : d.values){
                if(v.lang == lang){
                    str = v.text;
                    break;
                }else{
                    str = "Message not found";
                }
            }
            break;
        }
    }
    return str;
}

DICTIONARY dict = 
{
    {EMPTY_INPUT,{{ENGLISH,"Select input"},
    {JAPANESE,"空の入力です"}}},
    {INVALID_INPUT,{{ENGLISH,"Unvalid input"},
    {JAPANESE,"無効な入力です"}}},
    {REPLAY,{{ENGLISH,"Do you want to play again?('y'=yes/'n'=no/'m'=menu):"},
    {JAPANESE,"もう一度遊ぶ？('y'=yes/'n'=no/'m'=menu):"}}},
};