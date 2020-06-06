#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "semigraf.h"
using namespace std;

void menu(){
    setcolor(3);
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
    setcolor(15);
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


class board{
    public:
        int DIM=8;
        char mat[8][8];
        //attr
        //metodi
        board();
        void zero();
        void getBoard();
};

board::board(){
}
void board::zero(){
    for(int i=0;i<DIM;i++){
        for(int c=0;c<DIM;c++){
            mat[i][c]=' ';
        }
    }
}
void board::getBoard(){ 
	char a=65;
    setcolor(3);
    gotoxy(10,2); //start abc
    for(int i=0;i<=7;i++){
		cout<<"+-----------";
	}
	cout<<"+";
    gotoxy(10,3);
	for(int i=0;i<=7;i++){
		cout<<"|     ";
		for(int i=0;i<1;i++){
			cout<<a<<"     ";
			a++;
		}
	}
    cout<<"|";
    gotoxy(10,4);
    for(int i=0;i<=7;i++){
		cout<<"+-----------";
    }
	cout<<"+"; //end abc
    int cont=6;
    for(int i=DIM;i>0;i--){ //start num
        gotoxy(0,cont);
        cout<<"+-----+";
        cont++;
        gotoxy(0,cont);
        cout<<"|     |";
        cont++;
        gotoxy(0,cont);
        cout<<"|  "<<i<<"  |";
        cont++;
        gotoxy(0,cont);
        cout<<"|     |";
        cont++;

    }
    gotoxy(0,cont);
    cout<<"+-----+"; //end num
    cont=6;
    setcolor(15);
    for(int i=0;i<DIM;i++){ //start board
        gotoxy(10,cont);
        cout<<"+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+";
		cont++;
        gotoxy(10,cont);
        cout<<"|           |           |           |           |           |           |           |           |";
        cont++;
        gotoxy(10,cont);
        cout<<"|";
        for(int c=0;c<DIM;c++){
			cout<<"     "<<mat[i][c]<<"     |";
		}
        cont++;
        gotoxy(10,cont);
        cout<<"|           |           |           |           |           |           |           |           |";
        cont++;
	}
    gotoxy(10,cont);
	cout<<"+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+"; //end board
    cout<<endl<<endl;
}