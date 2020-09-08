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
int n,m ;
bool chk(LL a, LL b){
	return (a>=0 && a<n) && (b>=0 && b<m);
}

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}


void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int dx[4] = {0,-1,0,1};
int dy[4] = {1, 0, -1, 0};
int zk[4] = {1, 4,2, 3 };

int main(){
  fio();
  cin>>n>>m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  int vv[n][m][5];
  forn(i,n){
  	forn(j,m){
  		forn(k,5) vv[i][j][k] = 0;
  	}
  }
  forn(j,n){	
  	string s; cin>>s;
  	for(int i=0;i<m; i++){
  		v[j][i] = s[i]-'a';
  	}
  }

  LL an = 0;
  forn(i,n){
  	forn(j,m){
  		int cnt = 0;
  		forn(k,4){
  			int x = i + dx[k];
  			int y = j + dy[k];

  			if(chk(x,y) && v[x][y]==v[i][j])
  				cnt++;
  		}
  		//debug(cnt);
  		if(cnt == 4){
  			//cout<<"ys"<<endl;
  			forn(k,5) vv[i][j][k] = 1;
  			//cout<<vv[i][j][0]<<endl;
  		}
  	}
  }
  forn(i,n){
  	for1(j,m-1){
  		if(v[i][j-1] == v[i][j]){
  			vv[i][j][1] = vv[i][j-1][1] + 1;
  		}
  	}
  	for(int j = m-2; j >=0; j--){
  		if(v[i][j] == v[i][j+1]){
  			vv[i][j][2] = vv[i][j+1][2] + 1;
  		}
  	}
  }
  forn(i,m){
  	for1(j,n-1){
  		if(v[j-1][i] == v[j][i]){
  			vv[j][i][3] = vv[j-1][i][3] + 1;
  		}
  	}
  	for(int j = n-2; j >=0; j--){
  		if(v[j][i] == v[j+1][i]){
  			vv[j][i][4] = vv[j+1][i][4] + 1;
  		}
  	}
  }

  forn(i,n){
  	forn(j,m){
  		int cnt = 0;
  		int xx = 1e8;
  		forn(k,4){
  			int x = i + dx[k];
  			int y = j + dy[k];
  			if(chk(x,y) && v[x][y]==v[i][j])
  				{
  					cnt++;
  					xx = min(vv[x][y][zk[k]], xx);
  				}
  		}
  		if(cnt == 4) an += xx ;
  		else an++;
  	}
  }
  cout<<an<<endl;
  return 0;
}