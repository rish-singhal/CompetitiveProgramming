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
    forn(o,t){
      LL n,m; cin>>n>>m;
      vector<int> v;
      v.pb(m%10);
      for(LL i=2*m; i%10!=v[0];i+=m)
        v.pb(i%10);
    
      LL ss =0;
      for(auto i:v){
        ss+=i;
//        cout<<i<<" ";
      }
  //    cout<<endl;

      LL pp = n/m;
      LL an = (pp/v.size())*ss;
      int z = 1;
       LL kk = pp%v.size();
      for(int i=0 ;i <kk ; i++){
 //         if(z>kk) break;
          an += v[i];
 //         kk++;
      }
      cout<<an<<endl;
    }return 0;
}

