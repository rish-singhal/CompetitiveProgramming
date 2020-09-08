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
      LL n,x; cin>>n>>x;
      string s;
      cin>>s;
      vector <LL> v;
      v.pb(0);
      LL o =0, c = 0;
      for(int i=0;i<s.size();i++){
          if(s[i]=='0') o++;
          else c++;
          v.pb(o-c);
      }
      LL k = v[v.size()-1];
       c =0;
       bool b = 0;
      for(int i=0;i<n;i++){
        if(k==0){
          c+=v[i]==x;
          b = 1;
        }
        else{
          if(abs(x-v[i])%abs(k)==0 && (x-v[i])*k>=0){
            c++;
          }
        }
      }
      if(b==1 && c) cout<<-1<<endl;
      else
      cout<<c<<endl;
    }
    return 0;
}

