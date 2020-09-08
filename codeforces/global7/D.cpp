#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
#define all(v) v.begin(), v.end()

auto nxt() -> LL{
  LL x; cin>>x;
  return x;
}

string palin(string s){
  string a = s;
  reverse(all(s));
  string b = s;
  string p1 = a+"*"+b;
  string p2 = b+"*"+a;
  vector <int> kmp(p1.size(), 0);
  int k = 0;
  forn(i,p1.size()-1) {
    while (k && p1[k] != p1[i]) k = kmp[k - 1];
    if (p1[k] == p1[i]){
       ++k;
     }
    kmp[i] = k;
  }
//  cout<<p1<<": ";
  //for(auto i:kmp) cout<<i<<" ";
//  cout<<endl;
  string s1 = "";
  bool kk = 0;
  s1+=p1[kmp[kmp.size()-1]-1];
  for(int i=kmp.size()-2;i>=0;i--){
    if(kmp[i]==kmp[i+1]-1 && kmp[i]!=0) s1+=p1[kmp[i]-1];
    if(kmp[i]==1 || kmp[i]!=kmp[i+1]-1) break;
    if(kmp[i]!=kmp[i+1]-1 ){
      kk = 1; break;
    }
  }
  if(kk) s1 = p1[kmp[kmp.size()-1]-1];
  reverse(all(s1));

  fill(all(kmp), 0);
  k = 0;
  forn(i,p1.size()-1) {
    while (k && p2[k] != p2[i]) k = kmp[k - 1];
    if (p2[k] == p2[i]) ++k;
    kmp[i] = k;
  }

  string s2 = "";
  kk = 0;
  s2+=p2[kmp[kmp.size()-1]-1];
  for(int i=kmp.size()-2;i>=0;i--){
    if(kmp[i]==kmp[i+1]-1 && kmp[i]!=0) s2+=p2[kmp[i]-1];
    if(kmp[i]==1 || kmp[i]!=kmp[i+1]-1) break;
    if(kmp[i]!=kmp[i+1]-1 ){
      kk = 1; break;
    }
  }
  if(kk) s2 = p2[kmp[kmp.size()-1]-1];
  reverse(all(s2));
  if(s1.size() < s2.size() && s1.size()<= s.size()) return s1;
  else  if(s2.size() <= s.size())return s2;
  return "";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    string s; cin>>s;
    int n = s.size();
    string s2 = palin(s);
   cout<<s2<<endl;
    string k = "";
    string z = "";
    int pp = 0;
    for(pp=0;pp<(n/2);pp++){
      if(s[pp]==s[n-pp-1]) z+=s[pp];
      else break;
    }
    if(z.size()==0 || s2 == s){
      cout<<s2<<endl;
    }
    else{
      for(int i=pp; i<=(n-pp-1);i++){
        k+=s[i];
      }
      string s3 = palin(k);
      string zz = z;
      reverse(all(zz));
      z += s3 + zz;
      z = palin(z);
      if(z.size()>s2.size() && z.size() <=s.size()) cout<<z<<endl;
      else cout<<s2<<endl;
    }
  }
  return 0;
}
