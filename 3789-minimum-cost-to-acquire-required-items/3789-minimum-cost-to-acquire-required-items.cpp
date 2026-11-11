#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        long long only_individual = (n1 * c1) + (n2 * c2);
        long long only_bundles = max(n1, n2) * cb;

        long long overlap = min(n1, n2);
        long long hybrid = (overlap * cb) + ((n1 - overlap) * c1) + ((n2 - overlap) * c2);

        return min({only_individual, only_bundles, hybrid});
    }
};
