首先想到的想法是递归：

```cpp
class Solution {
public:
    bool ans(int n, int c) {
        bool can = false;
        for (int i=1; i<n; i++) {
            if (!(n%i)) {
                can = true;
                if (ans(n-i, c+1))
                    return true;
            }
        }
        if (!can)
            return c%2 ? true : false;
        else
            return false;
    }
    bool divisorGame(int N) {
        return ans(N, 0);
    }
};
```

然后发现输入 5 的时候，我返回的是 true，但是答案是 false。

然后重新看了一下题目，里面有一句话：

> 假设两个玩家都以最佳状态参与游戏

这句话其实就直接说明了，使用递归的方式是无法解决这个问题的，因此题目要求双方每次决策都是最优解，而不是是否存在一种方法能够让爱丽丝赢。

最优解就会想到动态规划，但是这道题我想了很久都没有想到一个“无后效性”的结果，还有 dp[] 数组的意义，然后瞄了一眼题解，马上就有了思路（惭愧）：

本题有一个“无后效性”，就是有一个必输场景和必赢场景：

* 当轮到一个人的时候，如果当前 N 是 2，那么其必赢；
* 当录到一个人的时候，如果当前 N 是 1，那么其必输；

因此 dp[] 数组的意义和最优子结构就出来了：

* dp[i] 的值为 true/false，意义是：此轮数字为 i 时，那么游戏的结果是必赢（true）或者是必输（false）
* i 的所有因数 j 中，如果存在 j 必输（dp[j] = false），则 i 必赢（dp[i] = true）；否则，i 必输（dp[i] = false）**这也体现了题目中的那句话：假设两个玩家都以最佳状态参与游戏**

最终 AC 的代码如下：

```cpp
class Solution {
public:
    bool divisorGame(int N) {
        bool dp[1001] = {false};
        bool win;
        dp[2] = true;

        for (int i=3; i<=N; i++) {
            win = false;
            for (int j=1; j<i; j++) {
                if (!(i%j) && !dp[i-j]) {
                    win = true;
                    break;
                }
                dp[i] = win;
            }
        }

        return dp[N];
    }
};
```