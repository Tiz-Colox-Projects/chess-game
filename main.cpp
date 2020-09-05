//CHESS GAME v0.1 - 02/06/2020
//By Tiz314, Colox343
#include <iostream>
#include "general.h"
#include "board.h" 
using namespace std;
int main(){
	bool game=true; //bool for check the game
	char sel;   //menu selection
	bool check=true;  //bool value for the while
	bool underCheck=false;
	while(check){
		menu();  
		game=true;
		cin>>sel;   //selection input
		switch(sel){
			case '1':{
				cout<<"You chose to play.";   //first case 
				enter();
				system("cls");  //or system("cls")
				//play
				gioc p1,p2;   //declaration of 2 names (objects)
				string n;
				cout<<"Please, insert player 1 (white) name: ";
				cin>>n;
				p1.insertName(n);   //name input
				cout<<"please, insert player 2 (black) name: ";
				cin>>n;
				p2.insertName(n);
				system("cls");
				board mat;  //declaration of the board
				mat.zero(); 
				mat.start();   //filling the board with different pieces
				mat.getBoard();
				int turn=1; //defining turn of each player
				string name;
				bool firstMove=true;
				while(game){
					if(turn%2!=0) name=p1.name;
					else name=p2.name;
					cout<<name<<", Insert your move using the following structure (a to b): ";
					if(turn==1 && firstMove) getline(cin,mat.move);  //double input just for the first time (one input won't work :/ )
					getline(cin,mat.move);
					if(mat.checkMove(mat.move,turn,underCheck)){  //----------sintax and logical check----------
						mat.changePos(mat.move);
						system("cls");
						mat.getBoard();
						/*cout<<endl<<endl;
						getPieces(mat.pieces);
						cout<<endl<<endl;*/
						if(turn%2!=0) underCheckCheck(p2.name,p1.name,mat,27,turn,game,underCheck); //under check/checkmate check
						else underCheckCheck(p1.name,p2.name,mat,3,turn,game,underCheck);
						turn++;
					}else{
						cout<<"Invalid option."<<endl;
						firstMove=false;
					}
				//insert winner name and call function
				}
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