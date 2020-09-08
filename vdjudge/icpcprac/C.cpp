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
    vector <int> a(n+1);
    for1(i,n) cin>>a[i];
    LL an = 0;
    int ll[n],rr[n];
    for1(i,n){
      ll[i] = i-1;
      while( ll[i]>0 && a[ll[i]] <= a[i]) ll[i] = ll[ll[i]];
    }
    for(int i=n;i>=1;i--){
      rr[i] = i+1;
      while( rr[i]<=n && a[rr[i]] < a[i]) rr[i] = rr[rr[i]];
    }
    for1(i,n){
      an += (LL)a[i]*(i-ll[i])*(rr[i]-i);
    }
    
    for1(i,n) a[i] = -a[i];

    for1(i,n){
      ll[i] = i-1;
      while( ll[i]>0 && a[ll[i]] < a[i]) ll[i] = ll[ll[i]];
    }
    for(int i=n;i>=1;i--){
      rr[i] = i+1;
      while( rr[i]<=n && a[rr[i]] <= a[i]) rr[i] = rr[rr[i]];
    }
    for1(i,n){
      an += (LL)a[i]*(i-ll[i])*(rr[i]-i);
    }
    cout<<an<<endl;
    return 0;
}

