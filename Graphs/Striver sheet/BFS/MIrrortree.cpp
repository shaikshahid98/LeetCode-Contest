void solve(BinaryTreeNode<int> *p )

{
    if(!p) return;
    swap(p->left,p->right);
    solve(p->left);
    solve(p->right);
}
void mirrorTree(BinaryTreeNode<int> *root) {
   solve(root);
   return;
}