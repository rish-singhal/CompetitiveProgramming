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
 // fio();
  	cout<<setprecision(10);
  	cout<<fixed;
  double m; scanf("%lf",&m);
  int t; cin>>t;
  while(t--){
  	double l[2], r[2], p[2];
  	forn(i,2) scanf("%lf%lf%lf",&l[i],&r[i],&p[i]);
  	double ann = 0;
  	forn(i,2){
  		forn(j,3){
  			double mm = m;
  			double an = 0;
  			if(j==1){
  				if(l[i]<=mm){
  					mm-=l[i];
  					an+=l[i]*p[i]/100.0;
  				}
  			}
  			else if(j==2){
  				if(l[i]<=mm){
  					double xx = min(mm,r[i]);
  					mm-=xx;
  					an+=xx*p[i]/100.0;
  				}
  			}
  			if(l[i^1]<=mm){
  				double xx = min(mm,r[i^1]);
  					mm-=xx;
  					an+=xx*p[i^1]/100.0;
  			}
  			ann = max(ann, an+m);
  		}
  	}
  	printf("%0.9lf\n",ann);
  }
  return 0;
}