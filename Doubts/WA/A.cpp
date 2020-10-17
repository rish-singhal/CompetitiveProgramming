#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << " input format: num query_type " << endl;
  int x;
  
  /*
   * query_type = 1 => "remove"
   * query_type = 0 => "add"
   */
  int query_type; 
  // defined as an int, as it is bounded by the input size
  // if input size is more than INT_MAX (then it will take a
  // lot of time to execute)
  int count[2] = {0,0};

  // Assuming we need to stop the loop as we input some 
  // other character than 0 or 1
  while((cin>>query_type) && (cin >> x) && (x == 0 || x == 1)){
    count[x] += query_type? -1 : 1;
   
    // error handling for wrong input.
    if(count[x] < 0) {
      cout << " Not possible to remove " << x << "as no instance exists " << endl;
      count[x] ++;
      continue;
    }
    if(count[1] == 0) {
      cout << "There is no first index of 1" << endl;
      continue;
    }
    
    cout << "First index of 1 is: " << count[0] + 1 << endl;
  }

  cout << " Program Terminated. " << endl;
  return 0;
}
