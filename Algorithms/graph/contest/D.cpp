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
const int MAXN = 1e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){ 
  fio();
  int n; cin>>n;
  int a=0, b=0;
  int e = 0;
  for(int i=0;2*i<=n;i++){
    a = 2*i;
    b = n - a;
    LL zz = b*2 + 3*a;
    zz>>=1; int bb = 0;
    for(int p = 2;p< zz;p++){
      if(zz%p==0){
          bb = 1;
          break;
      }
    }
    if(bb==0){
      e = zz;
      break;
    }
  }
  priority_queue <pair<int,int> > s;
  if(e==0) cout<<-1<<endl;
  else{
    cout<<e<<endl;
    for1(i,n){
      if(b>0){
        s.push({2,i});
        b--;
      }
      else{
        s.push({3,i});
      }
    }
//    for1(i,n) cout<<in[i]<<" ";
  //  cout<<endl;
  int aa[MAXN][MAXN] = {0};
  while(!s.empty()){
      auto a = s.top();     
      s.pop();
      if(a.fi==0) continue; 
      vector <pair<int,int> > vv;
      while(aa[a.se][s.top().se]){
        vv.pb(s.top());
        s.pop();
      }
      auto b = s.top();
      s.pop();
      a.fi--; b.fi--;
      aa[a.se][b.se] = 1;
      aa[b.se][a.se] =1;
      cout<<a.se<<" "<<b.se<<endl;
      if(a.fi) s.push(a);
      if(b.fi)s.push(b);
      for(auto jj : vv) s.push(jj); 
  }
  }
  return 0;
}

