#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v;
vector<int> res(20,0);
vector<int> t(20,1);
class Compare{
    public:
        bool operator()(int i,int j){
            if((res[j]+t[j]*v[j]) > (res[i]+t[i]*v[i])){
                return true;
            }
            return false;
        }
};

int minCookTime(vector<int> &arr, int m)
{
    // Write your code here
    int n = arr.size();
    v = arr;
    priority_queue<int,vector<int>,Compare> q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    for(int i=0;i<m;i++){
        int j = q.top();
        q.pop();
        res[j] += t[j]*arr[j];
        q.push(j);
    }
    return res[q.top()];
}
int main(){
    vector<int> arr = {1,2,3,4};
    cout<<minCookTime(arr,11)<<endl;

    return 0;
}