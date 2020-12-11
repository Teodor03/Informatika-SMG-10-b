#include<iostream>
#include<string>
#include<set>
using namespace std;

class bank_account{
private:

    string name;
    int id;
    string addr;
    double amount;

public:

    bank_account(): name{"test"},id{0},addr{"somewhere"},amount{0}{}

    bank_account(string& n,int _id,string& adr,double st_am):name{n},id{_id},addr{adr},amount{st_am}{}

    string get_name(){
        return name;
    }

    void add_money(double am){
        amount+=am;
    }

    bool pull_out_money(double am){
        if(amount>=am){
            amount-=am;
            return true;
        }
        return false;
    }



};

string ex_name="ex";

class bank_account_key{
    public:
    string& name;
    bank_account * obj;

    bank_account_key(): name{ex_name}{}

    bool operator <(const bank_account_key& other)const{
        return name<other.name;
    }

};

set<bank_account_key> main_data;
//vector<bank_account *> real_main_data;

int main(){

int code_action;
bank_account * add;
bank_account_key add_k;
string add_n,add_adr;
int add_id;
double add_val;

set<bank_account_key>::iterator curr;

while(cin>>code_action){
    switch(code_action){
    case 0:
        cin>>add_n>>add_id>>add_adr;
        add = new bank_account(add_n,add_id,add_adr,0);
        add_k.name = (*add).get_name();
        add_k.obj = add;
        main_data.insert(add_k);
//        //if( (main_data.find(*add)) == (set<bank_account>.end()) ){
//
//            delete add;
//        //}else{
//        //    cout<<"Invalid input. Name is already exhisting."<<endl;
//        //}
        break;
    case 1:
        cin>>add_n>>add_val;
        add_k.name=add_n;
        curr=main_data.find(add_k);
        if(curr==main_data.end()){
            cout<<"Cannot find!"<<endl;
            goto end_while;
        }
        (*((*curr).obj)).add_money(add_val);
        break;
    case 2:
        cin>>add_n>>add_val;
        add_k.name=add_n;
        curr=main_data.find(add_k);
        if(curr==main_data.end()){
            cout<<"Cannot find!"<<endl;
            goto end_while;
        }
        if( !(*((*curr).obj)).pull_out_money(add_val) ){
            cout<<"Not enough money"<<endl;
        }
        //cout<<(*(*curr).obj).
        break;
        end_while:;
    }
}
return 0;
}
