#include "CheckCompleteBT.hpp"

// void Solution::checkCompleteBT(TreeNode* root,int& depth,bool& result){

//   // if(root==nullptr){
//   //   return;
//   // }else if (root->right != nullptr && root->left != nullptr){
//   //   depth++;
//   // }else if (root->right != nullptr || )
//   if(root->right == nullptr){

//   }

// }

bool isCompleteAllExceptLast(TreeNode* rootLeft, TreeNode* rootRight){
  //  bool isLeftFill = (rootLeft->left != nullptr && rootLeft->right !=nullptr)? true:false;
  //  bool isRightFill = (rootRight->left != nullptr && rootRight->right !=nullptr)? true:false;
   bool isLeftLeaf = (rootLeft-> left == nullptr && rootLeft->right ==nullptr)? true:false;
   bool isRightLeaf = (rootRight-> left == nullptr && rootRight->right ==nullptr)? true:false;

   if(isLeftLeaf==false && isRightLeaf==false){
      if(rootLeft!=nullptr && rootRight!=nullptr){
        return isCompleteAllExceptLast(rootLeft->left,rootLeft->right) && isCompleteAllExceptLast(rootRight->left,rootLeft->right);
      }
   }
}

bool isCompleteTreeProto2(TreeNode* root){
   if(root == nullptr){
    return false;
    }
    bool isNodeLeaf = (leftRoot->left != nullptr || leftRoot->right != nullptr)? true:false;


  if(isLeftLeaf == true && isLeftLeaf == true){
     
  }
  while(1){

  }

}

bool Solution::isCompleteChild(TreeNode* root){

  if(root == nullptr){
    return false;
  }else if (root->right==nullptr && root->left==nullptr){
    return true;
  }
  return isCompleteChild(root->left)&& isCompleteChild(root->right);
}

bool Solution::checkAll(TreeNode* root, bool canLeftOnly){

  bool isLeftLeaf = (root->left->left == nullptr && root->left->right == nullptr)? true:false;
  bool isrightLeaf = (root->right->left == nullptr && root->right->right == nullptr)? true:false;

  if(root == nullptr){
    return false;
  }else if (root->right==nullptr && root->left==nullptr){
    return true;
  }
   if (isLeftLeaf==true || isrightLeaf==true){
    return false;
  }

  // if(root == nullptr){
  //   return false;
  // }else if (root->right==nullptr && root->left==nullptr){
  //   return true;
  // }
  return isCompleteChild(root->left)&& isCompleteChild(root->right);
}


bool Solution::isCompleteTreeProto(TreeNode* root){

  if(root == nullptr){
    return false;
  }else if(root->right == nullptr && root->left == nullptr){        //check if its the leaf node
      return true;
  }
  else if (root->right==nullptr || root->left==nullptr){
    if(root->right == nullptr){
      if(root->left->left !=nullptr || root->left->right != nullptr){
        return false;
      }else{
        return true;
      }
    }
    if(root->left == nullptr){
      return false;
    }
  }

  return isCompleteTreeProto(root->left)&& isCompleteTreeProto(root->right);
}

bool Solution::isCompleteTree(TreeNode* root){
 return isCompleteChild(root);
}

int main(){
  Solution s;
  //TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)),new TreeNode(3,nullptr,new TreeNode(7)));
  //TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)),new TreeNode(3,new TreeNode(6),nullptr));
  // TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)),new TreeNode(3,new TreeNode(6),new TreeNode(3)));
   //TreeNode* root = new TreeNode(1,new TreeNode(2), new TreeNode(3));
   //TreeNode* root = new TreeNode(1,new TreeNode(2), nullptr);
   //TreeNode* root = new TreeNode(1,nullptr, new TreeNode(3));
   TreeNode* root = new TreeNode(1);
  std::cout<<s.isCompleteTreeProto(root)<<std::endl;
  return 0;
}