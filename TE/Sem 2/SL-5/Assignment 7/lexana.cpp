#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;

vector<string> output,identifiers,operators,constants,keywords,c_keywords,c_operators,c_double_operators;

// Function for Trimimg
string trim(const string& str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Function to check double operator
bool is_double_op(string op){
    for(short int i=0;i<c_double_operators.size();i++)
        if(op.compare(c_operators[i]) == 0)
            return true;
    return false;
}

// Function to check single operator
bool is_op(char op){
    for(short int i=0;i<c_operators.size();i++)
        if(string(1,op).compare(c_operators[i]) == 0)
            return true;
    return false;
}

// Function to check keyword
bool is_keyword(string word){
    cout<<word<<"\n";
    for(short int i=0;i<c_keywords.size();i++)
        if(word.compare(c_keywords[i]))
            return true;
    return false;
}

// Function to check separator
bool is_separator(char a){
    if(a == ' ')
        return true;
    else if(a == ',')
        return true;
    return false;
}

// Function to check constants
bool is_const(string word){
   short int flg = 0;
   for(short int i=0;i<word.length();i++)
        if( word[i] == 0 || word[i] == 1 || word[i] == 2 || word[i] == 3 || 
            word[i] == 4 || word[i] == 5 || word[i] == 6 || word[i] == 7 || 
            word[i] == 8 || word[i] == 9)
            flg=1;
        else
            flg=0;
   if(flg)
        return true;  
}

// Function to process lines
void regex(string line){
    line = trim(line);    
    string chars="";
    int idx;
    for(int i=0;i<line.length();i++){
        if(is_double_op(line.substr(i,2))){
            operators.push_back(line.substr(i,2));
            output.push_back(line.substr(i,2).append(string("\t : Operator")));
            i++;
            if(chars.length()>0){
                if(is_keyword(chars)){
                    keywords.push_back(chars);
                    output.push_back(string(line[i],1).append(string("\t : Keyword")));
                    chars = "";                    
                }
                else if(is_const(chars)){
                    constants.push_back(chars);
                    output.push_back(string(1,line[i]).append(string("\t : Constant")));
                    chars = "";                    
                }
            }
        }
        else if(is_op(line[i])){
            operators.push_back(string(1,line[i]));
            output.push_back(string(1,line[i]).append(string("\t : Operator")));
            if(chars.length()>0){
                if(is_keyword(chars)){
                    keywords.push_back(chars);
                    output.push_back(string(1,line[i]).append(string("\t : Keyword")));
                    chars = "";                    
                }
                else if(is_const(chars)){
                    constants.push_back(chars);
                    output.push_back(string(1,line[i]).append(string("\t : Constant")));
                    chars = "";                    
                }
            }
        }
        else if(is_separator(line[i]) && chars.length()>0){
            if(is_keyword(chars)){
                keywords.push_back(chars);
                output.push_back(string(1,line[i]).append(string("\t : Keyword")));
            }
            else if(is_const(chars)){
                constants.push_back(chars);
                output.push_back(string(1,line[i]).append(string("\t : Constant")));
            }
            chars = "";
        }
        
        // characters
        chars.append(string(1,line[i]));
        cout<<chars<<"\n";        
    }
}

// Main funtion of the program
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
    c_keywords.push_back("if");
    c_keywords.push_back("else");
    c_keywords.push_back("void");
    c_keywords.push_back("bool");
    c_keywords.push_back("true");             
    
    // populate operators
    c_operators.push_back("\"");
    c_operators.push_back("'");   
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
    c_operators.push_back("(");                                           
    c_operators.push_back(")");
    c_operators.push_back("<");    
    c_operators.push_back(">");   
    c_operators.push_back(".");    
    c_operators.push_back("?"); 
    c_operators.push_back(":"); 
    c_operators.push_back("[");
    c_operators.push_back("]"); 
    c_operators.push_back("!");          
    
    //populate double chars
    c_double_operators.push_back("<=");
    c_double_operators.push_back(">=");
    c_double_operators.push_back("==");
    c_double_operators.push_back("++");
    c_double_operators.push_back("--");
    c_double_operators.push_back("<<");    
    c_double_operators.push_back(">>");
    c_double_operators.push_back("&&");    
    c_double_operators.push_back("||");
    c_double_operators.push_back("!=");        
    c_double_operators.push_back("::");                           
                
    // Open the file        
    ifstream ifile("input.cpp");
    
    // Read line by line
    while(getline(ifile,buffer)){
        regex(buffer);
    }
    
    // Close the file
    ifile.close();
 
    // Write output to a file
    ofstream ofile("output.txt");
    ofile<<" ================ Output ==================== \n\n";
    for(int i=0;i<operators.size();i++)
        ofile<<output[i]<<"\n";
    ofile<<" ================ Operators ================ \n";
    for(int i=0;i<operators.size();i++)
        ofile<<operators[i]<<"\n";
    ofile<<" ================ Keywords ================ \n";
    for(int i=0;i<keywords.size();i++)
        ofile<<keywords[i]<<"\n";
    ofile<<" ================ Identifires ================ \n";
    for(int i=0;i<identifiers.size();i++)
        ofile<<identifiers[i]<<"\n";
    ofile<<" ================ Constants ================ \n";
    for(int i=0;i<constants.size();i++)
        ofile<<constants[i]<<"\n";

	return 0;
}
