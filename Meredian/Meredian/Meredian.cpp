// Meredian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//Two steps:
//1 - Join arrays with uniq elements
//2 - Find meredian


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    map<int, bool> result;
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            for (auto el : nums1)
            {
                if (result.find(el) == result.end())
                {
                    result[el] = true;
                }
            }

            for (auto el : nums2)
            {
                if (result.find(el) == result.end())
                {
                    result[el] = true;
                }
            }

            map<int, bool>::iterator it;
            vector<int> new_v;

            for (it = result.begin(); it != result.end(); it++) {
                new_v.emplace_back(it->first);
            }

            auto a = new_v[result.size() / 2];
            double res = result.size() % 2 != 0 ?
                        new_v[result.size() / 2] :
                        (new_v[result.size() / 2] + new_v[result.size() / 2 - 1]) / (double)2;
            return res;
        }
};


int main()
{
    Solution sol;
    vector<int> v1{1, 2, 3};
    vector<int> v2{4};

    cout << sol.findMedianSortedArrays(v1, v2);
}

