#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int solveForQuery(int n, int* a);
void getInput(int n, int* a) {
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    int n;
    int *a;
    int i = 0;
    scanf("%d", &q);
    for(; i < q ; i ++) {
    	scanf("%d", &n);
        a = (int*)(malloc(sizeof(int) * n));
        getInput(n, a);
        if(solveForQuery(n, a) == TRUE) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
int solveForQuery(int n, int* a) {
    int* stack1 = (int*)(malloc(sizeof(int) * n));
    int top1 = -1;
    
    int solution = TRUE;
    int currentRoot;
    int rootInserted = FALSE;
    int i = 0;
    stack1[++top1] = a[0];
    for(i = 1 ;  i < n ; i ++) {
        if(rootInserted == FALSE) {
            //For Every Visited Element currentRoot will remain constant if seq is decreasing
            if(a[i] <= stack1[top1]) {
                //We are visiting towards left of bst
                stack1[++top1] = a[i];  
            } else {
                while(top1 >= 0 && a[i] > stack1[top1]) {
                    top1--;
                }
                currentRoot = stack1[top1];
                stack1[++top1] = a[i];
                rootInserted = TRUE;
            }
        } else {
            if(a[i] <= stack1[top1]) {
                if(a[i] < currentRoot) {
                    solution = FALSE;
                    break;
                } else {
                    stack1[++top1] = a[i];
                }
            } else {
                while(top1 >= 0 && a[i] > stack1[top1]) {
                    top1 --;
                }
                currentRoot = stack1[top1];
                stack1[++top1] = a[i];
            }
        }
    }
    return solution;
}
