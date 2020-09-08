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
      int n; cin>>n;
      map <pair<LL,LL>, LL > m,va;
      vector <pair<LL,LL> > v;
      forn(i,n){
        LL l,r,kk; cin>>l>>r>>kk;
        v.pb({l,r});
        m[{l,r}] = kk;
      }
      int nn = v.size();
      int bb = 0;
      srt(v);
      forn(i,nn){
        vector <int > pp;
        int val = va[v[i]];
        val *=-1;
        for(int j=i+1;j<nn;j++){
//          cout<<"wd "<<i<<" "<<j<<endl; 
          if(m[v[i]]!=m[v[j]]) continue;
          if(v[i].se < min({v[j].se,v[j].fi}))
            continue;
          if(v[i].fi > max({v[j].se,v[j].fi}))
            continue;
  //        cout<<i<<" "<<j<<endl;
          pp.pb(j);
          if(va[v[j]]==0) continue;
          if(val!=0 && val!=va[v[j]]){
            bb = 1;
           // cout<<val<<endl;
    //        cout<<"wedwe"<<endl;
            break;
          }
          else val = va[v[j]];

          if(va[v[i]]!=0 && va[v[j]]!=0){
              if(va[v[i]]==va[v[j]]) {
                bb = 1;
                break;
              }
          }
          }
        
        if(bb==1) break;
        if(val==0){
          va[v[i]] =1;
          for(auto po:pp) va[v[po]] = -1;
        }
        else{
          if(va[v[i]]!=0){
            if(va[v[i]] == val){
            bb = 1;
            break;
            }
          }
          va[v[i]] = -1*val;
          for(auto po:pp) va[v[po]] = val;
      }
      }
//      for(auto i:v) cout<<va[i]<<endl;
      if(bb) cout<<"NO\n";
      else cout<<"YES\n";
    }
    return 0;
}

