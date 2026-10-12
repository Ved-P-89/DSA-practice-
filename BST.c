//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*right;
    struct Node*left;
};
struct Node*createNode(int value){
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}
struct Node*insert(struct Node*root, int value){
    if(root==NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    } else{
        root->right = insert(root->right, value);
    }
    return root;
}
struct Node*Search(struct Node* root, int key){
    if(root == NULL|| root->data == key){
        return root;
    }
    if(key<root->data){
        return Search(root->left, key);
    } else{
        return Search(root->right, key);
    }
}
void inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
}
int main()
{
struct Node *root=NULL;
struct Node *result;
int choice,value,key,n,i;
do
{
printf("\n1.Insert");
printf("\n2.Search ");
printf("\n3.Inorder ");
printf("\n4.Preorder ");
printf("\n5.Postorder ");
printf("\n6.Exit");
printf("\nEnter choice ");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("Enter no. of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter value:");
scanf("%d",&value);
root=insert(root,value);
}
break;
case 2:
printf("Enter element to search:");
scanf("%d",&key);
result=Search(root,key);
if(result==NULL)
{
printf("Element not found");
}
else
{
printf("Element found");
}
break;
case 3:
printf("Inorder - ");
inorder(root);
break;
case 4:
printf("Preorder - ");
preorder(root);
break;
case 5:
printf("postorder - ");
postorder(root);
break;
case 6:
printf("Exit");
break;
default:
printf("Invalid");

}

}
while(choice!=6);
return 0;
}