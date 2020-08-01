```cpp
    // 1. L+connect+R
    // 2. L+connect
    // 3. L
    // 4. connect
    // 5. connect+R
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
                    int tm = std::max(R, ts);
                    L = tm;
                    if (tm > ans)
                        ans = tm;
                    state = CONNECT;
                    connect = nums[i];
                    break;
                }
            }
        }
        if (state == RIGHT)
            return ans>L+R+connect?ans:L+R+connect;
        else
            return ans;
    }
};
```

这道题花了我整整一天的时间才解了，首先，这道题目如果要在 O(n) 的时间解决的话，需要使用贪心。

然后我的思路是将题目抽象为 **L+connect+R**，其中 L 和 R 这两部分都为正数，connect 为负数

然后 L+connect+R 总共有如下的情况：

1. L+connect+R
2. L
3. L+connect
4. connect
5. connect+R

我的写法就是遍历整个数组，对于每一个数字，我定义了如下几个状态

* UNDEFINE（初始状态）
* LEFT
* CONNECT
* RIGHT

然后利用这些状态去匹配上面提到的 5 种状态

UNDEFINE/LEFT -- 正数 --> LEFT
UNDEFINE/CONNECT -- 负数 --> CONNECT // 连续的负数需要更新 ans 为**最大的那一个负数**
LEFT -- 负数 --> CONNECT
CONNECT -- 正数 --> RIGHT
RIGHT -- 正数 --> RIGHT
RIGHT -- 负数 --> 最重要的状态转移，核心的策略为：

let L+connect+R => ans
1. 如果 ans 或者 R 是 L/R/ans 中最大的，更新 max 和 L 为 L+connect+R
2. 如果 L 是 L/R/ans 中最大的，那么 L = R>ans?R:ans，因为只有**选择 R 或者 ans(L+connect+R) 才能跟后面的数连起来**