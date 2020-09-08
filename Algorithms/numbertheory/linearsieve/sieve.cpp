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
const int MAXN = 1e7 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector<LL> prime;
bool comp[MAXN];
LL f[MAXN];

void seive(){
	fill(comp,comp+MAXN,0);
	f[1] = 1;
	for(int i=2;i<=MAXN;i++){
		if(!comp[i]){
		// function for f(p)
		// an[i] = 
		 prime.pb(i);
		}
		for(auto p:prime){
			if(p*i>MAXN) break;
			comp[p*i] = 1;
			if(!(i%p)) {
			// function for f(p*i) when p|i
			//	ans[p*i] = (ans[i/cnt[i]])*(ans[cnt[i]]+cnt[p*i]*(cnt[p*i]-cnt[i]));
				break;
			}
			else{
				f[p*i] = f[p]*f[i];			
			}
		}
	}
}

int main(){
  fio();
  seive();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	cout<<f[n]<<"\n";
  }  
  return 0;

}