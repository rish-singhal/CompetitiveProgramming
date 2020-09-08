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
LL mm = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    string s; cin>>s;
    int cnt=  0;
    vector <LL> v;
    int bb = 0;
    for(int i=0;i<s.size();i++){
      if(s[i] =='m' || s[i] =='w'){
        bb = 1;
        cout<<0<<endl;
        return 0;
      }

      if(s[i] == 'u'){
          cnt++;
        }
        else{
          if(cnt) v.pb(cnt);
          cnt = 0;
        }
    }
          if(cnt) v.pb(cnt);
          cnt = 0;
  
    for(int i=0;i<s.size();i++){
        if(s[i] == 'n'){
          cnt++;
        }
        else{
          if(cnt) v.pb(cnt);
          cnt = 0;
        }
    }
    if(cnt) v.pb(cnt);
    cnt = 0;
    LL ff[100005];
    ff[1] = 1;
    ff[2] = 2;
    for(int i =3;i<100005;i++){
      ff[i] = (ff[i-1] + ff[i-2])%mm;
    }
    LL an = 1;
    for(auto i:v){
      an = (an*ff[i])%mm;
    }
    cout<<an<<endl;
    return 0;
}

