bool canFill(int mat[9][9], int r, int c, int val) {
    for(int i=0; i<9; i++) {
        if(mat[i][c]==val)
            return false;
        if(mat[r][i]==val)
            return false;
        int cr = (r/3)*3+i/3;
        int cc = (c/3)*3+i%3;
        if(mat[cr][cc]==val)
            return false;
    }
    return true;
}

bool getAns(int mat[9][9], int i, int j) {
    if(i>=9) {
        return true;
    }
    int nj = (j+1)%9;
    int ni = (nj==0)?i+1:i;
    if(mat[i][j] != 0) {
        if(getAns(mat, ni, nj)) {
            return true;
        }
    }
    else
    for(int v=1; v<=9; v++) {
        if(canFill(mat, i, j, v)) {
            mat[i][j] = v;
            if(getAns(mat, ni, nj)) {
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    return getAns(matrix, 0, 0);
}
