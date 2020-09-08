#include<bits/stdc++.h>
using namespace std;

int main(){
  int *ptr;
  int n; cin>>n;
  ptr = (int*) malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) {
    ptr[i] = i + 1;
  }
  cout<<ptr[n-1]<<endl;
  free(ptr);
  return 0;
}
