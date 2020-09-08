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

int n;

// LL bit[MAXN];

// void up(int i, int v){
// 	while(i<=n){
// 		bit[i]+=v;
// 		i+=i&-i;
// 	}
// }

// LL qu(int i){
// 	LL su = 0;
// 	while(i>0){
// 		su+=bit[i]; 
// 		i-=i&-i;
// 	}
// 	return su;
// }

int main(){
  fio();
  int t; cin>>t;
  while(t--){

  	cin>>n;
  	//forn(i,n+1) bit[i] =0;
  	vector<int> v(n);
  	set<int> s;
  	forn(i,n){
  		cin>>v[i];
  		s.insert(v[i]);
  	}
  	vector<int> nv;
    map<int,int> lst;
    map<int,int> fst;
  	for(auto i:s) nv.pb(i);
  	forn(i,n) {
      v[i] = lower_bound(all(nv), v[i]) - nv.begin() + 1;
      lst[v[i]] = i;
      if(fst.find(v[i])==fst.end())fst[v[i]] = i;
    }
 	debug(v);
 	vector<LL> vv(n+1,0);
 	LL ma = 0;
  	forn(i,n){
  		if(i == fst[v[i]] && i>lst[v[i]-1]){
        vv[v[i]] = vv[v[i]-1] + 1;
      }
      else
        vv[v[i]]++;
  		debug(i,v[i],vv[v[i]]);
  		ma = max(ma,vv[v[i]]);
  	}
  	cout<<(n-ma)<<endl;
  //	
  }
  return 0;
}