#include<bits/stdc++.h>
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

vector <LL> val,wt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int b,l,d; cin>>b>>l>>d;
    LL s = 0;
    vector <pair<LL,LL>  > pk(l);
    vector <LL> v(b);
    vector <LL> nb(l), nd(l), sb(l);
    set<LL> bo[l]; 
    vector <LL> ss[78600];
    forn(i,b){
      cin>>v[i];
    }
    
    forn(i,l){
      cin>>nb[i]>>nd[i]>>sb[i];
      s += nd[i] < 10000? 1:0;
//      forn(j,nb[i]){
  //      int k; cin>>k;
    //    bo[i].insert(k);
      //  ss[k].pb(i);
        //su+=v[k];
     // }
     // pk[i] = {bo[i].size(),i};  
    } 
    cout<<s<<endl;
/*    LL to = 15001;
    cout<<to<<endl;
    forn(i,15001){
      srt(pk);
      int oo = pk[pk.size()-1].se;
      cout<<oo<<" "<<bo[oo].size()<<endl;
      for(auto j: bo[oo]) cout<<j<<" ";
      cout<<endl;
      vector <LL> zs;
      for(auto j:bo[oo]) zs.pb(j);
      for(int k = 0; k<l;k++){
         for(auto j:zs)
          bo[k].erase(j);
        pk[k] = { bo[k].size(),k}; 
      }
    }
      
*/
    return 0;
}

