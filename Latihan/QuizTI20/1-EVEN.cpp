#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
char stack[SIZE];
int top = -1;

typedef struct node{
    char root;
    struct node *right;
    struct node *left;
}node;

node *createNode(char value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->root = value;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

node *createTree(char preFix[]){
    struct node *stack[100];
    int top = -1;
    int i = strlen(preFix) - 1;

    while(i >= 0){
        char ch = preFix[i];

        if (ch >= 'A' && ch <= 'Z'){
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


int precedence(char opr){
    switch(opr){
        case '^': return 5;
        case '*': return 4;
        case '/': return 4;
        case '+': return 3;
        case '-': return 3;
    }

    return 0;
}

int isOperator(char ch){
    return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-';
}

void inOrder(node *value){
    if (value == NULL) return;
    if (isOperator(value->root)) putchar('(');
    inOrder(value->left);
    printf("%c",value->root);
    inOrder(value->right);
    if (isOperator(value->root)) putchar(')');
}

void preOrder(node *value){
    if (value == NULL) return;
    printf("%c",value->root);
    preOrder(value->left);
    preOrder(value->right);
}

void postOrder(node *value){
    if (value == NULL) return;
    postOrder(value->left);
    postOrder(value->right);
    printf("%c",value->root);
}

void preFix(char infix[], char prefix[]){
    int len = strlen(infix);
    int k = 0;

    for(int i = len-1 ; i >= 0; i--){
        char ch = infix[i];

        if (ch >= 'A' && ch <= 'Z'){
            prefix[k++] = ch;
        }
        else if(ch == ')'){
            stack[++top] = ch;
        }
        else if (ch == '('){
            while(top != -1 && stack[top] != ')'){
                prefix[k++] = stack[top--];
            }
            top--;
        }
        else if(isOperator(ch)){
            while(top != - 1 && precedence(stack[top]) > precedence(ch) && stack[top] != '('){
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


void reverse(char curr[], char target[]){
    int len = strlen(curr);
    int k = 0;

    for(int i = len - 1; i >= 0; i--){
        target[k] = curr[i];
        k++;
    }

    target[k] = '\0';
}



int main(){
    char expression[] = "(A*B+(C*D-E))/(F+G)";
    char temp[SIZE];
    char newTemp[SIZE];

    preFix(expression, temp);
    reverse(temp, newTemp);

    printf("A. Prefix : %s\n",newTemp);
    

    node *tree = createTree(newTemp);

    printf("B. InOrder : ");
    inOrder(tree);
    printf("\n");

    printf("   Preorder : ");
    preOrder(tree);
    printf("\n");

    printf("   PostOrder : ");
    postOrder(tree);
    printf("\n");







    return 0;
}