class Solution {
public:
    string multiply(string num1, string num2) {
        int ans = 0, carry = 0, index = 0;
        
        for (int i=0; i<num1.size(); i++) {
            int tmp = 0;
            for (int j=0; j<num2.size(); j++) {
                tmp += (num1[i]-'0')*(num2[j]-'0')+carry;
            }
        }
    }
};