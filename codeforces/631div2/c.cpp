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
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
LL max(LL a , LL b) {
  return a>b?a:b;
}

int main(){
  fio();
  LL m, n; cin>>n>>m;
  vector<LL> v(m);
  LL sum = 0;
  int b = 0;
  forn(i,m){
    cin>>v[i];
    if(n-v[i]<(i)) {
  //    cout<<(n-v[i])<<" "<<(i+1);
    //  cout<<i<<endl;
      b = 1;
    }
    sum += v[i];
  }
  if(sum<n || b){
//    cout<<b<<endl;
    cout<<-1<<endl;
    return 0;
  }
    vector<int> an(m);
  an[m-1] = n-(v[m-1]) +1;
  int r = v[m-1]+1;
  int cc = m-2;
  sum-=v[m-1];
  while(cc>=0){
//    cout<<r<<" "<<(v[cc])<<" --- "<<endl;

    r = max(r, v[cc]);
    int l = min(n,r-1+v[cc]);
 //  cout<<" r l "<<r<<" "<<l<<endl;
    while(r<=l){
      if(n-r>=(cc) && n-r<=(sum-v[cc])){
        an[cc] = n-r+1;
        break;
      }
      r++;
    }
    sum-=v[cc];
    r++;
    //r = (n-an[cc]);
    cc--;
  }
  for(auto i:an) cout<<i<<" ";
  cout<<endl;
   return 0;
}

