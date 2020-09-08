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
      int n,m; cin>>n>>m;
      vector <int> a(n),b(m);
      map <int,int> as,bs;
      forn(i,n) {
        cin>>a[i];
        as[a[i]] = 1;      
      }
      forn(i,m){
        cin>>b[i];
        bs[b[i]] = 1;
 
      }
      LL an = 0;
      forn(i,n){
        LL k = abs(a[i]);
        for(LL p = 1; p*p<=k;p++){
          if(k%p!=0) continue;
         // (a,b/k), (a/k,b)
          if(p*p==k){
 //           a = p, b = k*p;

            if(bs[p] && bs[-k*p]) an++;
           if(k*p!=p) if(bs[-p] && bs[k*p]) an++;
 //           a = k*p
            continue;
          }
          else{
 //           a = p, b/k = k/p,
   //         a/k = p, b = k/p;


            if(bs[p] && bs[-(k*k/p)]) an++;
            if(p*p!=k*k) if(bs[-p] && bs[(k*k/p)]) an++;
            if(bs[p*k] && bs[-(k/p)]) an++;
            if(p*k*p!=k)if(bs[-p*k] && bs[(k/p)]) an++;

          }
        }
      }

      forn(i,m){
        LL k = abs(b[i]);
        for(LL p = 1; p*p<=k;p++){
          if(k%p!=0) continue;
         // (a,b/k), (a/k,b)
          if(p*p==k){
 //           a = p, b = k*p;

            if(as[p] && as[-k*p]) an++;
           if(k*p!=p) if(as[-p] && as[k*p]) an++;
 //           a = k*p
            continue;
          }
          else{
 //           a = p, b/k = k/p,
   //         a/k = p, b = k/p;


            if(as[p] && as[-(k*k/p)]) an++;
            if(p*p!=k*k) if(as[-p] && as[(k*k/p)]) an++;
            if(as[p*k] && as[-(k/p)]) an++;
            if(p*k*p!=k)if(as[-p*k] && as[(k/p)]) an++;
          }
        }
      }
      
      if(as[0] || bs[0]) an+=(n-as[0])*(m-bs[0]);
      cout<<an<<endl;
    }


    return 0;
}

