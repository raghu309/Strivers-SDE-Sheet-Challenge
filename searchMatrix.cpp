int findRow(vector<vector<int>> &mat, int target) {
    int lo = 0, hi = mat.size()-1;

    while(hi-lo>1) {
        int mid = (lo+hi)/2;
        if(mat[mid][0]<=target) {
            lo = mid;
        }else {
            hi = mid;
        }
    }
    if(mat[hi][0]<=target) {
        return hi;
    }else if(mat[lo][0]<=target) {
        return lo;
    }
    return mat.size();
}

int findCol(vector<int> &v, int target) {
    int lo = 0, hi = v.size()-1;

    while(hi - lo > 1) {
        int mid = (lo+hi)/2;
        
        if(v[mid] < target) {
            lo = mid+1;
        }else {
            hi = mid;
        }
    }
    if(v[lo]==target) {
        return lo;
    }else if(v[hi]==target) {
        return hi;
    }
    return v.size();
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row = findRow(mat, target);
    if(row == mat.size())
        return false;
    
    int col = findCol(mat[row], target);
    if(col >= mat[0].size())
        return false;
    return mat[row][col]==target;
}