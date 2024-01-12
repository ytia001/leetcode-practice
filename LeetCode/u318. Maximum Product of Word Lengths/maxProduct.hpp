#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words);
    bool comparator(string a , string b);
    unordered_map<char,string> filter (vector<string>& words);
    int maxLengthOneString(int currIndex, vector<int>& words);
};