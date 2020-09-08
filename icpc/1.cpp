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
      map <string, int> s;
      map <string, int> ss,ch;
      
      forn(i,n){
        string a; int b; cin>>a>>b;
        if(b){
          ss[a]++;
        }
        else{
          s[a]++;
        }
      }
      LL an =0;
      for(auto i:s){
        an+=max(s[i.fi],ss[i.fi]);
        ch[i.fi] = 1;
      }
      for(auto i:ss){
        if(ch[i.fi]) continue;
        an+=max(s[i.fi],ss[i.fi]);
      }
      cout<<an<<endl;
    }
    return 0;
}

