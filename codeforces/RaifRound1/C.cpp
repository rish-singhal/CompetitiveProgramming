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
// check MAXN


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	string s; cin>>s;
  	vector<int> cnt(2);
  	for(auto i:s){
  		cnt[i - 'A']++;
  	}
  	// if(!cnt[0] || !cnt[1]){
  	// 	cout<<cnt[0] + cnt[1]<<endl;
  	// 	continue;
  	// }
  	int cn = 0;
  	int an = 0;
  	reverse(all(s));
  	for(auto i : s){
  		if(i == 'B') cn++;
  		else{
  			if(cn > 0){
  				cn--;
  			}
  			else an += 1;
  		}
  	}
  	if(cn&1) an ++;
  	cout<<an<<endl;
  }
  
  return 0;
}