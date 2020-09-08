#include<bits/stdc++.h>
using namespace std;

class A{
  int a;

 public:
  int* ptr;

  A(){
    cout<<"Constructor is called!!"<<endl;
  }
  ~A(){
    cout<<"Destructor is called!!"<<endl;
  }
};

int main(){
 A* a = new A;
 cout<<"Object of Class A was created using new operator!!"<<endl;
 delete(a);
 cout<<"Object gets deleted using delete!!"<<endl;
// Default constructor is not called!
 A* b = (A*) malloc(sizeof(A));
 cout<<"Object of Class A was created using malloc!!"<<endl;
 free(b);
 cout<<"Using free!!"<<endl;
 return 0;
}
