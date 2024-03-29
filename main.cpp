
#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner, string &p1_name ,int &rows,int &columns );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

void who_won(char &winner, string &p1_name);
char draw (char TICTAC[][3], char winner, int &row , int &column , string &p1_name );

void playagain(char TICTAC[][3] , char &winner, string &p1_name ,int &row,int &column);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC, winner , row, column, p1_name );
        computer( TICTAC, winner, p1_name , row , column  );

        draw ( TICTAC, winner, row, column, p1_name );
    }
    who_won(winner, p1_name);
    while(1)
  {
    playagain(TICTAC,winner,p1_name ,row,column);
  }
}

//User Defined Functions

//Function to show how the table cells are numbered
void cellnumbers()
{
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
}
//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    if(row<1 || row>3 || column<1 || column>3)
    {
        cout<<"Invalid , Please enter correct row and column again" <<endl ;
        input_r_c(row, column) ;
    }
    return row-1;
    return column-1;
}

//Function to print the tictactoe table after inserting the user's move
void showtable ( char TICTAC[][3])
{
    system("cls");
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and 'X' will be inserted "<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and 'X' will be inserted "<<endl;
        input_r_c (row, column);
        draw ( TICTAC, winner , row, column, p1_name );
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
    }
 draw ( TICTAC, winner , row, column, p1_name );
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );
}

//computer's turn

void computer(char TICTAC[][3], char &winner, string &p1_name , int &row , int &column)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' && gameOver==false)
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        goto check ;

    }
    draw ( TICTAC, winner , row, column, p1_name );
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}
//checking if any of the rows is the same

char check_winner_row(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same

char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}
//function to check who won the game
void who_won (char &winner, string & p1_name )
{
    if(winner == 'X')
        cout<<"  \a Game Over ! \n You won the game , Congratulations ! :)"<<endl;
    else if(winner == 'O')
        cout<<"  \a Game Over ! " <<" \n Computer won the game :) "<<endl;
    else if(winner == 't')
        cout<<"  \a Game Over ! \n TIE :(  "<<endl ;
}
//function to check for ties
char draw (char TICTAC[][3], char winner , int &row , int &column , string &p1_name)
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
         if(winner=='O' || winner=='X')
        {
            who_won(winner, p1_name) ;
            playagain(TICTAC,winner,p1_name ,row,column);
        }
        if(winner!='O' && winner!='X')
        {
            winner = 't';
            gameOver = true ;
            cout<<" \a Game Over \n TIE :( \n ";
    playagain(TICTAC,winner,p1_name ,row,column);

       }
   }
}
//function gives an option to play again

void playagain(char TICTAC[][3] , char &winner, string &p1_name ,int &row,int &column)
{
    char option;
    cout << "Wanna play again? Y for yes, N for no" << endl;
    cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
    {

        cout << "invalid input enter again" << endl;
        cin >> option;
    }
    if (option == 'Y' || option == 'y')
    {
        gameOver = false ;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O');
                TICTAC[i][j] = ' ';
            }
        }
        winner='t';
        goto playagain ;

    }
    else if(option == 'N' || option == 'n')
    {
        exit(0);
    }

    playagain :

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC, winner, row, column, p1_name );
        computer( TICTAC, winner, p1_name ,row , column );
        draw ( TICTAC, winner, row, column, p1_name );
    }
    who_won(winner, p1_name);
}

















