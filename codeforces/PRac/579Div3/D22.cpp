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
    string a, b; cin>>a>>b;
    int n = a.size(), m = b.size();
    int pos = 0;
    vector <int> f(m), l(m);
    for(int i=0;i<n;i++){
       if(a[i]==b[pos])
         f[pos++] = i;
       if(pos == m) break;
    }
    pos--;
    for(int i=n-1;i>=0;i--){
      if(a[i]==b[pos])
        l[pos--] = i;
      if(pos==-1) break;
    }
    int an = max(l[0], n - f[m-1] -1 );
    for(int i=1;i<m;i++)
      an = max( an, l[i] - f[i-1]-1);
    cout<<an<<endl;
        
    return 0;
}

