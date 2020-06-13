//
//  main.cpp
//  HW1_CS201
//
//  Created by crystal on 2019/2/15.
//  Copyright © 2019 crystal. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int NICKEL = 5;
const int DIME = 10;
const int QUARTER = 25;
const int ONE = 100;
const int FIVE = 500;

int nickels=25;
int dimes=25;
int quarters=25;
int ones=0;
int fives=0;


void print_stock()
{
    cout<<"Stock contains:"<<endl;
    cout<<"\t"<<nickels <<" nicekls"<<endl;
    cout<<"\t"<<dimes <<" dimes"<<endl;
    cout<<"\t"<<quarters <<" quarters"<<endl;
    cout<<"\t"<<ones <<" ones"<<endl;
    cout<<"\t"<<fives <<" fives"<<endl<<endl;
}




void print_menu()
{
    cout<<"Menu for deposits: "<<endl;
    cout<<"\t\'n\' - deposit a nickel"<<endl;
    cout<<"\t\'d\' - deposit a dime"<<endl;
    cout<<"\t\'q\' - deposit a quarter"<<endl;
    cout<<"\t\'o\' - deposit a one dollar bill"<<endl;
    cout<<"\t\'f\' - deposit a five dollar bill"<<endl;
    cout<<"\t\'c\' - cancel the purchase"<<endl;
}






int main()
{
    cout<<"Welcome to the vending machine change maker program"<<endl;
    cout<<"Change maker initialized."<<endl;
    print_stock();
    
    
    while(1)
    {
        cout<<"Enter the purchase price (XX.XX) or \'q\' to quit: "<<endl;
        string user_input;
        cin >> user_input;
        if(user_input == "q")
        {
            int total= nickels*NICKEL+dimes*DIME+quarters*QUARTER+ones*ONE+fives*FIVE;
            cout<<"Total: "<<total/100<<" dollars and "<<total%100<<" cents"<<endl;
            break;
        }
        
        //convert datatype from string to double
        stringstream num(user_input);
        double x=0.0;
        num >> x;
        
        //calculate the total cents
        int total_cents = x * 100;
        int original_cents = total_cents;
        //validate the input
        if(total_cents<0 || total_cents%5!=0)
        {
            cout<<"Illegal price: Must be a non-nagetive multiple of 5 cents."<<endl<<endl;
            continue;
        }
        
        print_menu();
        
        while(total_cents>0)
        {
            string deposit;
            
            cout<<"Payment due: "<<total_cents/100<<" dollars and ";
            cout<<total_cents%100<<" cents"<<endl;
            cout<<"Indicate your deposit: ";
            cin>>deposit;
            
            if(deposit=="n")
            {
                total_cents = total_cents - NICKEL;
                nickels++;
            }
            else if(deposit=="d")
            {
                total_cents = total_cents - DIME;
                dimes++;
            }
            else if(deposit=="q")
            {
                total_cents = total_cents - QUARTER;
                quarters++;
            }
            else if(deposit=="o")
            {
                total_cents = total_cents - ONE;
                ones++;
            }
            else if(deposit=="f")
            {
                total_cents = total_cents - FIVE;
                fives++;
            }
            else if(deposit=="c")
            {
                total_cents = -1*(original_cents - total_cents);
                break;
            }
            else
                cout<<"Illegal selection: "<<deposit<<endl;
        }
        
        //print out the change info
        total_cents *= (-1);
    
        cout<<"\nPlease take the change below."<<endl;
        if(total_cents == 0)
        {
            cout<<"No change due."<<endl;
            print_stock();
            continue;
        }
        
        
        
        int quarterNeed = total_cents/QUARTER;
        if(quarterNeed <= quarters && quarterNeed!=0 )
        {
            total_cents -= quarterNeed*QUARTER;
            quarters -= quarterNeed;
            cout<<quarterNeed<<" quarters"<<endl;
        }
        else if(quarterNeed > quarters)
        {
            total_cents -= (quarters*QUARTER);
            cout<<quarters<<" quarters"<<endl;
            quarters = 0;
        }
    
    
    
        int dimeNeed = total_cents/DIME;
        if(dimeNeed <= dimes && dimeNeed!=0 )
        {
            total_cents -= dimeNeed*DIME;
            dimes -= dimeNeed;
            cout<<dimeNeed<<" dimes"<<endl;
        }
        else if(dimeNeed > dimes)
        {
            total_cents -= (dimes*DIME);
            cout<<dimes<<" dimes"<<endl;
            dimes = 0;
        }



        int nickelNeed = total_cents/NICKEL;
        if(nickelNeed <= nickels && nickelNeed!=0 )
        {
            total_cents -= nickelNeed*NICKEL;
            nickels -= nickelNeed;
            cout<<nickelNeed<<" nickels"<<endl;
        }
            else if(nickelNeed > nickels)
        {
            total_cents -= (nickels*NICKEL);
            cout<<nickels<<" nickels"<<endl;
            nickels = 0;
        }

 

        
        if(total_cents>0)
        {
            cout<<"Machine is out of change"<<endl;
            cout<<"See store manager for remaning refund."<<endl;
            cout<<"Amout due is: ";
            if(total_cents/100>0)
            {
                cout<<total_cents/100<<" dollars and ";
                cout<<total_cents%100<<" cents"<<endl;
            }
        }
        print_stock();
    }
    
    return 0;
}
