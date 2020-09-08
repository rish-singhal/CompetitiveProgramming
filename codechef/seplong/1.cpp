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


void multiply(int an[2][2], int mat[2][2]){
  int aa[2][2]={{0,0},{0,0}};
  forn(i,2)
    forn(j,2)
      forn(k,2)
          aa[i][j] = (aa[i][j] + (an[i][k])*mat[k][j])%10;
  forn(i,2)
    forn(j,2)
      an[i][j] = aa[i][j];
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
      LL n; cin>>n;
      LL k=1;
      while(1){
        if(k>n) break;
        k<<=1;
      }
      k>>=1;
      k--;     
      int mat[2][2]= {{1,1},{1,0}};
      int an[2][2]={{1,0},{0,1}};
      while(k){
        if(k&1){
          multiply(an,mat);
        }
        multiply(mat,mat);
      
        k>>=1;
      }
    cout<<(an[1][0])<<endl;     
    }
    return 0;
}

