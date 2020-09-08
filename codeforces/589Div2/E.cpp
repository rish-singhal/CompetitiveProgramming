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
const LL m = 1e9+7;

LL add(LL a,LL b){
 a =(a+ b)%m;
 return a;
}

LL sub(LL a, LL b){
  a =(a - b + m)%m;
  return a;
}

LL mult(LL a, LL b){
  a = (a*b)%m;
  return a;
}

LL pw(LL a, LL n){
  if(n==0) return 1;
  LL an = pw(a,n/2);
  an = mult(an,an);
  if(n&1) an = mult(an,a);
  return an;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL n,k; cin>>n>>k;
    LL kp[n+1], kp1[n+1];
    kp[0]=kp1[0]=1;
    for1(i,n){
      kp[i] = mult(k,kp[i-1]);
      kp1[i] = mult(k-1,kp1[i-1]);
    }

    LL dp[n+1][n+1];
    LL ncr[n+1][n+1];
    forn(i,n+1) ncr[i][0] = ncr[i][i] =  1;
    
    for1(i,n)
      for1(j,i-1)
        ncr[i][j] = add(ncr[i-1][j], ncr[i-1][j-1]);
    
    for1(i,n)
      dp[1][i] = kp[n-i], dp[i][0] = pw(sub(kp[n],kp1[n]),i);
    
    for(int r=2;r<=n;r++)
      for1(c,n){
        dp[r][c] = mult(kp1[c],mult(sub(kp[n-c],kp1[n-c]),dp[r-1][c]));
        for1(cc,c)
          dp[r][c] = add(dp[r][c], mult(ncr[c][cc], mult( kp1[c-cc], mult(kp[n-c],dp[r-1][c-cc]))));
      }
    cout<<dp[n][n]<<endl;
    return 0;
}

