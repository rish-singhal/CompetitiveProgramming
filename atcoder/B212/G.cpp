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
const LL mm = 998244353;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL phi(LL n)
{
    LL result = n;
    for(LL p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
         
    return result%mm;
}

int main(){
  fio();
  LL p; cin >> p;
  LL n = p - 1;
  LL su = 0;
  for(LL x = 1; x*x <= n; x++) {
  	if((n % x) == 0) {
  		su = (su + ((phi(x)%mm)*x)%mm) % mm;
  		if((n/x) != x) {
  			su = (su + ((phi(n/x)%mm)*((n/x)%mm))%mm) % mm;
  		}
  	}
  }
  cout << (su + 1)%mm << endl;
  return 0;
}