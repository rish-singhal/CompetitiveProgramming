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
const int MAXN = 2e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


LL bit[MAXN];
int n; 

void up(int x, LL v){
	x+=1;
	while(x<=(n+1)){
		bit[x]+=v;
		x+=x&-x;
	}
}

LL qu(int x){
	x+=1;
	LL an = 0;
	while(x>0){
		an+=bit[x];
		x-=x&-x;
	}
	return an;
}

vector<LL> v;

LL solve2(){
	vector<int> lma(n), rmi(n);
	stack <int> s;
	forn(i,n){
		while(!s.empty() && v[s.top()]<=v[i])
			s.pop();
		if(s.empty()) lma[i] = -1;
		else lma[i] = s.top();
		s.push(i);
	}

	while(!s.empty()) s.pop();

	for(int i=n-1;i>=0;i--){
		while(!s.empty() && v[s.top()]>=v[i])
			s.pop();
		if(s.empty()) rmi[i] = n;
		else rmi[i] = s.top();
		s.push(i);
	}

	///
	LL an = 0;
	vector<pair<int,int>> q;
	forn(i,n){
		q.pb({lma[i]+1,i});
		assert(lma[i]+1<=i);
		cout<<lma[i]+1<<" "<<i<<" --- "<<endl;
	}
	cout<<endl;
	sort(all(q));
	int l = q[0].fi;
	int rr = q[0].se;
	for(int i=l;i<=rr;i++){
		up(rmi[i]-1,1);
		//cout<<qu(n+1)<<endl;
	}
	an += qu(n+1) - qu(q[0].se-1);
	cout<<an<<endl;
	for1(i,n-1){
		while(l<q[i].fi){
			up(rmi[l]-1,-1);
			l++;
		}
		while(rr<q[i].se){
			up(rmi[rr]-1,-1);
			rr++;
		}
		while(rr>q[i].se){
			up(rmi[rr]-1,1);
			rr--;
		}
		an += qu(n) - qu(q[i].se-1);
	}
	return an;
}

void solve(){
	v.clear();
	cin>>n;
	forn(i,n+1) bit[i] = 0;
	v.resize(n);
	forn(i,n) cin>>v[i];
	LL an = solve2();
	forn(i,n+1) bit[i] = 0;
	reverse(all(v));
	an+=solve2();
	cout<<(an-n)<<endl;
}	

int main(){
  fio();
  int t; cin>>t;
  while(t--) solve();
  return 0;
}