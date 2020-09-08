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

LL dsu[MAXN];

LL pa(LL a){
	return dsu[a]<0? a: dsu[a] = pa(dsu[a]);
}

void join(LL a, LL b){
	a = pa(a);
	b = pa(b);
	if(a==b) return;
	if(dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b] = a;
}

int main(){
  fio();
  LL n,q; cin>>n>>q;
  forn(i,n+1) dsu[i] =  -1;
 while(q--){
 	LL l,r; cin>>l>>r;
 	int aa = l , bb = r;
 	while(1){
 		join(l,r);
 		if(r == aa && bb == l) break;
 		l++;
 		r--;
 	}
 	LL an = 0;
 	for1(i,n){
 		if(dsu[i]<0)an++ ;
 	}
 	cout<<an<<endl;
 }
  return 0;
}