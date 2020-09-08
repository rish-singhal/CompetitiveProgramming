#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	    
    int t;
    cin>>t;
        
        for(int j = 0;j < t;j++){
            
            int i,n;
            long sum = 0,mean =0,count =0;
            cin>>n;
            long  ar[n];
                
                for(i =0;i < n;i++){
                
                    cin>>ar[i];
                    sum+=ar[i];
                }
                mean = sum;
                int ind = -1;
                long long v = 1e17;
                for(i =0;i <n;i++){
                    
                    //    count++;
                        if(sum*(n-1) == n*(sum - ar[i])){
                           // cout<<count<<"\n";
                            //break;
                            if(ar[i]< v){
                              v = ar[i];
                              ind = i;
                            }
                        }
                }
                if(ind == -1){
                    cout<<"Impossible"<<"\n";
                }
                else cout<<(ind+1)<<endl;
            
        }
    
	return 0;
}
