#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<vector>
#define sz(x) x.size()
using namespace std;
int orientation(pair<int,int> p,pair<int,int> A,pair<int,int> r)
{
	int res=(A.second-p.second)*(r.first-A.first)-
            (r.second-A.second)*(A.first-p.first);
	if(res==0)
		return 0;//collinear
	if(res<0)
		return 2;//counter-clockwise
	return 1;// clockwise
}
int main()
{
    cout<<"enter the number of points\n";
    int n;
    cin>>n;
    pair<int,int> a[n];
    cout<<"enter the points\n";
    for(int i=0;i<n;i++)
    	cin>>a[i].first>>a[i].second;
    if(n<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	vector<pair<int,int> >ans;
	int p=0;
	for(int i=1;i<n;i++)
	{
		if(a[p].first<a[i].first)
			p=i;
	}
	int same=p;
	do
	{
		ans.push_back(a[p]);
		int A=(p+1)%n;
		for(int i=0;i<n;i++)
		{
			if(orientation(a[p],a[i],a[A])==2)
				A=i;
		}
		p=A;
	}
	while(p!=same);
	cout<<"the points in convex ans are:\n";
	for(int i=0;i<sz(ans);i++)
		cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<endl;
    return 0;
}
