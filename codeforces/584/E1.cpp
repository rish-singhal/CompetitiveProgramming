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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      int n,m; cin>>n>>m;
      int mm[n][m];
      vector <pair<int,pair<int,int>> > v;
      forn(i,n)
        forn(j,m)
        {
          cin>>mm[i][j];
          v.pb(make_pair(mm[i][j],make_pair(i,j)));
        }
      srt(v);
      reverse(all(v));
      LL an = 0;
      int k = n;
      set<int> s;
      map <int,vector<int> > mp;
      for(int i=0;i<n;i++)
      {
        an += v[i].fi;
        mp[v[i].se.fi].pb(v[i].se.se);
      }
      
      if(mp.size()!=2 || n<=3){
        cout<<an<<endl;
      }
      else{
      int flll=1;
      for(int j=0;j<4;j++){
      mp.clear();
      an  =0;
      for(int i=0;i<5;i++)
      {
       if(i==j)continue; 
        an += v[i].fi;
        mp[v[i].se.fi].pb(v[i].se.se);
      }
      if(mp.size()!=2){
        cout<<an<<endl;
        break;
      }
      vector <int> vz[2];
        int k =0;
         for(auto i:mp)
        {
          for(auto x:i.se)
            vz[k].pb(x);
          k++;
        }
        if((vz[0][0]-vz[0][1] + n)%n==(vz[1][0]-vz[1][1] + n)%n) {
          flll = 0;
          cout<<an<<endl;
          break;
        }
      }
    
    }
    }
    return 0;
}

