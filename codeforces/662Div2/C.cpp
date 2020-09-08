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
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	vector<int> v(n+1, 0);
  	forn(i,n){
  		int k; cin>>k;
  		v[k]++;
  	}
  	int b = 0;
  	int kk = 0;
  	int mm = 0;
  	LL su = 0;
  	LL cnt = 0;
  	//debug(v);
  	for1(i,n){
  		if(v[i] > (n+1)/2){
  			cout<<0<<endl;
  			b = 1;
  			break;
  		}
  		if(v[i] == (n+1)/2){
  			cout<<1<<endl;
  			b = 1;
  			break;
  		}
  		kk += (v[i] == 1);
  		mm = max(mm, v[i]);
  		su += (LL)v[i];
  	}
  	vector<LL> vv;
  	if(b) continue;
  	debug(kk);
  	int pp = 1;
  	int cnt2 =0;
  	LL sx = 0;
  	forn(i,n){
  		if(v[i]>1) {
  			vv.pb(v[i]);
  			cnt2 += ((v[i] == mm));
  			pp &= (v[i] == mm);
  			sx += (mm - v[i]);
  		}
  	}
  	sort(all(vv));
  	reverse(all(vv));
  	if(pp){
  		cout<<(cnt2 - 1 + kk)<<" -- "<<endl;
  		continue;
  	}
  	else{
  		if(sx >= kk){
  			sx -= kk;
  		}
  		else{
  			kk -= sx;
  			sx = 0;
  		}
  		if(sx == 0){
  			cout<<(cnt2 - 1 + kk);
  			continue;
  		}
  		else{
  			int cc = 0;
  			for(auto &i:vv){
  				if(i + sx >= mm){
  					sx -= (mm - i);
  					i = mm;
  					cc++;
  				}
  			}
  			cout<<(cc-1)<<endl;
  		}
  	}
  }
  return 0;
}