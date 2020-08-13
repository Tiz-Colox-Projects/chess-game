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
        bool WKMove;        //Variable of the white king movement
        bool WR1Move;       //Variable of the white rook on the left movement
        bool WR2Move;       //Variable of the white rook on the right movemenent
        bool BKMove;        //Variable of the black king movement
        bool BR1Move;       //Variable of the black rook on the left movement
        bool BR2Move;       //Variable of the black rook on the right movemenent
        pieceData pieces[32];        //Objects which represent every piece on the board
        string move;
        //methods
        board();
        void zero();
        void getBoard();
        void start();                               //It generates the initial arrangement on the board
        bool checkMove(string move,int turn,bool underCheck); //sintax and logic input control
        void changePos(string move);
        int convertNum(char n); //transforming input in table positions
        int convertLett(char n);
        void getPieces(pieceData pieces[]);
        int check4check(pieceData pieces[],int gioc,int turn);
        void checkPt2(string name1, string name2, board mat,int gioc,int turn,bool &check,bool &underCheck);
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
        cout<<"|     |  |           |           |           |           |           |           |           |           |"<<endl;
        cout<<"|  "<<f<<"  |  |";
        f--;
        for(int c=0;c<DIM;c++){
            cout<<"     ";
            switch(mat[i][c]){
                case 1:{
                    cout<<"\x1b[37mP\x1b[32m";    //switch for print in each part of the board. the letter depends on the number in the board
                    break;
                }
                case 2:{
                    cout<<"\x1b[37mR\x1b[32m";
                    break;
                }
                case 3:{
                    cout<<"\x1b[37mN\x1b[32m";
                    break;
                }
                case 4:{
                    cout<<"\x1b[37mB\x1b[32m";
                    break;
                }
                case 5:{
                    cout<<"\x1b[37mQ\x1b[32m";
                    break;
                }
                case 6:{
                    cout<<"\x1b[37mK\x1b[32m";
                    break;
                }
                case 7:{
                    cout<<"\x1b[30;33mP\x1b[32m";
                    break;
                }
                case 8:{
                    cout<<"\x1b[30;33mR\x1b[32m";
                    break;
                }
                case 9:{
                    cout<<"\x1b[30;33mN\x1b[32m";
                
                    break;
                }
                case 10:{
                    cout<<"\x1b[30;33mB\x1b[32m";
                
                    break;
                }
                case 11:{
                    cout<<"\x1b[30;33mQ\x1b[32m";
                
                    break;
                }
                case 12:{
                    cout<<"\x1b[30;33mK\x1b[32m";
                
                    break;
                }
                default:{
                    cout<<" ";
                    break;
                }
                
            }
            cout<<"     |";
        }
        cout<<"\x1b[32m";
        cout<<endl;
        cout<<"|     |  |           |           |           |           |           |           |           |           |"<<endl;
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
    WKMove=false;
    WR1Move=false;
    WR2Move=false;
    BKMove=false;
    BR1Move=false;
    BR2Move=false;
}
int board::convertNum(char n){
    switch(n){
        case '1':{
            return 1;
        }
        case '2':{
            return 2;
        }
        case '3':{
            return 3;
        }
        case '4':{
            return 4;
        }
        case '5':{
            return 5;
        }
        case '6':{
            return 6;
        }
        case '7':{
            return 7;
        }
        case '8':{
            return 8;
        }
        default:{
            return -1;
        }
    }
}
int board::convertLett(char n){
    switch(n){
        case 'a':{
            return 0;
        }
        case 'b':{
            return 1;
        }
        case 'c':{
            return 2;
        }
        case 'd':{
            return 3;
        }
        case 'e':{
            return 4;
        }
        case 'f':{
            return 5;
        }
        case 'g':{
            return 6;
        }
        case 'h':{
            return 7;
        }
        default:{
            return -1;
        }
    }
}
bool board::checkMove(string move,int turn,bool underCheck){  //sintax input and logic check
    int kingPos;
    if(turn%2!=0) kingPos=28;
    else kingPos=4;
    //string made of 8 characters
    if(move.length() != 8){   //check for the length and the input structure
        return false;
    }
    int startx,starty,endx,endy;
    startx=convertLett(move[0]);
    starty=convertNum(move[1]);
    endx=convertLett(move[6]);
    endy=convertNum(move[7]);
    starty=8-starty;
    endy=8-endy;
    if(turn%2!=0 && mat[starty][startx]>6) return false;
    else if(turn%2==0 && mat[starty][startx]<7) return false;
    if(mat[starty][startx]==0) return false; 
    if(underCheck && (convertLett(move[0])!=pieces[kingPos].col) && (convertNum(move[1]!=pieces[kingPos].row))) return false;
    if(move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' && move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h') return false;
    if(move[1] != '1' && move[1] != '2' && move[1] != '3' && move[1] != '4' && move[1] != '5' && move[1] != '6' && move[1] != '7' && move[1] != '8') return false;
    if(move[3] != 't' || move [4] !='o') return false;
    if(move[6] != 'a' && move[6] != 'b' && move[6] != 'c' && move[6] != 'd' && move[6] != 'e' && move[6] != 'f' && move[6] != 'g' && move[6] != 'h') return false;
    if(move[7] != '1' && move[7] != '2' && move[7] != '3' && move[7] != '4' && move[7] != '5' && move[7] != '6' && move[7] != '7' && move[7] != '8') return false;
    //--------------
    int i;
    for(i=0;i<32;i++){
        if(startx==pieces[i].col && starty==pieces[i].row) break;
    }
    pieces[i].setMoves(mat,WKMove,WR1Move,WR2Move,BKMove,BR1Move,BR2Move);
    if(!pieces[i].possibleMoves[endy][endx]) return false;
    return true;
}

