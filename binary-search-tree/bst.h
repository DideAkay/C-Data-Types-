#ifndef BST_H_
#define BST_H_
#define size 20
#include <string.h>
#include<stdlib.h> 
#include<stdio.h>

typedef struct BSTnode
{
    int code; 
    long long int numbers[20];
    struct BSTnode* left;
    struct BSTnode* right;
    struct BSTnode* parent;

}BSTnode_t;


BSTnode_t* createNode(int _code);
BSTnode_t* insertNode(int _code, BSTnode_t* _root);
BSTnode_t* findMin(BSTnode_t* _node);
BSTnode_t* findMax(BSTnode_t* _node);
BSTnode_t* deleteNode(int _code, BSTnode_t* _root);
BSTnode_t* findNode(int _code, BSTnode_t* _root);
void inorder(BSTnode_t *root);
void preorder(BSTnode_t *root); 
void postorder(BSTnode_t *root); 
int findDepth(BSTnode_t* node); //levelorder icin gerekli
void printLevel(BSTnode_t* root, int level_counter ); 
void levelOrder(BSTnode_t* root);




#endif