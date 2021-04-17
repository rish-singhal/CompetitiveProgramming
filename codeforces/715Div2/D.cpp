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

void solve2(string a, string b, int k){
	int su1 = 0, su2 = 0;
	for(auto i:a){
		if(k + '0' == i) su1++;
	}
	for(auto i:b){
		if(k + '0' == i) su2++;
	}
	if(su1 < su2){
		swap(a, b);
	}	
	// a have more number of ones
	int p1 = 0, p2 = 0;
	k ^= 1;
	vector <int> vv;
	int su = 0;
	char back = '9';
	for(auto i: b){
		if(back == '9' || i == back){
			su ++;
		}
		else{
			vv.pb(su);
			su = 1;
		}
		back = i;
	}
	vv.pb(su);

	int cnt = 0;
	//cout << a << " " << b << endl;
	//for(auto i: vv){
	//	cout<<i<<" ";
	//}
	//cout << endl;
	string ans = "";
	if(b[0] == k + '0'){
		forn(i,vv[0]) ans+= (k + '0');
		cnt++;
	}
	int cnt2 = 0;
	while(cnt2 < sz(a)){
		if(a[cnt2] != (k+'0') && cnt < sz(vv)){
			vv[cnt]--;
		}
		ans += a[cnt2];
		if(cnt < sz(vv) && vv[cnt] == 0){
			if(cnt + 1 < sz(vv)){
				cnt++;
				forn(i,vv[cnt]) ans+= (k + '0');
				cnt++;
			}
		}
		cnt2++;
	}
	cout << ans << endl;
}

void solve(){
	int n; cin >> n;
	vector <pair<int,string>> s;
	forn(i, 3 ){
		string k; cin >> k;
		int cnt = 0;
		for(auto i:k){
			cnt += (i == '0');
		}
		if(cnt >= n){
			s.push_back({0, k});
		}
		else s.push_back({1, k});
	}
	sort(all(s));
	if(s[0].fi != s[1].fi){
		reverse(all(s));
	}
	solve2(s[0].se, s[1].se, s[0].fi);
}

int main(){
  fio();
  int t; cin >> t;
  while(t--){
  	solve();
  } 
  return 0;
}