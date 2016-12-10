//
//  main.cpp
//  bubble sort
//
//  Created by Shan He on 12/8/16.
//  Copyright © 2016 Shan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void bubbleSort(vector<int> &a)
{
    bool flag;
    int n = a.size();
    for(int i = 1; i < n;++i) // n - 1 times bubble
    {
        flag = false;
        for(int j = 0;j < n - i;++j)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j],a[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main() {
    vector<int> v = {2,5,8,3,1};
    bubbleSort(v);
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}
