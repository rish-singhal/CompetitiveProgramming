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
const LL m = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    vector <LL> v = {1,2,3,4};
    LL an[100005];
    for(int i=1;i<100005;i++){
      LL kk = 1;
      for(auto &c:v) {
        kk = ( kk*c )%m;
        c++;
      }
      an[i] = ((i>=1?an[i-1]:0) + kk)%m;
    }
    int t; cin>>t;
    while(t--){
     int l,r; cin>>l>>r;
     cout<<( (an[r]-an[l-1]+m)%m )<<endl;
    }

       return 0;
}

