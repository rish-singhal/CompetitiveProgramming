#include<bits/stdc++.h>
using namespace std;
typedef long long LL
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

vector <int> cnt(4);

bool check(){
	for1(i,3) if(cnt[i]==0) return 0;
	return 1;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	for1(i,3) cnt[i] = 0;
  	string s; cin>>s;
  	int l = 0;
  	int an = 1e9;
  	for(int i=0;i<s.size();i++){
  		cnt[s[i]-'0']++;
  		while(cnt[s[l]-'0']>=2 && l<=i){
  			cnt[s[l]-'0']--;
  			l++;
  		}
  		if(check()){
  			an = min(an, i-l+1);
  		}
  	}
  	cout<<(an==1e9?0:an)<<endl;
  }
  return 0;
}