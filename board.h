#include <iostream>
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
    //start abc print
    cout<<"         ";
    for(int i=0;i<=7;i++){
		cout<<"+===========";
	}
	cout<<"+"<<endl;
    cout<<"         ";
	for(int i=0;i<=7;i++){
		cout<<"|     ";
		for(int i=0;i<1;i++){
			cout<<a<<"     ";
			a++;
		}
	}
    cout<<"|";
    cout<<endl<<"         ";
    for(int i=0;i<=7;i++){
		cout<<"+===========";
    }
    cout<<"+";
    cout<<endl;
	//end abc
    int f=8;
    for(int i=0;i<DIM;i++){ //start num print and board
        cout<<"+=====+  +===========+===========+===========+===========+===========+===========+===========+===========+"<<endl;
        cout<<"|     |  |           |           |           |           |           |           |           |           |"<<endl;
        cout<<"|  "<<f<<"  |  |";
        f--;
        for(int c=0;c<DIM;c++){
            cout<<"     ";
            switch(mat[i][c]){
                case 1:{
                    cout<<"\x1b[37;40mP\x1b[32;40m";    //switch for print in each part of the board. the letter depends on the number in the board
                    break;
                }
                case 2:{
                    cout<<"\x1b[37;40mR\x1b[32;40m";
                    break;
                }
                case 3:{
                    cout<<"\x1b[37;40mN\x1b[32;40m";
                    break;
                }
                case 4:{
                    cout<<"\x1b[37;40mB\x1b[32;40m";
                    break;
                }
                case 5:{
                    cout<<"\x1b[37;40mQ\x1b[32;40m";
                    break;
                }
                case 6:{
                    cout<<"\x1b[37;40mK\x1b[32;40m";
                    break;
                }
                case 7:{
                    cout<<"\x1b[30;33mP\x1b[32;40m";
                    break;
                }
                case 8:{
                    cout<<"\x1b[30;33mR\x1b[32;40m";
                    break;
                }
                case 9:{
                    cout<<"\x1b[30;33mN\x1b[32;40m";
                
                    break;
                }
                case 10:{
                    cout<<"\x1b[30;33mB\x1b[32;40m";
                
                    break;
                }
                case 11:{
                    cout<<"\x1b[30;33mQ\x1b[32;40m";
                
                    break;
                }
                case 12:{
                    cout<<"\x1b[30;33mK\x1b[32;40m";
                
                    break;
                }
                default:{
                    cout<<" ";
                    break;
                }
                
            }
            cout<<"     |";
        }
        cout<<"\x1b[32;40m";
        cout<<endl;
        cout<<"|     |  |           |           |           |           |           |           |           |           |"<<endl;

    }
    cout<<"+=====+"; //end num and board
	cout<<"  +===========+===========+===========+===========+===========+===========+===========+===========+"; //end board
    cout<<endl<<endl;
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
