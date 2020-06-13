#include <iostream>
using namespace std;

void display_board(char a[3][3]);
bool winP1(char a[3][3]);
bool winP2(char a[3][3]);
bool isFull(char a[3][3]);

int main()
{
    bool P1=true;
    bool P2=false;
    int r,c;
    char board[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3;j++)
            board[i][j]='*';
    }
    display_board(board);
    
    while(isFull(board)==false && winP1(board)==false && winP2(board)==false)
    {
        while(P1==true && isFull(board)==false)
        {
            cout<<"Player X turn:";
            cin>>r>>c;
            while(board[r-1][c-1]!='*')
            {
                cout<<"Invalide input, please reenter:";
                cin>>r>>c;
            }
            board[r-1][c-1]='X';
            display_board(board);
            
            if(winP1(board))
            {
                cout<<"Player X won."<<endl;
                break;
            }
            
            P1=false;
            P2=true;
            
        }
        while(P2==true && isFull(board)==false)
        {
            cout<<"Player O turn:";
            cin>>r>>c;
            while(board[r-1][c-1]!='*')
            {
                cout<<"Invalide input, please reenter:";
                cin>>r>>c;
            }
            board[r-1][c-1]='O';
            display_board(board);
            
            if(winP2(board))
            {
                cout<<"Player O won."<<endl;
                break;
            }
        
            P1=true;
            P2=false;
        }
    }
    
    if(isFull(board))
        cout<<"A tie has occured"<<endl;
    
    return 0;
}


void display_board(char a[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}


bool winP1(char a[3][3])
{
    //three rows
    if(a[0][0]=='X' && a[0][1]=='X' && a[0][2]=='X')
        return true;
    else if(a[1][0]=='X' && a[1][1]=='X' && a[1][2]=='X')
        return true;
    else if(a[2][0]=='X' && a[2][1]=='X' && a[2][2]=='X')
        return true;
    
    //tree columns
    else if(a[0][0]=='X' && a[1][0]=='X' && a[2][0]=='X')
        return true;
    else if(a[0][1]=='X' && a[1][1]=='X' && a[2][1]=='X')
        return true;
    else if(a[0][2]=='X' && a[1][2]=='X' && a[2][2]=='X')
        return true;
    
    //two crosses
    else if(a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X')
        return true;
    else if(a[2][0]=='X' && a[1][1]=='X' && a[0][2]=='X')
        return true;
    else
        return false;
}


bool winP2(char a[3][3])
{
    if(a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O')
        return true;
    else if(a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O')
        return true;
    else if(a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O')
        return true;
    
    else if(a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O')
        return true;
    else if(a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O')
        return true;
    else if(a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O')
        return true;
    
    else if(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O')
        return true;
    else if(a[2][0]=='O' && a[1][1]=='O' && a[0][2]=='O')
        return true;
    else
        return false;
}



bool isFull(char a[3][3])
{
    int count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j] != '*')
                count++;
        }
    }
    if(count==9)
    {
        return true;
    }
    else
        return false;
}
