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

// 1111000000
// 0000011111

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	string s; cin>>s;
  	int n = s.size();
  	vector<int> pr2(n), pr(n);
  	forn(i,n){
  		pr[i] = (s[i]=='1') + (i>=1?pr[i-1]:0);
  		pr2[i] = (s[i]=='0') + (i>=1?pr2[i-1]:0);
  	}
  	int mi = 1e8;
  	int cnt = 0, cnt2 = 0; //num of 0z
  	for(int i = n-1; i>=0; i--){
  		// to make all zeroes... 1s
  		int cc = pr[i] + cnt;
  		int cc2 = pr2[i] + cnt2;
  		mi = min({cc,mi,cc2});
  		cnt+=s[i]=='0';
  		cnt2+=s[i]=='1';
  	}
  	mi = min({mi,cnt,cnt2});
  	cout<<mi<<endl;
  }
  return 0;
}