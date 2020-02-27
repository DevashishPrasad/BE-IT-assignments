#include <iostream>
#include <string.h>

using namespace std;

string l("i+i$");

// Match function 
void match(char t, int *i) 
{ 
    if (l[i] == t) { 
        //l = getchar(); 
        i++;
    } 
    else
        cout<<"Error"; 
}

// Definition of E' as per the given production 
void E_(int *i)    
{ 
    if (l[i] == '+') { 
        match('+',i); 
        i++;
        match('i',i); 
        E_(); 
    } 
    else
        return; 
}

// Definition of E, as per the given production 
void E(int *i)
{ 
    if (l[i] == 'i') { 
        match('i',&i);     
        E_(&i); 
    }
}  

int main() 
{ 
    int i=0;
    // E is a start symbol. 
    E(&i); 
 
    // if lookahead = $, it represents the end of the string 
    // Here l is lookahead. 
    if (l[i] == '$') 
        cout<<"Parsing Successful"; 
}
