#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>

using namespace std;

vector<string> ust_table,identifiers,Literals,keywords,Term_table;

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

// Function to find the class of the string
int is_term(string word){
    for(short int i=0;i<Term_table.size();i++)
        if(word.compare(Term_table[i])==0)
            return i;
    return -1;
}

// Function to check separator
bool is_separator(char a){
    if(a == ' ')
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
	int check = -1;
    line = trim(line);
	if(line[0] == '/' && line[1] == '/')
		return;
    string chars="";
    int idx;
    for(int i=0;i<line.length();i++){
        // characters
        chars.append(string(1,line[i]));
        cout<<chars<<"\n";          
        
        if(i>0){
			if(is_term(line.substr(i-1,2))!=-1){
				string temp(" TRM  : \t\t ");
				temp.append(to_string(is_term(line.substr(i-1,2))));
				temp.append("\t\t : ");
				temp.append(line.substr(i-1,2));
			    ust_table.push_back(temp);
			    i++;
			    chars = "";
			}
		}
		if(is_term(string(1,line[i]))!=-1){
			string temp(" TRM  : \t\t ");
			temp.append( to_string(is_term(string(1,line[i]))));
			temp.append("\t\t : ");
			temp.append(string(1,line[i]));
		    ust_table.push_back(temp);
            if(chars.length() > 1){
	            chars = chars.substr(0, chars.length()-1);
	            identifiers.push_back(chars);
				string temp(" ID   : \t\t ");
				temp.append(to_string(identifiers.size()-1));
				temp.append("\t\t : ");
				temp.append(chars);
			    ust_table.push_back(temp);
	        }
		    chars = "";
		}
		else if(is_term(chars)!=-1){
			string temp(" TRM  : \t\t ");
			temp.append( to_string(is_term(chars)));
			temp.append("\t\t : ");
			temp.append(chars);
		    ust_table.push_back(temp);
		    chars = "";
		}
        if(is_separator(line[i])){
            if(chars.length() > 1){
	            chars = chars.substr(0, chars.length()-1);
	            identifiers.push_back(chars);
				string temp(" ID   : \t\t ");
				temp.append(to_string(identifiers.size()-1));
				temp.append("\t\t : ");
				temp.append(chars);
			    ust_table.push_back(temp);
	        }
	        chars = "";
            cout<<" 3 ::: "<<chars<<"\n";	        
        }
        else if(is_Literal(chars)){
        	while(is_Literal(chars)){
        		chars.append(string(1,line[++i]));
        	}
            Literals.push_back(chars.substr(0,chars.length()-1));
			string temp(" LIT : \t\t ");
			temp.append(to_string(Literals.size()-1));
			temp.append("\t\t : ");
			temp.append(chars);
		    ust_table.push_back(temp);
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
    Term_table.push_back("include");
    Term_table.push_back("vector");
    Term_table.push_back("string.h");        
    Term_table.push_back("fstream");
    Term_table.push_back("string.h");
    Term_table.push_back("using");            
    Term_table.push_back("namespace");
    Term_table.push_back("int");
    Term_table.push_back("return");
    Term_table.push_back("if");
    Term_table.push_back("else");
    Term_table.push_back("short");
    Term_table.push_back("char");        
    Term_table.push_back("void");
    Term_table.push_back("bool");
    Term_table.push_back("true");             
    Term_table.push_back("const");    
    //populate double chars
    Term_table.push_back("<=");
    Term_table.push_back(">=");
    Term_table.push_back("==");
    Term_table.push_back("++");
    Term_table.push_back("--");
    Term_table.push_back("<<");    
    Term_table.push_back(">>");
    Term_table.push_back("&&");    
    Term_table.push_back("||");
    Term_table.push_back("!=");        
    Term_table.push_back("::");         
    // populate operators
    Term_table.push_back("\"");
    Term_table.push_back("'");   
    Term_table.push_back(",");       
    Term_table.push_back("+");
    Term_table.push_back("-");
    Term_table.push_back(">");
    Term_table.push_back("<");
    Term_table.push_back("#");    
    Term_table.push_back("/");
    Term_table.push_back("*");
    Term_table.push_back("%");
    Term_table.push_back("{");
    Term_table.push_back("}");
    Term_table.push_back(";"); 
    Term_table.push_back("(");                                           
    Term_table.push_back(")");
    Term_table.push_back("<");    
    Term_table.push_back(">");   
    Term_table.push_back(".");    
    Term_table.push_back("?"); 
    Term_table.push_back(":"); 
    Term_table.push_back("[");
    Term_table.push_back("]"); 
    Term_table.push_back("!");          
    Term_table.push_back("=");    
    Term_table.push_back("&");            
                          
                
    // Open the file        
    ifstream ifile("input.cpp");
    
    // Read line by line
    while(getline(ifile,buffer))
        regex(buffer);
    
    // Close the file
    ifile.close();
 
    // Write ust_table to a file
    ofstream ofile("ust_table.txt");
    ofile<<" ================ ust_table ==================== \n\n";
    for(int i=0;i<ust_table.size();i++)
        ofile<<ust_table[i]<<"\n";
    ofile<<" ================ Identifiers ================ \n";
    for(int i=0;i<identifiers.size();i++)
        ofile<<i<<" : "<<identifiers[i]<<"\n";
    ofile<<" ================ Literal ================ \n";
    for(int i=0;i<Literals.size();i++)
        ofile<<i<<" : "<<Literals[i]<<"\n";

	return 0;
}
