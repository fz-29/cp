#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lli;
int findmax(int a[],int n)
{
    lli max = -9999999999;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    return max;
}
int allneg(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            return 0;
        }
    }
    return 1;
}
int allpos(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            return 0;
        }
    }
    return 1;
}
lli contiguousMaxSubarraySum(int a[],int n)
{
    lli maxSum=0,currentSum=0;
    int i,start, currentStart,end;
    for(i=0;i<n;i++)
    {
        currentSum += a[i];
        if(currentSum < 0) //greatfall-->array must end till the last increment place
        {
            currentSum = 0;
            currentStart = i + 1;

        }
        if(currentSum > maxSum) //increment
        {
            maxSum = currentSum;//update sum
            end = i;//keep shifting the end
            start = currentStart;
        }
    }
    return maxSum;
}
lli MaxSubarraySum(int a[],int n)
{
    lli sum=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
            sum += a[i];
    }
    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    int a[100005],t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];

        if(allneg(a,n))
        {
            lli maxElemInArray = findmax(a,n);
            cout<<findmax(a,n)<<" "<<findmax(a,n)<<endl;
        }
        else
        {
            cout<<contiguousMaxSubarraySum(a,n)<<" "<<MaxSubarraySum(a,n)<<endl;;
        }
    }
    return 0;
}
