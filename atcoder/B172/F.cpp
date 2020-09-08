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

// (x-k) ^ (y + k) = val;

int main(){
  fio();
  LL n; cin>>n;
  LL su = 0;
  LL sz = 0;
  vector<LL> a(n);
  forn(i,n){
  	cin>>a[i];
  	su ^= a[i];
  	if(i>1) sz ^= a[i];
  }
  if(su==0){
  	cout<<0<<endl;
  	return 0;
  }
  vector<LL> ax(41), bx(41), s(41);
  LL an = 0;
  su^=a[0]^a[1];

  // cout<<bitset<40>(a[0])<<" --"<<endl;
  // cout<<bitset<40>(a[1])<<" --"<<endl;
  // cout<<" -- "<<endl;
  //   cout<<bitset<40>(su)<<" --"<<endl;
  int bbb = 0;
  for(LL i = 40 ; i>=0; i--){
  if(i==1){
  		  cout<<bitset<40>(a[0])<<" --"<<endl;
  cout<<bitset<40>(a[1])<<" --"<<endl;
  cout<<" -- "<<endl;
    cout<<bitset<40>(su)<<" --"<<endl;
    //cout<<an<<endl;
  }
  	ax[i] = ((a[0]&(1LL<<i))!=0);
  	bx[i] = ((a[1]&(1LL<<i))!=0);
  	s[i] = ((su&(1LL<<i))!=0);
  	if((ax[i]^bx[i]) == s[i]){
  		bbb = 1;
  		if(((a[0]&(1LL<<i))!=0)){
  		a[0] = (a[0]^(1LL<<i));
  	}
  	if(((a[1]&(1LL<<i))!=0)){
  		a[1] = (a[1]^(1LL<<i));
  	}
  	if(((su&(1LL<<i))!=0)){
  		su = (su^(1LL<<i));
  	}
		 continue;
		}
  	if(s[i]==0){
  		if(bx[i]==1){
  			cout<<-1<<endl;
  			return 0;
  		}
  		else{
  			LL kk = (1LL<<i) - a[1];
  			if(kk<a[0] || (bbb && kk<=a[0])){
  				a[0]-=kk;
  				a[1]+=kk;
  				an+=kk;
  				if(((a[0]&(1LL<<i)) ^ (a[1]&(1LL<<i)) )!= (su&(1LL<<i))){
  					cout<<-1<<endl;
  					return 0;
  				}
  			}
  			else{
  				cout<<-1<<endl;
  				return 0;
  			}
  		}
  	}
  	else{
  		if(bx[i]==1){
  			LL ppp = (a[0] - ((1LL<<i) - 1));
  			if((a[1] + ppp) >=(1LL<<(i+1)) || (((a[1] + ppp)&(1LL<<i))==0))
  				{
  					cout<<-1<<endl;	
  					return 0;
  				}
  			a[0] -= ppp;
  			a[1] += ppp;
  			an+=ppp;
  			if(((a[0]&(1LL<<i)) ^ (a[1]&(1LL<<i)) )!= (su&(1LL<<i))){
  					cout<<-1<<endl;
  					return 0;
  				}
  		}
  		else{
  			LL kk = (1LL<<i) - a[1];
  			if(kk<a[0] || (bbb && kk<=a[0])){
  				a[0]-=kk;
  				a[1]+=kk;
  				an+=kk;
  				if(((a[0]&(1LL<<i)) ^ (a[1]&(1LL<<i)) )!= (su&(1LL<<i))){
  					cout<<-1<<endl;
  					return 0;
  				}
  			}
  			else{
  				cout<<-1<<endl;
  				return 0;
  			}

  		}
  	}
  	if(((a[0]&(1LL<<i))!=0)){
  		bbb = 1;
  		a[0] = (a[0]^(1LL<<i));
  	}
  	if(((a[1]&(1LL<<i))!=0)){
  		a[1] = (a[1]^(1LL<<i));
  	}
  	if(((su&(1LL<<i))!=0)){
  		su = (su^(1LL<<i));
  	}
  }
  cout<<an<<endl;
  return 0;
}