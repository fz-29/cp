/*********************** SIMPLER PROBLEM THAN CLASSICAL KNAPSACK *********************
A problem in which N numbers can be taken indefinitely, such that sum of numbers is less
than k can be visualized as :

A bag with limit k.
N items - with weight wi, and ci = wi * 1 = wi.
Therefore  maximize ci, subjected to sum(wi) <= k
or         maximize wi, subjected to sum(wi) <= k

*************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int input[2005];
    while(t--)
    {
        int n,k,target_iter,j;
        cin>>n>>k;
        vector<int> dp(k+2,0);
        for(j=0;j<n;j++)
            cin>>input[j];
        for(target_iter=1;target_iter<=k;target_iter++) //possible sums
        {
            for(j=0;j<n;j++) //iterating over all the elements
            {
                int weight = input[j];//can be thought as weight
                int cost = weight * 1;//cost
                if(target_iter >= weight)
                    dp[target_iter] = max(dp[target_iter],dp[target_iter - weight] + cost);
            }
        }
        cout<<dp[k]<<endl;
    }
    return 0;
}
