#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(i,s,e) for(ll i=s;i<e;i++)

int gcd(int a, int b){
	if(b == 0)
		return a;
	if(b > a)
		return(gcd(b,a));
	return(gcd(b,a%b));		
}

pair<int,int> findgcd(int n)
{
	int maxgcd = INT_MIN;
	int mingcd = INT_MAX;
	int a,b;
	//if(n == 0)
		//return(make_pair(mingcd,maxgcd));
	for(int i=0;i<n;i++)
	{
		vector<int>arr;
		int ele;
		for(int j = 0;j<pow(2,i);j++)
		{
			cin>>ele; arr.push_back(ele);
		}
		if(arr.size() == 1)
			continue;
		else{
			for(int k=0;k<arr.size();k = k+2){
				a = arr[k];
				b = arr[k+1];
				if(a == -1 || b == -1)
					continue;
				int g = gcd(a,b);		
				if(g > maxgcd)
					maxgcd = g;
				if(g < mingcd)
					mingcd = g;
			}
		}
		arr.clear();
	}
	return(make_pair(mingcd,maxgcd));
}

int main(){
    int T,n,m,X,Y;
    cin>>T;
    fr(t,1,T+1){
        cin>>n;
        pair<int,int> gcd = findgcd(n);
		if (gcd.first == INT_MAX && gcd.second == INT_MIN)
			cout<<0<<endl;
		else cout<<gcd.first<<" "<<gcd.second<<endl;
    }
    return 0;
}
