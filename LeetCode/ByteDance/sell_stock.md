一开始上来就直接一个二重循环，直接超时。实在想不出，瞄了一眼题解，立马有了思路，很明显的贪心算法，但是目前对于贪心算法的正确性我真的无法确认，看了一些博客说可以使用数学归纳法和反证法来证明：

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size())
            return 0;
        int cur_min = prices[0];
        int cur_max = 0;
        int ans = 0;

        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < cur_min) {
                cur_min = prices[i];
                cur_max = 0;
            } else {
                if (prices[i] - cur_min > ans) {
                    cur_max = ans = prices[i] - cur_min;
                }
            }
        }
        return ans;
    }
};
```