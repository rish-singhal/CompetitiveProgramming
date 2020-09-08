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


void takeinput(vector<LL> &v, int n, int k){
	forn(i,k) cin>>v[i];
	LL a, b, c, d; cin>>a>>b>>c>>d;
	a %= d, b%= d, c%=d;
	for(int i = k; i < n; i++){
		v[i] = c;
		v[i] = (v[i] + (b*(v[i-1])%d)%d)%d;
		v[i] = (v[i] + (a*(v[i-2])%d)%d)%d;
	}	
}

void solve(){
	LL n,k;
	cin>>n>>k;
	vector<LL> S(n), X(n), Y(n);
	takeinput(S, n, k);
	takeinput(X, n, k);
	takeinput(Y, n, k);

	//debug(S);


	LL co = 0, ci = 0;
	for(int i = 0; i < n; i++){
		if(S[i] < X[i]){
			ci += X[i] - S[i];
		}
		if(S[i] > X[i] + Y[i]){
			co += S[i] - (X[i] + Y[i]);
		}
	}
	if(ci == co){
		cout<<co<<endl;
		return;
	}
	else if(ci > co){
		ci -= co;
		long long cnt = 0;
		for(int i = 0; i < n; i++){
			if(S[i] > X[i] + Y[i]){
				S[i] = X[i] + Y[i];
				cnt += Y[i];
			}
			else if( S[i] >= X[i] && S[i] <=X[i] + Y[i]){
				cnt += S[i] - X[i];
			}
		}
		if(cnt >= ci){
			cout<< ci + co <<endl;
		}
		else cout<<-1<<endl;
	}
	else if(ci < co){
		co -= ci;
		long long cnt = 0;
		for(int i = 0; i < n; i++){
			if( S[i] >= X[i] && S[i] <=X[i] + Y[i]){
				cnt += X[i] + Y[i] - S[i];
			}
			else if(S[i] < X[i]){
				S[i] = X[i];
				cnt += Y[i];
			}
		}
		//cout<< ci + co <<endl;
		if(cnt >= co){
			cout<< ci + co <<endl;
		}
		else cout<<-1<<endl;
	}
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t){
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}