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

int main(){
  fio();
  int t; cin>>t;
  while(t--)
  {
  	int a,b,c; cin>>a>>b>>c;
  	vector<LL> va(a),vb(b),vc(c);
  	forn(i,a) cin>>va[i];
  	forn(i,b) cin>>vb[i];
  	forn(i,c) cin>>vc[i];
  	sort(all(va));
  	sort(all(vb));
  	sort(all(vc));
  	LL an  = LLONG_MAX;
  	for(auto i:va){
  		auto it = lower_bound(all(vb),i) -vb.begin();
  		auto it2 = lower_bound(all(vc),i) -vc.begin();
  		vector<LL> an1;
  		vector<LL> an2;
  		if(it>=0 && it<b){
  			an1.pb(vb[it]);
  		}
  		if(it-1>=0 && it-1<b){
  			an1.pb(vb[it-1]);
  		}
  		if(it+1>=0 && it+1<b){
  			an1.pb(vb[it+1]);
  		}

  		if(it2>=0 && it2<c){
  			an2.pb(vc[it2]);
  		}
  		if(it2-1>=0 && it2-1<c){
  			an2.pb(vc[it2-1]);
  		}
  		if(it2+1>=0 && it2+1<c){
  			an2.pb(vc[it2+1]);
  		}
  		for(auto p:an1){
  			for(auto q:an2){
  				an = min(an, (i-p)*(i-p) + (p-q)*(p-q) + (i-q)*(i-q));
  			}
  		}
  	}

  	for(auto i:vb){
  		auto it = lower_bound(all(va),i) -va.begin();
  		auto it2 = lower_bound(all(vc),i) -vc.begin();
  		vector<LL> an1;
  		vector<LL> an2;
  		if(it>=0 && it<a){
  			an1.pb(va[it]);
  		}
  		if(it-1>=0 && it-1<a){
  			an1.pb(va[it-1]);
  		}
  		if(it+1>=0 && it+1<a){
  			an1.pb(va[it+1]);
  		}

  		if(it2>=0 && it2<c){
  			an2.pb(vc[it2]);
  		}
  		if(it2-1>=0 && it2-1<c){
  			an2.pb(vc[it2-1]);
  		}
  		if(it2+1>=0 && it2+1<c){
  			an2.pb(vc[it2+1]);
  		}
  		for(auto p:an1){
  			for(auto q:an2){
  				an = min(an, (i-p)*(i-p) + (p-q)*(p-q) + (i-q)*(i-q));
  			}
  		}
  	}

  	for(auto i:vc){
  		auto it = lower_bound(all(vb),i) -vb.begin();
  		auto it2 = lower_bound(all(va),i) -va.begin();
  		vector<LL> an1;
  		vector<LL> an2;
  		if(it>=0 && it<b){
  			an1.pb(vb[it]);
  		}
  		if(it-1>=0 && it-1<b){
  			an1.pb(vb[it-1]);
  		}
  		if(it+1>=0 && it+1<b){
  			an1.pb(vb[it+1]);
  		}

  		if(it2>=0 && it2<a){
  			an2.pb(va[it2]);
  		}
  		if(it2-1>=0 && it2-1<a){
  			an2.pb(va[it2-1]);
  		}
  		if(it2+1>=0 && it2+1<a){
  			an2.pb(va[it2+1]);
  		}
  		for(auto p:an1){
  			for(auto q:an2){
  				an = min(an, (i-p)*(i-p) + (p-q)*(p-q) + (i-q)*(i-q));
  			}
  		}
  	}
  	cout<<an<<endl;

  }
  return 0;
}