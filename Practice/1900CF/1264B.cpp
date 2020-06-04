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

vector<int> v(4);

/*

0 -> 1

 2 -> 1,3

2 <- 3

0 1 0 1 0 1 0 1 "2,1" "2,3,2,3,2,3,2,3"

*/

void solve(int i){
	vector<int> cnt(4);
	forn(i,4) cnt[i]=v[i];
	vector<int> p;
	cnt[i]--;
	//cout<<"eeq"<<endl;
	if(cnt[i]<0) return;
	p.pb(i);
	int cn = 0;
	while(!(cnt[0]==0 && cnt[1]==0 && cnt[2]==0 && cnt[3]==0)){
		if( (p[cn]) - 1 >=0 && cnt[(p[cn]) - 1]>0){
			p.pb((p[cn]) - 1);
			cnt[(p[cn]) - 1]--;
			cn++;
		}
		else if((p[cn]) + 1 <4 && cnt[(p[cn]) + 1]>0){
			p.pb((p[cn]) + 1);
			cnt[(p[cn]) + 1]--;
			cn++;
		}
		else{
			return;
		}
	}

	//if(cnt[0]==0 && cnt[1]==0 && cnt[2]==0 && cnt[3]==0) return;

	cout<<"YES"<<endl;
	for(auto j:p )cout<<j<<" ";
		cout<<endl;
	exit(0);
}

int main(){
  fio();
 // vector<int> v(4);
  forn(i,4) cin>>v[i];
  forn(i,4){
  	solve(i);
  }
  cout<<"NO"<<endl;
  return 0;
}