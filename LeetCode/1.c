#include <stdlib.h>
#include <stdio.h>

/* int binary(int *num, int len, int target) { */
    /* int l = 0, r = len-1; */
    /* int mid = l + (r-l)/2; */

    /* while (l < r) { */
        /* if (num[mid] == target) */
            /* return target; */
        /* else if (num[mid] < target) */
            /* l = mid+1; */
        /* else */
            /* r = mid-1; */
    /* } */

    /* return -1; */
/* } */

/* static int cmp(const void *a, const void *b) { */
    /* return (*(int *)a)-(*(int *)b); */
/* } */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *) malloc(sizeof(int) * 2);

    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i]+nums[j] == target) {
                ans[0] = i;
                ans[j] = j;
                printf("%d %d\n", i, j);
                return ans;
            }
        }
    }

    /* qsort(nums, numsSize, sizeof(int), cmp); */
    /* for (int i=0; i<numsSize-1; i++) { */
        /* int ret = binary(nums+i+1, numsSize-i, target-nums[i]); */
        /* if (ret != -1) { */
            /* ans[0] = i; */
            /* ans[1] = ret+i; */
            /* printf("%d %d\n", i, ret); */
            /* return ans; */
        /* } */
    /* } */
    return NULL;
}

int main(void)
{
    int a[] = {7,2,15,11};
    int t = 9;
    twoSum(a, 4, t, NULL);
}
