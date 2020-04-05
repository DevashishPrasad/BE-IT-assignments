#include <iostream>
#include <string.h>

using namespace std;

string l;

/*
Grammar:

E --> i E'
E' --> + i E' | e
*/

// Definition of E' as per the given production 
void E_(int *i)    
{ 
    if (l[*i] == '+') {  
        *i = *i + 1;
        if (l[*i] == 'i'){
            *i = *i + 1;
            E_(i);   
        } 
    } 
    else
        return; 
}

// Definition of E, as per the given production 
void E(int *i)
{ 
    if (l[*i] == 'i'){
        *i = *i + 1;
        E_(i); 
    }
}  

int main() 
{ 
    // Index
    int *i = new int;
    *i = 0;
 
    cout<<"\n Enter the String to check : ";
    cin>>l;
    
    // E is a start symbol. 
    E(i); 
        
    //cout<<l;
    // if lookahead = $, it represents the end of the string 
    // Here l is lookahead. 
    if (l[*i] == '$') 
        cout<<"Parsing Successful"; 
    else
        cout<<"Parsing Unsuccessful"; 
}
