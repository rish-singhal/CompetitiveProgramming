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
const int MAXN = 1e7 +5;

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
  	priority_queue <pair<int,int>> pq;
  	pq.push({n,MAXN-1});
  	vector <LL> an(n+1);
  	int cnt = 0;
  	while(!pq.empty()){
  		auto x = pq.top();
  		int l = MAXN - x.se;
  		int r = l + x.fi - 1;
  		pq.pop();
  		//cout<<l<<" "<<r<<" : "<<endl;
  		int m = (l+r)/2;
  		an[m] = ++cnt;
  		if(m-1>=l){
  		//	cout<<(l)<<" "<<(m-1)<< "---- "<<endl;
  			pq.push({m-1-l+1, MAXN - l});
  		}
  		if(m+1<=r){
  			//cout<<(m+1)<<" "<<(r)<<" ** "<<endl;
  			pq.push({r-(m+1)+1, MAXN - (m+1)});
  		}
  	}
  	//cout<<"annn --- : ";
  	for1(i,n) cout<<an[i]<<" ";
  	cout<<endl;
  }
  return 0;
}