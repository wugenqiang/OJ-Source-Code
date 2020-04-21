/*最长连续因子
题目：
输入一个整数，输出其最长连续因子。
例如
输入：60
输出：2 3 4 5 6
注意：1不算因子*/ 
//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<int> factor;
	for (int i = 2; i <= num; i++)//存储因子 
		if (num%i == 0)
			factor.push_back(i);
	int* dp = new int[factor.size()];
	dp[0] = 1;
	for (int i = 1; i < factor.size(); i++) {
		if (factor[i] == factor[i-1]+1)
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = 1;
	}
	int index = 0;
	for (int i = 1; i < factor.size(); i++) {
		if (dp[i] > dp[index])
			index = i;
	}
	for (int i = index-dp[index]+1; i < index; i++)
		cout << factor[i] << " ";
	cout << factor[index] << endl;
	return 0;
}
