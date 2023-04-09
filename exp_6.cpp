#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool binarySearch(vector<pair<string,int>>array,int key){
    int lo = 0;
    int hi = array.size() - 1;
    
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(array[mid].second == key){
            return true;
        }else if(array[mid].second>key){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    
    return false;
}

void printArray(vector<pair<string,int>>array){
    for(int i = 0;i<array.size();i++){
        cout<<array[i].first<<" "<<array[i].second<<endl;
    }
} 


int main()
{
    vector<pair<string,int>> list1 = {
                                      {"durga",4388},
                                      {"Tara",4397},
                                      {"apeksha",4390} };
    vector<pair<string,int>> list2 = {
                                      {"CSE",4388},
                                      {"ECE",4397},
                                      {"MECH",4390} };
    vector<pair<string,int>> list3 = {
                                      {"8.6",4382},
                                      {"9.9",4397},
                                      {"7.4",4399} };
   
   
    
    int s1 = list1.size();
    int s2 = list2.size();
    int s3 = list3.size();
    
    // sort(list1.begin(),list1.end());
    // sort(list2.begin(),list2.end());
    // sort(list3.begin(),list3.end());
    
    vector<pair<string,int>>ans;
           
    
    int s= min({s1,s2,s3});

            if(s1==s){

                for(int i=0 ; i<s ; i++){

                    if(binarySearch(list2,list1[i].second) && binarySearch(list3,list1[i].second)){

                        ans.push_back(make_pair(list1[i].first,list1[i].second));

                    }

                }

            }else if(s2==s){

                for(int i=0 ; i<s ; i++){

                    if(binarySearch(list1,list2[i].second) && binarySearch(list3,list2[i].second)){

                        ans.push_back(make_pair(list2[i].first,list2[i].second));

                    }

                }

            }else{

                for(int i=0 ; i<s ; i++){

                    if(binarySearch(list2,list3[i].second) && binarySearch(list1,list3[i].second)){

                        ans.push_back(make_pair(list3[i].first,list3[i].second));

                    }

                }

            } 
            
            cout<<"The Name and roll numbers in list1 are :"<<endl;
            cout<<"NAME"<<" "<<"UID"<<endl;
            printArray(list1);
            cout<<endl;
            cout<<"The Branch and roll numbers in list2 are :"<<endl;
            cout<<"BRANCH"<<" "<<"UID"<<endl;
            printArray(list2);
            cout<<endl;
            cout<<"The CGPA  and roll numbers in list3 are :"<<endl;
            cout<<"CGPA"<<" "<<"UID"<<endl;
            printArray(list3);
            cout<<endl<<endl;
            
            
            cout<<"the common roll numbers in all the given three lists are : ";
            printArray(ans);
            
       
      

    return 0;
}

            
