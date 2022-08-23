#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Item {
    Item(string value, int timestamp) : mVal(value), mTs(timestamp) {
        // Do nothing
    }
    
    string  mVal;    // value
    int     mTs;     // timestamp
};

class TimeMap {
private:
    unordered_map<string,vector<Item>> mHm;  // Hash map

public:
    TimeMap() {
        // Do nothing
    }
    
    void set(string key, string value, int timestamp) {
        // Key exists?
        if (mHm.count(key)) {
            mHm[key].push_back(Item(value, timestamp));
        } else {
            vector<Item> tmp;
            tmp.push_back(Item(value, timestamp));
            
            mHm[key] = tmp;
        }
    }
    
    string get(string key, int timestamp) {
        // Key exists?
        if (mHm.count(key)) {
            vector<Item> &items = mHm[key];

            // Earlier record exists?
            if (items.front().mTs > timestamp) {
                return "";
            } else {
                // Binary search timestamp
                int l = 0;
                int r = items.size() - 1;
                int m = 0;

                while (l <= r) {
                    m = (l + r) / 2;

                    if (items[m].mTs == timestamp) {
                        return items[m].mVal;
                    } else if (items[m].mTs > timestamp) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }

                if (items[m].mTs > timestamp) {
                    return items[m - 1].mVal;
                } else {
                    return items[m].mVal;
                }
            }
        } else {
            return "";
        }
    }
};
