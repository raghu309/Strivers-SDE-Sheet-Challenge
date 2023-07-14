#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    vector<int> hsh(26, 0);
    for(auto el:str1)
        hsh[el-'a']++;
    for(auto el:str2)
        hsh[el-'a']--;

    for(auto el:hsh) {
        if(el != 0)
            return false;
    }
    return true;
}