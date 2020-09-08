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

int n;

int cot[MAXN][3];

void solve1(LL a,LL b,LL c){
	vector<string> v;
	vector<string> in;
  forn(i,n){
  	string s; cin>>s;
  in.pb(s);
  }

  for(int i=n-1;i>=0;i--){
  	if(in[i]=="AB"){
  		cot[i][0] = cot[i+1][0] + 1;
  		cot[i][1] = cot[i+1][1] + 1;
  		cot[i][2] = cot[i+1][2] ;
  	}
  	if(in[i]=="BC"){
  		cot[i][0] = cot[i+1][0] ;
  		cot[i][1] = cot[i+1][1] + 1;
  		cot[i][2] = cot[i+1][2] +1;
  	}
  	if(in[i]=="AC"){
  		cot[i][0] = cot[i+1][0] + 1;
  		cot[i][1] = cot[i+1][1] ;
  		cot[i][2] = cot[i+1][2] +1;
  	}
  }
  int jk = 0;
  for(auto s:in){	if(s=="AB"){
  		if(a>b || ((a==b) && cot[jk][1]> cot[jk][0])){
  			a--, b++;
  			v.pb("B");
  		}
  		else {
  			a++, b--;
  			v.pb("A");
  		}

  	}
  	else if(s=="AC"){
  		if(a>c || ((a==c) && cot[jk][2]> cot[jk][0])){
  			a--, c++;
  			v.pb("C");
  		}
  		else {
  			a++, c--;
  			v.pb("A");
  		}
  	}
  	else {
  		if(b>c || ((b==c) && cot[jk][2]> cot[jk][1])){
  			b--, c++;
  			v.pb("C");
  		}
  		else {
  			b++, c--;
  			v.pb("B");
  		}
  	}
  	if(a <0 || b<0 || c<0){
  		cout<<"No"<<endl;
  		return;
  	}
  	jk++;
  }
  cout<<"Yes"<<endl;
  for(auto i:v) cout<<i<<endl;
  	return;
}


vector<string> ss;

vector<string> an;
LL chk = 0;
int dp[MAXN][4][4][4];

void dfs(int a, int b, int c, int i){
	if(i==n){
		chk = 1;
		cout<<"Yes"<<endl;
		for(auto jj:an) cout<<jj<<endl;
			exit(0);
	}
	if(dp[i][a][b][c]) return;
	dp[i][a][b][c] = 1;
	if(ss[i]=="AB"){
		if(a-1>=0){
			an.pb("B");
			dfs(a-1, b+1,  c, i+1);
			an.pop_back();
		}
		else if(b>=1){
			an.pb("A");
			dfs(a+1, b-1,  c, i+1);
			an.pop_back();
		}
	}
	else if(ss[i]=="AC"){
		if(a-1>=0){
			an.pb("C");
			dfs(a-1, b,  c+1, i+1);
			an.pop_back();
		}
		else if(c>=1){
			an.pb("A");
			dfs(a+1, b,  c-1, i+1);
			an.pop_back();
		}
	}
	else{
		if(c-1>=0){
			an.pb("B");
			dfs(a, b+1,  c-1, i+1);
			an.pop_back();
		}
		else if(b>=1){
			an.pb("C");
			dfs(a, b-1,  c+1, i+1);
			an.pop_back();
		}
	}
	return ;
}

int main(){
  fio();
  cin>>n;
  LL a,b,c; cin>>a>>b>>c;
  if(a<=1 && b<=1 && c<=1){
  	for1(i,n) {
  		string s;cin>>s;
  		ss.pb(s);
  	}
  	dfs(a,b,c,0);
  	cout<<"No"<<endl;
  } 
  else{
  	solve1(a,b,c);
  }
  return 0;
}
