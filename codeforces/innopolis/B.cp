#include<bits/stdc++.h>
using namespace std;
#define typeof decltype
#define LL long long
#define pii pair<int,int> 
#define vi vector<int> 
#define vii vector<pii>
#define srt(a) sort(a.begin(),a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template <class T> bool uin(T &a, T b){ return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

int n; cin>>n;
string s; cin>>s;
auto chk = [&](int k) {
    int count=  0;
    forn(i,k){
        if(s[i]=='1') count++;
    }
    if(count<3) return 0;
    for(int i=1;i+k-1<n;i++)
        if(s[i-1]=='1') count --;
        if(s[i+k-1]=='1') count++;
        if(count<3) return 0;
    }
    return 1;
};

int l = 1, r = n;
while(l<r){
    int m = l + (r-l)/2;
    if(chk(m))
        r = m;
    else 
        l = m+1;
}
cout<<l<<endl;
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}