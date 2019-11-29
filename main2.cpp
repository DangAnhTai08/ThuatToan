#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool Ckeck_Ngoac(string str,stack<char> a){
    for(int i=0;i<str.size();i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            a.push(str[i]);
        }else if(str[i]=='}'||str[i]==']'||str[i]==')'){
            if(!a.empty()){
                if(str[i]==']'){
                    if(a.top()!='[') return false;
                }
                if(str[i]=='}'){
                    if(a.top()!='{') return false;
                }
                if(str[i]==']') {
                    if(a.top()!='[') return false;
                }
                a.pop();
            }
            else{
                return false;
            }
        }
    }
    return a.empty()==true;
}

bool ckeck_Ngoac2(string str,stack<char> stk){
    for(int i=0;i<str.size();i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            stk.push(str[i]);
        }else if(str[i]=='}'||str[i]==']'||str[i]==')'){
            if(!stk.empty()){
                if(str[i]=='}'){
                    if(stk.top()!='{') return false;
                }else if(str[i]==']'){
                    if(stk.top()!='[') return false;
                }else if(str[i]==')'){
                    if(stk.top()!='(') return false;
                }
                stk.pop();
            }else{
                return false;
            }
        }
    }
    return stk.empty()==true;
}

int main()
{
     string str;
    stack<char> a;
    getline(cin,str);
    if(ckeck_Ngoac2(str,a)==true){
        cout <<"Xau ngoac dung" <<endl;
    }else{
        cout << "xau ngoac sai: "<< endl;
    }
    return 0;
}
