#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void menu(){
    system("cls");
    cout<<"        CCCCCCCCCCCCChhhhhhh                                                                   "<<endl;
    Sleep(100);
    cout<<"     CCC::::::::::::Ch:::::h                                                                   "<<endl;
    Sleep(100);
    cout<<"   CC:::::::::::::::Ch:::::h                                                                   "<<endl;
    Sleep(100);
    cout<<"  C:::::CCCCCCCC::::Ch:::::h                                                                   "<<endl;
    Sleep(100);
    cout<<" C:::::C       CCCCCC h::::h hhhhh           eeeeeeeeeeee        ssssssssss       ssssssssss   "<<endl;
    Sleep(100);
    cout<<"C:::::C               h::::hh:::::hhh      ee::::::::::::ee    ss::::::::::s    ss::::::::::s"<<endl;
    Sleep(100);
    cout<<"C:::::C               h::::::::::::::hh   e::::::eeeee:::::eess:::::::::::::s ss:::::::::::::s "<<endl;
    Sleep(100);
    cout<<"C:::::C               h:::::::hhh::::::h e::::::e     e:::::es::::::ssss:::::ss::::::ssss:::::s"<<endl;
    Sleep(100);
    cout<<"C:::::C               h::::::h   h::::::he:::::::eeeee::::::e s:::::s  ssssss  s:::::s  ssssss "<<endl;
    Sleep(100);
    cout<<"C:::::C               h:::::h     h:::::he:::::::::::::::::e    s::::::s         s::::::s      "<<endl;
    Sleep(100);
    cout<<"C:::::C               h:::::h     h:::::he::::::eeeeeeeeeee        s::::::s         s::::::s   "<<endl;
    Sleep(100);
    cout<<" C:::::C       CCCCCC h:::::h     h:::::he:::::::e           ssssss   s:::::s ssssss   s:::::s "<<endl;
    Sleep(100);
    cout<<"  C:::::CCCCCCCC::::C h:::::h     h:::::he::::::::e          s:::::ssss::::::ss:::::ssss::::::s"<<endl;
    Sleep(100);
    cout<<"   CC:::::::::::::::C h:::::h     h:::::h e::::::::eeeeeeee  s::::::::::::::s s::::::::::::::s "<<endl;
    Sleep(100);
    cout<<"     CCC::::::::::::C h:::::h     h:::::h  ee:::::::::::::e   s:::::::::::ss   s:::::::::::ss  "<<endl;
    Sleep(100);
    cout<<"        CCCCCCCCCCCCC hhhhhhh     hhhhhhh    eeeeeeeeeeeeee    sssssssssss      sssssssssss    "<<endl<<endl;
    cout<<"Welcome to Chess! Please, select an option: "<<endl;
    cout<<"1- Play \n2- About \n3- Exit"<<endl;
}

void enter(){
    cout<<endl<<"Press ENTER to continue"<<endl;
    getch();
}

void about(){
    system("cls");
    cout<<"Chess game v0.1"<<endl;
    cout<<"Made by Tiz314, Colox343"<<endl;
    cout<<"Source code vailable on GitHub: https://github.com/Tiz314/Chess"<<endl;
    enter();
}

class gioc{
    public:
        string name;
        
        gioc();
        void insertName(string n);
        string getName(); 
};

gioc::gioc(){
}
void gioc::insertName(string n){
    name=n;
}
string gioc::getName(){
    return name;
}
