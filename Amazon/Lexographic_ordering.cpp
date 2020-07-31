#include<bits/stdc++.h>
// #include<vector>
using namespace std;

vector<pair<string,vector<int>>> findorder(vector<pair<string,int>>& arr, int n)
{
    map<string,vector<int>>mp;
    map<string,vector<int>>avg;
    for(int i=0;i<n;i++)
    {
        string s = arr[i].first;
        int cost =arr[i].second;
        vector<int>t(3,0);
        if(mp.find(s) == mp.end())
        {
            mp[s].push_back(cost);
            t[0] = t[1] = t[2] = cost;
            avg[s] = t;
        }
        else
        {
            mp[s].push_back(cost);
            if(avg[s][0] > cost)
                avg[s][0] = cost;
            if(avg[s][1] < cost)
                avg[s][1] = cost;
            avg[s][2] = avg[s][2] + cost;
        }
    }
 
        vector<pair<string,vector<int>>>res;
        for(auto it = avg.begin() ; it != avg.end() ;it++)
        {
            string s = it->first;
            vector<int>t = it->second;
            t[2] = t[2]/mp[s].size();
            res.push_back({s,t});
        }
        
    return res;
}


int main()
{
    int n;
    vector<pair<string,int>>arr;
    cin>>n;
    arr.resize(n);
    string s;
    int ele ;
    for(int i=0;i<n;i++)
    {
        cin>>s>>ele;
        arr[i].first = s;
        arr[i].second = ele;
    }
    vector<pair<string,vector<int>>>res = findorder(arr,n);
    for(auto it : res)
    {
        cout<<it.first<<" ";
        for(int i=0;i<3;i++)
            cout<<it.second[i]<<" ";
        cout<<endl;
    }
    return 0;
}




/*INPUT: 
5
banana 5
apple 10
banan 10
appl 20
appl 30

OUTPUT:
appl 20 30 25 
apple 10 10 10 
banan 10 10 10 
banana 5 5 5 */
