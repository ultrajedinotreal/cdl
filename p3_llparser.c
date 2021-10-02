
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20


int top;
char stack[SIZE];
char w[SIZE];
char n[5] = {'E', 'A', 'T', 'B', 'F'};
char t[6] = {'d', '+', '*', '(', ')', '$'};
char pt[5][6][5] = {"TA", "0", "0", "TA", "0", "0", "0", "+TA", "0", "0", "@", "@", "FB", "0", "0", "FB", "0", "0", "0", "@", "*FB", "0", "@", "@", "d", "0", "0", "(E)", "0", "0"};



void push(char a) 
{

    //printf("\ntop = %d", top);
    top++;
    stack[top] = a;
    //strcpy(stack[top], a);

}

void pop() 
{

    top--;

}

char getTop() 
{
    return stack[top];

}

int getIndexN(char a) 
{    
    int f = -1;
    for (int h = 0; h < 5; h++) {
        if (n[h] == a) {
            f = h;
            break;
        }
    }

    return f;

}

int getIndexT(char a) 
{   

    int f = -1;
    for (int h = 0; h < 6; h++) {
        if (t[h] == a) {
            f = h;
            break;
        }
    }
    return f;

}

int stackEmpty() 
{
    if (top == -1) 
        return 1;
    else
        return 0;
    
}



int main() 
{


    printf("HARIKRISHNAN PS  23  S7 CSE BETA\n ");
    int row, column, i = 0;
    char x, pt_entry[SIZE];
    top = -1;

    printf("Enter input ");
    scanf("%s", w);
    strcat(w, "$");

    printf("\nInput : %s\n", w);

    push('$');
    push('E');

    printf("\n");

    while(!stackEmpty()) {
        
        x = getTop();
        
        
        row = getIndexN(x);
        

        if (getIndexT(x) != -1 || x == '$') {
            if (x == w[i]) {
                if (x != '$') {
                    pop();
                    i++;
                }
                else {
                    printf("\nPARSING DONE\n\n");
                    exit(0);
                }
            }
            else {
                printf("ERROR\n");
                exit(0);
            }
        }

        else if (row != -1) {
            column = getIndexT(w[i]);
            strcpy(pt_entry, pt[row][column]);

            if (strcmp(pt_entry, "0") != 0) {
                printf("\n%c -> %s", x, pt_entry);
                pop();
                if (strcmp(pt_entry, "@") != 0) {
                    for (int k = (strlen(pt_entry)-1); k >= 0; k--) {
                        push(pt_entry[k]);
                    }
                }
            }
            else {
                printf("\nERROR\n");
                exit(0);
            }
        }
    }
    return 0;
}
