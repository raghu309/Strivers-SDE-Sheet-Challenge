int M;

bool canColor(vector<vector<int>> &mat, int cur, vector<int> &color, int c) {
    for(int node=0; node<mat.size(); node++) {
        if(mat[cur][node] && color[node] == c) {
            return false;
        }
    }
    return true;
}

bool getAns(vector<vector<int>> &mat, int cur, vector<int> &color) {
    if(cur >= mat.size())
        return true;
    
    for(int i=1; i<=M; i++) {
        if(canColor(mat, cur, color, i)) {
            color[cur] = i;
            if(getAns(mat, cur+1, color)) {
                return true;
            }
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> color(n, 0);
    M = m;
    return getAns(mat, 0, color)?"YES":"NO";
}











