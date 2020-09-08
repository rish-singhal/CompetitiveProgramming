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
vector <int> adj[205];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      int n; cin>>n;
      int gg[2*n+1][2*n+1];
      forn(i,2*n){
        forn(j,i*2n){
          gg[i][j] = inf;
        }
      }
      string s; cin>>s;
      forn(i,105) adj[i].clear();
      for1(i,n-1){
        gg[i][i-1] = 1;
        gg[i-1][i] = 1;
      }
      for(int i=n+1;i<2*n;i++){
        gg[i][i-1]= 1;
        gg[i-1][i] = 1;
      }
      forn(i,s.size()){
        if(s[i]=='1'){
          gg[i][i+n] =1;
          adj[i+n][i] = 1;
        }
      }
        forn(k,2*n)  
        forn (i,2*n)  
           forn(k,2*n)   
                if (gg[i][k]!=inf && gg[j][j]!=inf && gg[i][k] + gg[k][j] < gg[i][j])  
                    gg[i][j] =gg[i][k] + gg[k][j];  
            }  
        }  
    }  
    }
      return 0;
}

