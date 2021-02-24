#include<iostream>
#include<stack>
using namespace std;

stack<int> inv;

int n;
// 0 nothing , 1 adding, 2 taking
int events [365];

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        events[temp]=1;
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        events[temp]=2;
    }

    int res=0;
    for(int i=1;i<365;i++){
        if(events[i]==1){
            inv.push(i);
        }
        if(events[i]==2){
            res+=(i-inv.top())*(i-inv.top());
            inv.pop();
        }
    }
    cout<<res;
    return 0;
}
