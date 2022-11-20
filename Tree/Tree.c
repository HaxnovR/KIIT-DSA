#include<stdio.h>
#include<stdlib.h>
#define end -1
#define COUNT 10

typedef struct tree{
    int data;
    struct tree *lc, *rc;
}tree;

tree* insertLeft(tree* root, int value);
tree* insertRight(tree* root, int value);

void createTree(tree *root){
    tree *node = root;
    int data;
    printf("Enter left of %d:", node->data);
    scanf("%d", &data);
    if(data != 0){
        insertLeft(node, data);
        createTree(node->lc);
    }
    printf("Enter right of %d:", node->data);
    scanf("%d", &data);
    if(data != 0){
        insertRight(node, data);
        createTree(node->rc);
    }
}

tree* createNode(int value) {
  tree *newNode = malloc(sizeof(tree));
  newNode->data = value;
  newNode->lc = NULL;
  newNode->rc = NULL;

  return newNode;
}

tree* insertLeft(tree* root, int value) {
  root->lc = createNode(value);
  return root->lc;
}

tree* insertRight(tree* root, int value) {
  root->rc = createNode(value);
  return root->rc;
}

void preorder(tree *node){
    tree *temp = node;
    if(temp){
        printf("%d ", temp->data);
        preorder(temp->lc);
        preorder(temp->rc);
    }
}

void postorder(tree *node){
    tree *temp = node;
    if(temp){
        preorder(temp->lc);
        preorder(temp->rc);
        printf("%d ", temp->data);
    }
}

void inorder(tree *node){
    tree *temp = node;
    if(temp){
        preorder(temp->lc);
        printf("%d ", temp->data);
        preorder(temp->rc);
    }
}

void print2DUtil(tree* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->rc, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->lc, space);
}
 
// Wrapper over print2DUtil()
void print2D(tree* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(void){
    int value;
    printf("Enter data for root node:");
    scanf("%d", &value);
    tree *root = createNode(value);
    root->data = value;
    createTree(root);
    printf("\nPreOrder : ");
    preorder(root);
    printf("\nInOrder : ");
    inorder(root);
    printf("\nPostOrder : ");
    postorder(root);
    print2D(root);
}