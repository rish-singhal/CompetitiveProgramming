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


struct node{
	int val ,lazy, mark;
	void merge(const node& a, const node& b){
		val = a.val + b.val;
	}
	void add(int nval){
		val = nval;
		lazy = nval;
		mark = 1;
	}
};

vector<node> tree;
int b =1; 

int qu(int in, int ql, int qr, int l = 0, int r = b-1){
	debug(in, l ,r);
	if(ql>r || qr<l)
		return 0;
	if(ql<=l && qr>=r)
		return tree[in].val;
	if(tree[in].mark){ 
		for(auto child: {2*in, 2*in+1}){
			tree[child].add(tree[in].lazy);
		}
		tree[in].lazy = 0;
		tree[in].mark = 1;
	}
	int m = l + (r-l)/2;
	return qu(in<<1, ql ,qr, l, m) + qu(in<<1|1, ql, qr, m+1, r);
}

void up(int in, int ql, int qr, int v, int l = 0, int r = b-1){
	if(r<ql || qr<l)
		return;
	if(ql<=l && r<=qr){
		tree[in].add(v);
		return;
	}
	if(tree[in].mark){ 
		for(auto child: {2*in, 2*in+1}){
			tree[child].add(tree[in].lazy);
		}
		tree[in].lazy = 0;
		tree[in].mark = 1;
	}
	int m = l + (r-l)/2;
	up(2*in, ql, qr, v, l, m);
	up(2*in+1, ql, qr, v, m+1, r);
}


int main(){
  fio();
  int n; cin>>n;
  while(b<=n) b*=2;
  debug(b);
  tree.resize(2*b , node({0}));
  forn(i,n){
  	int x; cin>>tree[b+i].val;
  }
  for(int i=b-1; i>=1;i--)
  	tree[i].merge(tree[2*i], tree[2*i+1]);
  
  int q; cin>>q;
  while(q--){
  	int x; cin>>x;
  	if(x==1){
		int l,r; cin>>l>>r;
  		cout<<qu(1, l, r, 0, b-1)<<endl;
  	}
  	else{
  		int l,r, v; cin>>l>>r>>v;
  		up(1,l,r,v);
  	}
  }
  return 0;
}