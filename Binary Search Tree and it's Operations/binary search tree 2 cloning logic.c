#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree{
    TreeNode* root;
}BinaryTree;

TreeNode* create_tree_node(int data){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if(new_node == NULL){
        printf("Memory not available");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
TreeNode* insert_node(TreeNode* root, int data){
    if(root == NULL){
        return create_tree_node(data);
    }
    if(data < root->data){
        root->left = insert_node(root->left,data);
    }
    else if(data > root->data){
        root->right = insert_node(root->right,data);
    }
    return root;
}
int in_order_traversal(TreeNode* root){
    if(root != NULL){
        in_order_traversal(root->left);
        printf("%d ",root->data);
        in_order_traversal(root->right);

        
    }
    return 0;
}
int post_order_traversal(TreeNode* root){
    if(root != NULL){
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ",root->data); 
    }
    return 0;
}
int pre_order_traversal(TreeNode* root){
    if(root != NULL){
        printf("%d ",root->data); 
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
    return 0;
}

TreeNode* clone_tree(TreeNode* node){
    if(node == NULL){
        return NULL;
    }
    TreeNode* new_node = create_tree_node(node->data);
    new_node->left = clone_tree(node->left);
    new_node->right = clone_tree(node->right);

    return new_node;
}
void destroying(TreeNode* node){
    
    if(node != NULL){
        destroying(node->left);
        destroying(node->right);
        free(node); 
    }
    return;
}

int main(){
    BinaryTree tree;
    tree.root = NULL;
    
    tree.root = insert_node(tree.root,8);
    tree.root = insert_node(tree.root,3);
    tree.root = insert_node(tree.root,10);
    tree.root = insert_node(tree.root,1);
    tree.root = insert_node(tree.root,6);
    tree.root = insert_node(tree.root,14);
    tree.root = insert_node(tree.root,4);
    tree.root = insert_node(tree.root,7);
    tree.root = insert_node(tree.root,13);
    printf("in_order_traversal\n");
    in_order_traversal(tree.root);
    printf("\n");
    printf("Post_order_traversal\n");
    post_order_traversal(tree.root);
    printf("\n");
    printf("Pre_order_traversal\n");
    pre_order_traversal(tree.root);
    printf("\n");

    // cloning tree

    BinaryTree tree2;
    tree2.root = NULL;
    tree2.root = clone_tree(tree.root);

    printf("in_order_traversal of Tree 2\n");
    in_order_traversal(tree.root);
    printf("\n");

    destroying(tree.root);
    destroying(tree2.root);
    printf("printting after distroying tree2\n");
    printf("in_order_traversal of Tree 2\n");
    in_order_traversal(tree.root);
    printf("\n");


    return 0;
}
