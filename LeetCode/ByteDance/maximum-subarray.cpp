#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        enum {
            UNDEFINE = 0,
            LEFT,
            CONNECT,
            RIGHT,
        } state = UNDEFINE;
        int L = 0, connect = 0, R = 0, ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            //printf("CUR: %d\n", nums[i]);
            if (nums[i] >= 0) {
                switch (state) {
                case UNDEFINE:
                    state = LEFT;
                case LEFT:
                    L += nums[i];
                    if (L > ans)
                        ans = L;
                    break;
                case CONNECT:
                    state = RIGHT;
                    R = 0;
                case RIGHT:
                    R += nums[i];
                    if (R > ans)
                        ans = R;
                    break;
                }
                //printf("big state: %d L: %d ans: %d\n\n", state, L, ans);
            } else {
                switch (state) {
                case LEFT:
                case UNDEFINE:
                    state = CONNECT;
                    connect += nums[i];
                    if (connect > ans)
                        ans = connect;
                    break;
                case CONNECT:
                    connect += nums[i];
                    // 连续的负值
                    if (nums[i] > ans)
                        ans = nums[i];
                    break;
                case RIGHT:
                    int ts = L+connect+R; // temp sum
                    //printf("SMALL RIGHT START L: %d connect: %d: R: %d ts: %d\n", L, connect, R, ts);
                    if (ts > L && ts > R) {
                        //printf("ts is big: %d:%d\n", ts, ans);
                        L = ts;
                        if (ts > ans) {
                            ans = ts;
                        }
                    } else if (R > ts && R > L) {
                        //printf("R is big: %d:%d\n", R, ans);
                        L = R;
                        if (R > ans) {
                            ans = R;
                        }
                    } else if (L > ts && L > R) {
                        //printf("L is big: %d:%d\n", L, ans);
                        if (L > ans) {
                            ans = L;
                        }
                        L = R > ts ? R : ts;
                    }
                    state = CONNECT;
                    connect = nums[i];
                    //printf("SMALL RIGHT AFTER L: %d connect: %d: R: %d ans: %d\n", L, connect, R, ans);
                    break;
                }
                //printf("small state: %d cur: %d ans: %d\n\n", state, nums[i], ans);
            }
        }
        if (state == RIGHT)
            return ans>L+R+connect?ans:L+R+connect;
        else
            return ans;
    }
};

// [0]
// [-2,1,-3,4,-1,2,1,-5,4]
// [-1,-2,-3]
// [1,-10,100,1000]
// [100,-10,1,1000]
// [-1,-2,-3,1000]
// [1,2,3]
// [-2147483647]
// [-2,-1]
// [8,-19,5,-4,20]
// [-1,2,2,-3]
// [-9,-2,1,8,7,-6,4,9,-9,-5,0,5,-2,5,9,7]
int main()
{
    vector<int> v{-9,-2,1,8,7,-6,4,9,-9,-5,0,5,-2,5,9,7};
    class Solution s;
    cout << s.maxSubArray(v) << endl;

    return 0;
}