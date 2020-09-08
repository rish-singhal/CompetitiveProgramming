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
  string s; cin>>s;
  int n = s.size();
  int ma = -1;
  for(int i=0;i<n-1;i++){
  	int x = s[i]-'0';
  	int y = s[n-1]-'0';
  	string z = s;
  	if((x&1)==0 && y>x){
  		swap(s[i],s[n-1]);
  		cout<<s<<endl;
  		return 0;
  	}
  	if((x&1)==0) ma = i;
  }
  if(ma==-1) cout<<-1<<endl;
  else{
  	swap(s[ma],s[n-1]);
  	cout<<s<<endl;
  }
  return 0;
}