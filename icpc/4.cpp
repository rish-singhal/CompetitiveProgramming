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
const LL ms = (1<<20) + 10 ;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
  
    while(t--){
      map <LL,int> m;
      int n,k; cin>>n>>k;
      string  s; cin>>s;
      vector<pair<LL,LL> > sk;
      vector<LL> po(ms);
      vector <LL> ann(n);
      for1(i,k){
        string p; cin>>p;
        int msk=0;
        for(auto o:p){
          msk|=1<<(o-'a');
        }
        m[msk] = i;
        sk.pb({p.size(),msk});
      }
      srt(sk);
      for(int i=0;i<sk.size();i++){
        LL msk = sk[i].se;
        int ind = m[sk[i].se];
        po[msk]=ind;
        for(LL sm = msk; sm >0; sm = (sm-1)&msk){
          po[sm] = ind;
        }
      }
//      cout<<po[4]<<endl;
//      cout<<"wefwe--"<<endl;
      int msk = 0;
      int rmk = 0;
      for(int i=0;i<s.size();i++){
          if(i>=1 && po[(msk|(1<<(s[i]-'a')))]==0){
              ann[i-1] = po[msk];
            msk = 0;
              }
          msk|=1<<(s[i]-'a');
      }
    //cout<<"e2"<<endl;
      ann[n-1] = po[msk];
    for(int i=s.size()-2;i>=0;i--){
     if(ann[i]==0) ann[i]= ann[i+1];
     }
      forn(i,n) cout<<ann[i]<<" ";
      cout<<endl;
      }
    return 0;
}

