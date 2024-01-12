#include <string>
#include <iostream>

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
    string smallestFromLeaf(TreeNode* r, string s = "") {
    s = string(1, 'a' + r->val) + s;
    return r->left == r->right ? s : min(r->left ? smallestFromLeaf(r->left, s) : "|", 
        r->right ? smallestFromLeaf(r->right, s) : "|");
    }

    string comparator(string left , string right){
      if(left.compare(right) <= 0){
        return left;
      }
      return right;
    }
    
    void preOrder(TreeNode* root,string current,string& res) {
        if(!root){
          return;
        }
        else if(!root->left && !root->right){
          current = string(1,static_cast<char>(97+root->val)) + current;
          cout<<"current: "<<current<<endl; 
          res = comparator(res,current);
          cout<<"res: "<<res<<endl; 
          return;
        }
        
        current = string(1,static_cast<char>(97+root->val)) + current;
        preOrder(root->left,current,res);
        preOrder(root->right,current,res);
        return;
    }

    string smallestFromLeaf(TreeNode* root) {
        string res="zzzzzzzzzzzzzzzzz";
        preOrder(root,"",res);
        return res;
    }

    

    string smallestFromLeafTest(TreeNode* root) {
        if(!root) return "";
        string left = smallestFromLeafTest(root->left);
        string right = smallestFromLeafTest(root->right);
        string node = string(1,static_cast<char>(97+root->val));
        return comparator(left+node,right+node);
    }
};

int main(){
  string string1 = "ab";
  string string2 = "b";
  cout<<string1.compare(string2)<<endl;
  return 0;
}
