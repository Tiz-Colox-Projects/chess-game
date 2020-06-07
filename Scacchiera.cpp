#include "Scacchiera.h"

Scacchiera::Scacchiera(){
    
}

void Scacchiera::getInizio(){
    int c=0;
    for(int i=7; i>=0; i--){                     //Ciclo per selezionare la riga
        for(int j=0; j<8; j++){                 //Ciclo per selezionare la colonna
            switch(i){
                case 0:{                        //Caso della riga più in alto, quella nera
                    if(j<=4) campo[i][j]=8+j;
                    else campo[i][j]=15-j;
                    break;
                }
                case 1:{                        //Caso della riga dei pedoni neri
                    campo[i][j]=7;
                    break;
                }
                case 6:{                        //Caso della riga dei pedoni bianchi
                    campo[i][j]=1;
                    break;
                }
                case 7:{                        //Caso della riga più in baso, quella bianca
                    if(j<=4) campo[i][j]=2+j;
                    else campo[i][j]=9-j;
                    break;
                }                               //Caso delle righe centrali, che sono vuote
                default:{
                    campo[i][j]=0;
                }
            }
            if(campo[i][j]!=0){                 /*Se la casella viene riempita con un pezzo questo viene memorizzato
                                                nell'array dei pezzi presenti sulla scacchiera*/
                pezzi[c].tipo=campo[i][j];      //Memorizzazione del tipo
                pezzi[c].riga=i;                //Memorizzazione della riga
                pezzi[c].col=j;                 //Memorizzazione della colonna
                c++;                            //Incremento della variabile contatore
            }
        }
    }
}

bool Scacchiera::contrSelezione(int riga, int col, int player){
    if(campo[riga][col]==0) return false;       //Se la casella selezionata è vuota viene invalidata la selezione
    else{
        if(player==1 && campo[riga][col]>6) return false;   /*Se è il turno del giocatore 1(bianco) e la selezione
                                                            supera il valore 6 (è stato selzionato un pezzo neropezzo nero) 
                                                            viene invalidata*/
        else if(player==2 && campo[riga][col]<7) return false;  /*Se è il turno del giocatore 2(nero) e la selezione
                                                                è inferiore al valore 7 (è stato selzionato un pezzo bianco) 
                                                                viene invalidata*/
        else return true;           /*Se nessuna delle condizioni precedenti è rispettata vuol dire che è stato selezionato un pezzo 
                                    del proprio colore e la selezione viene convalidata*/
    }
}