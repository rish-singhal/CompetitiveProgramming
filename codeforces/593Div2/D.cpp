#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
map <pair<int,int>,int > ms;
map <pair<int,int>, int> ch;
int n,m,k;
int ann = 0;
bool chk(pair<int,int> p){
  if(ann == 1) return 0;
  if(ch[{p.fi,p.se}]==1) return 0;
  if(p.fi>n || p.fi<1 || p.se>m || p.se<1) return 0;
  return 1;
}

LL an = 0;
void dfs(int x,int y,int d,LL p){    
  cout<<(x)<<" "<<y<<" -- "<<d<<" "<<p<<endl;
    an = max(an,p);    
    if(an==n*m-k){
      ann  =1;
      return;
    }
    ch[{x,y}] = 1;
     if(d==1){
        if(chk({x,y+1}) && ms[{x,y+1}]!=1){
          dfs(x,y+1,1,p+1);
        }
        if(chk({x+1,y}) && ms[{x+1,y}]!=1){
          dfs(x+1,y,2,p+1);
        }
     
     }
     else if(d==2){
        if(chk({x+1,y}) && ms[{x+1,y}]!=1){
          dfs(x+1,y,2,p+1);
        }
        if(chk({x,y-1}) && ms[{x,y-1}]!=1){
          dfs(x,y-1,3,p+1);
        }
      }
     else if(d==3){
        if(chk({x,y-1}) && ms[{x,y-1}]!=1){
          dfs(x,y-1,3,p+1);
        }
        if(chk({x-1,y}) && ms[{x-1,y}]!=1){
          dfs(x-1,y,4,p+1);
        }
      
     }
     else if(d==4){
        if(chk({x-1,y}) && ms[{x-1,y}]!=1){
          dfs(x-1,y,4,p+1);
        }
        if(chk({x,y+1}) && ms[{x,y+1}]!=1){
          dfs(x,y+1,1,p+1);
        }
      
     }
     ch[{x,y}] = 0;
     return ;
}
      

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int k; cin>>n>>m>>k;
    forn(i,k){
      int x,y; cin>>x>>y;
      ms[{x,y}]=1;
    }
    dfs(1,1,1,1);
    if(n*m - k ==an) cout<<"Yes\n";
    else cout<<"No\n";
//    cout<<an<<endl;
    return 0;
}

