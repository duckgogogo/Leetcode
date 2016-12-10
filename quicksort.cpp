//
//  main.cpp
//  quicksort
//
//  Created by Shan He on 12/8/16.
//  Copyright © 2016 Shan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
int divide(vector<int> &a,int low,int high)
{
    int k = a[low];
    do{
        //从右向左检查，如果high的值大于k，则位置中的值正确，high--，继续往前检查，直到遇到一个小于k的值
        while(low < high && a[high] >= k) --high;
        //将小于k的值放入low的位置，此时high的位置就空出来了
        if(low < high)
        {
            a[low] = a[high];
            ++low;
        }
        //从low的位置开始从左向右检查，直到遇到一个大于k的值
        while(low < high && a[low] <= k) ++low;
        //将low位置的值放入high位置，重复第一步，直到low和high重叠，将k放入此位置；
        if(low < high)
        {
            a[high] = a[low];
            --high;
        }
    }while(low != high);
    a[low] = k;
    return low;
}  */
int divide(vector<int> &a,int low,int high)
{
    int k = a[low];
    while(low < high){
        //从右向左检查，如果high的值大于k，则位置中的值正确，high--，继续往前检查，直到遇到一个小于k的值
        while(low < high && a[high] >= k) --high;
        //将小于k的值放入low的位置，此时high的位置就空出来了
        if(low < high)
        {
            a[low] = a[high];
            ++low;
        }
        //从low的位置开始从左向右检查，直到遇到一个大于k的值
        while(low < high && a[low] <= k) ++low;
        //将low位置的值放入high位置，重复第一步，直到low和high重叠，将k放入此位置；
        if(low < high)
        {
            a[high] = a[low];
            --high;
        }
    }
    a[low] = k;
    return low;
}

void quickSort(vector<int> &a, int low, int high)
{
    int mid;
    if(low >= high) return;
    mid = divide(a,low,high);
    quickSort(a, low, mid - 1);
    quickSort(a, mid + 1, high);
}

void quickSort(vector<int> &a)
{
    int n = a.size();
    if(n == 0) return;
    quickSort(a,0,n-1);
}

int main() {
    vector<int> v = {23, 65, 12, 3, 8, 76, 345, 90, 21, 75, 34, 61};
    quickSort(v);
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
