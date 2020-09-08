#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	int n; cin>>n;
  	string s; cin>>s;
  	string p = "abacaba";
  	string pk = "abacabacaba";
  	int an = 0;
  	int cnt = 0;
  	if(n < 7){
  		cout<<"NO"<<endl;
  		continue;
  	}
  	for(int i = 0; i < n; i++){
  		if(s.substr(i, 7) == p){
  			cnt++;
  			//break;
  		}
  	}
  	if(cnt == 1){
  		for(auto &i:s) if(i=='?')  i= 'z';
  			cout<<"YES"<<endl;
  		cout<<s<<endl;
  		continue;
  	}
  	if(cnt >= 2){
  		cout<<"NO"<<endl;
  		continue;
  	}

  	// abacab?bacaba
  	for(int i = 0 ; i < n; i++){
  		int b = 0;
  		int cnt2 = 0;
  		for(int j = 0; j < 7 && (i + j) < n; j++){
  			cnt2 ++;
  			if(s[i+j]==p[j] || s[i+j]=='?') continue;
  			else{
  				b = 1; break;
  			}
  		}
  		int cnt3 = 0;
  		int kk = 0;
  		for(int j = 7; j < 11 && i + j < n; j++){
  			//cnt3 ++;
  			if(s[i+j] != pk[i]){
  				break;
  			}
  			cnt3 ++;
  		}
  		if(cnt3 == (5)){
  			kk = 1;
  		}
  		if(!b && cnt2 == 7 && (!kk)){
  			for(int j = 0; j < 7; j++){
  				s[i+j] = p[j];
  			}
  			break;
  		}
  	}
  	cnt = 0;
  	for(int i = 0; i < n; i++){
  		if(s.substr(i, 7) == p){
  			cnt++;
  		}
  	}
  	if(cnt != 1){
  		cout<<"NO"<<endl;
  		continue;
  	}
  	if(cnt == 1){
  		for(auto &i:s) if(i=='?')  i= 'z';
  			cout<<"YES"<<endl;
  		cout<<s<<endl;
  		continue;
  	}
  	
  }
  return 0;
}