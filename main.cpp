
#include <iostream>
#include <string>
using namespace std;

class Player{
        string name, xo;
        double score  = 0;
    public:
        Player(string name ="", string xo=""):name(name), xo(xo){}
        Player(Player &p):name(p.name), xo(p.xo){}

        string getXo(){
            return xo;
        }
        string getName(){
            return xo;
        }
        friend ostream& operator<<(ostream& out, Player &player){
            out<<"Player name ("<< player.xo<<"): "<<player.name<<", Score: "<< player.score<<"."<<endl;
            return out;
        }
        friend istream& operator>>(istream& in, Player &player){
            cout<<"Player name: ";cin>>player.name;
            cout<<"X or O: ";cin>>player.xo;
            return cin;
        }
};

class GameXO{
        Player *P1, *P2;
        bool turn, endGame;
        string table[3][3]  = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
        

    
        bool checkDraw(){
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    if(table[i][j] == "_"){
                        return false;
                    };
                }
                
            }
            return true;
        }
        
        Player& getPlayer(){
            return turn==true ? *P1 :  *P2;
        }

        bool Q_terminer(){
            string term;
            cout<<"Leave the game (Y/N)? ";cin>>term;
            return((term =="Y"  || term =="y"  ) && term !=" " ) ;
        } 
        void Table_Init(){
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    table[i][j] = "_";
                }
                
            }
            
        }


    public:
        GameXO(Player &p1, Player &p2){
            turn = false;
            P1 = new Player(p1);
            P2 = new Player(p2);
            cout<<"-----The game has started!"<<endl;
            cout<<p1;
            cout<<p2;
            
            
            
        }
        ~GameXO(){
            delete P1, P2;
        }


        
        bool Play_Turn(){
            int index ;
            Player p = getPlayer();
            turn = !turn;

            while(true){
            cout<<p.getName()<<" Turn: ";cin>>index;
            
            
            if(index < 4 && table[0][index-1] == "_" ){
                table[0][index-1] = p.getXo();
                break;
            }
            else if(index < 7 && table[1][index-4]== "_" ){
                table[1][index-4] = p.getXo();
                break;
            }
            else if (index < 10 &&table[2][index-7]== "_"){
                table[2][index-7] = p.getXo();
                break;
            }
            cout<<"Bad choice"<<endl;
           
            
            }
        }

        
        void Win_Check(){
            endGame = NULL;
            if(checkDraw()) {
                if(Q_terminer())endGame = true;
                else endGame = false;
            } ;
            Player p = getPlayer();

            for(int i =0 ; i <3 ;i++){
                if(table[i][i] == p.getXo() && table[i][i+1] == p.getXo() && table[i][i+2] == p.getXo()) { 
                    if(Q_terminer())endGame = true;
                    else endGame = false;
                }
            }
            for(int i =0 ; i <3 ;i++){
                if(table[i][i] == p.getXo() && table[i+1][i] == p.getXo() && table[i+2][i] == p.getXo()) { 
                    if(Q_terminer())endGame = true;
                    else endGame = false;
                }
            }

            if(table[0][0] == p.getXo() && table[1][1] == p.getXo() && table[2][2] == p.getXo()) { 
                    if(Q_terminer())endGame = true;
                    else endGame = false;
            }
            if(table[0][2] == p.getXo() && table[1][1] == p.getXo() && table[2][0] == p.getXo()) { 
                    if(Q_terminer())endGame = true;
                    else endGame = false;
            }



        
            
        }
      
        bool End_Game(){
            if(endGame != NULL) {
                Table_Init();
                if(endGame) return true;
                else return false;
            }
            return NULL;
        }
        void Table_Print(){
            cout<<"|---------------|---------------|---------------|"<<endl;
            for(int i =0 ; i <3 ;i++){
    
                cout<<"|\t\t"<<table[i][0]<<"\t\t|\t\t"<<table[i][1]<<"\t\t|\t\t"<<table[i][2]<<"\t\t|"<<endl;
                cout<<"|---------------|---------------|---------------|"<<endl;
            }
        
        }
    
};









int main() {
    
  



    Player p1, p2;
    cin>>p1;
    cin>>p2;
    GameXO game(p1, p2);
    while( true) {
        system("cls");
        cout << "************ Playing *************"<<endl;
        game.Table_Print();
        game.Play_Turn();
        game.Win_Check();
        if(game.End_Game() != NULL) {
            if(game.End_Game()) break;
            else continue;
        }
        game.Play_Turn();
        game.Win_Check();
        if(game.End_Game() != NULL) {
            if(game.End_Game()) break;
            else continue;
        }
        

        
    }





















    return 0;
}