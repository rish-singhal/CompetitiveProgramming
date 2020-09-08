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
int D;
struct Query
{
    int l, r, idx;
    bool operator<(const Query& a) const
    {
        return (l-1)/D<(a.l-1)/D||(l-1)/D==(a.l-1)/D&&r<a.r;
    };
};
LL fr[1000005];
LL cnt = 0;

void add(LL x)
{
    cnt += (2 * fr[x] + 1) * x;
    fr[x]++;
}
void remove(LL x)
{
    cnt -= (2 * fr[x] - 1) * x;
    fr[x]--;
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    D = sqrt(n);
    vector<int> a(n);
    forn(i, n) scanf("%d", &a[i]);
    vector<Query> v(q);
    forn(i, q)
    {
        int l, r;
        scanf("%d%d",&v[i].l,&v[i].r);
        v[i].l--, v[i].r--;
        v[i].idx = i;
    }
    srt(v);
    vector<LL> an(q);
    int l = 0, r = -1;
    for (auto q : v)
    {
        while (l > q.l)
        {
            l--;
            add(a[l]);
        }
        while (r < q.r)
        {
            r++;
            add(a[r]);
        }
        while (l < q.l)
        {
            remove(a[l]);
            l++;
        }
        while (r > q.r)
        {
            remove(a[r]);
            r--;
        }
        an[q.idx] = cnt;
    }
    for (auto i : an)
        printf("%lld\n", i);
    return 0;
}

