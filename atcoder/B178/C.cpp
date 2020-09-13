#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;
const LL m = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


LL po(LL a, LL n){
	if(n==0) return 1;
	LL an = po(a,n/2);
	an = (an*an)%m;
	if(n&1) return (an*a)%m;
	return an;
}


int main(){
  fio();
  LL n; cin>>n;
  LL an = po(10, n);
  an = (an - po(9, n) + m)%m;
  an = (an - po(9, n) + m)%m;
  an = (an + po(8, n))%m;
  cout<<an<<endl;
  return 0;
}