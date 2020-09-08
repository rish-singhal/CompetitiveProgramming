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
const int MAXN = 1e6 +5;
const LL inf  =1e9;
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



int dx[4] = {-1,0,+1,0};
int dy[4] = {0,1, 0, -1};

map<pair<int,int> ,int> vis;

int h,w,k; 
vector<pair<int,int>> v(2);
vector<string> po(MAXN);
// pair<LL,LL> dfs(int x, int y, int p){
// 	vis[{x,y}] = 1;
// 	//cout<<x<<" "<<y<<endl;
// 	if(x==v[1].fi && y==v[1].se){
// 		return {1,0};
// 	}
// 	pair<LL,LL> dis = {0,0};
// 	LL calc = 1e15;
// 	forn(kk,4){
// 		int i = (kk+p)%4;
// 		int xx = x + dx[i];
// 		int yy = y + dy[i];
// 		if(xx<0 || xx>=h || yy<0 || yy>=w || po[xx][yy]=='@' || vis.find({xx,yy})!=vis.end())
// 			continue;
// 		auto vv = dfs(xx,yy,i);
// 		LL zz = ((vv.fi+1 + k-1)/k) + vv.se;
// 		if(i!=p){
// 			zz = 1 + (vv.se +((vv.fi + k-1)/k));
// 		}
// 		if(zz<calc){
// 			calc = zz;
// 			if(i==p) dis = {vv.fi+1, vv.se};
// 			else dis = {1, ((vv.fi + k-1)/k)+vv.se};
// 		}
// 	}
// 	debug(x,y,dis);
// 	return dis;
// }

int main(){
  fio();
  cin>>h>>w>>k;
  forn(i,2) cin>>v[i].fi>>v[i].se;
  forn(i,2) v[i].fi--, v[i].se--;
  forn(i,h) cin>>po[i];
  //auto ann = dfs(v[0].fi, v[0].se, 0);
  // if(vis.find({v[1].fi, v[1].se})==vis.end()){
  // 	cout<<-1<<endl;
  // 	return 0;
  // }
 // cout<<"yes"<<endl;
  LL dis[h][w][4];
  pair<LL,LL> vk[h][w][4];
  
  forn(i,h)forn(j,w)forn(k,4) {
  	dis[i][j][k] = inf;
  	forn(kk,4) vk[i][j][k] = {-1,-1};
  }
  forn(i,4) {
  	dis[v[0].fi][v[0].se][i] = 0;
  	vk[v[0].fi][v[0].se][i] = {0,0};
  }
  priority_queue<pair<LL,pair<pair<LL,LL>,LL>>> pq;
  forn(i,4) pq.push({0,{{v[0].fi,v[0].se},i}});
  while(!pq.empty()){
  	auto pp = pq.top();
  	pq.pop();
  	LL x = pp.se.fi.fi;
  	LL y = pp.se.fi.se;
  	LL di = pp.se.se;
  	//debug(x,y,di,dis[x][y][di]);
  	LL aa,bb;
  	tie(aa,bb) = vk[x][y][di];
  	if(dis[x][y][di]==inf) continue;
  	forn(i,4){
  		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx<0 || xx>=h || yy<0 || yy>=w || po[xx][yy]=='@')
			continue;
		if(i==di){
			
			LL &kz = dis[xx][yy][i];
			LL pz = bb + ((aa+1+k-1)/k);
			if(kz>pz){
				kz = pz;
				vk[xx][yy][i] = {aa+1, bb};
			pq.push({-pz,{{xx,yy},i}});
			}
		}
		else{
			
			LL &kz = dis[xx][yy][i];
			LL pz =1 + ((aa+ bb+k-1)/k);
			if(kz>pz){
				kz = pz;
				vk[xx][yy][i] = {1, aa+bb};
				pq.push({-pz,{{xx,yy},i}});
			}
		}
  	}
  }
  LL an = inf;
  forn(i,4) an = min(an, dis[v[1].fi][v[1].se][i]);
  if(an==inf) cout<<-1<<endl;
  else cout<<an<<endl;
}
