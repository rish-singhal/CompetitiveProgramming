#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)

const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n,k; cin>>n>>k;
  vector <LL> v(n);
  forn(i,n) cin>>v[i];
  sort(v.begin(), v.end());
  vector <LL> pr(n), su(n);
  pr[0] = v[0];
  su[n-1] = v[n-1];
  for1(i,n-1) pr[i]+=pr[i-1]+v[i];
  forr(i,n-2) su[i]+=su[i+1] +v[i];
  LL l = 0, r=0;
  LL an = 1e18;
   for(int i=0;i<n;i++){
    if(v[i] == v[l]) r = i;
    else{
      LL len = r - l+1;
      if(len>=k){
        cout<<0<<endl;
        return 0;
      }
      LL kk = k - len;
      LL zl = l, zr = n - r - 1;
      vector <LL> vv;
      LL lz = ((v[l]-1)*zl) - (l>=1?pr[l-1]:0);
      LL rz = (r<=n-1?su[r+1]:0) - (zr*(v[l]+1));
//      cout<<v[l]<<" "<<zl<<" "<<zr<<" :"<<lz<<" " <<rz<<endl;
      if(kk <= zl ){
          an = min(an, kk + lz);
      }
      if(kk <= zr){
        an = min(an,kk+rz);
      }
      if(kk > zl && kk > zr){
        an = min(an,kk+lz+rz);
      }
  //    cout<<v[l]<<" "<<an<<endl;
      l = i, r = i;
    }
   }
   if( r-l+1>=k) {
     cout<<0<<endl;
    return 0;
   }
     LL kk = k - (r-l+1);
      LL zl = l, zr = n - r;
      vector <LL> vv;
      LL lz = ((v[l]-1)*zl) - (l>=1?pr[l-1]:0);
      LL rz = (r<=n-1?su[r+1]:0) - (zr*(v[l]+1));
      if(kk <= zl ){
          an = min(an, kk + lz);
      }
      if(kk <= zr){
        an = min(an,kk+rz);
      }
      if(kk > zl && kk > zr){
        an = min(an,kk+lz+rz);
      }

    cout<<an<<endl;  
    return 0;
}

