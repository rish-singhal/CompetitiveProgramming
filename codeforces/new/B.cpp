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
      vector <string> v(n);
      map <string,int> m;
      set <string> s;
      for(auto &i:v){ 
        cin>>i;
        m[i]++;
        s.insert(i);
      }
      int an = 0;
      forn(i,n){
        if(m[v[i]]>1){
          m[v[i]]--;
          an++;
          int j = 0;
          while(s.find(v[i])!=s.end()){
            v[i][0] = j+'0';
            j++;
          }
          s.insert(v[i]);
          m[v[i]]++;
        }
      }
      cout<<an<<endl;
      for(auto i:v) cout<<i<<endl;
    }

      
    return 0;
}

