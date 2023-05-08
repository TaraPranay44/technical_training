#include <iostream>
#include <bits/stdc++.h>


using namespace std;

void reverseArrays(vector<int>& arr1) {
    
    stack<int> s;

 
    for (int i = 0; i < arr1.size(); i++) {
        s.push(arr1[i]);
    }
    

   
    vector<int> new_arr;
    while (!s.empty()) {
        new_arr.push_back(s.top());
        s.pop();
    }

    for(int i = 0;i<new_arr.size();i++){
        cout<<new_arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    
    vector<int> arr1 = {90, 80, 70};
    vector<int> arr2 = {60, 50, 40};
    reverseArrays(arr1);
    reverseArrays(arr2);
    
    
}
