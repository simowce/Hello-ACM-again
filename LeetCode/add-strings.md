```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int promote = 0;
        string ans;

        int l1 = num1.size()-1, l2 = num2.size()-1;
        while (l1 >= 0 || l2 >= 0 || promote) {
            int n1 = l1 >= 0 ? num1[l1]-'0' : 0;
            int n2 = l2 >= 0 ? num2[l2]-'0' : 0;

            ans += (n1+n2+promote)%10+'0';
            promote = (n1+n2+promote)/10;

            l1--;
            l2--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

很简单的题目，有一个坑，就是遍历两个加数的时候，拿到的 0 不是 0，而是 '0'，因此需要 '0'-'0' 才能拿到真正的值。

同时，得到的值是反过来的，因此需要将其 reverse 一下，algorithm 库有一个函数：

```
reverse(s.begin(), s.end());
```

可以达到这个效果，记住 reverse 本身不返回值。