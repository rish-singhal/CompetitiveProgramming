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
const LL MAXN = 1e6 + 1e3;
const LL inf = 1e16;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int po[MAXN];

pair<LL,LL> t[2*MAXN];


pair<LL,LL> combine(pair<LL,LL> a, pair<LL,LL> b){
	if(a.se==-1) return b;
	if(a.fi > b.fi) return a;
	return b;
}

void up(LL x, pair<LL,LL> v){
	t[x+MAXN] = v;
	LL z = x+MAXN;
	while(z>1){
		t[z>>1] = combine(t[z], t[z^1]);
		z>>=1;
	}
}

pair<LL,LL> qu(LL l, LL r){
	pair<LL,LL>  mm = {0, -1};
	for(l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
		if(l&1) mm = combine(mm, t[l++]);
		if(r&1) mm = combine(mm, t[--r]);
	}
	return mm;
}

int main(){
  fio();
  int n;
  cin>>n;
  vector <vector<LL> >  v(MAXN);
  forn(i,n){
  	LL x = 0, z = 0;
  	string s; cin>>s;
  	LL t = 0;
  	while(s[t]==')' && t<s.size()){
  		x++;
  		z-=1;
  		t++;
  	}
  	while(t<s.size()){
  		if(s[t]==')') z--;
  		else z++;
  		t++;
  	}
  	v[x].pb(z);
  }
  forn(i,MAXN) sort(all(v[i]));
  forn(i,MAXN) reverse(all(v[i]));

  forn(i,MAXN){
  	t[i+MAXN] = {-inf, i};
  	if(v[i].size()>0){
  	 t[i+MAXN] = {v[i][0], i};
  	// cout<<"yyyy"<<endl;
  	 po[i]++;
  	}
  }

  for(int x = MAXN-1; x>0;x--){
  	t[x] = combine(t[x<<1|1], t[x<<1]);
  }

  LL bb = 0;
  forn(i,n){
  	pair<LL,LL> z = qu(0,bb+1);
  	//cout<<z.fi<<" "<<z.se<<" "<<bb<<endl;
  	if(z.fi + bb < 0){
  		cout<<"No"<<endl;
  		return 0;
  	}
  	else{
  		bb+=z.fi;
  		if(po[z.se]<v[z.se].size()){
  			up(z.se, {v[z.se][po[z.se]], z.se});
  			po[z.se]++;
  		}
  		else{
  			up(z.se, {-inf, z.se});
  		}
  	}
  }

  cout<<(bb==0?"Yes":"No")<<endl;
  return 0;
}