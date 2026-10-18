#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
typedef struct node{
    char value;
    struct node *left;
    struct node *right;
}node;

node *createNode(char value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

    node *createTree(char prefix[]){
        struct node *stack[SIZE];
        int top = -1;
        int i = strlen(prefix)-1;

        while( i >= 0){
            char ch = prefix[i];

            if (ch >='A' && ch <= 'Z'){
                node *newNode = createNode(ch);
                stack[++top] = newNode;
            }
            else{
                node *newNode = createNode(ch);
                newNode->left = stack[top--];
                newNode->right = stack[top--];

                stack[++top] = newNode;
            }
            i--;
        }

        return stack[top];
    }

int precedence(char ch){
    switch(ch){
        case '^': return 5;
        case 'x': return 4;
        case '/': return 4;
        case '+': return 3;
        case '-': return 3;
    }
    return 0;
}


int isOperator(char ch){
    return ch == '^' || ch == 'x' || ch == '/' || ch == '+' || ch == '-';
}


void inOrder(node *root){
    if (root == NULL) return;
    if(isOperator(root->value)) putchar('(');
    inOrder(root->left);
    printf("%c",root->value);
    inOrder(root->right);
    if(isOperator(root->value)) putchar(')');
}

void postOrder(node *root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c",root->value);
}

void preOrder(node *root){
    if (root == NULL) return;
    printf("%c",root->value);
    preOrder(root->left);
    preOrder(root->right);
}


void converting(char infix[], char prefix[]){
    int len = strlen(infix);
    int k = 0;

    for(int i = len ; i>= 0; i--){
        char ch = infix[i];

        if(ch >= 'A' && ch <= 'Z'){
            prefix[k++] = ch;
        }
        else if (ch == ')'){
            stack[++top] = ch;
        }
        else if (ch == '('){
            while(top != -1 && stack[top] != ')'){
                prefix[k++] = stack[top--];
            }
            top--;
        }
        else if (isOperator(ch)){
            while(top != -1 && precedence(stack[top]) > precedence(ch)){
                prefix[k++] = stack[top--];
            }
            stack[++top] = ch;

        }
    }

    while(top != -1){
        prefix[k++] = stack[top--];
    }


    prefix[k] = '\0';

}

void inverse(char curr[], char target[]){
    int len = strlen(curr);
    int k = 0;

    for(int i = len-1; i >= 0; i--){
        target[k] = curr[i];
        k++;
    }

    target[k] = '\0';
}




int main(){
    char inFix[] = "Ax((B+C)x(D-E))/(F+G)";
    char temp[SIZE];
    char newTemp[SIZE];

    converting(inFix,temp);

    inverse(temp, newTemp);

    printf("A. Prefix = %s\n",newTemp);

    node *tree = createTree(newTemp);

    printf("B. InOrder : \n");
    inOrder(tree);
    printf("\n");

    printf("    Postorder : \n");
    postOrder(tree);
    printf("\n");


    printf("    Preorder : \n");
    preOrder(tree);


    






    return 0;
}