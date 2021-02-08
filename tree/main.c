#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * root = NULL;

void insert(){
    struct node *t, *currentNode, *parentNode;
    int d;
    printf("Enter the data to be inserted: ");
    scanf("%d",&d);
    t=(struct node *)malloc(sizeof(struct node));
    t->data=d;
    t->left=NULL;
    t->right=NULL;
    if(root==NULL)
        root=t;
    else{
        currentNode=root;
        while(currentNode!=NULL){
            parentNode=currentNode;
            if(t->data>currentNode->data){
                currentNode=currentNode->right;
            }
            else if(t->data<currentNode->data){
                currentNode=currentNode->left;
            }
            else{
                printf("This number is already insreted\n");
                free(t);
                return;
            }
        }
        if(t->data>parentNode->data){
            parentNode->right=t;
            free(t);
        }
        else{
            parentNode->left=t;
            free(t);
        }
    }
}

void delete(){
    struct node *currentNode, *parentNode, *replaceNode ;
    int d;
    printf("Enter the data to be deleted: ");
    scanf("%d",&d);
    if(root==NULL)
        printf("The tree is empty");
    else{
        currentNode=root;
        while(currentNode){
            if(currentNode->data == d){
                break;
            }
            else if (d>currentNode->data) {
                parentNode=currentNode;
                currentNode=currentNode->right;
            }
            else{
                parentNode=currentNode;
                currentNode=currentNode->left;
            }
        }
        if(currentNode==NULL){
            printf("Element %d is not found in the tree\n",d);
        }
        else if(currentNode->left==NULL && currentNode->right==NULL){
            if(parentNode->right->data==d){
                parentNode->right=NULL;
            }
            else{
                parentNode->left=NULL;
            }
        }
        else if(currentNode->left!=NULL){
            replaceNode=currentNode;
            while(replaceNode->right!=NULL){
                parentNode=replaceNode;
                replaceNode=replaceNode->right;
            }
            currentNode->data=replaceNode->data;
            if(replaceNode->left!=NULL){
                parentNode->right=replaceNode->left;
            }
            free(replaceNode);
        }
        else{
            replaceNode=currentNode;
            while (replaceNode->left!=NULL) {
                parentNode=replaceNode;
                replaceNode=replaceNode->left;
            }
            if(replaceNode->right!=NULL){
                parentNode->left=replaceNode->right;
            }
            currentNode->data=replaceNode->data;
            free(replaceNode);
        }
    }
}

void inorder(struct node *p){
    if(p->left){
        inorder(p->left);
    }
    printf("%d\n",p->data);
    if(p->right){
        inorder(p->right);
    }
}
void pstorder(struct node *p){
    if(p->left){
        inorder(p->left);
    }
    if(p->right){
        inorder(p->right);
    }
    printf("%d\n",p->data);
    
}

void prorder(struct node *p){
    printf("%d\n",p->data);
    if(p->left){
        inorder(p->left);
    }
    if(p->right){
        inorder(p->right);
    }
    
}

void display(){
    int option;
    if(root==NULL){
        printf("The tree is empty\n");
    }
    printf("Enter the display option\n");
    printf("1.Inorder\n2.Postorder\n3.Preorder\n");
    scanf("%d",&option);
    switch (option) {
        case 1:
            printf("The elements in the tree are\n");
            inorder(root);
            break;
        case 2:
            printf("The elements in the tree are\n");
            pstorder(root);
            break;
        case 3:
            printf("The elements in the tree are\n");
            prorder(root);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

int main(int argc, const char * argv[]) {
    int option;
    while(1){
        printf("Choose your option\n1.Insert\n2.Delete\n3.display\n0.Exit\n");
        scanf("%d",&option);
        switch(option){
            case 0:
                exit(0);
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
