class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int> sa = buildSuffixArray(nums);

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[sa[i]] = i;
        }

        vector<int> lcp(n - 1, 0);

        int common = 0;

        for (int i = 0; i < n; i++) {

            int r = rank[i];

            if (r == n - 1) {
                common = 0;
                continue;
            }

            int j = sa[r + 1];

            while (i + common < n &&
                   j + common < n &&
                   nums[i + common] == nums[j + common]) {

                common++;
            }

            lcp[r] = common;

            if (common > 0) {
                common--;
            }
        }

        int ans = n;

        for (int r = 0; r < n; r++) {

            int maxLCP = 0;

            if (r > 0) {
                maxLCP = max(maxLCP, lcp[r - 1]);
            }

            if (r < n - 1) {
                maxLCP = max(maxLCP, lcp[r]);
            }

            int required = maxLCP + 1;

            if (required <= n - sa[r]) {
                ans = min(ans, required);
            }
        }

        return ans;
    }

private:
    vector<int> buildSuffixArray(vector<int>& nums) {

        int n = nums.size();
        int m = n + 1;

        vector<int> values(m);

        int maxVal = 0;

        for (int i = 0; i < n; i++) {
            values[i] = nums[i];
            maxVal = max(maxVal, nums[i]);
        }

        values[n] = 0;

        vector<int> p(m), c(m);

        int alphabet = max(maxVal + 1, m);

        vector<int> cnt(alphabet, 0);

        for (int x : values) {
            cnt[x]++;
        }

        for (int i = 1; i < alphabet; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            p[--cnt[values[i]]] = i;
        }

        c[p[0]] = 0;

        int classes = 1;

        for (int i = 1; i < m; i++) {

            if (values[p[i]] != values[p[i - 1]]) {
                classes++;
            }

            c[p[i]] = classes - 1;
        }

        vector<int> pn(m), newC(m);

        for (int len = 1; len < m; len <<= 1) {

            for (int i = 0; i < m; i++) {

                pn[i] = p[i] - len;

                if (pn[i] < 0) {
                    pn[i] += m;
                }
            }

            cnt.assign(classes, 0);

            for (int i = 0; i < m; i++) {
                cnt[c[pn[i]]]++;
            }

            for (int i = 1; i < classes; i++) {
                cnt[i] += cnt[i - 1];
            }

            for (int i = m - 1; i >= 0; i--) {
                int x = pn[i];
                p[--cnt[c[x]]] = x;
            }

            newC[p[0]] = 0;

            int newClasses = 1;

            for (int i = 1; i < m; i++) {

                int cur = p[i];
                int prev = p[i - 1];

                int mid = (cur + len) % m;
                int prevMid = (prev + len) % m;

                if (c[cur] != c[prev] ||
                    c[mid] != c[prevMid]) {

                    newClasses++;
                }

                newC[cur] = newClasses - 1;
            }

            swap(c, newC);

            classes = newClasses;
        }

        vector<int> sa(n);

        copy(p.begin() + 1, p.end(), sa.begin());

        return sa;
    }
};