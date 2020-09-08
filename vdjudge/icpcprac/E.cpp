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
      int n; cin>>n;
      LL mi=1e9 + 1,ma= -1e9 - 1; 
      int cnt1=0,cnt11=0,cnt0=0;
      for(int i=0;i<n;i++)
        {
          LL k; cin>>k;
          mi = min(mi,k);
          ma = max(ma,k);
          cnt1+=k==1;
          cnt11+= k==-1;
          cnt0 += cnt0==0;
        }
      if(n==1){
        cout<<"yes\n"<<endl;
        continue;
      }
      cout<<(cnt11 + cnt1 + cnt0)<<endl;
      if(cnt11 + cnt1 + cnt0 < n-1) {
        cout<<"no1\n";
        continue;
      }
      if(cnt11>1 && cnt1==0){
        cout<<"no2\n";
        continue;
      }
      if(mi < -1 && cnt11!=0 ){
        cout<<"no3\n";
        continue;
      }
      if(ma > 1 && cnt11!=0){
        cout<<"no4\n";
        continue;
      }
      if(mi*ma < mi || mi*ma > ma)
      {
        cout<<"no5\n";
        continue;
      }
 
      cout<<"yes\n";

    }      
    return 0;
}

