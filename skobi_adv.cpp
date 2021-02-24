#include<iostream>
#include<string>
using namespace std;

string expr;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>expr;
    char curr;
    int curly=0, ugly=0, normal=0;
    for(int i=0;i<expr.size();i++){
        curr=expr.at(i);
        switch(curr){
            case '{':
                if(ugly>0 or normal>0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                curly++;
            break;
            case '}':
                if(ugly>0 or normal>0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                if(curly==0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                curly--;
            break;
            case '[':
                if(normal>0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                ugly++;
            break;
            case ']':
                if(normal>0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                if(ugly==0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                ugly--;
            break;
            case '(':
                normal++;
            break;
            case ')':
                if(normal==0){
                    cout<<"Error at : "<<i+1;
                    return 0;
                }
                normal--;
            break;
        }
    }
    if(curly>0 or ugly>0 or normal>0){
        cout<<"Incomplete!";
        return 0;
    }
    cout<<"All is ok!";
    return 0;
}
