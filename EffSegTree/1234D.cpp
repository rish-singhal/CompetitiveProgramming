#include<bits/stdc++.h>
using namespace std;

int n;
int t[1<<18][26];

void upd(int p, char c){
  p+=n-1;
  for(int i = 0;i<26;i++) t[p][i] = 0;
  t[p][c-'a'] = 1;
  for(;p>1;p>>=1){
    for(int i=0;i<26;i++)
      t[p>>1][i] = t[p][i] + t[p^1][i];
    }
}

int qu(int l, int r){
  int an[26] = {0};
  int cnt = 0;
  for(l+=n-1, r+=n; l<r ; l>>=1, r>>=1){
    if(l&1) {
      for(int i=0;i<26;i++)
          an[i] += t[l][i];
      l++;
    }
    if(r&1){
      r--;
      for(int i=0;i<26;i++)
          an[i] += t[r][i];
    }
  }
  for(int i=0; i<26;i++)
    cnt+=an[i]>0;
  return cnt;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s; cin>>s;
  n = s.size();
  for(int i=0;i<n;i++)
    t[i+n][s[i]-'a'] = 1;
  for(int p=n-1;p>0;p--){
    for(int i=0;i<26;i++)
      t[p][i] = t[p<<1][i] + t[p<<1|1][i];
  }
  int q; cin>>q;
  while(q--){
    int o; cin>>o;
    if(o==1){
      int j; char c; cin>>j>>c;
      upd(j,c);
    }
    else{
      int l,r; cin>>l>>r;
      cout<<qu(l,r)<<endl;
    }
  }
  return 0;
}
