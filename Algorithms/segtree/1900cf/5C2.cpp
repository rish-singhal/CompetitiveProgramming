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
const int MAXN = 1e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int st[MAXN], x, len[MAXN], c[MAXN], ma, m=1;

int main(){
  fio();
  string s; cin>>s;
  forn(i,s.size()){
  	if(s[i]=='(') st[++x] = i;
  	else if(x){
  		c[i] = st[x--];
  		len[i] = i - c[i] + 1 + len[c[i]-1];
  		if(len[i]==ma) m++;
  		else if(len[i]>ma) ma = len[i], m =1;
  	}
  }
  cout<<ma<<" "<<m<<endl;
  return 0;
}