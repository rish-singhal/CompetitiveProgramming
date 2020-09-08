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
const LL m = 1e9 + 7;
const int N = 200005;
LL phi[N];
LL nCr[N];
LL an[N];
LL k;
vector <LL> di[N];
LL po(LL a, LL n){
  if(n==0) return 1;
  LL an = po(a,n/2);
  an = (an*an)%m;
  if(n&1) an = (an*a)%m;
  return an;
}


void ini(int n){ 
 nCr[k] = 1;
 for(int i= k+1;i<n;i++){
   nCr[i] =( ((nCr[i-1]*i)%m)*po(i-k,m-2))%m;
    }
  phi[1] = 1;
  for1(i,n-1) phi[i]=i;
    for(LL i=2;i<n;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(LL j=2*i;j<n;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    } 
  
  for(LL i=1;i<n;i++)
    for(LL j=i;j<n;j+=i)
      di[j].pb(i);
  
  an[k] = 1;
  for(LL d=k+1;d<n;d++)
  {
    an[d] = an[d-1];
    for(auto i:di[d]){
      an[d] = (an[d] + (phi[i]*(m + nCr[d/i] - nCr[d/i-1])%m))%m;
    }
  }

 for(LL d=k+1;d<n;d++)
    {
     an[d] = (an[d]*po(nCr[d],m-2))%m;
//      cout<<an[d]<<endl;
    }
    }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int q;
    cin>>q>>k;
    ini(N);
    while(q--){
      int a; cin>>a;
      cout<<an[a]<<endl;
    }

    return 0;
}

