class Solution {
public:
    bool isHappy(int n) {
         while (n != 1 && n != 4) {
            int ans = 0;

            while (n > 0) {
                int mod = n % 10;
                ans += mod * mod;
                n /= 10;
            }

            n = ans;
        }

        return n == 1;
    }
};