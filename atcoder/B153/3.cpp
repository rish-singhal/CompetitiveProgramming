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
    LL n,k; 
    cin>>n>>k;
    vector <LL> v(n);
    forn(i,n) cin>>v[i];
    srt(v);
    reverse(all(v));
    LL an = 0;
    for(int i=k;i<n;i++){
        an += v[i];
    }
    cout<<an<<endl;
    return 0;
}

