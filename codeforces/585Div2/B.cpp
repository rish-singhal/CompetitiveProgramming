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
    forn(i,n){
        cin>>v[i];
        v[i] = (v[i]>=0)?1:-1;
    }
    vector <int> vv(n+1);
    vv[0] = 1;
    for1(i,n) vv[i]=v[i-1]*vv[i-1];
    LL cnt = 0;
    forn(i,n+1) cnt+=vv[i]==1;
    LL an = cnt*(cnt-1)/2 ;
    an  += (n+1-cnt)*(n+1-cnt -1)/2;
    LL an2 = (cnt)*(n+1-cnt) ;
    cout<<an2<<" "<<an<<endl;
    return 0;
}

