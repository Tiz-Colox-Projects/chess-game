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
            if(campo[i][j]!=0){
                pezzi[c].tipo=campo[i][j];
                pezzi[c].riga=i;
                pezzi[c].col=j;
                c++;
            }
        }
    }
}