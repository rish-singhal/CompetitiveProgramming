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
      string s,t; cin>>s>>t;
      vector <int> v[26];
      for(int i=0;i<s.size();i++){
        v[s[i]-'a'].pb(i);
      }
      LL c = 1;
      int p = -1;
      bool b = true;
      for(int i=0;i<t.size();i++){
        if(v[t[i]-'a'].size()==0){
            b = 0;
            break;
        }
        auto j = upper_bound(all(v[t[i]-'a']),p);
        if(j!=v[t[i]-'a'].end())
        {
          p = *j;
        }
        else{
          c++;
          p = v[t[i]-'a'][0];
        }
//        cout<<"--- "<<p<<endl;
      }
      if(!b){
        cout<<-1<<endl;
      }
      else 
        cout<<c<<endl;
    }
    return 0;
}

