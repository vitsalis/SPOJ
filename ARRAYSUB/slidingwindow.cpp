#include <bits/stdc++.h>
using namespace std;
int a[100000];
list<int> b;
int main() 
{
	int n,k,maxi=0,r,i,max1=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
    scanf("%d",&k);
	for(i=0;i<k;i++)
	{
	    while(!b.empty() && a[i]>=a[b.back()])
	        b.pop_back();
	    b.push_back(i);
	}
	for(;i<n;i++)
	{
	  printf("%d ",a[b.front()]);
	  if(!b.empty() && b.front()==i-k)
	    b.pop_front();
	  while(!b.empty() && a[i]>=a[b.back()])
	        b.pop_back();
	    b.push_back(i);
	}
	printf("%d ",a[b.front()]);
	return 0;
}
