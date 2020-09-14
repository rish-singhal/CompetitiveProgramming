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
  int n,q; cin>>n>>q;
  vector<LL> p(n);
  LL su = 0;
  multiset<LL> s, pp;
  forn(i,n) {
  	cin>>p[i];
  	s.insert(p[i]);
  }
  sort(all(p));
  for1(i, n-1){
  	pp.insert(p[i] - p[i-1]);
  }
  if(pp.size() && s.size()) cout<<(*s.rbegin() - *s.begin() - *pp.rbegin())<<endl;
  else cout<<0<<endl;
  while(q--){
  	LL t, x; cin>>t>>x;
  	if(t){
  		auto r = s.upper_bound(x);
  		auto l = r;
  		if(l != s.begin()){
  			l--;
  			if(r != s.end()) pp.erase(pp.find(*r - *l));
  			if(r != s.end()) pp.insert((*r - x));
  			pp.insert((x - (*l)));
  		}
  		else{
  			if(r != s.end()) pp.insert((*r) - (x));
  		}
  		s.insert(x);
  	}
  	else{
  		auto r = s.upper_bound(x);
  		auto l = s.find(x);
  		if(l != s.begin()){
  			l--;
  			if(r != s.end()) pp.insert(*r - *l);
  			if(r != s.end()) pp.erase(pp.find(*r - x));
  			pp.erase(pp.find(x - (*l)));
  		}
  		else{
  			if(r != s.end()) pp.erase(pp.find((*r) - (x)));
  		}
  		s.erase(s.find(x));
  	}
  	//debug(s, pp);
  	if(pp.size() && s.size()) cout<<(*s.rbegin() - *s.begin() - *pp.rbegin())<<endl;
  	else{
  		cout<<0<<endl;
  	}
  }
  return 0;
}