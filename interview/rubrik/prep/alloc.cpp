#include<bits/stdc++.h>
using namespace std;

int main() {
  int* ptr;
  int n, i;

  n = 5;
  cout<<"Enter number of elements: "<<n<<endl;
  ptr = (int*) malloc(n * sizeof(int));

  if(ptr == NULL) {
    cout<<"Memory not allocated."<<endl;
    exit(0);
  }
  else {
    cout<<"Memory have been successfully allocated using malloc."<<endl;

    for(int i = 0; i < n; i++) {
      ptr[i] = i + 1;
    }

    cout<<"The elements of the array are: ";
    for(int i = 0; i < n; i++) {
      cout<<ptr[i]<<" ";
    }
    cout<<endl;
  
    ptr = (int*) realloc(ptr, 10*sizeof(int));
    for(int i = 0; i < 10; i++){
      ptr[i] = i + 1;
    }

    for(int i = 0; i < 10; i++){
      cout<<ptr[i]<<" ";
    }
    cout<<endl;
  
    free(ptr);
    cout<<"Pointer is freed"<<endl;
  }
  
  return 0;
}
