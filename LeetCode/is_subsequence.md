非常简单的一道题目，但是还是错了两次才过了，错的原因就是当在 字符串 t 中找到字符串 s 中的当前字符时候，t 的 index 没有自增：

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j = 0;
        int find = 0;

        for (i = 0; i < s.size(); i++) {
            for (; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    find++;
                    // 一开始这里忘记了
                    j++;
                    break;
                }
            }
        }
        if (s.size() == 0 || (find == s.size()))
            return true;
        else
            return false;
    }
};
```