/*
  This program is the C version of GFG problem Find missing number 
  First input takes number of testcases
   2nd input takes number of elements but the input will be n - 1 times as in the GFG problem
*/
#include <stdio.h>

int main() {
    
    int t,n,x1,x2,elem;
    
	scanf("%d",&t);
	
	while(t--)
	{
	    int i;
	    
        x1=0,x2=0;
	    
        scanf("%d",&n);
	    
        for(i=0;i<n-1;++i)
	    {
	        scanf("%d",&elem);
	     
            x1 = x1^(i+1);
	     
            x2 = x2^elem;
	    }
        
        x1 = x1 ^ (i + 1);
        
	    printf("%d\n",x1^x2);
	}
	return 0;
}
