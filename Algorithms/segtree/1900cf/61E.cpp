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
const int MAXN = 1e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n; 
vector<int> v;
vector<int> a;
LL t[2][MAXN];

void up(int i, LL v, int x){
	while(i<=n){
		t[x][i]+=v;
		i+=i&-i;
	}
}

LL qu(int i, int x){
	LL an = 0;
	while(i>0){
		an = an + t[x][i];
		i-=i&-i;
	}
	return an;
}

int main(){
  fio();
  cin>>n;
  v.resize(n);
  a.resize(n);
  forn(i,n) cin>>v[i];
  map<int,int> m;
  forn(i,n){
  	m[v[i]] = i;
  }
  sort(all(v));
  forn(i,n){
  	a[m[v[i]]] = i+1;
  }
  reverse(all(a));
  LL an = 0;
  forn(i,n){
  	LL to = qu(a[i]-1,0);
  	an += qu(a[i]-1,1);
  	up(a[i], to, 1);
  	up(a[i], 1, 0);
  }
  cout<<an<<endl;
  return 0;
}