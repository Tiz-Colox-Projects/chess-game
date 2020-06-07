class pieceData{
    public:
        pieceData();    //Constructor
        int type;       //Data of the coordinates and type of each piece
        int row;
        int col;        /*For the type are used the same numbers of the board
                        If a piece has been previously captured it's indicated with the number 0*/
};
pieceData::pieceData(){

}