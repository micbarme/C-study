#include<stdio.h>
#include<stdlib.h>             //合唱队   动态规划求最长递增子序列；
int main()
{
	int n, i, j, ans;
	int *num, *dpup, *dpdown;    

	scanf("%d",&n);
	num=(int *)malloc(n*sizeof(int));
	dpup=(int *)malloc(n*sizeof(int));
	dpdown=(int *)malloc(n*sizeof(int));

	for(i=0; i<n; i++)
		scanf("%d",&num[i]);

	for(i=0; i<n; i++)
	{
		dpup[i]=1;
		for(j=0; j<i; j++)
			if(num[i]>num[j]&&dpup[j]+1>dpup[i])
				dpup[i]=dpup[j]+1;
	}
	
    for(i=n-1;i>=0;i--)  
    {  
        dpdown[i]=1;  
        for(j=n-1;j>i;j--)  
            if(num[i]>num[j]&&dpdown[j]+1>dpdown[i])  
                dpdown[i]=dpdown[j]+1;  
    }

	ans=0;
	for(i=0;i<n;i++)  
    {  
        if(ans<dpup[i]+dpdown[i]-1)  
            ans=dpup[i]+dpdown[i]-1;  
    }  
    printf("%d", n-ans);  
    
	return 0;  
}

