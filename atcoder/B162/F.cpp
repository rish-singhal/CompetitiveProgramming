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
  LL n; cin>>n;
  vector<LL> v(n);
  LL sum1 = 0, sum2 = 0;
  vector<LL> p(n),s(n);
  forn(i,n){
  	cin>>v[i];
  	if(i&1) {
  		sum1+=v[i];
  		p[i] = v[i];
  	}
  	else {
  		sum2+=v[i];
  		s[i] = v[i];
  	}
  }
  // cout<<"odd: ";forn(i,n) cout<<p[i]<<" ";
  //  cout<<endl;
  //   cout<<"even: ";forn(i,n) cout<<s[i]<<" ";
  //  cout<<endl;
  for1(i,n-1) p[i]+=p[i-1];
  for1(i,n-1) s[i]+=s[i-1];  
   // cout<<"odd: ";forn(i,n) cout<<(p[i])<<" ";
   // cout<<endl;
   //  cout<<"even: ";forn(i,n) cout<<(s[n-1]-s[i])<<" ";
   // cout<<endl;
  vector<LL> ann(n,-1e18);
  LL zzz = -1e17;
  for1(i,n-1){
  	ann[i] = (s[i-1]-p[i]);
  }
  LL kk = -1e17;
  for(int i =1; i<=n-1;i++){
  	if(i!=1)zzz = max(-s[i]+p[i-1]+kk,zzz);
  	kk = max(kk,ann[i]);
  }
  zzz+=s[n-1];


  if((n&1)==0){
  	cout<<max(sum1,sum2)<<endl;
  }
  else{
  	LL an = -1e18;
  	forn(i,n){
  		LL k =0, z=0;
  		if(i==n-2) continue;
  		if((i&1)){
  			k = (i>=1?p[i-1]:0);
  			z = s[n-1]-s[i];

  		}
  		else{
  			k = (i>=1?s[i-1]:0);
  			z = max(s[n-1]-s[i],p[n-1]-p[i]);
  		}
  		an = max(an,k+z);
  	}
  	cout<<max({an,sum1,zzz})<<endl;
  	//cout<<sum1<<" "<<sum2<<endl;
  }
  return 0;
}