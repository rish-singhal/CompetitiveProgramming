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

void solve(){
	int n; cin>>n;
  vector<string> s(n);
  forn(i,n){
    cin>>s[i];
  }
  string an = "";
  string a ="";
  string p = "";
  forn(i,n){
    int l=-1,r=-1;
    forn(j,s[i].size()){
      if(s[i][j]=='*') {l = j; break;}
    }
    string zz = s[i];
    reverse(zz.begin(),zz.end());
    forn(j,zz.size()){
      if(zz[j]=='*') {r = zz.size()-1-j; break;}
    }
    //cout<<l<<" "<<r<<endl;
    while(l<r){
      if(s[i][l]!='*')an+=s[i][l];
      l++;
    }
    if(s[i][0]!='*'){
      string k="";
      for(auto c:s[i]) {
        if(c=='*') break;
        k+=c;   
      }
      for(int j=0;j<min(k.size(),a.size());j++){
        if(a[j]!=k[j]){
          cout<<"*"<<endl; 
          return;
        }
      }
      a = (a.size()>k.size()?a:k);
      
    }
    if(s[i][s[i].size()-1]!='*'){
      string k=""; 
      for(auto c:zz){
        if(c=='*') break;
        k+=c;  
      }
      for(int j=0;j<min(k.size(),p.size());j++){
        if(p[j]!=k[j]){
          cout<<"*"<<endl; 
          return;
        }
      }
      p = (p.size()>k.size()?p:k);
    }
  }
  reverse(p.begin(),p.end());
  string ann = a+an+p;
  if(ann.size()==0) cout<<"*"<<endl;
  else cout<<ann<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  for1(i,t){
  	cout<<"Case #"<<i<<": ";
  	solve();
  }
  return 0;
}