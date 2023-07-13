int romanToInt(string s) {
    unordered_map<char, int> mpp;
    mpp['I'] = 1;
    mpp['V'] = 5;
    mpp['X'] = 10;
    mpp['L'] = 50;
    mpp['C'] = 100;
    mpp['D'] = 500;
    mpp['M'] = 1000;
    int maxi = 1;
    int curVal = 0;
    for(int i=s.size()-1; i>=0; i--) {
        int val = mpp[s[i]];
        if(maxi <= val) {
            maxi = val;
            curVal += val;
        }else {
            curVal -= val;
        }
    }
    return curVal;
}