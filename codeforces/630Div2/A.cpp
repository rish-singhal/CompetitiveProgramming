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
  int t; cin>>t;
  while(t--){
    LL a,b,c,d; cin>>a>>b>>c>>d;
    LL x,y,x1,y1,x2,y2; cin>>x>>y>>x1>>y1>>x2>>y2;
    int xx = abs(a-b);
    int yy = abs(c-d);
    bool z = 1;
    if(a!=0 && b!=0 && (x1==x2)) {
      cout<<"No\n";
      continue;
    }
    if(c!=0 && d!=0 && (y1==y2)) {
      cout<<"No\n";
      continue;
    }
  
    if(a>b){
      z&=xx<=abs(x-x1);
    }
    else
      z&=xx<=abs(x-x2);
    if(c>d){
      z&=yy<=abs(y-y1);
    }
    else
      z&=yy<=abs(y-y2);
   cout<<(z?"Yes\n":"No\n");
  }

  return 0;
}

