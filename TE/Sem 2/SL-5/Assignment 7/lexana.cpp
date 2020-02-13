#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;

vector<string> identifiers,operators,constants,keywords,c_keywords,c_operators;

// Function for Trimimg
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

short int is_op(string op){
    for(short int i=0;i<c_operators.size();i++){
        if(op == c_operators[i]){
            if(i<4)
                return 0;
            return 1;
        }
    }
    return 2;
}

bool is_char(){

}

void regex(string line){
    line = trim(line);
    string op="00";
    string chars="";
    for(int i=0;i<line.length();i++){
        
        // operators
        if(is_op(string(1,line[i]))==1){
            operators.push_back(string(line[i],1));
        }
        else if(is_op((char*)&line[i])==0){
            if(line[i]==line[i+1]){
                op[0]=line[i];
                op[1]=line[i+1];
                operators.push_back(op);
                i++;
            }
        }
        
        // characters
        chars[i]=line[i];
    }
}

int main(){
    // declare variables    
    string buffer;

    // populate keywords
    c_keywords.push_back("include");
    c_keywords.push_back("vector");
    c_keywords.push_back("string.h");        
    c_keywords.push_back("fstream");
    c_keywords.push_back("string.h");
    c_keywords.push_back("using");            
    c_keywords.push_back("namespace");
    c_keywords.push_back("int");
    c_keywords.push_back("return");
                    
    // populate operators
    c_operators.push_back("+");
    c_operators.push_back("-");
    c_operators.push_back(">");
    c_operators.push_back("<");
    c_operators.push_back("#");    
    c_operators.push_back("/");
    c_operators.push_back("*");
    c_operators.push_back("%");
    c_operators.push_back("{");
    c_operators.push_back("}");
    c_operators.push_back(";"); 
    c_operators.push_back("-");
    c_operators.push_back("(");                                           
    c_operators.push_back(")");

    ifstream ifile("lexana.cpp");
    
    while(getline(ifile,buffer)){
        regex(buffer);
    }
    
    ifile.close();
 
    ofstream ofile("output.txt");
    for(int i=0;i<operators.size();i++)
        ofile<<operators[i]<<"\n";
	return 0;
}
