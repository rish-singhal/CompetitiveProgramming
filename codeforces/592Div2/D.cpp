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
LL deg[100005];
LL c[100005][3];
vector <int> adj[100005];
LL dp[100005][3][3];
LL bb[100005][3];
LL an[100005];
const LL inf = 1e17;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL n; cin>>n;
    forn(j,3){
      forn(i,n) cin>>c[i][j];
    }
    LL bo = 0;
    forn(i,n-1){
      int a,b; cin>>a>>b;
      a--,b--;
      deg[a]++;
      deg[b]++;
      adj[a].pb(b);
      adj[b].pb(a);
      if(deg[a]>2 || deg[b]>2) bo =1;
    }
    if(bo){
      cout<<-1<<endl;
      return 0;
    }
    vector <int> v(n);
    forn(i,n){
      if(deg[i] == 1){
          v[0] = i;
          v[1] = adj[i][0];
          int cc=2;
          for(;cc<n;cc++){
            for(auto x:adj[v[cc-1]]){
              if(x!=v[cc-2])
                v[cc] = x;
            }
          }
        break;
      }
    }
    vector <int> aa ={0,1,2};
    vector <int> vv;
    LL mm = 1e18;
    do{
//      for(auto i:aa) cout<<i<<" ";
  //    cout<<endl;
      LL an = 0;
      for(int i=0;i<n;i++){
        an+=c[v[i]][aa[i%3]];
      }   
      if(mm > an){
        mm = an;
        vv = aa;
      }
    }while(next_permutation(all(aa)));
    
    LL ann[n];
    for(int i=0;i<n;i++){
      ann[v[i]] = vv[i%3]+1;
      }
    cout<<mm<<endl;
    forn(i,n) cout<<ann[i]<<" ";
    cout<<endl;
    return 0;
}

