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
	int val;
	node(int val = 0): val(val){}
	node(node *a, node *b): val(0){
		val = a->val + b->val;
	}
	void merge(node *a, node *b){
		val = a->val + b->val;
	}
};

node* tr[4*MAXN];
int arr[MAXN];

node* qu(int in, int ql, int qr, int l, int r){
	debug(ql,qr,l,r, in);
	if(qr < l ||  r < ql) 
		return new node();
	if(l>=ql && r<=qr)
		return tr[in];
	int m = l + (r-l)/2;
	debug(m);
	return new node(qu(2*in, ql, min(qr,m), l, m),qu(2*in+1, max(m+1,ql), qr, m+1, r));
}

void build(int in, int l, int r){
	if(l==r){
		tr[in] = new node(arr[l]);
		debug(in, l);
		return;
	}
	int m = (l+r)/2;
	build(2*in,l,m);
	build(2*in+1,m+1,r);
	tr[in] = new node(tr[2*in], tr[2*in+1]);
}

void up(int in, int l, int r, int pos, int val){
	if(l==r){
		tr[in]->val = val;
		return;
	}
	int m = (l+r)/2;
	if(pos <= m){
		up(2*in, l, m, pos, val);
	}
	else up(2*in+1, m+1, r, pos, val);
}

int main(){
  fio();
  int n; cin>>n;
  int B = 1;
  while(B<=n) B*=2;
  forn(i,n){
  	int x; cin>>x;
  	tr[B+i] = new node(x);
  }
  //build(1, 0, n-1);
  for(int i = B-1; i>=1; i--)
  	tr[i] = new node(tr[2*i], tr[2*i+1]);
  int q; cin>>q;
  while(q--){
  	int x; cin>>x;
  	if(x==1){
	  	int l,r; cin>>l>>r;
	  	cout<<qu(1, l, r, 0, n-1)->val<<endl;
	  }
	else{
		int in, v; cin>>in>>v;
		up(1, 0, n-1, in, v);
	}
  }
  return 0;
}