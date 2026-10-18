#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

//input operator ke dalam stack
void push(char ch){
    stack[++top] = ch;
}

// pop operator
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

void postFix(char infix[], char postFix[]){
    int len = strlen(infix);
    int k = 0;

    for(int i = 0; i < len; i++){
        char ch = infix[i];

        //kalau ketemu operand
        if(ch >= 'A' && ch <= 'Z'){
            //atau if (!isoperator(ch) && ch != '(' && ch != ')')
            postFix[k++] = ch;
        }

        // kalau ketemu kurung buka masukin ke stack
        else if(ch == '('){
            push(ch);
        }

        // kalau ketemu kurung tutup di POP
        else if(ch == ')'){
            // pop semua elemen yang ada di scope tersebut
            // satu scope: (....)
            while(top != -1 && stack[top] != '('){
                //pop terus -> masukin ke postfix str
                postFix[k++] = pop();
            }
            pop();
        }

        //kalau ketemu operator -> ke stack
        else if(isOperator(ch) ){
            while(top != -1 && precedence(stack[top]) >= precedence(ch) && stack[top] != '('){
                postFix[k++] = pop();
            }
            push(ch);
        }
    }

    //pop semua sisa operator yang masih ada di stack
    while(top != -1){
        postFix[k++] = pop();
    }

    postFix[k] = '\0';
}




int main(){

    //char infix[] = "A+B*C";
    char infix[] = "(A+((B^C)*D))";
  
    char temp[MAX];
    postFix(infix,temp);

    printf("%s\n",temp);



    return 0;
}