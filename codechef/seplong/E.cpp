#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define repA(i,A)   for(auto i:A)

#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl

#define mp make_pair
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A) A.rbegin(),A.rend()
#define ft first
#define sd second

#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
#define Vpll vector<pll>

#define endl "\n"

const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

const ll N = 200005;

int add(ll a,ll b){
    if(a+b>=M)   return a+b-M;
    return a+b;
}

int mult(ll a,ll b){
    ll ans = (a*b);
    if(ans>=M)  ans%=M;
    return ans; 
}

int sub(ll a,ll b){
    if(a-b<0)   return (a-b+M);
    return a-b;
}

int power(ll a,ll n,ll m=M){
    ll ans=1;
    while(n){
        if(n&1) ans=ans*a;
        a=a*a;
        n=n>>1;
        ans=ans%m;
        a=a%m;
    }
    return ans;
}

ll phi[N];
int nCr[N];
int dp[N];
ll ans[N];
V divi[N];

void computetotient(ll n=N){
    rep(i,1,n+1) phi[i]=i;
    rep(i,2,n+1){
        if(phi[i]==i){
            phi[i]=i-1;
            for(ll j=2*i;j<n;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q,k;
    cin>>q>>k;
    nCr[k] = 1;
    rep(i,k+1,N){
        nCr[i] = mult(mult(nCr[i-1],i),power(i-k,M-2));
    }
    rep(i,1,N)  for(ll j=i;j<N;j+=i)    divi[j].pb(i);
    computetotient();
    ans[k]=1;
    rep(n,k+1,N){
        ans[n] = ans[n-1];
        for(auto i:divi[n]){
            ans[n] = add(ans[n], mult(phi[i] ,sub(nCr[n/i], nCr[n/i-1])));
        }
    }
    rep(n,k+1,N){
//        ans[n] = mult(ans[n], power(nCr[n], M-2));
    }
    while(q--){
        ll n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
