#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int main()
{
    //char ch;
    string line;
    fstream obj("abc.txt",ios::in);
//    while(obj>>ch)
  //   cout<<ch;
    while(getline(obj, line))
    {
          cout<<line<<endl;
    }
    obj.close();
    
    return 1;
}
