bool canPlace(vector<vector<int>> &board, int i, int j) {
    for(int c=0; c<board.size(); c++) {
        if(c==j)
            continue;
        if(board[i][c])
            return false;
    }
    for(int r=0; r<board.size(); r++) {
        if(r==i)
            continue;
        if(board[r][j])
            return false;
    }
    int r=i-1, c=j-1;
    while(r>=0 && c>=0) {
        if(board[r][c])
            return false;
        r--;
        c--;
    }
    r=i+1, c=j-1;
    while(r<board.size() && c>=0) {
        if(board[r][c])
            return false;
        r++;
        c--;
    }
    r=i+1, c=j+1;
    while(r<board.size() && c<board.size()) {
        if(board[r][c])
            return false;
        r++;
        c++;
    }
    r=i-1, c=j+1;
    while(r>=0 && c<board.size()) {
        if(board[r][c])
            return false;
        r--;
        c++;
    }
    return true;
}

void getAns(vector<vector<int>> &board, int idx, vector<vector<int>> &ans) {
    if(idx == board.size()) {
        vector<int> t;
        for(auto el:board) {
            for(auto e:el)
                t.push_back(e);
        }
        ans.push_back(t);
        return;
    }

    for(int i=0; i<board.size(); i++) {
        if(canPlace(board, idx, i)) {
            board[idx][i] = 1;
            getAns(board, idx+1, ans);
            board[idx][i] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    getAns(board, 0, ans);
    return ans;
}