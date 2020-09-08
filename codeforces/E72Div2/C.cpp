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
    int t; cin>>t;
    while(t--){
      string a; cin>>a;
      int n = a.size();
      vector <int> v(n);
      int pos = -1;
      LL an=0;
      for(int i=0;i<n;i++) if(a[i]=='1') v[i] = pos, pos = i;
      for(int i=0;i<n;i++) if(a[i]=='1'){
        LL s = 0;
        for(int j=i;j<n;j++)
            {
                s<<=1;
                s+= a[j]-'0';
                if(s>j-v[i]){
                  break;
                }
                an++;
            }
      }
      cout<<an<<endl;
    }


    return 0;
}