/*#include<iostream>
#include<stdlib.h>
#include <ctime>
#include<windows.h>
#include<conio.h>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner , string &p1_name );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

char tie (char TICTAC[][3], char winner  , string p1_name );
void who_won(char &winner, string &p1_name);
//char fuke (char TICTAC[][3], char &winner);
char draw (char TICTAC[][3] , char winner );

void clrscr(void);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );

      //  tie ( TICTAC, winner , p1_name ) ;

        draw ( TICTAC , winner );

        computer( TICTAC, winner , p1_name  );

      //  tie ( TICTAC, winner, p1_name ) ;

        draw ( TICTAC , winner );

//     fuke ( TICTAC , winner) ;
    }
    tie ( TICTAC, winner , p1_name) ;
    draw ( TICTAC , winner );
   // check_winner_row(TICTAC, winner );
    //check_winner_column(TICTAC, winner);
   // check_winner_diagonal(TICTAC, winner );
  //  cout<<winner;

    who_won(winner, p1_name);
    tie ( TICTAC, winner , p1_name ) ;
    draw ( TICTAC , winner );

//   playAgain (row, column, TICTAC, p1_name , winner);

}
//User Defined Functions
//Function to show how the table cells are numbered
void cellnumbers()
{
    //system("cls");
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
}
// system("cls");
//cout<<flush;

//function to clear console screen

//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    if(row<1 || row>3 || column<1 || column>3)
    {
        cout<<"Invalid , Please enter correct row and column again" <<endl ;
        input_r_c(row , column) ;
    }
    return row-1;
    return column-1;
}
//Function to print the tictactoe table after inserting the users' move
void showtable ( char TICTAC[][3])
{
    //system("cls");
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
        input_r_c (row, column);
        tie ( TICTAC,  winner , p1_name );
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        //  player_1(row , column , TICTAC , p1_name , winner);
    }
    tie ( TICTAC,  winner , p1_name );
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

//computer's turn

void computer(char TICTAC[][3], char &winner , string &p1_name)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;

    // cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        //  tie ( TICTAC , winner );
        goto check ;
        // goto full ;

    }
    tie ( TICTAC,  winner , p1_name );
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

char check_winner_row(char TICTAC[][3], char &winner )
{
    //checking if any of the rows is the same
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same
char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}

void who_won (char &winner, string & p1_name)
{
    if(winner == 'X')
        cout<<"  Game Over ! \n" <<p1_name<<" Won the game , Congratulations ! :) "<<endl;
    else if(winner == 'O')
        cout<<"  Game Over ! " <<" \n Computer won the game :) "<<endl;
    else if(winner == 't')
        cout<<"Game Over ! \n TIE :(  "<<endl ;

}
char tie (char TICTAC[][3], char winner ,string p1_name )
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        if(winner=='O' || winner=='X')
        {
            who_won(winner , p1_name) ;
            exit(0);
        }
        else {
            winner = 't';
            gameOver = true ;
            return winner ;
         who_won(winner , p1_name) ;
            exit(0);
           // cout<<"DRAW!";
          //  exit(0) ;
    }
    }
}

char draw (char TICTAC[][3] , char winner )
{
int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner);
    check_winner_diagonal(TICTAC , winner );
        if(winner!='O' && winner!='X')
     {
         winner = 't';
       gameOver = true ;
       cout<<"DRAW!";
        exit(0) ;
     }
       else exit(0) ;
     }

    }
*/
/*
#include<iostream>
#include<stdlib.h>
#include <ctime>
#include<windows.h>
#include<conio.h>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner , string &p1_name );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

char tie (char TICTAC[][3], char winner  , string p1_name );
void who_won(char &winner, string &p1_name);
//char fuke (char TICTAC[][3], char &winner);
char draw (char TICTAC[][3] , char winner );

void clrscr(void);

//void playAgain (int &rows,int &columns,char TICTAC[][3] , string &p1_name , char &winner);
//int input_c(int &column);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

     playagain :

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );

        tie ( TICTAC, winner , p1_name ) ;

        draw ( TICTAC , winner );

        computer( TICTAC, winner , p1_name  );

        tie ( TICTAC, winner, p1_name ) ;

        draw ( TICTAC , winner );

//     fuke ( TICTAC , winner) ;
    }
    tie ( TICTAC, winner , p1_name) ;
    draw ( TICTAC , winner );
  //  check_winner_row(TICTAC, winner );
   // check_winner_column(TICTAC, winner);
   // check_winner_diagonal(TICTAC, winner );
  //  cout<<winner;

    who_won(winner, p1_name);
    tie ( TICTAC, winner , p1_name ) ;
    draw ( TICTAC , winner );

    //option to play again

char option;
  cout << "Wanna play again? Y for yes, N for no" << endl;
  cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
{

cout << "invalid input enter again" << endl;
cin >> option;
// this loop run until user give right input
}
    if (option == 'Y' || option == 'y')
        {
           gameOver = false ;
            for(int i=0 ; i<3 ; i++)
            {
               for(int j=0 ; j<3 ; j++)
               {
                 if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O');
                 TICTAC[i][j] = ' ';
               }
            }
            // winner='t';
           goto playagain ;

        }
    else if(option == 'N' || option == 'n'){
        exit(0);
    }

//   playAgain (row, column, TICTAC, p1_name , winner);

}
//User Defined Functions
//Function to show how the table cells are numbered
void cellnumbers()
{
    //system("cls");
clrscr();
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
}
// system("cls");
//cout<<flush;

//function to clear console screen

//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    return row-1;
    return column-1;
}
//Function to print the tictactoe table after inserting the users' move
void showtable ( char TICTAC[][3] )
{
    //clrscr();
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

//Sleep(100) ;
  //  system(" CLS ");
}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
        input_r_c (row, column);
        tie ( TICTAC,  winner , p1_name );
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        //  player_1(row , column , TICTAC , p1_name , winner);
    }
    tie ( TICTAC,  winner , p1_name );
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

//computer's turn

void computer(char TICTAC[][3], char &winner , string &p1_name)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;

    // cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        //  tie ( TICTAC , winner );
        goto check ;
        // goto full ;

    }
    tie ( TICTAC,  winner , p1_name );
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

char check_winner_row(char TICTAC[][3], char &winner )
{
    //checking if any of the rows is the same
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same
char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}

void who_won (char &winner, string & p1_name)
{
    if(winner == 'X')
        cout<<" \a  Game Over ! \n" <<p1_name<<" Won the game , Congratulations ! :) "<<endl;
    else if(winner == 'O')
        cout<<"  \a Game Over ! " <<" \n Computer won the game :) "<<endl;
 //   else if(winner == 't')
   //     cout<<"Game Over ! \n TIE :(  "<<endl ;

}
char tie (char TICTAC[][3], char winner ,string p1_name )
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        if(winner=='O' || winner=='X')
        {
            who_won(winner , p1_name) ;
            main();
           // exit(0);
        }
        else {
            winner = 't';
            gameOver = true ;
            return winner ;
         who_won(winner , p1_name) ;
            //exit(0);
           // cout<<"DRAW!";
          //  exit(0) ;
    }
    }
}

char draw (char TICTAC[][3] , char winner )
{
int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner);
    check_winner_diagonal(TICTAC , winner );
        if(winner!='O' && winner!='X')
     {
         winner = 't';
       gameOver = true ;
       cout<<" \a Game Over ! \n TIE :(  !";
       //break ;
         //main();
        //exit(0) ;
     }
     //  else exit(0) ;


    }
    }

void clrscr(void)
{
    Sleep(100) ;
    system(" cls ");
    cout<<endl<<endl<<endl;
}
*/








