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
  int q; cin>>q;
  while(q--){
  	string s; cin >> s;
  	string t; cin >> t;
  	
  	int len1 = 0;
  	string str1 = "";
  	cout << " 13 " <<endl;
  	for(int len = 1; len <= (int)s.size(); len++){
  		if((s.size() % len) != 0)
  			continue;
  		int b = 0;
  		string sks = "";
  		for(int i = 0; i < s.size(); i += len){
  			string ss = "";
  			for(int k = i; k < i + len; k++)
  				ss += s[k];
  			if(i == 0) sks = ss;
  			else if(ss != sks)
  			{
  				b = 1; break;
  			}
  		}
  		if(!b){
  			len1 = len;
  			str1 = sks;
  			break;
  		}
  	}

  	int len2 = 0;
  	string str2 = "";
  	for(int len = 1; len <= s.size(); len++){
  		if(t.size() % len != 0)
  			continue;
  		int b = 0;
  		string sks = "";
  		for(int i = 0; i < t.size(); i += len){
  			string ss = "";
  			for(int k = i; k < i + len; k++)
  				ss += t[k];
  			if(i == 0) sks = ss;
  			else if(ss != sks)
  			{
  				b = 1; break;
  			}
  		}
  		if(!b){
  			len2 = len;
  			str2 = sks;
  			break;
  		}
  	}

  	if(str1 != str2)
  		cout << -1 << endl;
  	LL a = s.size()/len1;
  	LL b = t.size()/len2;

 	cout << a << " " << b << endl;
  	//LL mm = a*b/(__gcd(a,b));
  	//forn(i,mm) cout << str1 << " ";
  	
  }
  return 0;
}