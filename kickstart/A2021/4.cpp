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
const LL N = 250000 + 5;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


// ref: https://cp-algorithms.com/linear_algebra/linear-system-gauss.html

void solve() {
	int n; cin >> n;
	LL mat[n][n], B[n][n], R[n], C[n];
	forn(i, n)
	 forn(j, n)
	 	cin >> mat[i][j];


	vector <pair<LL,LL>> pr;
	
	forn(i, n)
	 forn(j, n)
	 	{
	 		cin >> B[i][j];
	 		pr.push_back({B[i][j], n*i + j});
	 	}

	sort(all(pr));

	vector <LL> mmp(n*n), rmp(n*n);

	forn(i, n*n)
		{
			mmp[pr[i].se] = n*n - i - 1;
			rmp[n*n - i - 1] = pr[i].se;
		}

	forn(i, n)
		cin >> R[i];

	forn(i, n)
		cin >> C[i];

	vector <bitset<N>> a(n*n);
	forn(i, n){
		forn(j, n){
			a[i][mmp[n*i + j]] = (mat[i][j] == -1);
		}
	}

	forn(j, n){
		forn(i, n){
			a[n + j][mmp[n*i + j]] = (mat[i][j] == -1);
		}
	}

	vector<LL> where (n*n, -1);
    for (LL col=0, row=0; col<n*n && row<2*n; ++col) {
        for (LL i=row; i<2*n; ++i)
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<2*n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
	
	vector <bool> chek(n*n, 0);

	LL ans = 0;
	
	for(LL i = n + n - 1; i >= 0; i--){
		LL kk =(n + n - 1) - i + 1;
		assert(kk >= 0);
		vector <LL> vv;
		forn(j, kk){
			//cout << i << " -- " << n*n - 1 - j << endl;
			LL in = (LL)n*n - 1 - j;
			if(chek[in] == 0 && a[i][in] == 1){
				vv.push_back(rmp[in]);
				chek[in] = 1;
			}
		}
		if(sz(vv) > 1){
			vector <LL> v2;
			LL ma= -1e18, su = 0;
			for(auto ind: vv)
			{
				su += (LL)B[ind/n][ind%n];
				ma = max(ma, (LL)B[ind/n][ind%n]);
				
			}
			su -= ma;
			ans += su;
		}
	}

	cout << ans << endl;
	return;
}

int main(){
  fio();
  int t; cin >> t;
  for1(i, t){
  	cout << "Case #" << i <<": ";
  	solve();
  }
  return 0;
}