/*
#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner , string &p1_name );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

char tie (char TICTAC[][3], char winner  , string p1_name );
void who_won(char &winner, string &p1_name);
char fuke (char TICTAC[][3], char &winner);
char draw (char TICTAC[][3] , char winner );

//void playAgain (int &rows,int &columns,char TICTAC[][3] , string &p1_name , char &winner);
//int input_c(int &column);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

       playagain :

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC , winner );
        computer( TICTAC, winner , p1_name  );
        draw ( TICTAC , winner );
    }
    who_won(winner, p1_name);

//option to play again

char option;
  cout << "Wanna play again? Y for yes, N for no" << endl;
  cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
{

cout << "invalid input enter again" << endl;
cin >> option;
// this loop run until user give right input
}
    if (option == 'Y' || option == 'y')
        {
           gameOver = false ;
            for(int i=0 ; i<3 ; i++)
            {
               for(int j=0 ; j<3 ; j++)
               {
                 if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O');
                 TICTAC[i][j] = ' ';
               }
            }
             winner='t';
           goto playagain ;

        }
    else if(option == 'N' || option == 'n'){
        exit(0);
    }

}

//User Defined Functions

//Function to show how the table cells are numbered
void cellnumbers()
{
    //system("cls");
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
       // system("cls");
      // cout<<flush;

}
// system("cls");
//cout<<flush;

//function to clear console screen

//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    if(row<1 || row>3 || column<1 || column>3)
    {
        cout<<"Invalid , Please enter correct row and column again" <<endl ;
        input_r_c(row , column) ;
    }
    return row-1;
    return column-1;
}

//Function to print the tictactoe table after inserting the users' move
void showtable ( char TICTAC[][3])
{
    //system("cls");
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
        input_r_c (row, column);
        tie ( TICTAC,  winner , p1_name );
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        //  player_1(row , column , TICTAC , p1_name , winner);
    }
    tie ( TICTAC,  winner , p1_name );
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

//computer's turn

void computer(char TICTAC[][3], char &winner , string &p1_name)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;

    // cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        //  tie ( TICTAC , winner );
        goto check ;
        // goto full ;

    }
    tie ( TICTAC,  winner , p1_name );
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

char check_winner_row(char TICTAC[][3], char &winner )
{
    //checking if any of the rows is the same
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same
char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}

void who_won (char &winner, string & p1_name)
{
    if(winner == 'X')
        cout<<"  Game Over ! \n" <<p1_name<<" Won the game , Congratulations ! :) "<<endl;
    else if(winner == 'O')
        cout<<"  Game Over ! " <<" \n Computer won the game :) "<<endl;
    else if(winner == 't')
        cout<<"Game Over ! \n TIE :(  "<<endl ;

}
char tie (char TICTAC[][3], char winner ,string p1_name )
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        if(winner=='O' || winner=='X')
        {
            who_won(winner , p1_name) ;
            exit(0);
        }
        else {
            winner = 't';
            gameOver = true ;
            return winner ;
         who_won(winner , p1_name) ;
            exit(0);
           // cout<<"DRAW!";
          //  exit(0) ;
    }
    }
}

char draw (char TICTAC[][3] , char winner )
{
int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner);
    check_winner_diagonal(TICTAC , winner );
        if(winner!='O' && winner!='X')
     {
         winner = 't';
       gameOver = true ;
       cout<<"DRAW!";
        exit(0) ;
     }
       else exit(0) ;
     }

    }
*/






