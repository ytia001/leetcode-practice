# include <unordered_map>
# include <queue>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    // TreeNode* traversal(TreeNode* root, unordered_map<int,TreeNode*>& mp){
    //   if(!root) return nullptr;

    //   TreeNode* left = traversal(root->left,mp);
    //   if(left) {
    //     mp[root->val] = left;
    //     mp[left->val] = root;
    //   }
    //   TreeNode* right = traversal(root->right,mp);
    //   if(right) {
    //     mp[root->val] = right;
    //     mp[left->val] = root;
    //   }
    //   return root;
    // }

    TreeNode* traversal(TreeNode* root, unordered_map<int,TreeNode*>& mp ,int target, TreeNode*& startNode){
      if(!root) return nullptr;
      if(root->val == target){ 
        startNode = root;
        return root;
      }

      if(TreeNode* left = traversal(root->left,mp,target,startNode)){
        mp[left->val] = root;
        return root;
      }
      if(TreeNode* right = traversal(root->right,mp,target,startNode)){
        mp[right->val] = root;
        return root;
      }

      return nullptr;
    }

    int amountOfTime(TreeNode* root, int start) {
       int res = -1;
       unordered_map<int,TreeNode*> mp;
       TreeNode* startNode = nullptr;
       traversal(root,mp,start,startNode); 
       queue<TreeNode*> q;
       q.push(startNode);
      
       while(!q.empty()){
         int size = q.size();
         res++;
         while(size-- > 0){
           TreeNode* cur = q.front(); q.pop();
           if(mp.count(cur->val)) q.push(mp[cur->val]);
           if(cur->left && !mp.count(cur->left->val)) q.push(cur->left);
           if(cur->right && !mp.count(cur->right->val)) q.push(cur->right);
         }
       }
       return res;
    }
};