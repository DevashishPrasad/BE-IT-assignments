#include <iostream>
#include <string.h>

using namespace std;

string l;

/*
Grammar:
E  -->  TE'
E' -->  +TE' | -TE' | e
T  -->  FT'
T' -->  *FT' | /FT' | e
F  -->  digit 
*/

// Definition of T, as per the given production 
bool F(int *i)
{ 
    int idx = 0;
    while(isdigit(l[*i])){
        *i = *i + 1;
        idx++;
    }
    if(idx == 0)
        return false;
    return true;
}  

// Definition of T', as per the given production 
void T_(int *i)
{ 
    if(l[*i] == '*' || l[*i] == '/'){
        *i = *i + 1;
        if(l[*i] == '$'){
            *i = *i - 1;
            return;
        }        
        if(F(i))
            T_(i);
    }
}

// Definition of T, as per the given production 
bool T(int *i)
{ 
    if(F(i)){
        T_(i);
        return true;
    }
    return false;
}  

// Definition of E', as per the given production 
void E_(int *i)
{
    if(l[*i] == '+' || l[*i] == '-'){
        *i = *i + 1;
        if(l[*i] == '$'){
            *i = *i - 1;
            return;
        }
        if(T(i))
            E_(i);
    }
}  

// Definition of E, as per the given production 
void E(int *i)
{ 
    T(i);
    E_(i);
}  

int main() 
{ 
    // Index
    int *i = new int;
    *i = 0;
 
    cout<<"\n Enter the String to check : ";
    cin>>l;
    
    l.append("$");
    // E is a start symbol. 
    E(i); 
    

    if (l[*i] == '$') 
        cout<<"Parsing Successful"; 
    else
        cout<<"Parsing Unsuccessful"; 
}
