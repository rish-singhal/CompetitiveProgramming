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
    string a,b; cin>>a>>b;
    vector<int> va,vb;
    for(int i=0;i<n;i++){
        if(a[i]=='a' && b[i]=='b')
         va.pb(i+1);
        if(a[i]=='b' && b[i]=='a')
         vb.pb(i+1);
    }
    int cnt =0;
    if(va.size()%2!=vb.size()%2) { 
      cout<<-1<<endl;
      return 0;
    }
    int f = 0;

    LL  xx = ((vb.size() + va.size()))/2 + f;      
       
    if(va.size()&1 && vb.size()&1) 
    {
      cout<<(xx+1)<<endl;
      va.pb(vb[vb.size()-1]);
      cout<<vb[vb.size()-1]<<" "<<vb[vb.size()-1]<<endl;
      f = 1;
    }

    if(!f)cout<<xx<<endl;
      for(int i=0;i<va.size();i+=2)
        cout<<va[i]<<" "<<va[i+1]<<endl;
      for(int i=0;i<vb.size()-f;i+=2)
        cout<<vb[i]<<" "<<vb[i+1]<<endl;
      return 0;
}

