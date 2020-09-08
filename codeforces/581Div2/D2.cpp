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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    string x;
    cin >> x;
    int n = x.size();
    vector<int> v(n);
    int c = 0;
    while (x[c] == '0')
    {
        cout << 0;

        c++;
    }
    reverse(all(x));
    string z;
    int i = 0;
    int cnt = 0;
    int cnt2 = 0;
    int cntb = 0;
    while (i < n - c)
    {
        int zz = 0;
        int kk = cnt;
        while (i < n - c && x[i] == '0')
        {
            z += '0';
            zz++;
            cnt++;
            i++;
        }
        int cc = 0;
        while (i < n - c && x[i] == '1')
        {
            cc++;
            i++;
        }
        //cout<<"\n"<< cntb<<" "<<cc<<" "<<cnt2<<" "<<cnt<<endl;
        if(cntb==0){
            cnt = max(0,min(cc+zz-kk,cc-zz));
        }
        else{
        cnt = max(0,min(cntb+cc - (cnt2+cnt),cc-cnt));
        }
        for (int j = 0; j < cc - cnt; j++)
            z += '1';
        for (int j = 0; j < cnt; j++)
            z += '0';
        cntb = cc - cnt;
        cnt2 = zz;
    }
    reverse(all(z));
    cout << z << endl;
    return 0;
}