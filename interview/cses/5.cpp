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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

//1 3 5 7 2 4 

int main(){
  fio();
  int n ;cin>>n;
  if(n==1){
  	cout<<1<<endl;
  	return 0;
  }
  if(n<=3){
  	cout<<"NO SOLUTION"<<endl;
  	return 0;
  }
  if(n==4){
  	cout<<"3 1 4 2"<<endl;
  	return 0;
  }
  	for(int i=1; i<=n; i+=2)
  		cout<<i<<" ";
  	for(int i=2;i<=n;i+=2)
  		cout<<i<<" ";
  cout<<endl;
  return 0;

}