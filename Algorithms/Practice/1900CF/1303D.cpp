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
  	LL n,m; cin>>n>>m;
  	vector<int> v(64);
  	forn(i,m){
  		LL x; cin>>x;
  		forn(i,64) if(x>>i&1) v[i]++;
  	}
  	forn(i,64){
  		if(n>>i&1) v[i]--;
  	}
  	// forn(i,7) cout<<v[i]<<" ";
  	// cout<<endl;
  	int cnt = 0;
  	for(int i=0;i<64;i++){
  		if(v[i]==1) cnt=0;
  		if((v[i]/2)>0){
  			int k = (v[i]/2);
  			if(cnt){
  				k = ((v[i]-1)/2);
  				cnt = 0;
  			}
  			v[i]-=k*2;
  			v[i+1]+=k;
  		}	
  		if(v[i]<0) cnt++;
  	}
  	// forn(i,10) cout<<v[i]<<" ";
  	// cout<<endl;
  	LL an = 0;
  	int  b = 0;
  	for(int i=63; i>=0;i--){
  		if(v[i]>=0) continue;
  		int j = i+1;
  		while(j<64 && v[j]<=0) j++;
  		if(j==64){
  			cout<<-1<<endl;
  			b = 1;
  			break;
  		}
  		while(j>i && j>=1){
  			//if(v[j]<1) continue;
  			v[j]-=1;
  			v[j-1]+=2;
  			an++;
  			j--;
  		}
  		if(v[i]<0){
  			cout<<-1<<endl;
  			b = 1;
  			break;
  		} 
  	}
  	if(b) continue;
  	cout<<an<<endl;
  }	
  return 0;
}