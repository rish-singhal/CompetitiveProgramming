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
LL n,k;
string s;
LL p(int i){ return (i-1+n)%n; }
LL f(int i){ return (i+1)%n; }
bool ch(int i){ 
    i = (i+n)%n;
  if(s[p(i)]=='W' && s[i]=='B' && s[f(i)]=='W')
        return 1;
  if(s[p(i)]=='B' && s[i]=='W' && s[f(i)]=='B')
        return 1;
  return 0;
}
map <int,int> m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cin>>n>>k;
    cin>>s;
    int l = -1, r = -1;
    int b = 0;
    forn(i,n){
      if(ch(i)==0){
        b = 1;
        break;
      }
    }
    if(!b){
      if(k&1){
        for(auto &i:s){
          i = (i=='W'?'B':'W');
        }
      }
      cout<<s<<endl;
      return 0;
    }
  //  if(n==200000) cout<<"rish"<<endl;
    b = 0;
    for(int i=0;i<2*n;i++){
      if(ch(i)){
        if(b) r = i%n;
        else{
          b = 1, l = r = i%n;
        }
      }
      else{
        if(b){
          b = 0;
          m[r] = l;
          r = -1, l = -1;
        }
      }
    }
    for(auto c:m){
      
      l = c.se;
         r = c.fi;
        if(n==200000) cout<<l<<" "<<r<<endl;
       //  if(r==-1) continue;
         //         cout<<l<<" "<<r<<endl;
         char ll = s[p(l)];
         char rr = s[f(r)];
        if(n==200000) cout<<ll<<" "<<rr<<endl;
         LL len = ( r - l + 1 + n)%n;
         LL tt = min(k,len>>1);
        for(int i=0;i<tt;i++){
          s[(l+i)%n] = ll;
          s[(r-i+n)%n] = rr;
          if((r-i+n)%n==0 && n==200000) cout<<"yessss"<<" "<<s[(r-i+n)%n]<<endl; 
        }
        if(n==200000) cout<<((r-tt+n)%n)<<endl;
        if(tt<(len>>1)){
        // int kk = 1;
         for(int i=tt;i<(len/2);i++){
          s[(l+i)%n] =(s[(l+i-1+n)%n]=='W'?'B': 'W');
          s[(r-i+n)%n] =(s[(r-i+n+1)%n]=='W'?'B':'W');
        
         }
        }               
        if(len&1){
          int po = (l+(len)/2)%n;
  //        cout<<po<<" ewew"<<endl;
          if(k>=(len+1)/2){
           s[po] = ll; 
    //       cout<<"ee"<<endl;
          }
          else{
           s[po] = s[f(po)]=='W'?'B':'W';
          }
        }
    }
    cout<<s<<endl;
        return 0;
}
