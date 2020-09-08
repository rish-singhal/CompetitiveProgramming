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


int main(){
  fio();
  int n; cin>>n;
  multiset<LL> ms;
  map<LL,LL> m;
  forn(i,n){
  	LL x;cin>>x;
  	m[x]++;
  }
  for(auto i:m){
  	ms.insert(i.se);
  }
  int q; cin>>q;
  forn(i,q){
  	string s; LL x; cin>>s>>x;
  	if(s=="+"){
  		if(m.find(x)!=m.end() && m[x]!=0){
  			ms.erase(ms.find(m[x]));
  			m[x]++;
  			ms.insert(m[x]);
  		}
  		else{
  			ms.insert(1);
  			m[x]++;
  		}
  	}
  	else{
  		ms.erase(ms.find(m[x]));
  		m[x]--;
  		if(m[x]>0){
  			ms.insert(m[x]);
  		}
  	}
  	//debug(ms);
  	if(ms.size()==0){
  		cout<<"NO"<<endl;
  		continue;
  	}
  	LL y = *ms.rbegin();
  	if(y >= 8){
  		cout<<"YES"<<endl;
  	}
  	else if(y >= 6 && ms.size()>1){
  		auto zz = ms.end();
  		zz--;
  		zz--;
  		if(*zz >= 2){
  			cout<<"YES"<<endl;
  		}
  		else cout<<"NO"<<endl;
  	}
  	else if(y>=4 && ms.size()>1){
  		auto zz = ms.end();
  		zz--;
  		zz--;
  		if(*zz >= 4){
  			cout<<"YES"<<endl;
  		}
  		else if(*zz >= 2 && ms.size()>2){
  			zz--;
  			if(*zz >= 2){
  				cout<<"YES"<<endl;
  			}
  			else cout<<"NO"<<endl;
  		}
  		else cout<<"NO"<<endl;
  	}
  	else{
  		cout<<"NO"<<endl;
  	}
  }
  return 0;
}