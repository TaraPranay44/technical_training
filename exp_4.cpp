#include <iostream>
#include <bits/stdc++.h>


using namespace std;


string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    vector<pair<int,int>> sorted;
    for(int i = 0;i<indices.size();i++){
        sorted.push_back({indices[i],i});
    }
    sort(sorted.rbegin(),sorted.rend());
    // reverse(sorted.begin(),sorted.end());
    for(auto ind : sorted){
        int i = ind.first;
        string temp = sources[ind.second] , tar = targets[ind.second];
        if(s.substr(i,temp.size()) == temp){
            s = s.substr(0,i) + tar + s.substr(i+temp.size());
        }
    }
    return s;
}


int main()
{
    string s = "Sara Praani"; 
    vector<int>indices = {0,8,10};
    vector<string> sources = {"S","a","i"};
    vector<string> targets = {"T","","ay"};
    
    cout<<"what is his name"<<endl;
    cout<<"his name is : "<<s<<endl;
    cout<<"you are pronouncing it wrong, ";
    string ans = findReplaceString(s,indices,sources,targets);
    
    cout<<"His name is: "<<ans;
    

    return 0;
}
