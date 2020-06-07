#include <iostream>
#include "semigraf.h"
#include "pieceData.h"
using namespace std;

class board{
    public:
        //attr
        int DIM=8;
        int mat[8][8];      /*Matrix for indication of the pieces on the board

                            The white pieces are indicated with
                            1=pawns
                            2=rooks
                            3=knights
                            4=bishops
                            5=queen
                            6=king

                            The black pieces are indicated with
                            7=pawns
                            8=rooks
                            9=knights
                            10=bishops
                            11=queen
                            12=king*/
        pieceData pieces[32];        //Objects which represent every piece on the board
        //methods
        board();
        void zero();
        void getBoard();
        void start();                               //It generates the initial arrangement on the board
        bool selectionControl(int row, int col, int player);      //It verifies that the piece selection is valid
};

board::board(){ //constructor for board class
}

void board::zero(){      //formatting board content
    for(int i=0;i<DIM;i++){
        for(int c=0;c<DIM;c++){
            mat[i][c]=0;
        }
    }
}

void board::getBoard(){    //print of the board
	char a=65;
    setcolor(3);
    gotoxy(10,2); //start abc print
    for(int i=0;i<=7;i++){
		cout<<"+===========";
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
		cout<<"+===========";
    }
	cout<<"+"; //end abc
    int cont=6;
    for(int i=DIM;i>0;i--){ //start num print
        gotoxy(0,cont);
        cout<<"+=====+";
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
    cout<<"+=====+"; //end num
    cont=6;
    setcolor(7);
    for(int i=0;i<DIM;i++){ //start board print
        gotoxy(10,cont);
        cout<<"+===========+===========+===========+===========+===========+===========+===========+===========+";
		cont++;
        gotoxy(10,cont);
        cout<<"|           |           |           |           |           |           |           |           |";
        cont++;
        gotoxy(10,cont);
        cout<<"|";
        for(int c=0;c<DIM;c++){
            cout<<"     ";
            switch(mat[i][c]){
                case 1:{
                    cout<<"P";    //switch for print in each part of the board. the letter depends on the number in the board
                    break;
                }
                case 2:{
                    cout<<"R";
                    break;
                }
                case 3:{
                    cout<<"N";
                    break;
                }
                case 4:{
                    cout<<"B";
                    break;
                }
                case 5:{
                    cout<<"Q";
                    break;
                }
                case 6:{
                    cout<<"K";
                    break;
                }
                case 7:{
                    setcolor(8);
                    cout<<"P";
                    setcolor(7);
                    break;
                }
                case 8:{
                    setcolor(8);
                    cout<<"R";
                    setcolor(7);
                    break;
                }
                case 9:{
                    setcolor(8);
                    cout<<"N";
                    setcolor(7);
                    break;
                }
                case 10:{
                    setcolor(8);
                    cout<<"B";
                    setcolor(7);
                    break;
                }
                case 11:{
                    setcolor(8);
                    cout<<"Q";
                    setcolor(7);
                    break;
                }
                case 12:{
                    setcolor(8);
                    cout<<"K";
                    setcolor(7);
                    break;
                }
                default:{
                    cout<<" ";
                    break;
                }
                
            }
            cout<<"     |";
        }
        cont++;
        gotoxy(10,cont);
        cout<<"|           |           |           |           |           |           |           |           |";
        cont++;
	}
    setcolor(7);
    gotoxy(10,cont);
	cout<<"+===========+===========+===========+===========+===========+===========+===========+===========+"; //end board
    cout<<endl<<endl;
    setcolor(15);
}

//----------------------//

void board::start(){
    int c=0;                                    //Counter variable
    for(int i=7; i>=0; i--){                    //Cycle to select the row
        for(int j=0; j<8; j++){                 //Cycle to select the column
            switch(i){
                case 0:{                        //Case of the highest row, the black one
                    if(j<=4) mat[i][j]=8+j;
                    else mat[i][j]=15-j;
                    break;
                }
                case 1:{                        //Case of the row of the black pawns
                    mat[i][j]=7;
                    break;
                }
                case 6:{                        //Case of the row of the white pawns
                    mat[i][j]=1;
                    break;
                }
                case 7:{                        //Case of the lowest row, the white one
                    if(j<=4) mat[i][j]=2+j;
                    else mat[i][j]=9-j;
                    break;
                }
                default:{                       //Case of the central rows, the empty ones
                    mat[i][j]=0;
                }
            }
            if(mat[i][j]!=0){                 /*If the box id filled the piece is memorized in the array 
                                                with the pieces on the board*/
                pieces[c].type=mat[i][j];      //Memorise of the type
                pieces[c].row=i;               //Memorise of the row
                pieces[c].col=j;               //Memorise of the column
                c++;                           //Increase of the counter variable
            }
        }
    }
}

bool board::selectionControl(int row, int col, int player){
    if(mat[row][col]==0) return false;       //If the box is empty the selction is invalid
    else{
        if(player==1 && mat[row][col]>6) return false;   /*If it's the turn of the player 1 (white) and the selection
                                                        value is higher than 6 (it's a black piece) it's invalid*/
        else if(player==2 && mat[row][col]<7) return false; /*If it's the turn of the player 2 (black) and the selection
                                                            value is lower than 6 (it's a white piece) it's invalid*/
        else return true;           /*If no condition is respected the player has selcted one of it's pieces and the
                                    selection is valid*/
    }
}
