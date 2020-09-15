#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n;

int fr2(vector<int> &dp1, vector<int> &dp2, vector<int> &v,int i);

int fr1(vector<int> &dp1, vector<int> &dp2, vector<int> &v,int i){
if(i >= n) return 0;
if( dp1[i] == -1){
dp1[i] = min( v[i]+v[i+1]+fr2(dp1,dp2,v,i+2), v[i]+fr2(dp1,dp2,v,i+1));
}
return dp1[i];
}

int fr2( vector<int> &dp1, vector<int> &dp2, vector<int> &v,int i){
if(i >= n) return 0;
if( dp2[i] == -1) {
dp2[i] = min(fr1(dp1,dp2,v,i+1), fr1(dp1,dp2,v,i+2));
}
return dp2[i];
}

int main() {
int t,inp;
cin>>t;

while(t--){

cin>>n;
vector <int> v;
vector <int> dp1(n, -1);
vector <int> dp2(n, -1);

for(int i=0;i<n;i++){
cin>>inp;
v.push_back(inp);
}

dp2[n-1]=0;
dp1[n-1]=v[n-1];
dp2[n-2]=0;
dp1[n-2]=v[n-2];

cout<<fr1(dp1,dp2,v,0)<<endl;
}
return 0;
}