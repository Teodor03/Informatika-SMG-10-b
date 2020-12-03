#include<iostream>
#include<cstring>
using namespace std;

class rabotnik{
    protected:
    char ime [31];
    bool dlyvnost;
    long long zaplata;

    public:

    rabotnik (){
        ime[0] = '\0';
        dlyvnost=0;
        zaplata=10000;
    }

    rabotnik (const char * im,bool dl=false,long long zapl=0){
        strcpy(ime,im);
        dlyvnost=dl;
        zaplata=zapl;
    }

    virtual void cout_info(){
        cout<<ime<<" "<<dlyvnost<<" "<<zaplata<<" ";
    }

};

class programist: public rabotnik{
    protected:
    int otr_ch;
    public:
    programist (const char * im,long long zapl,int ot_ch): rabotnik{im,true,zapl}{
        otr_ch=ot_ch;
    }

    void cout_info(){
        cout<<ime<<" "<<dlyvnost<<" "<<zaplata<<" "<<otr_ch;
    }

};



int main(){
programist a("Petyr",100000,10);
a.cout_info();
return 0;
}
