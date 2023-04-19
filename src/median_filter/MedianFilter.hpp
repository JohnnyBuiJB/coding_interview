#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Item {
    int val_;
    int index_;
    
    Item(int val, int index) : val_(val), index_(index) {}
};

class SortBuffer {
    vector<int> buffer;
public:
    SortBuffer(int size) {
        buffer.resize(size);
    }
    
    void add(int val) {
        buffer.push_back(val);
        sort(buffer.begin(), buffer.end());
    }
};

class MedianFilter {
private:
    double median_ = 0.0;
    int len_ = 0;
    int cur_index_ = 0;
    vector<Item> sort_;
    int filter_len_ = 0;

public:
    MedianFilter(int filter_len) : len_(filter_len) {}
    
    // 5
    double median_filter(int val) {
        // Trivial
        // if (sort_.empty()) {
        //     return NAN;
        // }
        
        // precondition: 
        // Remove earliest data
        int earliest_index = INT_MAX;
        auto earliest_it = sort_.begin();
        for (auto& item : sort_) {
            if (item.index_ < earliest_index) {
                earliest_index = item.index_;
                earliest_it = &item;
            }
        }
        sort_.erase(earliest_it);
        
        // Search for position to insert: find the smallest data that is larger than val
        int l = 0;
        int r = sort_.size();
        int pos = 0;
        int m = 0;
        
        while (l <= r) {
            m = (l + r) / 2;
            
            if (sort_[m].val_ == val) {
                break;
            } else if (sort_[m].val_ < val) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        if (sort_[m].val_ == val) {
            pos = m;
        } else if (sort_[m].val_ < val) {
            pos = m + 1;
        } else {
            pos = m - 1;
        }
        
        // Add new value
        ++cur_index_;
        sort_.insert(pos, Item(val, cur_index_));
        int n = sort_.size();
        
        if (n % 2) {
            median_ = (double) sort_[n / 2].val_;
        } else {
            median_ = (double) (sort_[n / 2].val_ + sort_[n / 2 - 1].val_) / 2;
        }
        
        return median_;
    }
}
