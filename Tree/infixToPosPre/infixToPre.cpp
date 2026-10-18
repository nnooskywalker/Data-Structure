#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
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

int isOperator (char ch){
    return ch == '+' || ch =='-' || ch == '*' || ch == '/' || ch == '^';
}

void preFix(char infix[], char preFix[]){
    int len = strlen(infix);
    int k = 0;
    int top = -1;

    for(int i = len - 1; i >= 0; i--){
        char ch = infix[i];

        if(ch >= 'A' && ch <= 'Z'){
            preFix[k++] = ch;
        }
        else if(ch == ')'){
            push(ch);
        }
        else if(ch == '('){
            while(top != -1 && stack[top] != ')'){
                preFix[k++] = pop();
            }
            pop();
        }
        else if(isOperator(ch)){
            while(top != -1 && precedence(stack[top]) > precedence(ch)){
                preFix[k++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1){
        preFix[k++] = pop();
    }

    preFix[k] = '\0';
}

void reverse(char arr[], char save[], int len){

    int k = 0;

    for(int i = len-1; i >= 0; i--){
        save[k] = arr[i];
        k++;
    }
    save[k] = '\0';
}


int main(){

    char infix[] = "A+B*C";
  
    char temp[MAX];
    char target[MAX];
    preFix(infix,temp);

    int len = strlen(temp);
    reverse(temp,target, len);

    printf("%s\n",target);



    return 0;
}