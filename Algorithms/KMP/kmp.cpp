#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define forr(i,n) for(int i=(n);i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

struct KMP{
	vi pi;
	string s;
	KMP(string &s): s(s){
		build();
	};
	void build(){
		pi.resize(sz(s));
		for1(i, sz(s)-1) {
			int j = pi[i-1];
			while(j > 0 && s[i]!=s[j]) j = pi[j-1];
			if(s[i]==s[j]) j++;
			pi[i] = j;
		}
	}
};

int main(){
  fio();
  string s; cin>>s;
  KMP k(s);
  for(auto i:k.pi) cout<<i<<" ";
  	cout<<endl;
  return 0;
}