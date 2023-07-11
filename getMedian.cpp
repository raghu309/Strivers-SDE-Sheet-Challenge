int getRes(vector<vector<int>> &matrix, int mid) {
    int gte = 0;
    int lte = 0;
    int eq = 0;
    int med = matrix.size()*matrix[0].size();
    med/=2;

    for(auto &v:matrix) {
        for(auto &el:v) {
            if(el > mid)
                gte++;
            else if(el < mid)
                lte++;
            else
                eq++;
        }
    }
    if(gte+eq>med && lte+eq>med)
        return 0;
    if(gte > lte) {
        return 1;
    }else if(lte > gte) {
        return -1;
    }
}

int getMedian(vector<vector<int>> &matrix)
{
    int hi = 0;
    int lo = 1e9;

    for(auto &v:matrix) {
        for(auto &el:v) {
            hi = max(hi, el);
            lo = min(lo, el);
        }
    }
    while(hi-lo > 1) {
        int mid = (lo+hi)/2;

        if(getRes(matrix, mid)==0) {
            return mid;
        }else if(getRes(matrix, mid)==-1) {
            hi = mid;
        }else if(getRes(matrix, mid)==1) {
            lo = mid;
        }
    }
    if(getRes(matrix, lo)==0) {
        return lo;
    }
    if(getRes(matrix, hi)==0) {
        return hi;
    }
    return 0;
}


