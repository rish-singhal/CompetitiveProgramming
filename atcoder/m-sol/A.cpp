#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int x; cin>>x;
  if(x >= 400 && x <= 599) cout<<8<<endl;
  else if(x >= 600 && x <= 799) cout<<7<<endl;
  else if(x >= 800 && x <= 999) cout<<6<<endl;
  else if(x >= 1000 && x <= 1199) cout<<5<<endl;
  else if(x >= 1200 && x <= 1399) cout<<4<<endl;
  else if(x >= 1400 && x <= 1599) cout<<3<<endl;
  else if(x >= 1600 && x <= 1799) cout<<2<<endl;
  else if(x >= 1800 && x <= 1999) cout<<1<<endl;
  return 0;
}