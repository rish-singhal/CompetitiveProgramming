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
      LL a,b,c; cin>>a>>b>>c;
      string s; cin>>s;
      string bb = s;
      for(auto &c:s)
        if(c=='S') c = 'R';
        else if(c=='R') c='P';
        else c = 'S';
      int cnt = 0;
      for(int i=0;i<n;i++){
        if(s[i]=='R'){
          if(a){
            bb[i] = 'R';
            cnt++;
          a--;
        }
       else if(s[i]=='P'){
          if(b){
            bb[i] = 'P';
            cnt++;
          }
          b--;
        }
       else if(s[i]=='R'){
          if(c){
            cnt++;
            bb[i] = 'R';
          }
          c--;
        }
        }
        if(cnt>=(n+1)/2){
          cout<<"YES"<<"\n"<<bb<<endl;
        }
        else cout<<"NO\n";
        }
      }
    return 0;
}

