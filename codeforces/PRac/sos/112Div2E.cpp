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
    vector <int> v(n);
    forn(i,n) cin>>v[i];
    vector <int> F(1<<22,-1);
    for(auto i:v) F[i] = i;
    for(int i=0;i<22;i++)
      for(int msk = 0;msk<(1<<22);msk++)
        if(msk&(1<<i)) F[msk] = max(F[msk],F[msk^(1<<i)]);
    
    for(auto i:v)
      cout<<F[((1<<22)-1)^i]<<" ";
    cout<<endl;
    return 0;
}

