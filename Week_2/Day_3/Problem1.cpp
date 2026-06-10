class Solution {
public:
    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    long long queryMax(int l, int r) {
        int j = lg[r - l + 1];
        return max(stMax[j][l], stMax[j][r - (1 << j) + 1]);
    }

    long long queryMin(int l, int r) {
        int j = lg[r - l + 1];
        return min(stMin[j][l], stMin[j][r - (1 << j) + 1]);
    }

    long long getValue(int l, int r) {
        return queryMax(l, r) - queryMin(l, r);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;

        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] =
                    max(stMax[j - 1][i],
                        stMax[j - 1][i + (1 << (j - 1))]);

                stMin[j][i] =
                    min(stMin[j - 1][i],
                        stMin[j - 1][i + (1 << (j - 1))]);
            }
        }

        struct Node {
            long long val;
            int l;
            int r;

            bool operator<(const Node& other) const {
                return val < other.val;
            }
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            if (cur.r > cur.l) {
                int nr = cur.r - 1;
                pq.push({getValue(cur.l, nr), cur.l, nr});
            }
        }

        return ans;
    }
};
