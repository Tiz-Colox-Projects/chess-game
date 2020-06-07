//CHESS GAME v0.1 - 02/06/2020
//By Tiz314, Colox343
#include <iostream>
#include "general.h"
#include "board.h"
using namespace std;
int main(){
	char sel;   //menu selection
	bool check=true;  //bool value for the while
	while(check){
		menu();  //menu
		cin>>sel;   //selection input
		switch(sel){
			case '1':{
				cout<<"You chose to play.";   //first case 
				enter();
				system("cls");
				//play
				gioc p1,p2;   //declaration of 2 names (objects)
				string n;
				cout<<"Please, insert player 1 (white) name: ";
				cin>>n;
				p1.insertName(n);   //name input
				cout<<"please, insert player 2 (black) name: ";
				cin>>n;
				p2.insertName(n);
				board mat;  //declaration of the board
				mat.zero(); 
				mat.start();   //filling the board with different pieces
				mat.getBoard();
				enter();
				break;
			}
			case '2':{
				//about
				about();
				break;
			}
			case '3':{
				//exit
				cout<<"You're going to exit the game."<<endl;
				enter();
				check=false;
				break;
			}
			default:{
				cout<<"Invalid option."<<endl;
				enter();
				break;
			}
		}
	}
	return 0;
}