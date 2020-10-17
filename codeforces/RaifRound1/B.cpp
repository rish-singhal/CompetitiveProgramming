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
// check MAXN


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
  	int cnt = 0, cnt2= 0;
  	int bb = 0;
  	for(int i = 0; i < n - 1; i ++){
  		if(s[i] == '>' && s[i + 1] == '<')
  			{
  				bb = 1;
  				continue;
  			}
  		if(s[i] == '<' && s[i + 1] == '>')
  			{
  				bb = 1;
  				continue;
  			}
  		if(s[i] == '-' || s[i+1] == '-'){
  			cnt++;
  		}
  		else{
  			cnt2 ++;
  		}
  	}

  	if(s[n-1] == '>' && s[0] == '<')
  			{
  				bb = 1;

  			}
  	else if(s[n-1] == '<' && s[0] == '>')
  			{
  				bb = 1;
  			}
  	else if(s[n-1] == '-' || s[0] == '-'){
  			cnt++;
  		}
  		else{
  			cnt2 ++;
  		}

  	if(!bb) cnt += cnt2;
  	cout<<cnt<<endl;
  }
  
  return 0;
}