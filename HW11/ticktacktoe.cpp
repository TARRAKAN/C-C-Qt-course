#include <iostream>
#include <cstdlib>
#include <ctime>

class xNo{ 
    char desk[3][4] = {{"   "},{"   "},{"   "}};    
public:
    void pDesk(){
        std::cout<<"  1 2 3 \n";
        for(int i = 0; i < 3; i++){
            std::cout<<i+1<<"|";
            for(int j = 0; j < 3; j++)
            {
                std::cout<<desk[i][j]<<"|";  
            }
            std::cout<<"\n";
        }
    }
    //-------------ADD---------------------------
    int add(int x, int y, char ch){
        bool checker = (desk[y-1][x-1]==' ')&&(y >= 1)&&(x <= 3)&&(x >= 1)&&(y <= 3);
        if(checker){
            desk[y-1][x-1] = ch;
            return 1;
        }
        else
            return 0;  
    }
    //-------------CHECK-------------------------
    int check(char checkCh){  
        for(int i = 0; i < 3;i++){
            int markX = 0;
            int markY = 0; 
            for(int j = 0; j < 3; j++){
                if(desk[i][j]==checkCh)
                    markX++;
                if(desk[j][i]==checkCh)
                    markY++;
            }
            if((markX == 3)||(markY == 3)){
                std::cout<<checkCh<<" - won!\n";
                return 0;           
            }
        }
        int markX = 0;
        int markY = 0;
        for(int i = 0, j = 3; (i < 3)&&(j>=0); i++){
            j--;
            if(desk[i][i] == checkCh)
                markX++;
            if(desk[i][j] == checkCh)
                markY++;
            if((markX == 3)||(markY == 3)){
                std::cout<<checkCh<<" - won!\n";
                return 0;
            }
        }
        markX = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(desk[i][j]!=' ')
                    markX++;
                if(markX == 9){
                    std::cout<<"Friendship - won!\n";
                    return 0;
                }
            }
        }
        return 1;
    }
};

int main(){
    xNo ttt;
    std::cout<<"TICK-TACK-TOE"<<'\n';
    std::cout<<"TYPE OF THE GAME:\nPvP  - 1\nPvE  - 2\nEXIT - 3\n";
    int typeOfGame = 0;
    std::cin>>typeOfGame;
    if(typeOfGame == 1){
            ttt.pDesk();
            char player = 'O';
        while(ttt.check('X') && ttt.check('O')){
            int x = 0;
            int y = 0;
            if(player == 'O')
                player = 'X';
            else
                player = 'O';
            while(true){               
                std::cout<<"add "<<player<<":\nInput a line:";
                std::cin>>y;
                std::cout<<"Input a column:";
                std::cin>>x;
                if(ttt.add(x,y,player))
                    break;
                else
                    std::cout<<"Something went wrong! Do in again!\n";
            }
            ttt.pDesk();
        }
    }
    else if(typeOfGame == 2){
        std::cout<<"Choose a difficulty:\n1 - Easy breezy\n4 - DOOM ON STEROIDS\n";
        std::cin>>typeOfGame;
        char side = ' ';
        char turn = 'X';
        std::cout<<"Choose your side(X or O):";
        std::cin>>side;
        if(typeOfGame == 1){
            while(ttt.check('X') && ttt.check('O')){                
                if(turn == side){                                   //player's
                    while(true){                                    //turn
                        int x = 0;                                  //
                        int y = 0;                                  //
                        std::cout<<"add "<<turn<<":\nInput a line:";//
                        std::cin>>y;                                //
                        std::cout<<"Input a column:";               //
                        std::cin>>x;                                //
                        if(ttt.add(x,y,turn)){                      //
                            ttt.pDesk();                            //
                            break;                                  //
                        }
                        else
                            std::cout<<"Something went wrong! Do in again!\n";
                    }      
                }
                else{
                    srand(time(NULL));         //COMPUTER'S
                    while(true){               //TURN
                        int x = 0;             //
                        int y = 0;             //   
                        y = 1 + rand() % 3;    //
                        x = 1 + rand() % 3;    //
                        if(ttt.add(x,y,turn)){ //
                            ttt.pDesk();       //
                            break;             //
                        }
                    }
                    
                }
                if(turn == 'O')     //change turn to the oposite char
                        turn = 'X'; //
                    else            //
                        turn = 'O'; //
            }
        }
        else if(typeOfGame == 4){
            while(ttt.check('O') && ttt.check('X')){                
                if(turn == side){                                   //player's
                    while(true){                                    //turn
                        int x = 0;                                  //
                        int y = 0;                                  //
                        std::cout<<"add "<<turn<<":\nInput a line:";//
                        std::cin>>y;                                //
                        std::cout<<"Input a column:";               //
                        std::cin>>x;                                //
                        if(ttt.add(x,y,turn)){                      //
                            ttt.pDesk();                            //
                            break;                                  //
                        }
                        else
                            std::cout<<"Something went wrong! Do in again!\n";
                    }      
                }
                else{
                    for(int i = 1; i <= 3; i++){
                        for(int j = 1; j <= 3; j++){
                            ttt.add(i,j,turn);
                        }       
                    }
                    ttt.pDesk();
                    ttt.check(turn);
                    break;   
                }
                if(turn == 'O')     //change turn to the oposite char
                        turn = 'X'; //
                    else            //
                        turn = 'O'; //
            }
        }   
    }
    else if(typeOfGame == 3)
        return 0;
}
