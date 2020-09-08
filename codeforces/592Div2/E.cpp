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
    LL n,k; cin>>n>>k;
    vector <LL> v(n);
    forn(i,n) cin>>v[i];
    srt(v);
    LL an = v[n-1] - v[0];
    for(int i=0;i<n/2;i++){
      if((v[i+1]-v[i])*(i+1)<=k){
        k-=(v[i+1]-v[i])*(i+1);
        v[i]=v[i+1]; 
      }
      else{
        v[i]+=k/(i+1);
        k = 0; 
      }
      if((-v[n-i-2]+v[n-i-1])*(i+1)<=k){ 
       k-=(-v[n-i-2]+v[n-i-1])*(i+1);
       v[n-i-1]=v[n-i-2]; 
      }
      else{
        v[n-i-1]-=k/(i+1);
        k = 0; 
      }
     // cout<<k<<endl;
      an = v[n-i-1] - v[i];
      if(k==0) break;
    }
  //  for(auto i:v) cout<<i<<" ";
  //  cout<<endl;
    cout<<an<<endl;
    return 0;
}

