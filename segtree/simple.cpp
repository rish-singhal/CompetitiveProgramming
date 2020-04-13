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

void build(int a[], int v, int l, int r){
  if(l==r){
    t[v] = a[l];
    return;}
  int tm = (l+r)/2;
  build(a,v*2,l,tm);
  build(a,v*2+1,tm+1,r);
  t[v] = t[v*2] + t[v*2 + 1];
}

LL qu(int a[], int l, int r)



int main(){
  fio();
    
  return 0;
}

