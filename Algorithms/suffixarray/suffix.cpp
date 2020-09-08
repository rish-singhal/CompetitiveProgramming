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

struct suffix{
	vector<int> p, c, lcp;
	int n;
	string s;
	suffix(string s): s(s){
		n = s.size();
		p.resize(n+1);
		c.resize(n+1);
		build();
	}
	void rsort(vector<int> &p, vector<int> &c){
		vector<int> cn(n);
		forn(i,n) cn[c[p[i]]]++;
		vector<int> po(n);
		po[0] = 0;
		for1(i,n-1) po[i] = cn[i-1] + po[i-1];
		vector<int> np(n);
		forn(i,n){
			np[po[c[p[i]]]++] = p[i];
		}
		p = np;
	}
	void build(){
		vector<pair<int,int>> v;
		forn(i,n) v.pb({s[i],i});
		sort(all(v));
		forn(i,n) p[i] = v[i].se;
		c[p[0]] = 0;
		for1(i,n-1){
			if(s[p[i]] == s[p[i-1]]){
				c[p[i]] = c[p[i-1]];
			}
			else
				c[p[i]] = c[p[i-1]] + 1;
		}	
		int k = 0;
		while((1LL<<k) <= n){
			forn(i,n){
				p[i] = (p[i] - (1LL<<k) + n)%n;
			}
			rsort(p, c);
			vector<int> nc(n);
			nc[p[0]] = 0;
			for1(i,n-1){
				pair<int,int> a = {c[p[i]], c[(p[i] + (1LL<<k))%n]};
				pair<int,int> b = {c[p[i-1]], c[(p[i-1] + (1LL<<k))%n]};
				if(a == b)
					nc[p[i]] = nc[p[i-1]];
				else
					nc[p[i]] = nc[p[i-1]] + 1;
			}
			c = nc;
			k++;	
		}
	}
};


int main(){
  fio();
  string s; cin>>s;
  s += "$";
  suffix suff(s);
  int q; cin>>q;
  while(q--){
  	string qs; cin>>qs;
  	int L = 0, R = suff.n;
  	while(L < R){
  		int M = L + (R-L)/2;
  		if(s.substr(suff.p[M],qs.size()) >= qs){
  			R = M;
  		}
  		else L = M+1;
  	}
  	int an1 = L;
  	L = 0, R = suff.n;
  	while(L < R){
  		int M = L + (R-L)/2;
  		if(s.substr(suff.p[M],qs.size()) > qs){
  			R = M;
  		}
  		else L = M+1;
  	}
  	cout<<(L - an1)<<endl;
  }
  return 0;
}