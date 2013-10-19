class Solution {
public:
    TreeNode *dfs(vector<int> &pos, int x, vector<int> &ino, int y, int len){
        if (len<=0) return NULL;
        int i = y;
        while (i<y+len && ino[i] != pos[x+len-1]){
            i++;
        }
        TreeNode *t = new TreeNode(pos[x+len-1]);
        t->left = dfs(pos, x, ino, y, i-y);
        t->right = dfs(pos, x+i-y, ino, i+1, len-(i-y+1) );
        return t;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return dfs(postorder, 0, inorder, 0, inorder.size());
    }
};
