
#include "ContinueMenu.h"
#include "Dictionary.h"


using namespace std;

char Continue_Menu::cont(){
    //continue while user input is "y"
    char cont='y';
    
    if(selected_lang == 1){
        cout<<"Do you want to play again?"<<endl;
    }else if(selected_lang == 2){
        cout<<"もう一度遊ぶ？"<<endl;
    } 

    cin>>cont;
    //change user input to lower cases
    cont = tolower(cont);
    cout<<cont<<endl;
     
    while(cont!='y' && cont!='n'){
        cout << "You may only type 'y' or 'n'.\n";
        cout << "Do you want to play again?(y/n):" << endl;
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