/*void playAgain (int &rows,int &columns,char TICTAC[][3] , string &p1_name , char &winner )
{

char option;
  cout << "Wanna play again? Y for yes, N for no" << endl;
  cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
{

cout << "invalid input enter again" << endl;
cin >> option;
// this loop run until user give right input
}
    if (option == 'Y' || option == 'y')
        {
           goto playagain ;
        }
    else if(option == 'N' || option == 'n'){
        exit(0);
    }

}*/







/*
char tie (char TICTAC[][3], char winner )
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        if(winner!='O' && winner!='O')
        {
            winner = 't';
            gameOver = true ;
            return winner ;
            cout<<"DRAW!";
            exit(0) ;
        }

    }
}*/
/*
        full :
if(TICTAC[0][0]=='X' || TICTAC[0][0]=='O' &&
   TICTAC[0][1]=='X' || TICTAC[0][1]=='O' &&
   TICTAC[0][2]=='X' || TICTAC[0][2]=='O' &&
   TICTAC[1][0]=='O' || TICTAC[1][0]=='X' &&
   TICTAC[1][1]=='O' || TICTAC[1][1]=='X' &&
   TICTAC[1][2]=='O' || TICTAC[1][2]=='X' &&
   TICTAC[2][0]=='O' || TICTAC[2][0]=='X' &&
   TICTAC[2][1]=='O' || TICTAC[2][1]=='X' &&
   TICTAC[2][2]=='O' || TICTAC[2][2]=='X'  )
{
    cout<<"tieeeeee";
    exit( 0 );
}
void tie (char TICTAC[][3] , char winner )
{
int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {
       winner = 'c';
       gameOver = true ;
       return winner;
    }
}*/
//function to play again if the user wants
/*
void playAgain (int &rows,int &columns,char TICTAC[][3] , string &p1_name , char &winner )
{

char option;
  cout << "Wanna play again? Y for yes, N for no" << endl;
  cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
{

cout << "invalid input enter again" << endl;
cin >> option;
// this loop run until user give right input
}
    if (option == 'Y' || option == 'y')
        {
    while(!gameOver)
    {
        player_1( rows, columns, TICTAC, p1_name , winner );

        computer( rows, columns, TICTAC , winner  );
    }

    who_won(winner , p1_name);
      //  initializeTable();
     //  startGame(firstPlayer, secondPlayer);
    }
    else if(option == 'N' || option == 'n'){
        exit(0);
    }

}
*/
/*{
    cout<<"Now computer's turn.."<<endl;
    int r =  (rand() % 9 );
    int c =  (rand() % 9 );
    if (r >=1 && r<=3 && c >=1 && c<=3 )
        TICTAC[r][c]='O';
    showtable (  TICTAC  );
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner );
    check_winner_diagonal(TICTAC , winner );

}*/
//we need to implement functions to:
//press a button to play again
//find a sol for system clear to delete only specific things not the whole prev printed things on the console

/*
void computer(int &row,int &column,char TICTAC[][3] , char &winner)
{
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
   // cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    while(TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O')
        {
       int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
  //  cout << "   Computer Move : "<< Move <<" " << movee <<endl;

    if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
   {
       cout << "   Computer Move : "<< Move <<" " << movee <<endl;
       TICTAC[Move-1][movee-1]='O';
   }
        }
 /*  else if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
   {
       int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
    cout << "   Computer Move : "<< Move <<" " << movee <<endl;
     if(TICTAC[Move-1][movee-1]!='X' &&TICTAC[Move-1][movee-1]!='O' )
        {
    TICTAC[Move-1][movee-1]='O';
        }
   }*/
