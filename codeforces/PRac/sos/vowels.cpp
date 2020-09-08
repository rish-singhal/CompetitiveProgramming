#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n; cin>>n;
    vector <int> F(1<<24);
    forn(i,n){
      string s; cin>>s;
      int msk = 0;
      for(auto i:s){
        msk |= (1<<(i-'a'));
      }
      F[msk]++;
    }
    for(int i=0;i<24;i++)
      for(int msk = 0; msk<(1<<24);msk++)
        if(msk&(1<<i)) F[msk]+=F[msk^(1<<i)];

    LL an = 0;
    for(int i=0;i<(1<<24);i++)
      an^=(n-F[i])*(n-F[i]);
    cout<<an<<endl;
    return 0;
}

