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
  while(t--) {
  	int n; cin>>n;
  	vector<int> v(n);
  	int cnt = 0;
  	forn(i,n) {
  		cin>>v[i];
  		cnt += v[i];
  	}
  	if(cnt > 1){
  		cout<<2<<endl;
  		cout<<1<<" "<<1<<endl;
  	}
  	else{
  		cout<<1<<endl;
  		cout<<0<<endl;
  	}
  }
  return 0;
}