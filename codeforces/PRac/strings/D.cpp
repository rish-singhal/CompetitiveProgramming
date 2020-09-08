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

int n;
string s;
string add(int p){
	if(s[p]=='0'){
		string pp(1e6,'9');
		return pp;
	}
	string a="";
	for(int i=0;i<p;i++){
		a+=s[i];
	}
	string b="";
	for(int i=p;i<n;i++){
		b+=s[i];
	}
	if(a.size()>b.size()) swap(a,b);
	int n1 = a.size(), n2 = b.size();
	int d = n2 - n1;
	int c = 0;
	string an = "";
	int i,j;
	for(i=n1-1, j=n2-1;i>=0 && j>=0;i--,j--){
		int v = ((a[i]-'0')+(b[j]-'0') + c);
		an+=((v%10)+'0');
		c = v/10;
	}	
	while(j>=0){
		int v = ((b[j]-'0') + c);
		an+=((v%10)+'0');
		c = v/10;
		j--;
	}
	while(c){
		an+=((c%10)+'0');
		c/=10;
	}
	reverse(all(an));
	return an;
}

int main(){
  fio();
  cin>>n;
  cin>>s;
  int l = (n%2?(n/2):(n/2)-1),r= (n%2?(n/2)+1:(n/2));
  while(l>=0 && s[l]=='0') l--;
  while(r<n && s[r]=='0') r++;
  vector<string> v;
  v.pb(add(l));
  v.pb(add(r));
  sort(all(v));
  if(v[0].size()>v[1].size()) swap(v[0],v[1]);
  cout<<v[0]<<endl;
  return 0;
}