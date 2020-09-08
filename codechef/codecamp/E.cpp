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
  int n; cin>>n;
  if(n<=3){
  	cout<<"NO"<<endl;
  	return 0;
  }
  int cnt = 0;
  cout<<"YES"<<endl;
  while((n-4)>=4){
  	//cout<<n<<endl;
  		cout<<n<<" - "<<(n-1)<<" = 1"<<endl;
  		cout<<(n-2)<<" - "<<(n-3)<<" = 1"<<endl;
  		cout<<"1 - 1 = 0"<<endl;
  		cnt++;
  		n-=4;
  }
  if(n==4){
  	cout<<"1 * 2 = 2"<<endl;
  	cout<<"2 * 3 = 6"<<endl;
  	cout<<"6 * 4 = 24"<<endl;
  }
  if(n==5){
  	cout<<"3 - 2 = 1"<<endl;
  	cout<<"1 * 1 = 1"<<endl;
  	cout<<"1 + 5 = 6"<<endl;
  	cout<<"6 * 4 = 24"<<endl;
  }
  if(n==6){
  	cout<<"1 * 2 = 2"<<endl;
  	cout<<"2 + 3 = 5"<<endl;
  	cout<<"5 - 5 = 0"<<endl;
  	cout<<"0 + 6 = 6"<<endl;
  	cout<<"4 * 6 = 24"<<endl;
  }
  if(n==7){
  	cout<<"3 - 2 = 1"<<endl;
  	cout<<"1 * 1 = 1"<<endl;
  	cout<<"1 * 7 = 7"<<endl;
  	cout<<"7 - 6 = 1"<<endl;
  	cout<<"1 + 5 = 6"<<endl;
  	cout<<"6 * 4 = 24"<<endl;
  }
  forn(i,cnt) cout<<"24 + 0 = 24"<<endl;
  return 0;
}