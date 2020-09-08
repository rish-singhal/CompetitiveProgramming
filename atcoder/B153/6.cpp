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

LL n;
LL tree[200005];
void update(LL idx, LL val){
    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

LL read(LL idx){
    LL sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL d,aa; cin>>n>>d>>aa;
    vector <pair<LL,LL> > a(n);
    forn(i,n) cin>>a[i].fi>>a[i].se;
    srt(a);
    vector <LL> h(n);
    forn(i,n) h[i] = a[i].fi;
    LL an = 0;
    for(LL i =0;i<n;i++){
      LL va = read(i+1) + a[i].se;
      LL nx = upper_bound(all(h),h[i]+2*d) - h.begin();
//      cout<<nx<<endl;
      if(va>0){
       LL up = ((va/aa)*aa + (va%aa==0?0LL:aa));
       update(i+1,-up);
       update(nx+1,up);
       an+= up/aa;

      }
    }
    cout<<an<<endl;

    return 0;
}

