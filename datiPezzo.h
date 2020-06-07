class DatiPezzo{
    public:
        DatiPezzo();    //Costruttore
        int tipo;       //Dati riguardanti le coordinate e il tipo per ogni pezzo
        int riga;
        int col;        /*Per il tipo sono usati gli stessi numeri della scacchiera
                        Se un pezzo viene catturato il tipo viene segnato con lo 0*/
};
DatiPezzo::DatiPezzo(){

}