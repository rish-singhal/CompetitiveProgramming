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

// di days

// 4 2 3 1 3

// 1 2 3 "4 [1 2 3 1] 3"
//     ... x-1 x	y y+1 y+2

LL maa(LL a, LL b, LL x){
	//a, a-1, a-2,...
		//cout<<a<<" "<<b<<" "<<(x)<<" --- ";
		LL p = min(a,x);
		LL su = ((a+a-(p-1))*p/2);
		LL z = x-p;
		su+=(z*(z+1))/2;

		LL zz = min(b,x);
		LL su2 = (zz*(zz+1)/2);
		LL pz = x - zz;
		su2 += ((a+a-(pz-1))*pz/2);
		//cout<<su2<<endl;
		return max(su2,su);
}

int main(){
  fio();
  LL n, x; cin>>n>>x;
  vector<LL> d(2*n);
  forn(i,n) {
  	cin>>d[i];
  	d[i+n] = d[i];
  }
  LL z = *max_element(all(d));
  if(z>=x){
  	//...sum z, z-1, ..., z-(x-1)
  	cout<<(((z + (z-(x-1)))*x)/2)<<endl;
  	return 0;
  }
  LL cnt = 0;
  LL l = 0;
  LL su = 0;
  LL an = 0;
  // forn(i,2*n) cout<<i<<" ";
  // cout<<endl;
  // forn(i,2*n) cout<<d[i]<<" ";
  // cout<<endl;
  forn(i,2*n){
  
  	cnt+=d[i];
  	su+=(d[i])*(d[i]+1)/2;
  	//cout<<l<<" "<<i<<" "<<cnt<<endl;
  	if(cnt>x){
  		LL suu =  0;
  		suu = su + maa(d[l],d[i],x-(cnt-d[i]-d[l])) - (d[i])*(d[i]+1)/2 - (d[l])*(d[l]+1)/2;
  		an = max(an,suu);
		while(cnt>x && l<i){
			cnt-=d[l];
			su-=(d[l])*(d[l]+1)/2;
			l++;
  			//cout<<l<<" "<<i<<" -- "<<maa(d[l],d[i],x-(cnt-d[i]-d[l]))<<endl;
  			if(l!=i && cnt>=x){suu = su + maa(d[l],d[i],x-(cnt-d[i]-d[l])) - (d[i])*(d[i]+1)/2 - (d[l])*(d[l]+1)/2;
  			 an = max(an,suu);}
		}
			//cout<<"yes"<<endl;
  	}
  }
  cout<<an<<endl;
  return 0;
}