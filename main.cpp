//CHESS GAME v0.1 - 02/06/2020
//By Tiz314, Colox343
#include <iostream>
#include "general.h"
#include "board.h"
using namespace std;
int main(){
	char sel;
	bool check=true;
	while(check){
		menu();
		cin>>sel;
		switch(sel){
			case '1':{
				cout<<"You chose to play.";
				enter();
				system("cls");
				//play
				gioc p1,p2;
				string n;
				cout<<"Please, insert player 1 (white) name: ";
				cin>>n;
				p1.insertName(n);
				cout<<"please, insert player 2 (black) name: ";
				cin>>n;
				p2.insertName(n);
				board mat;
				mat.zero();
				mat.start();
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