void board::changePos(string move){
    int tempValue;
    int startx,starty,endx,endy;
    starty=8-convertNum(move[1]); //rewrite for real position
    endy=8-convertNum(move[7]);
    startx=convertLett(move[0]);
    endx=convertLett(move[6]);
    tempValue=mat[starty][startx];
    mat[starty][startx]=0;
    mat[endy][endx]=tempValue;
    for(int i=0; i<32; i++){            //If there's a piece on the final box it's erased from the board
        if(pieces[i].row==endy && pieces[i].col==endx){
            pieces[i].row=-1;
            pieces[i].col=-1;
        }
    }
    for(int i=0; i<32; i++){            //The position of the moved piece is rewritten
        if(pieces[i].row==starty && pieces[i].col==startx){
            pieces[i].row=endy;
            pieces[i].col=endx;
        }
    }
}

void getPieces(pieceData pieces[]){ //test function
    int e=0;
    for(int i=0;i<4;i++){
        for(int c=0;c<8;c++){
            cout<<pieces[e].type;
            e++;
        }
        cout<<endl;
    }
}

int check4check(pieceData pieces[],int gioc,int turn){ //first fuction for under check/checkmate checking
    return 0;
    int kingPos; //position of the king. useful for checking
    if(turn%2!=0) kingPos=28;
    else kingPos=4; //defining the value
    //if(pieces[kingPos].possibleMoves[pieces[kingPos].row+1][pieces[kingPos].col]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row+1][pieces[kingPos].col-1]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row+1][pieces[kingPos].col+1]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row-1][pieces[kingPos].col]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row][pieces[kingPos].col+1]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row][pieces[kingPos].col-1]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row-1][pieces[kingPos].col-1]==0 && pieces[kingPos].possibleMoves[pieces[kingPos].row-1][pieces[kingPos].col+1]==0) return 2;
    //cout<<pieces[gioc].type<<endl<<pieces[gioc].row<<endl<<pieces[gioc].col<<endl<<endl;
    //return 2;
    //case 2: (checkmate)
    //case 1: (just under check)
    //algorithm needed!
}

void checkPt2(string name1,string name2, board mat,int gioc,int turn,bool &check,bool &underCheck){ //second fuction for under check/checkmate checking
    switch(check4check(mat.pieces,gioc,turn)){ //depending on the value:
		case 1:{
		    //black/white under check
            underCheck=true;
            cout<<endl<<name1<<" is under check!"<<endl;
            turn--;
			break;
        }
		case 2:{
		    //white/black checkmate
            check=false;
            system("cls");
            finalMsg(name2);
		    break;
		}
	}
}