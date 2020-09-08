#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int cnt[MAXN];
vector<LL> an[MAXN];



int main(){
  fio();
  	int n; cin>>n;
  	vector <LL> v(n);
    vector<LL> zz(n);
    forn(i,n){
      cin>>v[i];
      zz[i] = v[i];
      for(int j=2; j*j<=v[i];j++){
        if(v[i]%j==0){
          cnt[j]++;
          LL pp = 1;
          while(v[i]%j==0){
            v[i]/=j;
            pp*=j;
          }
          an[j].pb(pp);
          sort(all(an[j]));
          if(an[j].size()>2) an[j].pop_back();
        }

      }
      if(v[i]!=1){
          cnt[v[i]]++;
          an[v[i]].pb(v[i]);
          sort(all(an[v[i]]));
          if(an[v[i]].size()>2) an[v[i]].pop_back();
      }
    }
    LL ann = 1;
    for(int j=2; j<=MAXN; j++){
        if(cnt[j] == n-1 && an[j].size()>=1){
          ann = ann*an[j][0];
        }
        else if(cnt[j] ==n && an[j].size()>=2){
           ann = ann*an[j][1];
        }
    }
    cout<<ann<<endl;
  	
  return 0;
}