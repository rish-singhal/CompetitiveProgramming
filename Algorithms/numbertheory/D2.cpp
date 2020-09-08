#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;
const int M = 1e9+7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

bool isPower(unsigned n) 
{ 
    if (n==1)  return true; 
  
    // Try all numbers from 2 to sqrt(n) as base 
    for (int x=2; x<=sqrt(n); x++) 
    { 
        unsigned y = 2; 
        unsigned p = pow(x, y); 
  
        // Keep increasing y while power 'p' is smaller 
        // than n.  
        while (p<=n && p>0) 
        { 
            if (p==n) 
                return true; 
            y++; 
            p = pow(x, y); 
         } 
    } 
    return false; 
} 

LL chk[1000];

int main(){
  fio();
  int n = 1000;
  LL an = 0;
  for1(i,1000) chk[i] = isPower(i);
  for1(i,n){
  	an = (an+1)%M;
  	if(i==1) continue;
  	for(int j=2;j*j<=i;j++){
  		if(i%j==0){
  			if(chk[j]) an = (an+j)%M;
  			if(chk[i/j] && j*j!=i) an = (an+(i/j))%M;
  		}
  	}
  	if(chk[i]) an = (an+i)%M;
  	cout<<i<<" : "<<an<<endl;
  }

  return 0;
}