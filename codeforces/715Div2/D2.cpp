#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	int n; cin >> n;
  	vector <string> s(3);
  	forn(i, 3) cin >> s[i];
  	for(auto c :{'0','1'}){
  		vector <int> cnt(3);
  		forn(i, 3){
  			for(auto d: s[i])
  				if(d == c) cnt[i]++;
  		}
  	vector<int> ord(3);
  	iota(all(ord), 0);
  	sort(all(ord), [&](int i, int j){
  		return cnt[i] > cnt[j];
  	});
  	if(cnt[ord[1]] >= n){
  		string ans = "";
  		int i = 0, j=0;
  		while(i < 2*n || j < 2*n){
  			char nxt;
  			if((i < 2*n && s[ord[0]][i] != c) || (j < 2*n && s[ord[1]][j] != c))
  				nxt = (char) (c^'0'^'1');
  			else 
  				nxt = c;
  			ans += nxt;
  			if(i < 2*n && s[ord[0]][i] == nxt)
  				i++;
  			if(j < 2*n && s[ord[1]][j] == nxt)
  				j++;
  		}
  		cout << ans << endl;
  		break;
  	  }
    }
  }
  return 0;
}