class Solution {
public:
    vector<int>vt;
    void right(TreeNode*root,int level)
    {
        if(root==NULL)
            return;
        if(level==vt.size())
            vt.push_back(root->val);
        right(root->right,level+1);
        right(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        right(root,0);
        return vt;
    }
};
