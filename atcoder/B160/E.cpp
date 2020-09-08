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

int main(){
  fio();
  LL x,y,a,b,c; cin>>x>>y>>a>>b>>c;
  vector <LL> va(a), vb(b), vc(c);
  for(auto &i:va) cin>>i;
  for(auto &i:vb) cin>>i;
  for(auto &i:vc) cin>>i;
  sort(va.begin(),va.end());
  sort(vb.begin(),vb.end());
  sort(vc.begin(),vc.end());
  LL an = 0;
  LL l = a-x, r = b-y, z = c-1;
  for(int i=l;i<a;i++) an+=va[i];
  for(int i=r;i<b;i++) an+=vb[i];
  while(1){
    if(z<0) break;
    if(r >= b && l>= a) break;
    int bo = 1;
    if(r>=b && l<a){
        if(vc[z] > va[l]) {
          an+=vc[z]-va[l];
          z--,l++;
        continue;
        }
        break;
    }  
    if(l>=a && r<b){
        if(vc[z] > vb[r]) {
          an+=vc[z]-vb[r];
          z--,r++;
          continue;
        }
        break;
    }  

    if(va[l] > vb[r]){
        if(vc[z] > vb[r]) {
          an+=vc[z]-vb[r];
          z--,r++;
          continue;
        }
      }
    else{
        if(vc[z] > va[l]) {
          an+=vc[z]-va[l];
          z--,l++;
          continue;
        }
    }
    break;
  }
  cout<<an<<endl;
  return 0;

}

