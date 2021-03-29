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

// CJ == X, JC == Y
// C???????C
// C???????J
// J???????C
// J???????J
// C???J
// 
// 2*X + 2*Y 
void solve() {
	LL x, y; cin >> x >> y;
	string s; cin >> s;
	int n = sz(s);
	LL an = 0;
	// if(x >= 0 && y >= 0) {
	// 	int b = -1;
	// 	for(int i = 0; i < n; i++) {
	// 		int k = s[i] - 'A';
	// 		if(s[i] == '?') continue;
	// 		if(k != b)
	// 		{
	// 			if(b != -1) {
	// 				if(s[i] == 'J')
	// 					an += x;
	// 				else 
	// 					an += y;
	// 			}
	// 			b = k;
	// 		}
	// 	}
	// 	cout << an << endl;
	// 	return;
	// }
	
	char b = 'A';
	int q = 0;
	for(int i = 0; i < n; i++) {
		char k = s[i];
		if(s[i] == '?') {
			q++; continue;
		}
		if(k != b) {
			if(b != 'A') {
				if(s[i] == 'J') {
					if(q == 0)
						an += x;
					else{
						q--;
						an += x;
						an += min(((q+1)/2)*(x+y), 0LL);
					}
				}
				else {
					if(q == 0)
						an += y;
					else{
						q--;
						an += y;
						an += min(((q+1)/2)*(x+y), 0LL);
					}
				}
			}
			else if(q != 0) {
				if(s[i] == 'J') {
					if(q % 2 == 0)
						an += min({(q/2)*(x+y), 0LL,x});
					else
					{
						an += min({((q)/2)*(x+y), x + ((q-1)/2)*(x+y), 0LL, x});
					}
				}
				else {
					if(q % 2 == 0)
						an += min({(q/2)*(x+y), 0LL, y});
					else
					{
						an += min({((q)/2)*(x+y), y + ((q-1)/2)*(x+y), 0LL, y});
					}
				}
			}
			b = k;
		}
		else {
			if(q != 0) {
				an += min(((q+1)/2)*(x+y), 0LL);
			}
		}
		q = 0;
	}
	if(q != 0) {
		if(b == 'C') {
			if(q % 2 == 0)
				an += min({(q/2)*(x+y), 0LL, x});
			else
			{
				an += min({((q)/2)*(x+y), x + ((q-1)/2)*(x+y), 0LL, x});
			}
		}
		else if(b == 'J'){
			if(q % 2 == 0)
				an += min({(q/2)*(x+y), 0LL, y});
			else
			{
				an += min({((q)/2)*(x+y), y + ((q-1)/2)*(x+y), 0LL, y});
			}
		}
		else {
			if(q%2 == 0){
				an += min({(q/2)*(x+y) - x, (q/2)*(x+y) - y, 0LL});
			}
			else {
				an += min({(q/2)*(x+y), 0LL});
			}
		}
	}
	cout << an << endl;

}

int main(){
  fio();
  int t; cin >> t;
  for1(i, t){
  	cout << "Case #" << i << ": ";
  	solve();
  }
  return 0;
}