/*   check_winner_row(TICTAC , winner );
   check_winner_column(TICTAC , winner);
   check_winner_diagonal(TICTAC , winner );
   showtable (  TICTAC  );

}
*/
/*
void computer(int &row,int &column,char TICTAC[][3] , char &winner)
{
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
    cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
   {
       TICTAC[Move-1][movee-1]='O';
   }
   else if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
   {
       int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
    cout << "   Computer Move : "<< Move <<" " << movee <<endl;
     if(TICTAC[Move-1][movee-1]!='X' &&TICTAC[Move-1][movee-1]!='O' )
        {
    TICTAC[Move-1][movee-1]='O';
        }
   }
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner);
    check_winner_diagonal(TICTAC , winner );
    showtable (  TICTAC  );

}*/
/* else if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
 {
     cout << "   Computer Move : "<< Move <<" " << movee <<endl;
     TICTAC[Move-1][movee-1]='O';
 }*/
/*   if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
{
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
   // cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' &&TICTAC[Move-1][movee-1]!='O' )
        {
            cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    TICTAC[Move-1][movee-1]='O';
        }
}
if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
   {
       cout << "   Computer Move : "<< Move <<" " << movee <<endl;
       TICTAC[Move-1][movee-1]='O';
   }
   else if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
{
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
    cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' &&TICTAC[Move-1][movee-1]!='O' )
        {
    TICTAC[Move-1][movee-1]='O';
        }
}*/
/*
char fuke (char TICTAC[][3], char &winner)
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {

    if( check_winner_column(TICTAC , winner) ||
   check_winner_row(TICTAC , winner) ||
   check_winner_diagonal(TICTAC , winner) !='X'
   && check_winner_column(TICTAC , winner)
    || check_winner_row(TICTAC , winner)
    || check_winner_diagonal(TICTAC , winner) !='O'  )

   {
    winner = 't' ;
return winner ;
   }
}
}*/
/*
char draw (char TICTAC[][3] , char winner )
{
int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner);
    check_winner_diagonal(TICTAC , winner );
        if(winner!='O' && winner!='O')
     {
         winner = 't';
       gameOver = true ;
       cout<<"DRAW!";
       else exit(0) ;
     }

    }
}
*/


























