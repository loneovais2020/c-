#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <random>
using namespace std;
    fstream file("history.txt",ios::in|ios::out|ios::app);
    time_t my_time= time(NULL);
class Tic_Tac_Toe{
    char board[9]={' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};
    void player_vs_player(){
    string x_player_name , o_player_name;
    cout<<"Enter X player name: ";
    cin>>x_player_name;
    cout<<"Enter o player name: ";
    cin>>o_player_name;
    while(true){
        system("cls");
        show_board();
        if (count_board('X') == count_board('o'))
        {
            cout<<x_player_name<<"'s turn."<<endl;
            get_x_player_choice();
        }
        else
        {
            cout<<o_player_name<<"'s turn."<<endl;
            get_o_player_choice();
        }
         char winner=check_winner();
     if (winner=='X')
     {
         system("cls");
         show_board();
         cout<<x_player_name<<" won the game."<<endl;
         file<<x_player_name<<" won the game at"<<ctime(&my_time)<<endl;
    
        
         break;
     }
     else if (winner == 'o')
     {
         system("cls");
         show_board();
         cout<<o_player_name<<" won the game."<<endl;
         file<<o_player_name<<" won the game at"<<ctime(&my_time)<<endl;
         break;
     }
     else if (winner == 'D')
     {
         cout<<"Game is draw."<<endl;
         file<<"Game is draw at "<<ctime(&my_time)<<endl;
         break;
     }
    }

}

void computer_vs_player(){
    string player_name;
    cout<<"Enter your name: ";
    cin>>player_name;
    while (true)
    {
     system("cls");
     show_board();
     if (count_board('X') == count_board('o'))
     {
         cout<<player_name<<"'s turn."<<endl;
         get_x_player_choice();
     }
     else{
         get_computer_choice();
     }
     char winner=check_winner();
     if (winner=='X')
     {
         system("cls");
         show_board();
         cout<<player_name<<" won the game."<<endl;
         file<<player_name<<" won the game at "<<ctime(&my_time)<<endl;
     
      
         break;
     }
     else if (winner == 'o')
     {
         system("cls");
         show_board();
         cout<<"Computer  won the game."<<endl;
         file<<"Computer  won the game at "<<ctime(&my_time)<<endl;
         break;
     }
     else if (winner == 'D')
     {
         cout<<"Game is draw."<<endl;
         file<<"Game is draw at "<<ctime(&my_time)<<endl;
         break;
     }
     
     
     
    }
    
}

void get_computer_choice(){
srand(time(0));
int choice;
do
{
    choice=rand()%10;
} while (board[choice]!=' ');
board[choice]='o';

}
void get_x_player_choice(){
while (true)
{
    cout<<"Select your position(1-9) : ";
    int choice;
    cin>>choice;
    choice--;
    if (choice < 0 || choice > 8)
    {
        cout<<"Please select your choice from (1-9)."<<endl;
    }
    else if(board[choice]!=' '){
        cout<<"PLease select an empty position."<<endl;

    }
    else
    {
        board[choice]='X';
        break;
    }
    
    
}

}
void get_o_player_choice(){
while (true)
{
    cout<<"Select your position(1-9) : ";
    int choice;
    cin>>choice;
    choice--;
    if (choice < 0 || choice > 8)
    {
        cout<<"Please select your choice from (1-9)."<<endl;
    }
    else if(board[choice]!=' '){
        cout<<"PLease select an empty position."<<endl;

    }
    else
    {
        board[choice]='o';
        break;
    }
    
    
}

}
int count_board(char symbol){
    int total=0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i]==symbol)
        {
            total+=1;
        }
        
    }
    return total;

}

char check_winner(){
    // checking winner in horizontal direction 
    if (board[0]==board[1] && board[1]==board[2] && board[0]!=' ')
    {
        return board[0];
    }
    if (board[3]==board[4] && board[4]==board[5] && board[3]!=' ')
    {
        return board[3];
    }
    if (board[6]==board[7] && board[7]==board[8] && board[6]!=' ')
    {
        return board[6];
    }
        // checking winner in vertical direction 
        if (board[0]==board[3] && board[3]==board[6] && board[0]!=' ')
    {
        return board[0];
    }
    if (board[1]==board[4] && board[4]==board[7] && board[1]!=' ')
    {
        return board[1];
    }
    if (board[2]==board[5] && board[5]==board[8] && board[2]!=' ')
    {
        return board[2];
    }
            // checking winner in diagonal direction 
           if (board[0]==board[4] && board[4]==board[8] && board[0]!=' ')
    {
        return board[0];
    }
    if (board[2]==board[4] && board[4]==board[6] && board[2]!=' ')
    {
        return board[2];
    }
    if (count_board('X') + count_board('o') < 9){
        return 'C';

    }
    else
    {
        return 'D';
    }

}
void show_history(){
file.seekg(0);
string history;
while (file.good())
{
    getline(file,history);
    cout<<history<<endl;
}

}
void show_board(){
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[0]<<"  |   "<<board[1]<<"  |   "<<board[2]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[3]<<"  |   "<<board[4]<<"  |   "<<board[5]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[6]<<"  |   "<<board[7]<<"  |   "<<board[8]<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
   
}
friend int main();
};


int main(){
Tic_Tac_Toe t1;
char return_back;
int mode;
cout<<"1. computer vs player"<<endl;
cout<<"2. player vs player"<<endl;
cout<<"3. history"<<endl;
cout<<"select game mode."<<endl;
cin>>mode;
switch (mode)
{
case 1:
    t1.computer_vs_player();
    break;
case 2:
    t1.player_vs_player();
    break;
case 3:
    t1.show_history();
    break;

default:
cout<<"Enter a valid choice."<<endl;
    break;
}
cout<<"Enter Y to return to main menu\nEnter N to exit program ";
cin>>return_back;
if (return_back=='Y'||return_back=='y')
{
    exit(main());
}
else{
    exit(1);
}

return 0;
}

