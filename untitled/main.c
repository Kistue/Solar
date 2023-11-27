#include <stdio.h>
#include "stdlib.h"

typedef struct TreeNode
{
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* creatNode(int key){
    TreeNode* newNode = (TreeNode*)malloc(sizeof (TreeNode));
    if(newNode == NULL){
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
TreeNode* insertNode(TreeNode* root , int key){
    if(root == NULL){
        return creatNode(key);
    }
    if(key < root->key){
        root->left = insertNode(root->left , key);
    } else if(key > root->key){
        root->right = insertNode(root->right , key);
    }
    return root;
}
TreeNode* findNode(TreeNode* root , int key){
    if(root == NULL || root->key == key){
        return root;
    }
    if(key < root->key){
        return findNode(root->left , key);
    } else {
        return findNode(root->right , key);
    }
}
TreeNode* minValueNode(TreeNode* node){
    TreeNode* current = node;
    while (current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}
TreeNode* deleteNode(TreeNode* root , int key) {
    if (root == NULL) {
        return root;
    }
    //查询需要删除的节点
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        //1.单节点和叶节点删除
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        //2.两个子叶点删除
        TreeNode *minNode = minValueNode(root->right);
        root->key = minNode->key;
        root->right = deleteNode(root->right, minNode->key);
    }
    return root;
}
void printTree(TreeNode* root){
    if(root == NULL){
        return ;
    }
    printTree(root->left);
    printf("%d " , root->key);
    printTree(root->right);
}


int main() {
    TreeNode* root = NULL;
    root = insertNode(root , 3);
    insertNode(root , 1);
    insertNode(root , 2);
    insertNode(root , 4);
    insertNode(root , 5);
    insertNode(root , 6);

    //printTree(root);

    deleteNode(root , 5);
    printTree(root);
}