/*
#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner , string &p1_name );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

char tie (char TICTAC[][3], char winner  , string p1_name );
void who_won(char &winner, string &p1_name);
char fuke (char TICTAC[][3], char &winner);
char draw (char TICTAC[][3] , char winner );

//void playAgain (int &rows,int &columns,char TICTAC[][3] , string &p1_name , char &winner);
//int input_c(int &column);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

       playagain :

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC , winner );
        computer( TICTAC, winner , p1_name  );
        draw ( TICTAC , winner );
    }
    who_won(winner, p1_name);

//option to play again

char option;
  cout << "Wanna play again? Y for yes, N for no" << endl;
  cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
{

cout << "invalid input enter again" << endl;
cin >> option;
// this loop run until user give right input
}
    if (option == 'Y' || option == 'y')
        {
           gameOver = false ;
            for(int i=0 ; i<3 ; i++)
            {
               for(int j=0 ; j<3 ; j++)
               {
                 if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O');
                 TICTAC[i][j] = ' ';
               }
            }
             winner='t';
           goto playagain ;

        }
    else if(option == 'N' || option == 'n'){
        exit(0);
    }

}

//User Defined Functions

//Function to show how the table cells are numbered
void cellnumbers()
{
    //system("cls");
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
       // system("cls");
      // cout<<flush;

}
// system("cls");
//cout<<flush;

//function to clear console screen

//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    if(row<1 || row>3 || column<1 || column>3)
    {
        cout<<"Invalid , Please enter correct row and column again" <<endl ;
        input_r_c(row , column) ;
    }
    return row-1;
    return column-1;
}

//Function to print the tictactoe table after inserting the users' move
void showtable ( char TICTAC[][3])
{
    //system("cls");
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and 'X' will be inserted"<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and 'X' will be inserted"<<endl;
        input_r_c (row, column);
        tie ( TICTAC,  winner , p1_name );
        draw(TICTAC , winner ) ;
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        //  player_1(row , column , TICTAC , p1_name , winner);
    }
    tie ( TICTAC,  winner , p1_name );
    draw(TICTAC , winner ) ;
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

//computer's turn

void computer(char TICTAC[][3], char &winner , string &p1_name)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;

    // cout << "   Computer Move : "<< Move <<" " << movee <<endl;
    if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' )
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        //  tie ( TICTAC , winner );
        goto check ;
        // goto full ;

    }
    tie ( TICTAC,  winner , p1_name );
    draw(TICTAC , winner ) ;
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}

char check_winner_row(char TICTAC[][3], char &winner )
{
    //checking if any of the rows is the same
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same
char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}

void who_won (char &winner, string & p1_name)
{
    if(winner == 'X')
        cout<<"  Game Over ! \n" <<p1_name<<" Won the game , Congratulations ! :) "<<endl;
    else if(winner == 'O')
        cout<<"  Game Over ! " <<" \n Computer won the game :) "<<endl;
    else if(winner == 't')
        cout<<"Game Over ! \n TIE :(  "<<endl ;

}
char tie (char TICTAC[][3], char winner ,string p1_name )
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
        if(winner=='O' || winner=='X')
        {
            who_won(winner , p1_name) ;
           // exit(0);
        }
        else {
            winner = 't';
            gameOver = true ;
             who_won(winner , p1_name) ;
            return winner ;

          //  exit(0);
           // cout<<"DRAW!";
          //  exit(0) ;
    }
    }
}

char draw (char TICTAC[][3] , char winner )
{
int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
    for(int j=0 ; j<3 ; j++)
       {
        if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
            counter+=1;
       }
    }
    if ( counter == 9 )
    {
    check_winner_row(TICTAC , winner );
    check_winner_column(TICTAC , winner);
    check_winner_diagonal(TICTAC , winner );
        if(winner!='O' && winner!='X')
     {
         winner = 't';
       gameOver = true ;
       cout<<"DRAW!";
        exit(0) ;
     }
     //  else exit(0) ;
     }

    }
*/
/*
#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner, string &p1_name ,int &rows,int &columns );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

void who_won(char &winner, string &p1_name);
char draw (char TICTAC[][3], char winner, int &row , int &column , string &p1_name );

void playagain(char TICTAC[][3] , char &winner, string &p1_name ,int &row,int &column);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC, winner , row, column, p1_name );
        computer( TICTAC, winner, p1_name , row , column  );
        draw ( TICTAC, winner, row, column, p1_name );
    }
    who_won(winner, p1_name);
    while(1)
  {
    playagain(TICTAC,winner,p1_name ,row,column);
  }
}

//User Defined Functions

//Function to show how the table cells are numbered
void cellnumbers()
{
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
}
//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    if(row<1 || row>3 || column<1 || column>3)
    {
        cout<<"Invalid , Please enter correct row and column again" <<endl ;
        input_r_c(row, column) ;
    }
    return row-1;
    return column-1;
}

//Function to print the tictactoe table after inserting the user's move
void showtable ( char TICTAC[][3])
{
    system("cls");
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
        input_r_c (row, column);
        draw ( TICTAC, winner , row, column, p1_name );
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
    }
 draw ( TICTAC, winner , row, column, p1_name );
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );
}

//computer's turn

void computer(char TICTAC[][3], char &winner, string &p1_name , int &row , int &column)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' && gameOver==false)
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        goto check ;

    }
    draw ( TICTAC, winner , row, column, p1_name );
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}
//checking if any of the rows is the same

char check_winner_row(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same

char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}
//function to check who won the game
void who_won (char &winner, string & p1_name )
{
    if(winner == 'X')
        cout<<"  \a Game Over ! \n" <<p1_name<<" Won the game , Congratulations ! :)"<<endl;
    else if(winner == 'O')
        cout<<"  \a Game Over ! " <<" \n Computer won the game :) "<<endl;
    else if(winner == 't')
        cout<<"  \a Game Over ! \n TIE :(  "<<endl ;
}
//function to check for ties
char draw (char TICTAC[][3], char winner , int &row , int &column , string &p1_name)
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
         if(winner=='O' || winner=='X')
        {
            who_won(winner, p1_name) ;
            playagain(TICTAC,winner,p1_name ,row,column);
        }
        if(winner!='O' && winner!='X')
        {
            winner = 't';
            gameOver = true ;
            cout<<" \a Game Over \n TIE :( \n ";
    playagain(TICTAC,winner,p1_name ,row,column);

       }
   }
}
//function gives an option to play again

void playagain(char TICTAC[][3] , char &winner, string &p1_name ,int &row,int &column)
{
    char option;
    cout << "Wanna play again? Y for yes, N for no" << endl;
    cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
    {

        cout << "invalid input enter again" << endl;
        cin >> option;
    }
    if (option == 'Y' || option == 'y')
    {
        gameOver = false ;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O');
                TICTAC[i][j] = ' ';
            }
        }
        winner='t';
        goto playagain ;

    }
    else if(option == 'N' || option == 'n')
    {
        exit(0);
    }playagain :
cellnumbers();
while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC, winner, row, column, p1_name );
        computer( TICTAC, winner, p1_name ,row , column );
        draw ( TICTAC, winner, row, column, p1_name );
    }
    who_won(winner, p1_name);
}
#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std ;

bool gameOver = false;

//Function Prototypes

void cellnumbers();
void showtable (char TICTAC[][3]);

int input_r_c(int &row, int &column);

void player_1(int &rows,int &columns,char TICTAC[][3], string &p1_name, char &winner );
void computer(char TICTAC[][3], char &winner, string &p1_name ,int &rows,int &columns );

char check_winner_row(char TICTAC[][3], char &Winner );
char check_winner_column(char TICTAC[][3], char &Winner);
char check_winner_diagonal(char TICTAC[][3], char &Winner);

void who_won(char &winner, string &p1_name);
char draw (char TICTAC[][3], char winner, int &row , int &column , string &p1_name );

void playagain(char TICTAC[][3] , char &winner, string &p1_name ,int &row,int &column);

int main ()
{
    cout<<endl<<"                                                Tic Tac Toe Game"<<endl<<endl;
    cout<<"  Please enter your name : ";
    string p1_name ;
    cin>>p1_name;
    cout<<"  " << p1_name <<" : ( X )         VS         Computer : ( O ) " <<endl;
    char TICTAC[3][3]= { {}, {}, {} }, winner='t';
    int row, column;

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC, winner , row, column, p1_name );
        computer( TICTAC, winner, p1_name , row , column  );
        draw ( TICTAC, winner, row, column, p1_name );
    }
    who_won(winner, p1_name);
    while(1)
  {
    playagain(TICTAC,winner,p1_name ,row,column);
  }
}

//User Defined Functions

//Function to show how the table cells are numbered
void cellnumbers()
{
    cout<<"  please enter the rows and columns according to this figure : "<<endl;
    cout <<"                       |     |     "<<endl
         <<"                   1,1 | 1,2 | 1,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   2,1 | 2,2 | 2,3 "<<endl
         <<"                  _____|_____|_____"<<endl
         <<"                       |     |     "<<endl
         <<"                   3,1 | 3,2 | 3,3 "<<endl
         <<"                       |     |     "<<endl;
}
//Function to input the desired position of the player and return the row and column values
int input_r_c (int &row, int &column)
{
    cin>>row>>column;
    if(row<1 || row>3 || column<1 || column>3)
    {
        cout<<"Invalid , Please enter correct row and column again" <<endl ;
        input_r_c(row, column) ;
    }
    return row-1;
    return column-1;
}

//Function to print the tictactoe table after inserting the user's move
void showtable ( char TICTAC[][3])
{
    system("cls");
    cout<<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[0][0]<<"  |  "<<TICTAC[0][1]<<"  |  "<<TICTAC[0][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[1][0]<<"  |  "<<TICTAC[1][1]<<"  |  "<<TICTAC[1][2]<<endl
        <<"                  _____|_____|_____"                                             <<endl
        <<"                       |     |     "                                             <<endl
        <<"                    "<<TICTAC[2][0]<<"  |  "<<TICTAC[2][1]<<"  |  "<<TICTAC[2][2]<<endl
        <<"                       |     |     "                                             <<endl;

}

//Functions to check if there is a winner

void player_1(int &row,int &column,char TICTAC[][3],string &p1_name, char &winner )
{
    cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
    input_r_c (row, column);

    if(TICTAC[row-1][column-1]== 'X' || TICTAC[row-1][column-1]== 'O')
    {
        cout<<"   Invalid move, try again.\n";
        cout<<"  "<<p1_name<<" , please choose your position and insert 'X' "<<endl;
        input_r_c (row, column);
        draw ( TICTAC, winner , row, column, p1_name );
        TICTAC[row-1][column-1]='X';
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
    }
 draw ( TICTAC, winner , row, column, p1_name );
    TICTAC[row-1][column-1]='X';
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );
}

//computer's turn

void computer(char TICTAC[][3], char &winner, string &p1_name , int &row , int &column)
{
check :
    srand(time(0));
    int  Move = rand() % 3 +1;
    int  movee = rand() % 3 + 1;
if(TICTAC[Move-1][movee-1]!='X' && TICTAC[Move-1][movee-1]!='O' && gameOver==false)
    {
        cout << "   Computer Move : "<< Move <<" " << movee <<endl;
        TICTAC[Move-1][movee-1]='O';
    }
    else  if (TICTAC[Move-1][movee-1]=='X' || TICTAC[Move-1][movee-1]=='O' )
    {
        goto check ;

    }
    draw ( TICTAC, winner , row, column, p1_name );
    check_winner_row(TICTAC, winner );
    check_winner_column(TICTAC, winner);
    check_winner_diagonal(TICTAC, winner );
    showtable (  TICTAC  );


}
//checking if any of the rows is the same

char check_winner_row(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[i][0]==TICTAC[i][1] && TICTAC[i][1]==TICTAC[i][2])
        {
            if(TICTAC[i][0]=='X' || TICTAC[i][0]=='O' )
            {
                winner = TICTAC[i][0];
                gameOver=true ;
                return winner ;
                exit(0);
            }
        }
    }

}
//checking if any of the columns is the same

char check_winner_column(char TICTAC[][3], char &winner )
{
    for(int i=0 ; i<3 ; i++)
    {
        if( TICTAC[0][i]==TICTAC[1][i] && TICTAC[1][i]==TICTAC[2][i])
        {
            if( TICTAC[0][i]=='X' || TICTAC[0][i]=='O' )
            {
                winner = TICTAC[0][i];
                gameOver=true ;
                return winner;
                exit(0);
            }
        }
    }

}
//checking both diagonals
char check_winner_diagonal(char TICTAC[][3], char &winner )
{
    if( TICTAC[0][0]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][2] )
    {
        if (TICTAC[0][0]=='X' || TICTAC[0][0]=='O')
        {
            winner = TICTAC[0][0];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }
    if( TICTAC[0][2]==TICTAC[1][1] && TICTAC[1][1]==TICTAC[2][0])
    {
        if( TICTAC[0][2]=='X' || TICTAC[0][2]=='O'  )

        {
            winner = TICTAC[0][2];
            gameOver=true ;
            return winner ;
            exit(0);
        }
    }

}
//function to check who won the game
void who_won (char &winner, string & p1_name )
{
    if(winner == 'X')
        cout<<"  \a Game Over ! \n" <<p1_name<<" Won the game , Congratulations ! :)"<<endl;
    else if(winner == 'O')
        cout<<"  \a Game Over ! " <<" \n Computer won the game :) "<<endl;
    else if(winner == 't')
        cout<<"  \a Game Over ! \n TIE :(  "<<endl ;
}
//function to check for ties
char draw (char TICTAC[][3], char winner , int &row , int &column , string &p1_name)
{
    int counter=0;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O')
                counter+=1;
        }
    }
    if ( counter == 9 )
    {
        check_winner_row(TICTAC, winner );
        check_winner_column(TICTAC, winner);
        check_winner_diagonal(TICTAC, winner );
         if(winner=='O' || winner=='X')
        {
            who_won(winner, p1_name) ;
            playagain(TICTAC,winner,p1_name ,row,column);
        }
        if(winner!='O' && winner!='X')
        {
            winner = 't';
            gameOver = true ;
            cout<<" \a Game Over \n TIE :( \n ";
    playagain(TICTAC,winner,p1_name ,row,column);

       }
   }
}
//function gives an option to play again

void playagain(char TICTAC[][3] , char &winner, string &p1_name ,int &row,int &column)
{
    char option;
    cout << "Wanna play again? Y for yes, N for no" << endl;
    cin >> option;

    while(option != 'Y' && option != 'y' && option != 'N' && option != 'n')
    {

        cout << "invalid input enter again" << endl;
        cin >> option;
    }
    if (option == 'Y' || option == 'y')
    {
        gameOver = false ;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(TICTAC[i][j]=='X' || TICTAC[i][j]=='O');
                TICTAC[i][j] = ' ';
            }
        }
        winner='t';
        goto playagain ;

    }
    else if(option == 'N' || option == 'n')
    {
        exit(0);
    }

    playagain :

    cellnumbers();

    while(!gameOver)
    {
        player_1( row, column, TICTAC, p1_name, winner );
        draw ( TICTAC, winner, row, column, p1_name );
        computer( TICTAC, winner, p1_name ,row , column );
        draw ( TICTAC, winner, row, column, p1_name );
    }
    who_won(winner, p1_name);
}
*/
