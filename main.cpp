
#include <iostream>
#include <string>
using namespace std;

class Player{
        string name, xo;
        double score  ;
    public:
        Player(string name ="", string xo=""):name(name), xo(xo), score(0){}
        Player(Player &p):name(p.name), xo(p.xo), score(p.score){}

        string getXo(){
            return xo;
        }
        string getName(){
            return xo;
        }
        void operator ++(int){
            score++;
        }
        friend ostream& operator<<(ostream& out, Player &player){
            out<<player.xo<<" Player name: "<<player.name<<", Score: "<< player.score<<"."<<endl;
            return out;
        }
        friend istream& operator>>(istream& in, Player &player){
            cout<<"Player name: ";
            getline(in, player.name);
            cout<<"X or O: ";in>>player.xo;
            in.ignore();
            return in;
        }
};

class GameXO{
        Player *P1, *P2;
        bool turn, draw;
        string table[3][3]  = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
   
        
        Player* getPlayer(){
            return turn==true ? P1 :  P2;
        }

        bool Q_Leave(){
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
            
    
        }
        ~GameXO(){
            delete P1; 
            delete P2;
        }


        
        bool Play_Turn(){
            turn = !turn;
            int index ;
            Player *p = getPlayer();
            

            while(true){
            cout<<p->getName()<<" Turn: ";cin>>index;
            
            
            if(index < 4 && table[0][index-1] == "_" ){
                table[0][index-1] = p->getXo();
                break;
            }
            else if(index < 7 && table[1][index-4]== "_" ){
                table[1][index-4] = p->getXo();
                break;
            }
            else if (index < 10 &&table[2][index-7]== "_"){
                table[2][index-7] = p->getXo();
                break;
            }
            cout<<"Bad choice"<<endl;
           
            
            }
            
        }

        bool Draw_Check(){
            
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    if(table[i][j] == "_"){
                        return false;
                    };
                }
                
            }
            cout<<"Draw!"<<endl;
            return true;
        }
        
        bool Win_Check(){
            
            
            Player *p = getPlayer();
            
            for(int i =0 ; i <3 ;i++){
                if(table[i][i] == p->getXo() && table[i][i+1] == p->getXo() && table[i][i+2] == p->getXo()) { 
                    cout<<p->getName()<<" Win!"<<endl;
                    (*p)++;
                    return true;
                }
            }
            for(int i =0 ; i <3 ;i++){
                if(table[i][i] == p->getXo() && table[i+1][i] == p->getXo() && table[i+2][i] == p->getXo()) { 
                     cout<<p->getName()<<" Win!"<<endl;
                     (*p)++;
                    return  true;
                }
            }

            if(table[0][0] == p->getXo() && table[1][1] == p->getXo() && table[2][2] == p->getXo()) { 
                    cout<<p->getName()<<" Win!"<<endl;
                    (*p)++;
                    return  true;
            }
            if(table[0][2] == p->getXo() && table[1][1] == p->getXo() && table[2][0] == p->getXo()) { 
                    cout<<p->getName()<<" Win!"<<endl;
                    (*p)++;
                    return  true;
            }

            return false;

        
            
        }
      
        bool End_Game(){
           
            Table_Init();
            if(Q_Leave())return true;
            return false;
          
           
        }

        void Table_Print(){
            cout<<"|-------------------------------|-------------------------------|-------------------------------|"<<endl;
            for(int i =0 ; i <3 ;i++){
    
                cout<<"|\t\t"<<table[i][0]<<"\t\t|\t\t"<<table[i][1]<<"\t\t|\t\t"<<table[i][2]<<"\t\t|"<<endl;
                cout<<"|-------------------------------|-------------------------------|-------------------------------|"<<endl;
            }
        
        }
    
        void Print_Result(){
            cout<<"Player 1:\n";
            cout<<*P1;
            cout<<"\nPlayer 2:\n";
            cout<<*P2;

        }
};









int main() {
    
  



    Player p1, p2;
    cin>>p1;
    cin>>p2;
    GameXO game(p1, p2);
    
    while( true) {
        system("cls");
        cout << "********************* Playing *********************"<<endl;
        game.Table_Print();

// ******************** Plyaer 1 *************************

        game.Play_Turn();
        if(game.Draw_Check()){
            if(game.End_Game()) break;
            else continue;
        };
        
        if(game.Win_Check()) {
            
            if(game.End_Game()) break;
            else continue;
        };


// ******************** Plyaer 2 *************************


        game.Play_Turn();
       
        if(game.Win_Check()) {
            
            if(game.End_Game()) break;
            else continue;
        };
        

        
    }
    game.Print_Result();


    return 0;
}