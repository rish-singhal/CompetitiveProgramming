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
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i,n) cin>>v[i];
    map<int,int> m;
    for(int i=0;i<n;i++)
      for(int j=i;j<n;j++){
        int s = 0;  
        for(int k = i; k<=j;k++){
              s+=v[k];
        }
        m[s]++;
      }
    cout<<(m.size()-1)<<endl;
    return 0;
}
