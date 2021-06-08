#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
 
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t;
  cin >> t;
  while(t--) {
  	int n;
  	cin >> n;
  	vector<int> v(n);
  	ordered_set cmn, plus, minus;
  	forn(i, n) {
  		cin >> v[i];
  	}
  	multiset <int> cmn, plus, minus;
  	forn(i, n){
  		int lowcnt = cmn.order_of_key(v[i])
  		auto highcnt = cmn.order_of_key(cmn.upper_bound(v[i]));
  		int cnt = highcnt - lowcnt;
  		cout << lowcnt << " " << highcnt << " " << cnt << endl;
  		cmn.insert(v[i]);
  	}

  }
  return 0;
}