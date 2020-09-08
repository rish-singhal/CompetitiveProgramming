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
    while(t--){
      LL n,m; cin>>n>>m;
      if(n==1){
        if(m<=1) cout<<m<<endl;
        else cout<<-1<<endl;
        continue;
      }
      if(n==2){
        if(m==0) cout<<-1<<endl;
        else if(m<=2) cout<<m<<endl;
        else if(m==3) cout<<2<<endl;
        else  cout<<-1<<endl;
        continue;
      }
      if(m<n-1){
        cout<<-1<<endl; continue;
      }
      if(m*2>n*(n+1)){
         cout<<-1<<endl; continue;
      }
      
      if(m<=n+1)
        {cout<<2<<endl; continue;
        }
      if(m<=2*n){
        cout<<3<<endl; continue;
      }
      m-=2*n;
      LL an = 3 + 2*(m/n);
      if(m%n==0) an =an;
      else if(n/2 >= m%n) an++;
      else an+=2;
      cout<<an<<endl;
      }
    return 0;
}

