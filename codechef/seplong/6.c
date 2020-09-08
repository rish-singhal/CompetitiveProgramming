#include <stdio.h>
#define LL long long
LL const mm = 1e9+7;
LL min(LL a,LL b)
{
  return a>b?b:a;
}
int main()
{
    int t; scanf("%d",&t);
    while(t--){
      LL a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
      LL an = 0;
      a-=1, c-=1;
      for(LL k =1 ;k<=b;k++)
      {
         LL n = 0, m = 0;
         LL aa = min(k,c);
         LL bb = min(k,a);
        LL zz= aa>bb?aa:bb;
         for(LL p=1;p<=zz;p++){
           LL po = k*k/p;
           LL ap = min(a,po);
           LL cp = min(c,po);
          if(p<=aa) {
            n += ap;
            n-=(n>=mm)*mm;
          }
          if(p<=bb){
              m +=cp;
              m -=(m>=mm)*mm;
          }
          an += a*c;
          an -= (an>=mm)*mm;
          an -= (n + m);
          an -= (an>=mm)*mm;
          an +=(an<0)*mm;
          an += ( aa*bb);
          an -=(an>=mm)*mm;
         }
          printf("%lld\n",an);
    }
    }


        return 0;
}

