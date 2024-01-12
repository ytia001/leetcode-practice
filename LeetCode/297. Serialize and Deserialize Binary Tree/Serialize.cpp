#include <string>

using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
private:
    string output;
    //string input;

    void serializeSearch(TreeNode* root){
      if(!root){
        output += "x";
        return;
      }

      if(root->val < 0){
        output +=  to_string(-root->val) + "-";
      }else{
        output +=   to_string(root->val) + "+";
      }

      //output += to_string(root->val)+"|";
      //cout<<"output: "<<output<<endl;

      serializeSearch(root->left);
      serializeSearch(root->right);

    }

    TreeNode* createTree(string& data,TreeNode* root){
      if(data.empty()){
        return nullptr;
      }
      if(data.front()=='x'){
        data = data.substr(1);
        return nullptr;
      }

      TreeNode* newNode;
      int val = 0;

      while(data.front()!='+' && data.front()!= '-'){
        val *= 10;
        val += data.front()-'0';
        data = data.substr(1);
      }

      if(data.front()=='-'){
        newNode = new TreeNode(-val);
      }else{
        newNode = new TreeNode(val);
      }
      data = data.substr(1);

      //cout<<newNode->val<<endl;
      //root->val = data[index] - '0';
      newNode->left = createTree(data,newNode->left);
      newNode->right = createTree(data,newNode->right);
      
      return newNode;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if(!root) return "x"; 
      serializeSearch(root);
      // for(auto s : output){
      //   cout<<"out: "<<s<<endl;
      // }
      return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      //input = data;
      TreeNode* resultNode = createTree(data,nullptr);
      return resultNode;
    }
};

// class Codec {
// private:
//     string output;
//     TreeNode* root;
//     int index = -1;

//     void serializeSearch(TreeNode* root){
//       if(!root){
//         output += "x";
//         return;
//       }

//       output += to_string(root->val)+"|";
//       //cout<<"output: "<<output<<endl;

//       serializeSearch(root->left);
//       serializeSearch(root->right);

//     }

//     TreeNode* createTree(string data,TreeNode* root, int& index){
//       index++;
//       if(index > (data.size()-1) || data[index]=='x'){
//         //index++;
//         return nullptr;
//       }

//       TreeNode* newNode;
//       int val = 0;
//       if(data[index]=='-'){
//         index++;
//         while(data[index]!='|'){
//           val *= 10;
//           val += data[index++]-'0';
//         }
//         newNode = new TreeNode(-val);
//       }else{
//         while(data[index]!='|'){
//           val *= 10;
//           val += data[index++]-'0';
//         }
//         newNode = new TreeNode(val);
//       }

//       //cout<<newNode->val<<endl;
//       //root->val = data[index] - '0';
//       newNode->left = createTree(data,newNode->left,index);
//       newNode->right = createTree(data,newNode->right,index);
      
//       return newNode;
//     }
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//       if(!root) return "x"; 
//       serializeSearch(root);
//       // for(auto s : output){
//       //   cout<<"out: "<<s<<endl;
//       // }
//       return output;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//       TreeNode* resultNode = createTree(data,nullptr,index);
//       return resultNode;
//     }
// };



// class Codec {
// private:
//     string output;
//     TreeNode* root;
//     int index = -1;

//     void serializeSearch(TreeNode* root){
//       if(!root){
//         output += "-1";
//         return;
//       }

//       output += to_string(root->val);

//       serializeSearch(root->left);
//       serializeSearch(root->right);

//     }

//     TreeNode* createTree(string data,TreeNode* root, int& index){
//       index++;
//       if(index > (data.size()-1) || data[index]=='-1'){
//         return nullptr;
//       }

//       TreeNode* newNode = new TreeNode(data[index]-'0');
//       //root->val = data[index] - '0';
//       newNode->left = createTree(data,newNode->left,index);
//       newNode->right = createTree(data,newNode->right,index);
      
//       return newNode;
//     }
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//       if(!root) return "-1"; 
//       serializeSearch(root);
//       return output;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//       TreeNode* resultNode = createTree(data,nullptr,index);
//       return resultNode;
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));