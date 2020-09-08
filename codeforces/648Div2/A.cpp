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

int main(){
  fio();
  int t; cin>>t;
  while(t--){ 
  	int n; cin>>n;
  	vector<int> v(n) ,bb(n);
  	vector<int> l, r, rr,ll;
  	vector<pair<int,int>> vv;
  	vector<int> vk;
  	forn(i,n){
  		cin>>v[i];
  		vk.pb(v[i]);
  	}
  	int cnt = 0;
  	forn(i,n){
  	 cin>>bb[i];
  	 cnt+=bb[i];
  	}
  	if(cnt==0 || cnt==n){
  		sort(all(vk));
  		if(v==vk){
  			cout<<"YES"<<endl;
  		}
  		else cout<<"NO"<<endl;
  	}
  	else{
  		cout<<"YES"<<endl;
  	}
  	
  }
  return 0;
}