#include<stdio.h>
int bnsrch_rec(int *arr,int l,int h,int se)
{
	int mid=(l+h)/2;
	if(l>h)
	{
		return -1;
	}
	else if(arr[mid]==se)
	{
	return mid;	
	}
	else if(arr[mid]<se)
	{
		l=mid+1;
	}
	else if (arr[mid]>se)
	{
		h=mid-1;
	}
	bnsrch_rec(arr,l,h,se);
}	
int main()
{
	int n,arr[100],se,res;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	res=bnsrch_rec(arr,0,n-1,se);
	printf("%d",res);	
}