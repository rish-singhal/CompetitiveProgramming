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
const LL mm = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      LL a,b,c; cin>>a>>b>>c;
      vector<LL> m(a*c+1);
      for(LL i=1;i<=a-1;i++)
        for(LL j=1;j<=c-1;j++)
          m[i*j]++;
      vector <LL> v(b*b+2);
      for(LL i = 1;i<=b;i++)
        v[i*i+1]=1;
      for(LL i =1;i<v.size();i++)
        v[i]+=v[i-1];
      LL an= 0;
      for(int i=1;i<=m.size();i++)
      { //cout<<i.fi<<" "<<i.se<<" "<<v[i.fi]<<endl;
        an = ( an + m[i]*(v[min((LL)i,(LL)v.size()-1)]))%mm;
      }
        cout<<an<<endl;
    }
        
    return 0;
}

