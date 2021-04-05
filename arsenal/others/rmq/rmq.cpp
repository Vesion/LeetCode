

// http://www.geeksforgeeks.org/range-minimum-query-for-static-array/

// Problem:
//      RMQ(Range-Minimum-Query) problem given an array nums,
//      and a query is a range [l, r], we have to answer the minimum value of from nums[l] to nums[r].
//      The array is of size N, and there are Q queries.
//
// Solutions:
//      1. Brute-force: O(N) time, O(1) space
//      2. Segment Tree:
//              Preprocessing: O(N) time, O(N) space
//              Query: O(logN) time
//      3. Square Root Decomposition:
//              Preprocessing: O(sqrt(N)*sqrt(N)) = O(N) time, O(sqrt(N)) space
//              Query: O(sqrt(N))
//      4. Sparse Table (ST):
//              Preprocessing: O(NlogN) time, O(NlogN) space
//              Query: O(1)
//      5. Monotonical stack (offline query):
//              Preprocessing, O(N) time, O(N) space
///             All Queries: O(QlogQ + QlogN), Q is amount of queries
