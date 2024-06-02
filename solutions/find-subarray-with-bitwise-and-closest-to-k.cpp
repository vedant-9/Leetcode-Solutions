template <typename T>
class SegmentTree {
   private:
    int n;
    vector<T> arr;
    vector<T> segment_tree;
    vector<T> lazy;
    T merge(T a, T b) {
        return a & b;
    }
    void build_segment_tree(int node, int start, int end) {
        if (start == end) {
            segment_tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build_segment_tree(2 * node + 1, start, mid);
        build_segment_tree(2 * node + 2, mid + 1, end);
        segment_tree[node] = merge(segment_tree[2 * node + 1], segment_tree[2 * node + 2]);
    }

    void update_point(int node, int start, int end, int index, T value) {
        if (start == end) {
            arr[index] = value;
            segment_tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid) {
            update_point(2 * node + 1, start, mid, index, value);
        } else {
            update_point(2 * node + 2, mid + 1, end, index, value);
        }
        segment_tree[node] = merge(segment_tree[2 * node + 1], segment_tree[2 * node + 2]);
    }
    void update_range(int node, int start, int end, int left, int right, T value) {
        if (lazy[node] != 0) {
            segment_tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > right || end < left) {
            return;
        }
        if (left <= start && end <= right) {
            segment_tree[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
        int mid = (start + end) / 2;
        update_range(2 * node + 1, start, mid, left, right, value);
        update_range(2 * node + 2, mid + 1, end, left, right, value);
        segment_tree[node] = segment_tree[2 * node + 1] + segment_tree[2 * node + 2];
    }
    T query_segment_tree(int node, int start, int end, int left, int right) {
        if (lazy[node] != 0) {
            segment_tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > right || end < left) {
            return (1LL << 32) - 1;  // For range sum, change this to 0 for other queries
        }
        if (left <= start && end <= right) {
            return segment_tree[node];
        }
        int mid = (start + end) / 2;
        T left_sum = query_segment_tree(2 * node + 1, start, mid, left, right);
        T right_sum = query_segment_tree(2 * node + 2, mid + 1, end, left, right);
        return merge(left_sum, right_sum);
    }

   public:
    SegmentTree(const vector<T>& input_arr) {
        arr = input_arr;
        n = arr.size();
        segment_tree.resize(4 * n, 0);  // Adjust size based on the maximum number of elements
        lazy.resize(4 * n, 0);
        build_segment_tree(0, 0, n - 1);
    }
    void update_point(int index, T value) {
        update_point(0, 0, n - 1, index, value);
    }
    void update_range(int left, int right, T value) {
        update_range(0, 0, n - 1, left, right, value);
    }
    T query(int left, int right) {
        return query_segment_tree(0, 0, n - 1, left, right);
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree<int> st(nums);

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            int l = i;
            int r = n - 1;

            while(r - l > 1) {
                int mid = (l + r) / 2;
                if(st.query(i, mid) >= k) 
                    l = mid;
                else
                    r = mid;
            }

            ans = min(ans, abs(k - st.query(i, l)));
            ans = min(ans, abs(k - st.query(i, r)));
        }
        
        return ans;
    }
};
