
#include "ContinueMenu.h"
#include "Dictionary.h"

using namespace std;

char Continue_Menu::cont(){
    //continue while user input is "y"
    char cont;
    
    cout<<dict.get_value(REPLAY,selected_lang)<<endl;

    cin>>cont;
    //change user input to lower cases
    cont = tolower(cont);

    while(cont!='y' && cont!='n' && cont!='m'){
        //cout<<dict.get_value(INVALID_INPUT,selected_lang)<<endl;
        cout<<dict.get_value(REPLAY,selected_lang)<<endl;

        //clear previous input 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //user input
        cin >> cont;
        cont = tolower(cont);
    }  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

    return cont;
}

Replay_Action get_replay_action(const string& input){
    if(input == "m"){
        return Replay_Action::Menu;
    }
    if(input == "n"){
        return Replay_Action::Exit;
    }
    return Replay_Action::Replay;
}