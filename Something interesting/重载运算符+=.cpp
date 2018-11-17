#include <iostream>  
#include <string>   
using namespace std;   

class cstring  
{
private:
    char s[100];  
public:  
    cstring(const char* str){strcpy(s,str);}    
    friend cstring& operator +=(cstring& str1, const cstring& str2);
    friend ostream& operator <<(ostream& output, const cstring&); 
};  

cstring& operator +=(cstring& str1, const cstring& str2)    
{  
    strcat(str1.s,str2.s);    
    return str1;  
}  

ostream& operator<<(ostream &output, const cstring &ob){  
    output<<ob.s;  
    return output; 
}   

int main()  
{  
    cstring str1("laozhu,"),str2("dongleba");  
    str1 += str2;   
    cout<<str1<<endl;
	cout<<str2<<endl;
    return 0;  
}  
