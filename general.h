#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void menu(){
    system("cls");
    cout<<"=========================="<<endl;
    Sleep(200);
    cout<<" __        ___  __   __  "<<endl;
    Sleep(200);
    cout<<"|  ` |__| |__  |__` |__` "<<endl;
    Sleep(200);
    cout<<"|__, |  | |___ .__| .__| "<<endl<<endl;
    Sleep(200);
    cout<<"=========================="<<endl<<endl;
    Sleep(200);
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