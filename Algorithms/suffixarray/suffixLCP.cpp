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
		p.resize(n);
		c.resize(n);
		build();
		buildlcp();
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
	void buildlcp(){
		lcp.resize(n-1);
		int k = 0;
		forn(i,n-1){
			int in = p[c[i]];
			int inb = p[c[i]-1];
			int dd = 0;
			in += k;
			inb += k;
			while(s[in++] == s[inb++]) dd++;
			lcp[c[i]-1] = dd + k;
			k = max(dd + k - 1,0);
		}	
	}
};


int main(){
  fio();
  string s; cin>>s;
  s += "$";
  suffix suff(s);
  for(auto i:suff.p) cout<<i<<" ";
  cout<<endl;
  for(auto i:suff.lcp) cout<<i<<" ";
  cout<<endl; 

  return 0;
}