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

LL ans[200005];
priority_queue <int> ss[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int k,n; cin>>n>>k;
    vector<int> v(n);
    //set<int> ss;
    LL an = 1e17;
    forn(i,n) {
      cin>>v[i];
      int z = 0;
      int g = v[i];
      while(g){
       //   ss.insert(g)
          if(ss[g].size()<k){
            ss[g].push(z);
            ans[g]+=z;
          }
          else{
            if(ss[g].top() > z){
              ans[g]+= z - ss[g].top();
              ss[g].pop();
              ss[g].push(z);
            }
          }
          if(ss[g].size()==k)
            an = an < ans[g]? an: ans[g];
          z++;
          g>>=1;
      }
    }
    //LL an = 1e17;
    /*for(auto i:ss){
      LL cn = 0;
      int zz = 0;
//      cout<<i.fi<<": ";
      if(s[i].size()<k) continue;
        for(auto c: s[i]){
          if(zz == k) break;  
          cn+=c;
  //      cout<<c<<" ";
          zz++;
      }
//      cout<<endl;
      if(zz==k)
        an = an > cn? cn:an;
    }*/
    cout<<an<<endl;
     
    return 0;
}

