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

map < pair<int,int> , int> e;
vector <pair<int,int> > ed;

int an[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n,m; cin>>n>>m;
    forn(i,m){
      int u,v; cin>>u>>v;
      e[{u,v}]=e[{v,u}]=1;
      ed.pb({u,v});
    }
    map <int,int> mm;
    int pp=-1;
    int cnt[3]={1,1,1};
    an[1] =1;
    for(int i=2;i<=n;i++){
      if(e.find({i,1})==e.end())
       {
        an[i] = 1;
        cnt[0] ++;
       }
    }
    for(int i=2;i<=n;i++){
      if(an[i]==0){
        an[i] = 2;
        for(int j=1;j<=n;j++){
          if(j==i) continue;
          if(e.find({i,j})==e.end())
            {
              an[j]=2;
              cnt[1] ++;
            }
        }
        break;
      }
    }
    int f = 0;
    for(int i=2;i<=n;i++){
      if(an[i]==0){
        an[i] = 3;
        f= 1;
        for(int j=1;j<=n;j++){
          if(j==i) continue;
          if(e.find({i,j})==e.end())
            {
              an[j] = 3;
              cnt[2]++;
            }
        }
        break;
      }
    }
  if(f==0){
    cout<<-1<<endl;
    return 0;
  }
  for(auto ee:ed)
  {
      if(an[ee.fi] == an[ee.se] )
      {
        cout<<-1<<endl;
        return 0;
      }
  }
  if( cnt[0]*cnt[1] + cnt[1]*cnt[2] + cnt[2]*cnt[0] != ed.size()){
    cout<<-1<<endl;
    return 0;
  }
  for1(i,n) cout<<an[i]<<" " ;
  cout<<endl;
    return 0;
}

