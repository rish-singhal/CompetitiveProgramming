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

LL abs(LL x){
  return x>=0?x:-x;
}

LL dsu[2005];
LL chk[2005];

LL pa(LL u){
  return dsu[u]<0?u:dsu[u]= pa(dsu[u]);
}

void join(LL a,LL b){
  a = pa(a);
  b = pa(b);
  if(a==b) return;
  if(dsu[a] < dsu[b]) swap(a,b);
  dsu[b] += dsu[a];
  dsu[a] = b;
  chk[a] = max(chk[b],chk[a]);
  return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n; cin>>n;
    vector<LL> x(n),y(n),c(n),k(n);
    forn(i,n) cin>>x[i]>>y[i];
    for(auto &i:c) cin>>i;
    for(auto &i:k) cin>>i;
    vector<pair<int,pair<int,int> > v;
    map <int, pair<int,int> > e;
    map <int, int> ve;
    forn(i,n){
      v.pb({c[i],{1,i}});
        ve[i] = i;
      }
    int cnt=  0;
    forn(i,n){
      for(int j=0;j<i;j++){
        LL ann = (k[i] + k[j])*( abs(x[i]-x[j]) + abs(y[i]-y[j]));
        v.pb({ann,{2,cnt}});
        e[cnt] = {i,j};
        cnt++;
        }
    }
    srt(v);
    vector <LL> vs;
    vector <pair<LL,LL> > es;
    LL cst= 0;
    for(auto i:v){
      if(i.se.fi == 1){
        if(chk[pa(i.se.se)]==0){
          vs.pb(i.se.se);
          cst+=i.fi;
          chk[pa(i.se.se)] = 1;
      }     
        else{
          auto ed = e[i.se.se];
          if(pa(ed.fi)!=pa(ed.se)){
            if(chk[pa(ed.fi)] == 1 && chk[pa(ed.se)] ==1) continue;
            join(ed.fi,ed.se);
            es.pb(ed);
            cst += i.fi;
        }
    }
      }
    }
    cout<<cst<<endl;
    cout<<vs.size()<<endl;
    for(auto i:vs){
      cout<<(i+1)<<" ";
    }
    cout<<endl;
    cout<<es.size()<<endl;
    for(auto i:es){
      cout<<(i.fi+1)<<" "<<(i.se)<<endl;
    }


    return 0;
}

