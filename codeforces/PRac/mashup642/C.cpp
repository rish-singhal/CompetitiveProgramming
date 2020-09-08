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
 	while(t--){
 		LL n; cin>>n;
 		vector <LL> an;
 		for(LL i=2; i*i<=n; i++){
 			if(n%i==0){
 				while(n%i==0){
 					an.pb(i);
 					n/=i;
 				}
 			}
 		}
 		if(n!=1){
 			an.pb(n);
 		}
 		if(an.size()<3) cout<<"NO"<<endl;
 		else {
 			vector <LL> az(3);
 			az[0] = an[0];
 			map<LL,LL> m;
 			m[an[0]] = 1;
 			int cnt = 0;
 			LL x=1;
 			int i = 1;
 			for(i=1;i<an.size();i++){
 				x*=an[i];
 				if(m[x]==0){
 					az[1] = x;
 					i++;
 					break;
 				}
 			}
 			az[2] = 1;
 			for(;i<an.size();i++){
 				az[2]*=an[i];
 			}
 			if(az[0]==az[1] || az[1]==az[2] || az[2]==az[0] || az[0]<=1 ||az[1]<=1||az[2]<=1 )
 				cout<<"NO"<<endl;
 			else{
 				cout<<"YES"<<endl;
 				for(auto i:az) cout<<i<<" ";
 					cout<<endl;
 			}
 		}

 	} 
  return 0;
}