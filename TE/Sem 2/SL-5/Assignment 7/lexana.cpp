#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;

vector<string> output,identifiers,operators,Literals,keywords,c_keywords,c_operators,c_double_operators;

// Functions for Trimimg string
string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
string& rtrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
string& trim(string& str, const string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
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
    for(short int i=0;i<c_keywords.size();i++)
        if(word.compare(c_keywords[i])==0)
            return true;
    return false;
}

// Function to check separator
bool is_separator(char a){
    if(a == ' ')
        return true;
    else if(a == ',')
        return true;
    else if(a == ';')
        return true;
    return false;
}

// Function to check Literals
bool is_Literal(string word){
	//cout<<"Literal : "<<word;
	short int flg = 0;
	for(short int i=0;i<word.length();i++){
        if( word[i] == '0' || word[i] == '1' || word[i] == '2' || word[i] == '3' || 
            word[i] == '4' || word[i] == '5' || word[i] == '6' || word[i] == '7' || 
            word[i] == '8' || word[i] == '9')
            flg=1;
        else{
            flg=0;
            break;
        }
   }
   //cout<<" ::: "<<flg<<"\n";
   if(flg)
        return true;  
}

// Function to process lines
void regex(string line){
    line = trim(line);
	if(line[0] == '/' && line[1] == '/')
		return;
    string chars="";
    int idx;
    for(int i=0;i<line.length();i++){
        // characters
        chars.append(string(1,line[i]));
        cout<<chars<<"\n";          
        
        if(i>0)
		    if(is_double_op(line.substr(i-1,2))){
		        operators.push_back(line.substr(i,2));
		        output.push_back(line.substr(i,2).append(string("\t\t\t : Operator")));
		        i++;
		        if(chars.length()>0){
			        chars = chars.substr(0, chars.length()-2);            
		            if(is_keyword(chars)){
		                keywords.push_back(chars);
		                output.push_back(chars.append(string("\t\t\t : Keyword")));                    
		            }
		            else if(is_Literal(chars)){
		                Literals.push_back(chars);
		                output.push_back(chars.append(string("\t\t\t : Literal")));
		            }
		        }
		        chars = "";
		        cout<<" 1 ::: "<<chars<<"\n";
		    }
        if(is_op(line[i])){
            operators.push_back(string(1,line[i]));
            output.push_back(string(1,line[i]).append(string("\t\t\t : Operator")));
            if(chars.length()>0){
	            chars = chars.substr(0, chars.length()-1);            
                if(is_keyword(chars)){
                    keywords.push_back(chars);
                    output.push_back(chars.append(string("\t\t\t : Keyword")));                    
                }
                else if(is_Literal(chars)){
                    Literals.push_back(chars);
                    output.push_back(chars.append(string("\t\t\t : Literal")));
                }
            }
            chars = "";
            if(line[i] == '\''){
            	i++;
            	chars.append(string(1,line[i]));
	            while(line[i]!='\''){
		    		chars.append(string(1,line[++i]));
		    	}
			    Literals.push_back(chars.substr(0,chars.length()-1));
			    output.push_back(chars.substr(0,chars.length()-1).append(string("\t\t\t : Literal")));
			    chars = chars.substr(chars.length()-1,chars.length());
			}
            if(line[i] == '"'){
            	i++;
            	chars.append(string(1,line[i]));
	            while(line[i]!='"'){
		    		chars.append(string(1,line[++i]));
		    	}
			    Literals.push_back(chars.substr(0,chars.length()-1));
			    output.push_back(chars.substr(0,chars.length()-1).append(string("\t\t\t : Literal")));
			    chars = chars.substr(chars.length()-1,chars.length());
			}
            cout<<" 2 ::: "<<chars<<"\n";
        }
        else if(is_separator(line[i])){
            if(chars.length() > 1){
	            chars = chars.substr(0, chars.length()-1);
	            identifiers.push_back(chars);
	            output.push_back(chars.append(string("\t\t\t : Identifier")));
	        }
	        chars = "";
            cout<<" 3 ::: "<<chars<<"\n";	        
        }
        else if(is_keyword(chars)){
            keywords.push_back(chars);
            output.push_back(chars.append(string("\t\t\t : Keyword")));
            chars = "";
            cout<<" 4 ::: "<<chars<<"\n";            
        }
        else if(is_Literal(chars)){
        	while(is_Literal(chars)){
        		chars.append(string(1,line[++i]));
        	}
            Literals.push_back(chars.substr(0,chars.length()-1));
            output.push_back(chars.substr(0,chars.length()-1).append(string("\t\t\t : Literal")));
            chars = chars.substr(chars.length()-1,chars.length());
            cout<<" 5 ::: "<<chars<<"\n";            
        }
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
    c_keywords.push_back("short");
    c_keywords.push_back("char");        
    c_keywords.push_back("void");
    c_keywords.push_back("bool");
    c_keywords.push_back("true");             
    c_keywords.push_back("const");    
    
    // populate operators
    c_operators.push_back("\"");
    c_operators.push_back("'");   
    c_operators.push_back(",");       
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
    c_operators.push_back("=");    
    c_operators.push_back("&");            
    
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
    for(int i=0;i<output.size();i++)
        ofile<<output[i]<<"\n";
    ofile<<" ================ Operators ================ \n";
    for(int i=0;i<operators.size();i++)
        ofile<<operators[i]<<"\n";
    ofile<<" ================ Keywords ================ \n";
    for(int i=0;i<keywords.size();i++)
        ofile<<keywords[i]<<"\n";
    ofile<<" ================ Identifiers ================ \n";
    for(int i=0;i<identifiers.size();i++)
        ofile<<identifiers[i]<<"\n";
    ofile<<" ================ Literal ================ \n";
    for(int i=0;i<Literals.size();i++)
        ofile<<Literals[i]<<"\n";

	return 0;
}
