int maxSum(int* nums, int numsSize, int k) {
    const long long MOD = 1000000007LL;
    long long ans = 0;
    int bits[30] = {0};

    for (int i = 0; i < numsSize; i++) {
        for (int b = 0; b < 30; b++) {
            if ((nums[i] >> b) & 1)
                bits[b]++;
        }
    }

    for (int i = 0; i < k; i++) {        //aiter pore string bosbe er ter por nums bosbe
        long long x = 0;

        for (int b = 29; b >= 0; b--) {
            if (bits[b] > 0) {
                x |= (1LL << b);       bits[b]--;
            }
        }

        ans = (ans + x * x) % MOD;
    }

    return (int)ans;
}