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
const int MAXN = 5e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n;
int a[MAXN];

int f(int l, int r){
	int mi = INT_MAX;
	for(int i=l;i<=r;i++) mi = min(mi, a[i]);
	for(int i=l;i<=r;i++) a[i]-=mi;
	int b = l;
	int an = mi;
	for(int i=l;i<=r;i++){
		if(a[i]==0){
			if(i!=b) an+=f(b,i-1);
			b = i+1;
		}
	}
	if(a[r]!=0 && r>=b) an+=f(b,r);
	return min(an, r-l+1);
}

int main(){
  fio();
  cin>>n;
  forn(i,n) cin>>a[i];
  cout<<f(0,n-1)<<endl;
  return 0;
}