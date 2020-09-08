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
const int MAXN = 2e5 +5;

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
  multiset<LL> s[MAXN+5];
  multiset<LL> ss;
 vector<LL> ra(n), ki(n);
  forn(i,n){
  	LL a, b; cin>>a>>b;
  	ra[i] = a;
  	ki[i] = b;
  	s[b].insert(a);
  }
  
  for1(i,MAXN){
  	if(s[i].size()==0) continue;
  	ss.insert(*(s[i].rbegin()));

  }
  //debug(ss);
  while(q--){
  	LL c, d; cin>>c>>d;
  	c--;
  	LL rr = ra[c];
  	LL ll = ki[c];
  	ki[c] = d;
  	LL pp = *s[ll].rbegin();
  	LL pk = -1;
  	LL ppp = s[d].size();
    if(ppp) pk = *s[d].rbegin();
  	s[ll].erase(s[ll].find(rr));
  	s[d].insert(rr);
  	
  	LL kz = *s[d].rbegin();
    if(s[ll].size()!=0){
    LL pz = *s[ll].rbegin();
  	if(pz!=pp){
  		ss.erase(ss.find(pp));
  		 ss.insert(pz);
  	}}
    else{
    	ss.erase(ss.find(pp));
        }
     if(ppp){
  	if(kz!=pk ){
  		ss.erase(ss.find(pk));
  		ss.insert(kz);
  	}
    }
    else{
    	ss.insert(kz);
        }
  	//debug(ss);
  	cout<<(*ss.begin())<<endl;
  }
  return 0;
}