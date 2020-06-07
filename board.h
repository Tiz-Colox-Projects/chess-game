#include <iostream>
#include "semigraf.h"
#include "datiPezzo.h"
using namespace std;

class board{
    public:
        int DIM=8;
        int mat[8][8];    /*Matrice che indica i pezzi sulla scacchiera.

                            Per i bianchi sono indicati con
                            1=pedoni
                            2=torri
                            3=cavalli
                            4=alfieri
                            5=regina
                            6=re

                            Per i neri sono
                            7=pedoni
                            8=torri
                            9=cavalli
                            10=alfieri
                            11=regina
                            12=re*/
        DatiPezzo pezzi[32];        //Oggetti che rappresentano ogni pezzo presente sulla scacchiera
        //attr
        //methods
        board();
        void zero();
        void getBoard();
        void start();                               //Genera la disposizione iniziale della scacchiera
        bool selectionControl(int riga, int col, int player);      //Verifica che la selzione del pezzo selezionato sia valida
};

board::board(){
}

void board::zero(){
    for(int i=0;i<DIM;i++){
        for(int c=0;c<DIM;c++){
            mat[i][c]=0;
        }
    }
}

void board::getBoard(){ 
	char a=65;
    setcolor(3);
    gotoxy(10,2); //start abc
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
    for(int i=DIM;i>0;i--){ //start num
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
    for(int i=0;i<DIM;i++){ //start board
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
                    cout<<"P";
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

//----------------------

void board::start(){
    int c=0;
    for(int i=7; i>=0; i--){                     //Ciclo per selezionare la riga
        for(int j=0; j<8; j++){                 //Ciclo per selezionare la colonna
            switch(i){
                case 0:{                        //Caso della riga più in alto, quella nera
                    if(j<=4) mat[i][j]=8+j;
                    else mat[i][j]=15-j;
                    break;
                }
                case 1:{                        //Caso della riga dei pedoni neri
                    mat[i][j]=7;
                    break;
                }
                case 6:{                        //Caso della riga dei pedoni bianchi
                    mat[i][j]=1;
                    break;
                }
                case 7:{                        //Caso della riga più in baso, quella bianca
                    if(j<=4) mat[i][j]=2+j;
                    else mat[i][j]=9-j;
                    break;
                }                               //Caso delle righe centrali, che sono vuote
                default:{
                    mat[i][j]=0;
                }
            }
            if(mat[i][j]!=0){                 /*Se la casella viene riempita con un pezzo questo viene memorizzato
                                                nell'array dei pezzi presenti sulla scacchiera*/
                pezzi[c].tipo=mat[i][j];      //Memorizzazione del tipo
                pezzi[c].riga=i;                //Memorizzazione della riga
                pezzi[c].col=j;                 //Memorizzazione della colonna
                c++;                            //Incremento della variabile contatore
            }
        }
    }
}

bool board::selectionControl(int riga, int col, int player){
    if(mat[riga][col]==0) return false;       //Se la casella selezionata è vuota viene invalidata la selezione
    else{
        if(player==1 && mat[riga][col]>6) return false;   /*Se è il turno del giocatore 1(bianco) e la selezione
                                                            supera il valore 6 (è stato selzionato un pezzo neropezzo nero) 
                                                            viene invalidata*/
        else if(player==2 && mat[riga][col]<7) return false;  /*Se è il turno del giocatore 2(nero) e la selezione
                                                                è inferiore al valore 7 (è stato selzionato un pezzo bianco) 
                                                                viene invalidata*/
        else return true;           /*Se nessuna delle condizioni precedenti è rispettata vuol dire che è stato selezionato un pezzo 
                                    del proprio colore e la selezione viene convalidata*/
    }
}