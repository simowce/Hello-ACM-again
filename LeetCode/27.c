/*27. Remove Element My Submissions QuestionEditorial Solution*/
/*Total Accepted: 111019 Total Submissions: 331354 Difficulty: Easy*/
/*Given an array and a value, remove all instances of that value in place and return the new length.*/

/*Do not allocate extra space for another array, you must do this in place with constant memory.*/

/*The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/

/*Example:*/
/*Given input array nums = [3,2,2,3], val = 3*/

/*Your function should return length = 2, with the first two elements of nums being 2.*/

// 思路：
// 使用两个指针，i, j ，i 的目标是找到左侧等于 val 的位置，j 的目标是找到有点不等于 val 的位置，
// 如果在右侧遇到等于 val ，那么直接跳掉
// 返回值是数组中不是 val 的个数，暂时的解决方法是将数组遍历一遍，计算 val 的个数，然后用总数减去
// 如何精确计算 val 的个数
int removeElement(int *nums, int numsSize, int val)
{
    int i = 0;
    int j = numsSize - 1;
    int num_val = 0;
    
    if (numsSize == 0)
        return NULL;
    while (i < numsSize)
        if (nums[i++] == val)
            num_val++;
    i = 0;
    while (i != j) {
        while (nums[i] != val && i != j)
            i++;
        while (nums[j] == val && i != j)
            j--;
        nums[i] = nums[j];
        if (i != j) {

            j--;
        }
    }
    return numsSize-num_val;
}
