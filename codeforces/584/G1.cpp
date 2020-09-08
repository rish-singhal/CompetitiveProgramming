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
    int n,q ;cin>>n>>q;
    vector <int> v(n);
    map <int,int> cnt,ls;
    forn(i,n) {
      cin>>v[i];
      cnt[v[i]]++;
      ls[v[i]]=i;
    }
    int an =0;
    for(int i=0;i<n;)
    {
      int r = ls[v[i]];
      int c = 0 ;
      int cc = cnt[v[i]];
      int j;
      for( j=i;j<=r;j++){
        r = max(r,ls[v[j]]);
        cc = max(cc,cnt[v[j]]);
        c++;
      }
      i = j;
      an += -cc+c;
    }
    cout<<an<<endl;
    return 0;
}

