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

int main(){
  fio();
  LL n; cin>>n;
  string s ="";
  while(n>0){
  	int k = n%26;
  	if(k!=0)s+=(k+'a'-1);
  	else s+=('z');
  	n/=26;
  	if(k==0) n--;
  }
  reverse(all(s));
  cout<<s<<endl;
  return 0;
}