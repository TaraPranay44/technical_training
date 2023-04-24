#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxi(vector<int>&arr){
    int maxim = INT_MIN;
    for(int i = 0;i<arr.size();i++){
        maxim = max(maxim,arr[i]);
    }
    return maxim;
}

void count_Sort(vector<int>&arr){
    int max = maxi(arr);
    vector<int>count(max,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
   
    int i =0; // counter for count array
    int j =0; // counter for given array A

    while(i <= max){
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}

void printArray(vector<int>&arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr = {5,4,5,3,5,4,2,1,5,3,1};
    
    printArray(arr);
    count_Sort(arr);
    printArray(arr);
    

    return 0;
}
