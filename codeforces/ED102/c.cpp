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
  int t; cin>>t;
  while(t--){
  	LL n, k; cin >> n >> k;
  	if(n == k){
  		for1(i,n)
  			cout << i << " ";
  		cout << endl;
  		continue;
  	}
  	int kk = n - k;
  	vector <LL> an(k);
  	for(int i = 0; i < k; i++)
  		an[i] = i +1;
  	for(int i = 0; i <= (kk); i++)
  		an[k - 1 - (i)] = k  - (kk + 1) + i + 1;
  	for(auto i : an )
  		cout << i << " ";
  	cout << endl;
  }
  return 0;
}