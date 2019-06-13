// LC16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// jjj

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
        int front,end;
		int n=nums.size();
		end=n-1;
		int i;
		int _min=-1,temp,tmp,sum=0;
		int flag=~(unsigned int)0/2;
		for(i=0;i<n;i++)
		{
			front=i+1;
			end=n-1;
			if(flag==nums[i])
			{
				continue;
			}
			else
			{
				while(front<end)
				{
					tmp=target-nums[i]-nums[front]-nums[end];
					if(_min<0)
					{
						_min=abs(tmp);
						sum=nums[i]+nums[front]+nums[end];
					}
					else
					{
						temp=abs(tmp);
						if(temp<_min)
						{
							_min=temp;
							sum=nums[i]+nums[front]+nums[end];
						}
					}
					if(tmp>0)
						front++;
					else if(tmp<0)
						end--;
					else
						return sum;
				}
				flag=nums[i];
			}
		}
		return sum;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		nums.push_back(k);
	}
	cin>>n;
	Solution s;
	cout<<s.threeSumClosest(nums,n)<<endl;
	return 0;
}


