//#recursive + memoization


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int knapsack(vector<int>& val, vector<int>& wt, int rem_wt, int n)
{
    if(n == 0 || rem_wt == 0)
        return 0;
    int profit = 0;
	if(dp[n][rem_wt] != -1)
		return dp[n][rem_wt];

    if(wt[n-1] <= rem_wt)
    {
        profit = max((val[n-1]+ knapsack(val,wt, rem_wt-wt[n-1], n-1)),
        knapsack(val,wt, rem_wt, n-1));
    }
    else
        profit = knapsack(val,wt, rem_wt, n-1);

	dp[n][rem_wt] = profit;
        
    return profit;
    
}

int main() {
	//code
	int n,W;
	int T;
	cin >> T;
	vector<int>val;
	vector<int>wt;
	while(T--){
	cin>>n>>W;
	val.resize(n);
	wt.resize(n);
	for(int i=0 ; i<n;i++)
	    cin>>val[i];
	for(int i=0;i<n;i++)
	    cin>>wt[i];
	dp.resize(n+1,vector<int>(W+1,-1));
	int profit = knapsack(val, wt, W, n);
	cout<<profit<<endl;
	dp.clear();
	}
	return 0;
}


/*
INPUT :
2
3 50
60 100 120
10 20 30
3 6
10 15 40
1 2 3

OUTPUT :
220
65
*/
