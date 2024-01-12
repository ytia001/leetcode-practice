#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double dfs(unordered_map<string, unordered_map<string, double>>& eq, unordered_set<string>& visited, const string& nominator, const string& denominator, double result) {
        if (nominator == denominator) {
            return result;
        }
        unordered_map<string, double>& adjNode = eq[nominator];
        for (const auto& i : adjNode) {
            const string& nextNode = i.first;
            if (!visited.count(nextNode)) {
                visited.insert(nextNode);
                double divisionResult = dfs(eq, visited, nextNode, denominator, result * i.second);
                if (divisionResult != -1) {
                    return divisionResult;
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> eq;
        unordered_set<string> variables;
        vector<double> res;

        // Populate the equations and values
        for (int i = 0; i < equations.size(); i++) {
            const string& nominator = equations[i][0];
            const string& denominator = equations[i][1];
            double val = values[i];
            variables.insert(nominator);
            variables.insert(denominator);
            eq[nominator][denominator] = val;
            eq[denominator][nominator] = 1 / val;
        }

        // Perform division calculations
        for (const auto& query : queries) {
            const string& nominator = query[0];
            const string& denominator = query[1];
            if (variables.count(nominator) && variables.count(denominator)) {
                if (eq[nominator].count(denominator) == 0) {
                    unordered_set<string> visited;
                    visited.insert(nominator);
                    res.emplace_back(dfs(eq, visited, nominator, denominator, 1));
                } else {
                    res.emplace_back(eq[nominator][denominator]);
                }
            } else {
                res.emplace_back(-1);
            }
        }

        return res;
    }
};