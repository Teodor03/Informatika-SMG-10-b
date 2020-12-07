#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<typeinfo>
using namespace std;

class rabotnik{
    public:
    string ime;
    bool dlyvnost;
    long long zaplata;

    public:

    rabotnik (){
        ime[0] = '\0';
        dlyvnost=0;
        zaplata=10000;
    }

    rabotnik (string im,bool dl=false,long long zapl=0){
        ime =im;
        dlyvnost=dl;
        zaplata=zapl;
    }

    virtual void cout_info(){
        cout<<ime<<" "<<dlyvnost<<" "<<zaplata<<" ";
    }

};

class programist: public rabotnik{
    public:
    int otr_ch;
    public:
    programist (string im,long long zapl,int ot_ch): rabotnik{im,true,zapl}{
        otr_ch=ot_ch;
    }

    void cout_info(){
        cout<<ime<<" "<<dlyvnost<<" "<<zaplata<<" "<<otr_ch;
    }

};

int n;
vector<rabotnik *> spisyk;

int main(){
cin>>n;
string a;
int d,zapl,otr_chas;
for(int i=0;i<n;i++){
    cin>>a;
    cin>>d>>zapl;
    if(d){
        cin>>otr_chas;
        spisyk.push_back(new programist(a,zapl,otr_chas));
    }else{
        spisyk.push_back(new rabotnik(a,false,zapl));
    }
}
rabotnik * c_rab;
for(int i=0;i<n;i++){
    c_rab = spisyk[i];
    if(typeid(*c_rab)==typeid(rabotnik)){
        cout<<c_rab->zaplata<<endl;
    }else{
        cout<<dynamic_cast<programist*>(c_rab)->zaplata*dynamic_cast<programist*>(c_rab)->otr_ch<<endl;
    }
}
return 0;
}
