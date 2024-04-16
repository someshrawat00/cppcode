#include <stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

//PreOrder Traversal
void inorder(struct node* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

//PreOrder Traversal
void preorder(struct node* root){
    if(root == NULL) return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//PostOrder Traversal
void postorder(struct node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}


int main(){
    
    struct node* root = newNode(8);
    root->left = newNode(7);
    root->right = newNode(9);
    
     while(1)
    {
        int choice;

        printf("1.Print preorder\n");
        printf("2.Print postorder\n");
        printf("3.Print inorder\n");
        printf("4.Exit\n");

        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(1);
        }
    }

    return 0;
}