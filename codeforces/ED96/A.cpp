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
  map <LL, vector<LL>> m;
  for(LL i = 0; i <= 1000; i+=3){
  	for(LL j = 0; j <= 1000; j+=5){
  		for(LL k = 0; k <= 1000; k+=7){
  			if(m.find(i+j+k)!=m.end()){
  				continue;
  			}
  			m[i+j+k] = {i/3, j/5, k/7};
  		}
  	}	
  }
  while(t--){
  	int n; cin>>n;
  	int k = n%3;
  	if(m.find(n)==m.end()){
  		cout<<-1<<endl;
  		continue;
  	}
  	for(auto i:m[n]) cout<<i<<" ";
  		cout<<endl;
  }
  return 0;
}