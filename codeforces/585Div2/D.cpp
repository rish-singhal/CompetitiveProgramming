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
    string s; cin>>s;
    LL l=0,r=0;
    int cl = 0, cr = 0;
    for(int i=0;i<s.size()/2;i++)
      if(s[i]=='?') cl++;
      else l+= s[i]-'0';
    for(int i=s.size()/2;i<s.size();i++)
      if(s[i]=='?') cr++;
      else r+= s[i]-'0';
      if(2*l + (9*cl)!= 2*r + (9*cr)))
        cout<<"Monocarp"<<endl;
      else 
        cout<<"Bicarp"<<endl;
     return 0;
}

