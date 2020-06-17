#include <iostream>
#include <iomanip>
using namespace std;

void menu(){
    system("cls");
    cout<<" \x1b[32m       CCCCCCCCCCCCChhhhhhh                                                                   "<<endl;   //initial menu function
    cout<<"     CCC::::::::::::Ch:::::h                                                                   "<<endl;
    cout<<"   CC:::::::::::::::Ch:::::h                                                                   "<<endl;
    cout<<"  C:::::CCCCCCCC::::Ch:::::h                                                                   "<<endl;
    cout<<" C:::::C       CCCCCC h::::h hhhhh           eeeeeeeeeeee        ssssssssss       ssssssssss   "<<endl;
    cout<<"C:::::C               h::::hh:::::hhh      ee::::::::::::ee    ss::::::::::s    ss::::::::::s"<<endl;
    cout<<"C:::::C               h::::::::::::::hh   e::::::eeeee:::::eess:::::::::::::s ss:::::::::::::s "<<endl;
    cout<<"C:::::C               h:::::::hhh::::::h e::::::e     e:::::es::::::ssss:::::ss::::::ssss:::::s"<<endl;
    cout<<"C:::::C               h::::::h   h::::::he:::::::eeeee::::::e s:::::s  ssssss  s:::::s  ssssss "<<endl;
    cout<<"C:::::C               h:::::h     h:::::he:::::::::::::::::e    s::::::s         s::::::s      "<<endl;
    cout<<"C:::::C               h:::::h     h:::::he::::::eeeeeeeeeee        s::::::s         s::::::s   "<<endl;
    cout<<" C:::::C       CCCCCC h:::::h     h:::::he:::::::e           ssssss   s:::::s ssssss   s:::::s "<<endl;
    cout<<"  C:::::CCCCCCCC::::C h:::::h     h:::::he::::::::e          s:::::ssss::::::ss:::::ssss::::::s"<<endl;
    cout<<"   CC:::::::::::::::C h:::::h     h:::::h e::::::::eeeeeeee  s::::::::::::::s s::::::::::::::s "<<endl;
    cout<<"     CCC::::::::::::C h:::::h     h:::::h  ee:::::::::::::e   s:::::::::::ss   s:::::::::::ss  "<<endl;
    cout<<"        CCCCCCCCCCCCC hhhhhhh     hhhhhhh    eeeeeeeeeeeeee    sssssssssss      sssssssssss    "<<endl<<endl;
    cout<<"Welcome to Chess! Please, select an option: "<<endl;
    cout<<"1- Play \n2- About \n3- Exit"<<endl;
}

void enter(){
    //cout<<endl<<"Press ENTER to continue"<<endl;   //press enter to continue function
    
    cout<<endl;
    system("pause"); // or system pause
}

void about(){
    system("cls"); //or system clear
    cout<<"Chess game v0.1"<<endl;   //about print
    cout<<"Made by Tiz314, Colox343"<<endl;
    cout<<"Source code vailable on GitHub: https://github.com/Tiz314/Chess"<<endl;
    enter();
}

class gioc{
    public:
        string name;   //gioc function for assign names to the players
        
        gioc();
        void insertName(string n);
        string getName(); 
};

gioc::gioc(){  //constructor for the gioc class
} 
void gioc::insertName(string n){   //name assignment
    name=n;
}
string gioc::getName(){ //print the name
    return name;
}