#include<stdio.h>
#include<string.h>              //动态规划思想求字符串编辑距离   i，j代表s1[], s2[]的起始点。

int minimum(int a, int b, int c)
{
	int x;
	x = a<b ?a : b;
	return x<c ? x : c;
}

int CalDistance(char s1[], char s2[])
{
	int len1, len2, i, j;
	int dp[100][100];

	len1=strlen(s1);
	len2=strlen(s2);

	for(i=0; i<=len1; i++)
		dp[i][len2]=len1-i;
	for(j=0; j<=len2; j++)
		dp[len1][j]=len2-j;

	for(i=len1-1; i>=0; i--)
		for(j=len2-1; j>=0; j--)
		{
			if(s1[i]==s2[j])
				dp[i][j]=dp[i+1][j+1];
			else
				dp[i][j]=minimum(dp[i+1][j+1], dp[i+1][j], dp[i][j+1])+1;
		}
	return dp[0][0];
}

int main()
{
	char s1[100], s2[100];
	int res;
	
	gets(s1);
	gets(s2);

	res=CalDistance(s1, s2);
	
	printf("%d", res);
	return 0;
}

