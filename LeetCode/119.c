/*
119. Pascal's Triangle II My Submissions QuestionEditorial Solution
Total Accepted: 71862 Total Submissions: 224193 Difficulty: Easy
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 思路：
// 首先，排列的话，左右的对称值是相等的，所以可以避免重复计算
// 然后，为了避免连续相乘爆 long long，采用乘一个除一个的做法
// 注意，乘的个数和除的个数是相等，同时为了避免“整除”说带来的不精确，采用先乘后除的做法
// 之所以敢这么做是基于一个理解：
// 在连续的 n 个数中，总是存在一个数能够将 n 整除
int c_a_of_b(int a, int b)
{
	// 巨坑无比，long long 就 AC ，int 就报错
    long long int sum = 1;
    int i, j;
    int t = a-b+1;
    
    if (b == 0 || b == a)
        return 1;
    if (b == 1 || b == a-1)
        return a;
    for (i = 0; i < b; i++) {
        sum *= (a-i);
        sum /= (i+1);
        
    }
    
    return sum;
}

int* getRow(int rowIndex, int* returnSize) {
    int *ans = malloc(sizeof(int)*(rowIndex+1));
    int i;
    int times;
    
    *returnSize = rowIndex+1;
    times = rowIndex/2 + rowIndex%2;
    for (i = 0; i <= times; i++)
        ans[i] = ans[rowIndex-i] = c_a_of_b(rowIndex, i);
    
    return ans;
}
