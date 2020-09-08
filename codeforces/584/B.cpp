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
    int n; cin>>n;
    string s; cin>>s;
    vector <int> m(n);
    for(int i=0;i<n;i++)
      m[i] = s[i]-'0';
    vector <pair<int,int> > p(n);
    forn(i,n){
      int a,b; cin>>a>>b;
      p[i] = make_pair(a,b);
    }
    int mx = -1;
    for(int i =0;i<=1000005;i++){
      int an = 0;
      for(int j=0;j<n;j++)
      {
        if(i==p[j].se) m[j]^=1;
        if(i> p[j].se && (i-p[j].se)%p[j].fi==0) m[j]^=1;
        an+=m[j];
      }
      mx = max(an,mx);
    }
    cout<<mx<<endl;
    return 0;
}

