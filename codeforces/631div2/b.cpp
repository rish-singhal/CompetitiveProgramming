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

set<int> s;
int n;
bool chk(int i){
  int a = *s.begin();
  int b = *s.rbegin();
  if(a==1 && b==s.size() && b==i+1) return 1;
  return 0;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
    cin>>n;
    vector<int> an;
    vector <int> zz(n);
    s.clear();
    map<int,int> mm;
    forn(i,n){
      int k; cin>>k;
      zz[i] =k;
      //    cout<<k<<" "<<s.count(k)<<endl;
      if(s.count(k)==0){
//      cout<<k<<endl;
        s.insert(k);
      }
      if(chk(i) && i+1!=n) mm[i+1] = 1;
    }
    s.clear();
    reverse(zz.begin(),zz.end());
    forn(i,n){
      int k = zz[i];
  //    cout<<k<<" "<<s.count(k)<<endl;
      if(s.count(k)==0){
  //    cout<<k<<endl;
        s.insert(k);
      }
      if(chk(i) && i+1!=n && mm[n-(i+1)]) an.pb(n- i-1);
    }
  
    cout<<(an.size())<<endl;
    for(auto i:an){
      cout<<(i)<<" "<<(n-i)<<endl;
    }
  }
  return 0;
}

