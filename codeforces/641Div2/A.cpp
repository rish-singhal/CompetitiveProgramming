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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


int main(){
  fio();
	int t; cin>>t;

	while(t--){
		LL n,k ;cin>>n>>k;
		LL b = -1;
		while(k>0){
			LL an = -1;
			for(LL i=2; i*i<=n;i++){
				if(n%i==0){
					an = i;
					break;
				}
			}
			if(an==-1) an = n;
			n+=an;
			k--;
			if(b==an) break;
			b = an;
		}
		cout<<(n + (k*b))<<endl;
	}  
  return 0;
}
