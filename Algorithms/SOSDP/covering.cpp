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
const LL mm = 1e9 + 7;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}



int main(){
  fio();
  LL N; cin >> N;
  LL F[1<<N], G[1<<N], H[1<<N];
  LL SF = 0, SG = 0, SH = 0;
  forn(i, 1<<N) {
  	cin >> F[i];
  	SF = (SF + F[i])%mm;
  }
  forn(i, 1<<N) {
  	cin >> G[i];
  	SG = (SG + G[i])%mm;
  }

  forn(i, 1<<N) {
  	cin >> H[i];
  	SH = (SH + H[i])%mm;
  }

  forn(i, N)
  	forn(msk, 1<<N)
  		if((msk & (1<<i)) == 0)
  			{
  				F[msk|(1<<i)] = (F[msk] + F[msk|(1<<i)])%mm;
  				G[msk|(1<<i)] = (G[msk] + G[msk|(1<<i)])%mm;
  				H[msk|(1<<i)] = (H[msk] + H[msk|(1<<i)])%mm;
  			}

  LL ans = 0;

  forn(msk, 1 << N)
  	{
  		LL k = (SF - F[msk] +mm)%mm;
  		k = k*(SG - G[msk] + mm)%mm;
  		k = k*(SH - H[msk] + mm)%mm;

  		k = (k + mm)%mm;
  		k = ((SF*(SG*SH)%mm)%mm - k + mm)%mm;
  	    k = (k + mm)%mm;
  	    ans = (ans + k)%mm;
  	}

  	cout << ans << endl;
  return 0;
}