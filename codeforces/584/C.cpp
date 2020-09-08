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

int an[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
      int n; cin>>n;
      string s; cin>>s; 
      map <int,vector<int> > m;
      for(int i=0;i<s.size();i++)
        m[s[i]-'0'].pb(i);
      int fl = 1;
      int ff = 0;
      int ann = 0;
      int po,pos2 = 0;
      int an[n];   
        for(int i=0;i<=9;i++)
      {
        if(m[i].empty()) continue;
        if(fl){
        for(auto j:m[i]){
          if(!ff){
              ff = 1;
              po =j;
              an[j]= 1;
              continue;
            }
           if( j>po)
            {
              po =j;
              an[j] = 1;
            }
           if(j<po){
              fl = 0;
              pos2 =j;
              an[j]= 2;
        }
        }

        }
        else{
        for(auto j:m[i]){
          
           if( j>pos2)
            {
               pos2 = j;
                an[j] = 2;
            }
           if(j<pos2){
              ann = 1; break; 
        }
        }
        }
        if(ann==1) break;  
        
    }
    if(ann==1) cout<<"-"<<endl;
    else{
      for(int i=0;i<n;i++)
        cout<<an[i];
      cout<<endl;
    }
    }

    return 0;
}
