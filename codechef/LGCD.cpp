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
    forn(i,t){
    int n,k;
    cin >> n;
    map<int,LL> m;
    forn(i,n) { cin>>k; m[k]++;}
    LL an =0;
    for(auto i:m)
      if(m.find(2*i.fi)!=m.end())
        an+=i.se*m[2*i.fi];
    cout<<an<<endl;
    }
    return 0;
}
