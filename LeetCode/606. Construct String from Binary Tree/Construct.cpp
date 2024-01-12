# include <string>

using namespace std;
 //Definition for a binary tree node.
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

    string tree2str(TreeNode* root) {
      string res = "";
      if(!root) return res;
      res = to_string(root->val);

      string leftNode = tree2str(root->left);
      string rightNode = tree2str(root->right);

      res += "(" + leftNode +")" + (!rightNode.empty() ? "("+ rightNode + ")" : "") ;

      return res; 
    }


    string tree2str(TreeNode* root) {
       string res = "";
      if(!root) return res;
      res = to_string(root->val);

      string leftNode = tree2str(root->left);
      string rightNode = tree2str(root->right);

      if(!leftNode.empty() && !rightNode.empty()){
        res = res + "(" + leftNode +")("+ rightNode + ")";
      }

      else if (!leftNode.empty()){
        res = res + "(" + leftNode + ")";
      }

      else if (!rightNode.empty()){
        res = res + "()("+ rightNode + ")";
      }

      return res; 
    }
};