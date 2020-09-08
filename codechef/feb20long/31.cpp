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
      int n,m; cin>>n>>m;
      vector<int> xp(100005),xn(100005),yp(100005),yn(100005);
      int zx = 0,zy = 0;
      
      forn(i,n){
        int k; cin>>k;
        if(k==0) zx = 1;
        else if(k>0) xp[k]=1;
        else xn[-k]=1;
      }
      
      forn(i,m){
        int k; cin>>k;
        if(k==0) zy = 1;
        else if(k>0) yp[k]=1;
        else yn[-k]=1;
      }

      LL an = 0;
      for(int i=1;i<100001;i++){
        if(!xp[i]) continue;
        int k = 1;
        int p = i ;
        for(int j=2;j*j<=p;j++){
          int a = 0;  
          while(p%j==0){
              p/=j;
              a^=1;
          }
          k *= (a==1?j:1);
        }
        k*=p;
        for(int j=1;j*j*k<=100000;j++)
        {if(!xn[j*j*k]) continue;
            an += yp[(int)sqrt((long)j*j*(long)k*i)] + yn[(int)sqrt((long)j*j*(long)k*i)];

        }
      }

      for(int i=1;i<100001;i++){
        if(!yp[i]) continue;
        int k = 1;
        int p = i ;
        for(int j=2;j*j<=p;j++){
          int a = 0;  
          while(p%j==0){
              p/=j;
              a^=1;
          }
          k *= (a==1?j:1);
        }
        k*=p;
        for(int j=1;j*j*k<=100000;j++)
        { if(!yn[j*j*k]) continue;
            an += xp[(int)sqrt((long)j*j*(long)k*i)] + xn[(int)sqrt((long)j*j*(long)k*i)];

        }
      }
      if(zx || zy) an += (long)(n-zx)*(long)(m-zy);
      cout<<an<<endl;
    }
      
    return 0;
}

