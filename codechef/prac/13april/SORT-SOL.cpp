// Problem SORTING. Fastest setter's 100-point solution
// O(logN)-per-query. Overall complexity: O(N log N)

#include <stdio.h>

#define maxn 1111111

struct node{ // node of the persistent segment tree
	int L,R,sum; // left and right bounds and the sum in the segment
	node*hL,*hR; // left and right sons
	node(){}
	node(int L,int R):L(L),R(R),sum(0){}
}all[20000000];
int tot;

typedef node * pnode;

pnode root[maxn];
int a[maxn],pos[maxn],n,i;
long long ans;

pnode create(int L,int R){ // create persistent segment tree
	pnode ret=&all[tot++];
	ret->L=L,ret->R=R;
	ret->hL=ret->hR=NULL;
	if(L<R){
		ret->hL=create(L,(L+R)/2); // create left son
		ret->hR=create((L+R)/2+1,R); // create right son
	}
	return ret;
}

pnode change(pnode t,int j){ //	create a new version with the j-th number equal to one and all other numbers equal to the numbers in the version t
	pnode ret=&all[tot++];
	ret->L=t->L;ret->R=t->R;
	ret->hL=t->hL,ret->hR=t->hR;
	ret->sum=t->sum+1; // increase the amount of ones in the semgment
	if(t->L<t->R)
		if(t->hL->R>=j)ret->hL=change(ret->hL,j);else ret->hR=change(ret->hR,j); // standard thing
	return ret;
}

int getkth(pnode low,pnode high,int key){ // get the k-th number
	if(low->L==low->R)return low->L; // if the size of the range equals to one the the number is found
	if(high->hL->sum-low->hL->sum>=key) 
		return getkth(low->hL,high->hL,key);else // if the amount of one in the left son is enough, go to the left son
		return getkth(low->hR,high->hR,key-(high->hL->sum-low->hL->sum)); // otherwise go to the right son and subtract the amount of numbers in the left son
		
}

int qL[2222222],qR[2222222],q1,q2;

void solve(int L,int R){ // simulate the QuickSort
	qL[q1]=L,qR[q1]=R;++q1;q2=0;
	while(q1!=q2){ // BFS is used here
		L=qL[q2];R=qR[q2];
		if(R-L+1>=2){
			int median=a[getkth(root[L-1],root[R],(R-L+2)/2)]; // get the pivot in O(logN) time
			ans+=R-L+1;
			qL[q1]=L,qR[q1]=median-1;++q1; // add [L; pivot)
			qL[q1]=median+1,qR[q1]=R;++q1; // add (pivot; R]
		}
		++q2;
	}
}

int main (int argc, char * const argv[]) {
	scanf("%d",&n); // size of the permutation
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	root[0]=create(1,n); // create the first version
	for(i=1;i<=n;i++)root[i]=change(root[i-1],pos[i]); // create additional N versions
	solve(1,n);
	printf("%lld\n",ans);
    return 0;
}
