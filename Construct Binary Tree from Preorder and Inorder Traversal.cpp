class Solution {
public:
    TreeNode *dfs(vector<int> &pre, int x, vector<int> &ino, int y,
                    int len){
        if (len<=0) return NULL;
        int i = y;
        while (i<y+len && ino[i] != pre[x]){
            i++;
        }
        TreeNode *t = new TreeNode(pre[x]);
        t->left = dfs(pre, x+1, ino, y, i-y);
        t->right = dfs(pre, x+1+i-y, ino, i+1, len-(i-y+1) );
        return t;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return dfs(preorder, 0, inorder, 0, preorder.size());
    }
};
