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
const int MAXN = 2e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL d[MAXN][MAXN];
LL min(LL a, LL b){
  return a>b?b:a;
}


int main(){
  fio();
  LL n,x,y; cin>>n>>x>>y;
  vector <LL> an(n+1);
  for1(i,n){
    for(int j=i+1;j<=n;j++){
      if(i<=x && j>=y){
        an[j-i-(y-x)+1]++;
      }
      else if( i>=x && j>=y){
        LL pp = min( (i-x) + 1LL + (j-y), (j-i));
        an[pp] ++;
      }
      else if(i>=x && j<=y){
        LL pp = min( (i-x) + 1LL + (y-j), (j-i));
        an[pp]++;
      }
      else if(i<=x && y>=j && j>=x)
      {
        LL pp = min(x-i + 1LL + (y-j),(j-i));
        an[pp]++;
      }
      else an[j-i]++;
    //if(an[5]) cout<<i<<" "<<j<<endl;
    }
  }
  for1(i,n-1) cout<<an[i]<<endl;

  return 0;
}

