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

struct SuffixArray{
	vector<int> p, c, lcp;
	int n; string s;
	SuffixArray(string &s): s(s), n(s.size()){
		p.resize(n), c.resize(n), lcp.resize(n-1);
		vector<pair<char,int>> v;
		forn(i,n) v.pb({s[i],i});
		sort(all(v));
		forn(i,n) p[i] = v[i].se;
		for1(i,n-1) c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);
		int k = 0;
		while((1LL<<(k)) <= n){
			forn(i,n) p[i] = (p[i] - (1LL<<k) + n)%n;
			vector<int> cn(n), po(n,0), np = p, nc = c;
			forn(i,n) cn[c[np[i]]]++;
			for1(i,n-1) po[i] = cn[i-1] + po[i-1];
			forn(i,n) p[po[c[np[i]]]++] = np[i];
			for1(i,n-1){
				pair<int,int> a = {nc[p[i]], nc[(p[i] + (1LL<<k))%n]},
				b = {nc[p[i-1]], nc[(p[i-1] + (1LL<<k))%n]};
				c[p[i]] = c[p[i-1]] + (a!=b);
			} k++;
		} k = 0;
		forn(i,n-1){
			int in = p[c[i]] + k, inb = p[c[i]-1] + k, dd = k;
			while(s[in++] == s[inb++]) dd++;
			lcp[c[i]-1] = dd, k = max(dd - 1,0);
		}
	}
};

int main(){
  fio();
  string s; cin>>s;
  s += " ";
  SuffixArray sa(s);
  for(auto i:sa.p)
  	cout<<i<<" "<<s.substr(i,sa.n)<<endl;
  return 0;
}