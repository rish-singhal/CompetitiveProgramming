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
 LL cnt[3];
int main(){
  fio();
  int n; cin>>n;

  string s; cin>>s;

  for(auto i:s){
  	if(i=='R') cnt[1]++;
  	if(i=='G') cnt[2]++;
  	if(i=='B') cnt[0]++;
  }
  LL an = (cnt[1]*cnt[2]*cnt[0]);
//  cout<<an<<endl;
  for(int i=0;i<=(n-3);i++){
  	for(int j=i+2;j<n;j+=2){
  		if(s[i]!=s[j] && s[(i+j)/2]!=s[i] && s[(i+j)/2]!=s[j] ){
  			an--;
  		}
  	}
  }
  cout<<an<<endl;
  return 0;
}