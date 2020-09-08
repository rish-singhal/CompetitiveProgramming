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


LL chleap(LL a){
  return a%400==0 || ( a%4==0 && a%100!=0);
}

LL fun(LL a){
  cout<<a<<" : ";
  a--;
  LL lp =  (a/4) - (a/100) + (a/400);
  LL k = a+lp+1;
  cout<<(k%7)<<" "<<chleap(a+1)<<" ";
  if(k%7 == 4 && !chleap(a+1)) cout<<"*";
  cout<<endl;
  
  if(k<6) return 0;
  return ((k-3)/7);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int t; cin>>t;
    while(t--){
//      LL a,b,c,d; cin>>a>>b>>c>>d;
      //cin>>a;
  //    for(int i =0;i<500;i++)fun(i);
       //    if(a>2) b++;
     //if(c==1) d--;
    for(int i = 1600;i<=2100;i++) fun(i);
     //cout<<(fun(d) - fun(b-1))<<endl;
    }
    return 0;
}

