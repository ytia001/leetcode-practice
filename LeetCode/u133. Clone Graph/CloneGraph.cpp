#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> originalQ;
        queue<Node*> copyQ;
        unordered_set<int> history;
        if(!node) return nullptr;

        originalQ.push(node);
        Node* start = new Node(node->val);
        copyQ.push(start);
        while(!originalQ.empty()){
          // Node* curNode = originalQ.front();
          vector<Node*> neighbours = originalQ.front()->neighbors;
          Node* newNode = copyQ.front();
          originalQ.pop();
          copyQ.pop();
          while(!neighbours.empty()){
            Node* curNode = neighbours.back();
            neighbours.pop_back();
            if(!history.count(curNode->val)){
              history.insert(curNode->val);
              Node* neighbourNode = new Node(curNode->val);
              newNode->neighbors.push_back(neighbourNode);
              copyQ.push(neighbourNode);
              originalQ.push(curNode);
            } 
          }
        }
        return start;
    }
};