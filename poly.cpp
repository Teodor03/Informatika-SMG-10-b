#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct TPoint {
  double x,y;
};

//class TPolygon {
//  TPoint A[50];
//  int n;
//public:
//  TPolygon();
//  int verts();
//  void add_vert(TPoint a);
//  double perimetr();
//  double surface();
//
//};

class TPolygon {

  TPoint *A;
  int n;

  double f_dist(int i_a,int i_b){
    if(i_a<0 or i_a>=n or i_b<0 or i_b>=n){
        return 0;
    }
    return sqrt((A[i_a].x-A[i_b].x)*(A[i_a].x-A[i_b].x) + (A[i_a].y-A[i_b].y)*(A[i_a].y-A[i_b].y));
  }

  bool is_cross(TPoint a,int ind){
    TPoint b=A[ind];
    TPoint c=A[ind+1];
    if(c.y<b.y){
        swap(b,c);
    }
    double d_x;
    if(b.y<=a.y and a.y<=c.y){
        if(b.y==c.y){
            return true;
        }
        if(b.x==c.x){
            d_x=b.x;
        }else{
            if(b.x<c.x){
                d_x=(a.y-b.y)*abs(b.x-c.x)/(c.y-b.y)+b.x;
            }else{
                d_x=b.x-(a.y-b.y)*abs(b.x-c.x)/(c.y-b.y);
            }
        }
        if(a.x<=d_x){
            return true;
        }
    }
    return false;
  }

public:
  TPolygon(){
    n = 3;
    A = new TPoint[n];
    A[0].x = A[0].y = 0;
    A[1].x = 1; A[1].y = 0;
    A[2].y = 1; A[2].x = 0;
  }
  ~TPolygon(){
    delete [] A;
  }
  int verts(){return n;}
  void add_vert(TPoint a) {
    TPoint *p = new TPoint[n+1];
    for (int i=0; i<n; i++) p[i] = A[i];
    delete [] A;
    A = p;
    A[n++] = a;
  }

  double perimetr(){
    double res=0;
    for(int i=0;i<(n-1);i++){
        res+=f_dist(i,i+1);
    }
    res+=f_dist(n-1,0);
    return res;
  }

  double surface(){
      double res=0;
      for(int i=0;i<n-1;i++){
          res+=( (A[i].x-A[i+1].x)*((A[i].y+A[i+1].y)/2)  );
      }
      res+= ( (A[n-1].x-A[0].x)*((A[n-1].y+A[0].y)/2)  );
      return abs(res);
  }

  bool is_inside(TPoint a){
    int res=0;
    for(int i=0;i<n-1;i++){
        if(is_cross(a,i)){
            cout<<"n"<<i<<endl;
            res++;
        }
    }
    if(res%2){
        return true;
    }
    return false;
  }

};


int main () {
    TPolygon a;
    cout<<a.perimetr()<<endl;
    cout<<a.surface()<<endl;
    cout<<a.is_inside({0.1,0.1});
  return 0;
}
