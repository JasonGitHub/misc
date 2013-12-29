// use two pointers, O(m + n)
vector<int> FindIntersection(const vector<int> &v1, const vector<int> &v2) {
    vector<int> ret;
    vector<int>::const_iterator iter1 = v1.begin(), iter2 = v2.begin();
    while (iter1 != v1.end() && iter2 != v2.end()) {
        if (*iter1 < *iter2) {
            ++iter1;
        } else if (*iter1 > *iter2) {
            ++iter2;
        } else {
            ret.push_back(*iter1);
            ++iter1;
            ++iter2;
        }
    }
    return ret;
}

// binary search, O(m * lg(n)), better when m << n
vector<int>::const_iterator Find(int val, const vector<int> &v) {
    vector<int>::const_iterator lo = v.begin(), hi = v.end() - 1;
    while (lo <= hi) {
        vector<int>::const_iterator mid = lo + (hi - lo) / 2;
        if (val > *mid) {
            lo = mid + 1;
        } else if (val < *mid) {
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return v.end();
}

vector<int> FindIntersectionBinarySearch(const vector<int> &v1, const vector<int> &v2) {
    vector<int> ret;
    for (vector<int>::const_iterator iter = v1.begin();
         iter != v1.end(); ++iter) {
        if (Find(*iter, v2) != v2.end()) ret.push_back(*iter);
    }
    return ret;
}
