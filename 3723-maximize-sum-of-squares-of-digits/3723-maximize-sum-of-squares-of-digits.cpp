class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        if (num * 9LL < sum) {
            return "";
        }

        int nines = sum / 9;
        int remainder = sum % 9;

        std::string ans = "";
        ans.append(nines, '9');

        if (remainder > 0) {
            ans.push_back('0' + remainder);
        }

        int zeros = num - ans.length();
        if (zeros > 0) {
            ans.append(zeros, '0');
        }

        return ans;
    }
};
