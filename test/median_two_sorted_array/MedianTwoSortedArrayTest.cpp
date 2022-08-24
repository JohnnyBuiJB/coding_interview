#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"


#undef new
#include <new>

using namespace std;

extern double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    
    double exp = 2.0;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    
    double exp = 2.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC003) {
    vector<int> nums1 = {2};
    vector<int> nums2 = {};
    
    double exp = 2;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC004) {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,7};
    
    double exp = 2.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC005) {
    vector<int> nums1 = {};
    vector<int> nums2 = {2,3};
    
    double exp = 2.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC006) {
    vector<int> nums1 = {100001};
    vector<int> nums2 = {100000};
    
    double exp = 100000.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC007) {
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3};
    
    double exp = 2;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC008) {
    vector<int> nums1 = {2};
    vector<int> nums2 = {1,3};
    
    double exp = 2;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC009) {
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3,4};
    
    double exp = 2.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC010) {
    vector<int> nums1 = {2,3,4,5,6};
    vector<int> nums2 = {1};
    
    double exp = 3.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}

TEST(sample, TC011) {
    vector<int> nums1 = {1,2,3,4,7,8};
    vector<int> nums2 = {5,6};
    
    double exp = 4.5;

    auto act = findMedianSortedArrays(nums1, nums2);
    CHECK(act == exp);
}
