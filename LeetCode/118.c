int** generate(int numRows, int** columnSizes) {
    int i, j;
    int **ans;
    
    ans = malloc(sizeof(int *) * numRows);
    *columnSizes = malloc(sizeof(int)*numRows);
    for (i = 0; i < numRows; i++) {
        (*columnSizes)[i] = i+1;
        ans[i] = malloc(sizeof(int)*(i+1));
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                ans[i][j] = 1;
            else
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}
