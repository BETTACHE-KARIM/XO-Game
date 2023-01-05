
#include <iostream>
#include <string>
using namespace std;
class Player{
    string name, xo;
   
    public:
     double score = 0;
    void setProp(string val, string v_xo){
        name = val;
        xo = v_xo;
    }
    string getname(){
        return name ;
     
    }
        string getxo(){
        return xo ;
     
    }
    
    bool play(string ta[3][3], int index){

        if(index < 4 && ta[0][index-1] == "_" ){
           
            ta[0][index-1] = xo;
            return true;
        }
        else if(index < 7 && ta[1][index-4]== "_" ){
            
            ta[1][index-4] = xo;
            return true;
        }
         else if (index < 10 &&ta[2][index-7]== "_"){
            
            ta[2][index-7] = xo;
            return true;
        }

       
        return false;
        
    }


    
    bool checkWin(string ta[3][3]){
        
       for(int i =0 ; i <3 ;i++){
            if(ta[i][i] == xo && ta[i][i+1] == xo && ta[i][i+2] == xo) return true;
        }
        for(int i =0 ; i <3 ;i++){
            if(ta[i][i] == xo && ta[i+1][i] == xo && ta[i+2][i] == xo) return true;
        }

        if(ta[0][0] == xo && ta[1][1] == xo && ta[2][2] == xo) return true;
        if(ta[0][2] == xo && ta[1][1] == xo && ta[2][0] == xo) return true;
        


        
        return false;
    }

    static bool checkDraw(string ta[3][3]){
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if(ta[i][j] == "_"){
                    return false;
                };
            }
            
        }
        return true;
    } 
    static void printTable(string ta[3][3]){
        cout<<"|---------------|---------------|---------------|"<<endl;
        for(int i =0 ; i <3 ;i++){
   
            cout<<"|\t\t"<<ta[i][0]<<"\t\t|\t\t"<<ta[i][1]<<"\t\t|\t\t"<<ta[i][2]<<"\t\t|"<<endl;
            cout<<"|---------------|---------------|---------------|"<<endl;
        }
       
    }
    
};



void initialize(string ta[3][3]){
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            ta[i][j] = "_";
        }
        
    }
    
}




bool Q_terminer(){
    string term;
     cout<<"Tapez no pour terminer: ";cin>>term;
     return(term =="no") ;
}

int main() {
    
    Player p1, p2;
    string name, win;
    int position, res;
    string table[3][3]  = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
    

    cout << "Name of First Player: ";cin>>name;
    p1.setProp(name, "X");
    cout << "Name of Second Player: ";cin>>name;
    p2.setProp(name, "O");


    while( true) {
        cout << "************ Playing *************"<<endl;
        Player::printTable(table);
        position = -1;
        while(true){
            cout<<p1.getname()<<" Where to play? ";cin>>position;
            
            if( p1.play(table, position) ) break;
          

        }
    
        if(Player::checkDraw(table)){
            
            Player::printTable(table);
            cout<<"Draw."<<endl;
            initialize(table);
            if(Q_terminer()) break;
            continue;
        }
        
         // ------------------------------------ A
        if(p1.checkWin(table) ) {
           initialize(table);
            win =p1.getname();
            p1.score++;
            Player::printTable(table);
            cout<<p1.getname()<<" Win."<<endl;

            if(Q_terminer()) break;
            continue;
        };
       
        
        // ------------------------------------ B
        while(true){
            
            cout<<p2.getname()<<" Where to play? ";cin>>position;
            if( p2.play(table, position) ) break;
          

        }
        if(p2.checkWin(table) )  {
           initialize(table);
            win =p2.getname();
            p2.score++;
            Player::printTable(table);
            cout<<p2.getname()<<" Win."<<endl;

            if(Q_terminer()) break;
            continue;
        };
        
        
        
    }
    cout<<p1.getname()<<" score: "<<p1.score<<endl;
    cout<<p2.getname()<<" score: "<<p2.score<<endl;






    return 0;
}