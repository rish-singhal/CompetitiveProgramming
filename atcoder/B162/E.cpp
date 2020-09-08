#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;
const LL m = 1e9+7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<LL> pr;
LL phi[MAXN];

LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) an = (an*a)%m;
	return an;
}

int main(){
  fio();
  LL n,k; cin>>n>>k;
  LL an = po(k,n);
  for(LL i=2; i<=k; i++){
  	if(phi[i]==0){
  		pr.pb(i);
  		phi[i] = i-1;
  	}
  	an = (an + po(k/i,n)*phi[i])%m;
  	for(auto p:pr){
  		if(i*p>k) break;
  		if(i%p==0){
  			phi[i*p] = (p*phi[i])%m;
  			break;
  		}
  		else{
  			phi[i*p] = (phi[i]*phi[p])%m;
  		}
  	}
  }
  cout<<an<<endl;
  return 0;
}