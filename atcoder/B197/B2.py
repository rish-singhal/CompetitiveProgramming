h,*s=open(0)
h,w,y,x=map(int,h.split())
s+='#'*w,
a=-3
for p,q in(-1,0),(0,-1),(0,1),(1,0):
 i,j=y-1,x-1
 while'#'<s[i][j]:a+=1;i+=p;j+=q
print(a)