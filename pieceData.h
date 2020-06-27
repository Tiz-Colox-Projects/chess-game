class pieceData{
    public:
        pieceData();    //Constructor
        int type;       //Data of the coordinates and type of each piece
        int row;
        int col;        /*For the type are used the same numbers of the board
                        If a piece has been previously captured it's indicated with the number 0*/
        bool possibleMoves[8][8];   //This matrix indicates the boxes where the piece can move
        void setMoves(int m[][8], bool WKMove, bool WR1Move, bool WR2Move, bool BKMove, bool BR1Move, bool BR2Move);        
        /*This function gets the boxes where the piece can move, m is the arrengement of the pieces
        m is the arrangement of the pieces and the other are
        WKMove=variable of the white king movement
        WR1Move=variable of the white rook on the left movement
        WR2Move=variable of the white rook on the right movemenent
        BKMove=variable of the black king movement
        BR1Move=variable of the black rook on the left movement
        BR2Move=variable of the black rook on the right movemenent*/

        /*Functions to verify the moves of every piece
        row2 and col2 are the coordinates of the box and m in the arrangement of the pieces on the board*/
        bool verMoveWP(int row2, int col2, int m[][8]);     //White pawns
        bool verMoveBP(int row2, int col2, int m[][8]);     //Black pawns
        bool verMoveR(int row2, int col2, int m[][8], int t);      //Rooks
        bool verMoveN(int row2, int col2, int m[][8]);      //Knights
        bool verMoveB(int row2, int col2, int m[][8], int t);      //Bishops
        bool verMoveQ(int row2, int col2, int m[][8]);      //Queen
        bool verMoveK(int row2, int col2, int m[][8], bool KMove, bool R1Move, bool R2Move);      //King
};
pieceData::pieceData(){

}
void pieceData::setMoves(int m[][8], bool WKMove, bool WR1Move, bool WR2Move, bool BKMove, bool BR1Move, bool BR2Move){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            switch(type){                   //Selection of the type of the piece
                case 0:{
                    break;
                }
                case 1:{                    //Case of the white pawns
                    possibleMoves[i][j]=verMoveWP(i,j,m);
                    break;
                }
                case 7:{                    //Case of the black pawns
                    possibleMoves[i][j]=verMoveBP(i,j,m);
                    break;
                }
                case 2:                     //Case of the rooks
                case 8:{
                    possibleMoves[i][j]=verMoveR(i,j,m,type);
                    break;
                }
                case 3:                     //Case of the knights
                case 9:{
                    possibleMoves[i][j]=verMoveN(i,j,m);
                    break;
                }
                case 4:                     //Case of the bishops
                case 10:{
                    possibleMoves[i][j]=verMoveB(i,j,m,type);
                    break;
                }
                case 5:                     //Case of the queen
                case 11:{
                    possibleMoves[i][j]=verMoveQ(i,j,m);
                    break;
                }          
                case 6:{                //Case of the white king
                    possibleMoves[i][j]=(WR2Move);
                    break;
                }                   
                case 12:{               //Case of the white king
                    possibleMoves[i][j]=verMoveK(i,j,m,BKMove,BR1Move,BR2Move);
                    break;
                }
            }
        }
    }
}
bool pieceData::verMoveWP(int row2, int col2, int m[][8]){
    if(row2==row && col2==col) return false;                        /*If the box is the same of the piece it can't move there and the
                                                                    returned value is false*/
    else if(m[row2][col2]>=1 && m[row2][col2]<=6) return false;     /*If the box's value is beetween 1 and 6 (there's a white piece) 
                                                                    the returned value is false*/
    else if(col-col2<-1 || col-col2>1) return false;                /*If the box is more than 2 spaces distant horizontally the
                                                                    returned value is false*/
    else{
        if(col-col2==0){                                            //Case of the same column of the piece
            if(m[row-1][col]>0) return false;                       //If the next box in vertical is occupied the pawn can't move
            else if(row==6){                                       //Case of the beginning row
                if(row2-row==2 && m[row2][col2]>0) return false;   /*If the box is 2 spaces upper and there's another
                                                                     piece the returned value is false*/
                else if(row2-row>2) return false;                   /*If the box is more than 2 spaces upper the returned value
                                                                    is false*/
            }                                                       
            else if(row2-row>1) return false;                       /*If the box is more than 1 spaces upper the returned value
                                                                    is false*/
        }
        else if((m[row2][col2]>0 && m[row2][col2]<=6) || row2-row!=1) return false;      
        //If the pawn doesn't move diagonally or there isn't an enemy piece the returned value is false
    }
    return true;                                //If no condition is respected the pawn can move to the box
}
bool pieceData::verMoveBP(int row2, int col2, int m[][8]){
    if(row2==row && col2==col) return false;                        /*If the box is the same of the piece it can't move there and the
                                                                    returned value is false*/
    else if(m[row2][col2]>6) return false;                          /*If the box's value is higher than 6 (there's a black piece) 
                                                                    the returned value is false*/
    else if(col-col2<-1 || col-col2>1) return false;                /*If the box is more than 2 spaces distant horizontally the
                                                                    returned value is false*/
    else{
        if(col-col2==0){                                            //Case of the same column of the piece
            if(m[row+1][col]>0) return false;                       //If the next box in vertical is occupied the pawn can't move
            else if(row==1){                                             //Case of the beginning row
                if(row-row2==2 && m[row2][col2]>0) return false;   /*If the box is 2 spaces lower and there's another
                                                                        piece the returned value is false*/
                else if(row-row2>2) return false;                       /*If the box is more than 2 spaces lower the returned value
                                                                        is false*/
            }
        }
        else if(m[row2][col2]>6 || row-row2!=1) return false;      /*If the pawn doesn't move diagonally or there isn't an enemy 
                                                                    piece the returned value is false*/
    }
    return true;                                //If no condition is respected the pawn can move to the box
}
bool pieceData::verMoveR(int row2, int col2, int m[][8], int t){
    if(row2==row && col2==col) return false;            //If the box is the same of the rook it can't move there
    else if(row2!=row && col2!=col) return false;       /*If the row and the column of destination are different at the same time 
                                                        the returned value is false*/
    else{                                               //Case of the same row or column. The controls are applicated with cycles
        if(row2<row){                                   //Case of an upper box
            for(int i=1; row-i>=row2; i++){
                if(row-i==row2){
                    if(t==2 && (m[row-i][col]<=6 && m[row-i][col]>0)) return false;
                    else if(t==8 && m[row-i][col]>6) return false;
                }                   /*If the box is the selected one and there's a piece of the same color the returned value
                                    is false*/
                else if(m[row-i][col]!=0) return false;     /*If it's not the selcted box and there's another piece in the returned 
                                                            value is false*/
            }
        }
        else if(row2>row){          //Case of a lower box
            for(int i=1; row+i<=row2; i++){
                if(row+i==row2){
                    if(t==2 && (m[row+i][col]<=6 && m[row+i][col]>0)) return false;
                    else if(t==8 && m[row+i][col]>6) return false;
                }
                else if(m[row+i][col]!=0) return false;
            }
        }
        else if(col2<col){          //Case of a box on the left
            for(int i=1; col-i>=col2; i++){
                if(col-i==col2){
                    if(t==2 && (m[row][col-i]<=6 && m[row][col-i]>0)) return false;
                    else if(t==8 && m[row][col-i]>6) return false;
                }
                else if(m[row][col-i]!=0) return false;
            }
        }
        else{                       //Case of a box on the right
            for(int i=1; col+i<=col2; i++){
                if(col+i==col2){
                    if(t==2 && (m[row][col+i]<=6 && m[row][col+i]>0)) return false;
                    else if(t==8 && m[row][col+i]>6) return false;
                }
                else if(m[row][col+i]!=0) return false;
            }
        }
    }
    return true;                //If no condition is respected the box is valid
}
bool pieceData::verMoveN(int row2, int col2, int m[][8]){
    if(row2==row || col2==col) return false;            //If the row or the column are the same of the knight the box is invalid
    else if(row-row2>2 || row-row2<-2) return false;    /*If the difference beetween the rows or the columns is higher than 2 spaces
                                                        the box is invalid*/
    else if(col-col2>2 || col-col2<-2) return false;    
    else{
        if((row-row2==2 || row-row2==-2) && (col-col2!=1 && col-col2!=-1)) return false;    /*If the difference beetween the rows is 2
                                                                                            spaces and the columns' one is different 
                                                                                            than 1 the returned value is false*/
        else if((col-col2==2 || col-col2==-2) && (row-row2!=1 && row-row2!=-1)) return false;   //The opposite of the previously case
        else if(type==3 && (m[row2][col2]>0 && m[row2][col2]<=6)) return false;         /*If in the box there's a piece of the same
                                                                                        color the returned value is false*/
        else if(type==9 && m[row2][col2]>6) return false;
    }
    return true;        //If no condition is respected the box is valid
}
bool pieceData::verMoveB(int row2, int col2, int m[][8], int t){
    if(row2==row || col2==col) return false;        //If the the boxes are'nt diagonally aligned the position is invalid
    else if(row-row2!=col-col2 && row-row2!=-1*(col-col2)) return false;
    else{                                           //Controls of the pieces through the boxes
        if(row2<row){                               //Case of an upper row
            if(col2<col){                           //Case of a column on the left
                for(int i=1; row-i>=row2; i++){     //Cycle for the controls
                    if(row-i==row2){
                        if(t==4 && (m[row-i][col-i]<=6 && m[row-i][col-i]>0)) return false;
                        else if(t==10 && m[row-i][col-i]>6) return false;
                    }                   /*If the box is the selected one and there's a piece of the same color the returned value
                                        is false*/
                    else if(m[row-i][col-i]!=0) return false;     /*If it's not the selcted box and there's another piece in the returned 
                                                                value is false*/
                }
            }
            else{                                   //Case of a column on the right
                for(int i=1; row-i>=row2; i++){     //Cycle for the controls
                    if(row-i==row2){
                        if(t==4 && (m[row-i][col+i]<=6 && m[row-i][col+i]>0)) return false;
                        else if(t==10 && m[row-i][col+i]>6) return false;
                    }                   /*If the box is the selected one and there's a piece of the same color the returned value
                                        is false*/
                    else if(m[row-i][col+i]!=0) return false;     /*If it's not the selcted box and there's another piece in the returned 
                                                                value is false*/
                }
            }
        }
        else{                                       //Case of a lower row
            if(col2<col){                           //Case of a column on the left
                for(int i=1; row+i<=row2; i++){     //Cycle for the controls
                    if(row+i==row2){
                        if(t==4 && (m[row+i][col-i]<=6 && m[row+i][col-i]>0)) return false;
                        else if(t==10 && m[row+i][col-i]>6) return false;
                    }                   /*If the box is the selected one and there's a piece of the same color the returned value
                                        is false*/
                    else if(m[row+i][col-i]!=0) return false;     /*If it's not the selcted box and there's another piece in the returned 
                                                                value is false*/
                }
            }
            else{                                   //Case of a column on the right
                for(int i=1; row+i<=row2; i++){     //Cycle for the controls
                    if(row+i==row2){
                        if(t==4 && (m[row+i][col+i]<=6 && m[row+i][col+i]>0)) return false;
                        else if(t==10 && m[row-i][col]>6) return false;
                    }                   /*If the box is the selected one and there's a piece of the same color the returned value
                                        is false*/
                    else if(m[row+i][col+i]!=0) return false;     /*If it's not the selcted box and there's another piece in the returned 
                                                                value is false*/
                }
            }
        }
    }
    return true;                //If no condition is respected the box is valid
}
bool pieceData::verMoveQ(int row2, int col2, int m[][8]){
    if(verMoveR(row2,col2,m,type-3) || verMoveB(row2,col2,m,type-1)) return true;
    else return false;
}
//The movement of the queen is a mix of the rooks and bishops' ones. If one of their control is true the box is valid
bool pieceData::verMoveK(int row2, int col2, int m[][8], bool KMove, bool R1Move, bool R2Move){
    if(row==row2 && col==col2) return false;        //IF the box is the same of the pice's one it's invalid
    else if(!KMove){                                //Case when the king has never moved
        if(col-col2==-2){                            //First case of the castling
            if(R2Move) return false;                //If the rook has previously moved the returned value is false
            else{
                for(int i=1; col+i<=col2; i++){          //If there's a piece through the king and the rook the move is invalid
                    if(m[row][col-i]!=0) return false;
                }
            }
        }
        else if(col-col2==2){                      //The same of the previously case
            if(R1Move) return false;
            else{
                for(int i=1; col+i>=col2; i++){
                    if(m[row][col+i]!=0) return false;
                }
            }
        }
        else if((row-row2<-1 || row-row2>1) || (col-col2<-1 || col-col2>1)) return false;
        //Else if the king moved more than 1 box in a direction the move is invalid
        else{
            if(type==6 && (m[row2][col2]>0 && m[row2][col2]<6)) return false;
            else if(type==12 && m[row2][col2]>6) return false;
        }
        //Else if on the box there's a piece of the same color the returned value is false
    }
    else if((row-row2>1 || row-row2<-1) || (col-col2<-1 || col-col2>1)) return false;
    //Else if the king moved more than 1 box in a direction the move is invalid   
    else{
        if(type==6 && (m[row2][col2]>0 && m[row2][col2]<6)) return false;
        else if(type==12 && m[row2][col2]>6) return false;
    }
    //Else if on the box there's a piece of the same color the returned value is false
    return true;                //If no condition is respected the box is valid
}
