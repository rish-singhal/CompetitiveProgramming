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
  while (t--) {
  	LL n, m; cin >> n >> m;
  	if(m < n) {
  		cout << 0 << endl;
  		continue;
  	}
  	vector <LL> vn(32, 0), vm(32, 0) ,an(32, 0);
  	forn(i, 32) {
  		vn[i] = ((n >> i) & 1);
  		vm[i] = ((m >> i) & 1);
  	}
  	LL ann = 0;
  	int b = 0;
  	for(int i = 31; i >= 0; i--) {
  		if(vm[i] > vn[i]) {
  			an[i] = 1;
  			ann += (1 << i);
  		}
  		else if(vm[i] < vn[i]) {
  			b = 1;
  			break;
  		}
  		else {
  			continue;
  		}
  	}
  	if(b) {
  		cout << ann << endl;
  		continue;
  	}
  	b = 0;
  	int k = 0;
  	for(int i = 0; i <= 31; i++) {
  		if(an[i] == 0 && vm[i] == 0) {
  			an[i] = 1;
  			b = 1;
  			k = i;
  			ann += (1LL << i);
  			break;
  		}
  	}
  	assert(b == 1);
  		for(int i = 0; i < k; i ++){
  			if(an[i]) ann -= (1LL << i);
  		}
  	
  	cout << ann << endl;
  }
  return 0;
}