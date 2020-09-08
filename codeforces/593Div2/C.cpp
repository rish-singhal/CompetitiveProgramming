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
    int m[n][n];
    int c = 1;
    int p = 0;
    forn(i,n){
      forn(j,n){
        int k = j;
        if(p&1) k = n-k-1;
        m[k][i] = c;
        c++;
      }
      p++;
    }
    forn(i,n){
      forn(j,n) cout<<m[i][j]<<" ";
      cout<<endl;
    }
        return 0;
}

