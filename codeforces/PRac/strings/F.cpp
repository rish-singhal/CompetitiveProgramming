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
  int n;  cin>>n;
  vector<string> s(n);
  forn(i,n) cin>>s[i];
  vector<string> an(n);
  an[0] = s[n-1];
  for(int i=n-2, p=0; i>=0; i--, p++){
  	string k = "";
  	int b=0;
  	for(int j=0;j<min(s[i].size(),an[p].size());j++){
  		if(s[i][j]==an[p][j]){
  			k+=s[i][j];
  		}
  		else if(s[i][j]<an[p][j]){
  			k = s[i];
  			break;
  		}
  		else{
  			break;
  		}
  	}
  	an[p+1] = k;
  }
  reverse(all(an));
  for(auto i:an) cout<<i<<endl;
  return 0;
}