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
const LL mm  =  1e9 + 7;
LL po(LL a,LL n){
    if(n==0) return 1;
    LL an = po(a,n/2);
    an = an*an%mm;
    if(n&1) an =(an*a)%mm;
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL n,m;cin>>n>>m;
    cout<<(po(po(2,m)-1,n))<<endl;
    return 0;
}

