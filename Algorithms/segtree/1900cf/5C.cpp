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
  stack<int> st;
  vector<int> c(n),d(n);
  forn(i,n){
  	if(s[i]=='('){
  		st.push(i);
  	}
  	else{
  		if(st.size()==0){
  			c[i] = d[i] = -1;
  			continue;
  		}
  		int j = st.top();
  		st.pop();
  		d[i] = c[i] = j;
  		if(c[d[i]-1]!=-1 && s[d[i]-1]==')' && d[i]>=1){
  			c[i] = c[d[i]-1];
  		}
  	}
  }
  int ma = 0;
  forn(i,n)
  	if(s[i]==')' && d[i]!=-1) ma = max(ma, (i - c[i]+1));
  int cnt = 0;
  forn(i,n)
  	if((i - c[i]+1) == ma && d[i]!=-1 && s[i]==')') cnt++;

  cout<<ma<<" "<<(ma==0?1:cnt)<<endl;
  return 0;
}