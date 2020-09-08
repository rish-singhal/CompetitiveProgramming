#include<bits/stdc++.h>
using namespace std;

void * aligned_malloc(size_t align, size_t size) {
  void * ptr;
  void ** p;
  
  int offset = align - 1 + sizeof(void*);
  ptr = (void *) malloc(size + offset);
  
  if(ptr){
    p = (void **) (((size_t)(ptr) + offset) & ~(align - 1));
    p[-1] = ptr;
  }
  return p;
}

void aligned_free(void * p) {
   free(((void**)p)[-1]);
}

int main(){
  
  return 0;
} 
