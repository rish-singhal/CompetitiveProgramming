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
  int n,k,c; cin>>n>>k>>c;
  string s; cin>>s;
  unordered_map<int,int> m;
  for(int i = n-1;i>=0;i--){
    if(s[i]=='o'){
      m[i] = k--;
      i-=c;
    }
  }
  int x(0);
  for(int i=0;i<n;i++){
    if(s[i]=='o'){
      if(m[i]==++x) cout<<i+1<<endl;
      i+=c;
    }
  }
  
  return 0;
}

