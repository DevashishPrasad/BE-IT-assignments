#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Book
{
    char *name;
    char *auth;
    char *publish;
    int *stk;
    float *price;
    
    public:
    static int trans;
    static int cost;
    
    // constructor
    Book()
    {
        name = new char[100];
        auth = new char[100];
        publish = new char[100];
        stk = new int;
        price = new float;
    }
    void add()
    {
        cout<<"\n\n\nEnter the details for the book- ";
        cout<<"\nTitle : ";
        cin>>name;
        cout<<"\nAuthor : ";
        cin>>auth;
        cout<<"\nPublisher :";
        cin>>publish;
        cout<<"\nStock : ";
        cin>>*stk;
        cout<<"\nPrice : ";
        cin>>*price;
    }
    void display()
    {
        cout<<"\n"<<name<<"\t"<<auth<<"\t"<<publish<<"\t\t"<<*stk<<"\t"<<*price;
    }
    bool search(char *temp)
    {
        if(!strcmp(name,temp))
            return true;
        return false;
    }
    void modify()
    {
        cout<<endl<<"The book found -";
        display();
        add();
    }
    void purchase()
    {
        cout<<endl<<"The book found -";
        display();
        int stock;
        cout<<endl<<"Enter the number of books you want to purchase - ";
        cin>>stock;
        if(stock<=*stk)
        {
              *stk -= stock;
              Book::trans ++;
              Book::cost += stock*(*price);
              cout<<endl<<"Books purchased successfully";
        }
        else
              cout<<endl<<"Sry, the amount of books requested is not available";                    
              
    }
};

int Book::trans=0;
int Book::cost=0;

int main()
{
    Book b[50] ;
    char *temp;
    int max, i, ch, n, flg;
    cout<<"\nEnter the number of books to be entered in the database - ";
    cin>>max;

    for(i=0; i<max; i++)
        b[i].add();
        
    cout<<"\nDatabase created successfully ";
    
    do
    {
        cout<<"\n\n\n\n *******  MENU  *******";
        cout<<"\n 1. ADD a book";
        cout<<"\n 2. DISPLAY all books";
        cout<<"\n 3. SEARCH a book";
        cout<<"\n 4. MODIFY a book";
        cout<<"\n 5. PURCHASE books";        
        cout<<"\n 6. BILL(checkout)";
        cout<<"\n 7. TRANSACTIONS";        
        cout<<"\n 8. EXIT";
        cout<<"\n Enter your choice - ";
        cin>>ch;
        
        switch(ch)
        {
            case 1: 
                    cout<<"\n Enter the number of books to be added - ";
                    cin>>n;
                    for(i=max; i<max+n; i++)
                        b[i].add();
                    max += n;
                    cout<<"\n Books added sucessfully";
                    break;
            case 2:
                    cout<<"\n Displaying all books in database";
                    cout<<"\nName\tAuthor\tPublisher\tStock\tPrice";        
                    for(i=0; i<max; i++)
                        b[i].display();
                    break;
            case 3:
                    flg = 0;
                    temp = new char[100];
                    cout<<"\n Enter the name of book you want to search - ";
                    cin>>temp;
                    cout<<"\nName\tAuthor\tPublisher\tStock\tPrice";        
                    for(i=0; i<max; i++)
                    {
                            if(b[i].search(temp))
                            {
                                b[i].display();
                                flg=1;
                                break;
                            }
                    }
                    if(!flg) cout<<"\nNo books found with name "<<temp;
                    delete temp;
                    break;
            case 4:
                    flg = 0;
                    temp = new char[100];
                    cout<<"\n Enter the name of the book you want to modify - ";
                    cin>>temp;
                    for(i=0; i<max; i++)
                    {
                            if(b[i].search(temp))
                            {
                                b[i].modify();
                                flg=1;
                            }
                    }
                    if(!flg) cout<<"\nNo books found with name "<<temp;
                    delete temp;
                    break;
            case 5:
                    flg = 0;
                    temp = new char[100];
                    cout<<"\n Enter the name of the book you want to purchase - ";
                    cin>>temp;
                    for(i=0; i<max; i++)
                    {
                            if(b[i].search(temp))
                            {
                                b[i].purchase();
                                flg=1;
                            }
                    }
                    break;
            case 6:
                    cout<<"\n Your total amount of purchase is - "<<Book::cost<<"/-";
                    cout<<"\n Checkedout out successfully";
                    Book::trans=0;
                    Book::cost=0;
                    break;
            case 7:
                    cout<<endl<<"Your transactions = "<<Book::trans; 
                    break;
            case 8: 
                    return 0;
            default:
                    cout<<"\nPlease, enter a valid choice";
        }
    }while(1);
    
    return 0;
}

