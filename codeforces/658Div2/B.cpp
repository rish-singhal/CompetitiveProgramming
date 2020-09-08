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
  	int n; cin>>n;
  	int m = 0;
  	vector<int> v(n);
  	forn(i,n){
  		cin>>v[i];
  	}
  	if(n==1){
  		cout<<"First"<<endl;
  		continue;
  	}
  	int bb = 0;
  	forn(i,n){
  		if(v[i]>1){
  			if(m==0){
  				cout<<"First"<<endl;
  			}
  			else cout<<"Second"<<endl;
  			bb = 1;
  				break;
  		}
  		else{
  			m ^=1;
  		}
  	}
  	if(!bb){
  		if(m == 1){
  			cout<<"First"<<endl;
  		}
  		else{
  			cout<<"Second"<<endl;
  		}
  	}
  }
  return 0;
}