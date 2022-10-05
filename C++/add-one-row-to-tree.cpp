/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        
        int count=0;
        
        while(q.size()>0)
        {
            int n=q.size();
            count++;
            
            while(n--)
            {
                TreeNode *node=q.front();
                q.pop();
                
                if(count!=depth-1)
                {
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                else
                {
                    TreeNode *leftPar=new TreeNode(val);
                    leftPar->left=node->left;
                    node->left=leftPar;
                    
                    TreeNode *rightPar=new TreeNode(val);
                    rightPar->right=node->right;
                    node->right=rightPar;
                }
            }
        }
        return root;
    }
};