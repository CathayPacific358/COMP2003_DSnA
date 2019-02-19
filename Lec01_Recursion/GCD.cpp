#include <stdio.h>

int GCD(int x, int y);

int main(){
    int x, y, result;

    // Ask for input
    printf("Plz input x: ");
    scanf("%d", &x);
    printf("Plz input y: ");
    scanf("%d", &y);

    // To make sure x > y
    if(x < y){
        printf("Plz make sure x > y");
        scanf("%d", &x);
    }

    result = GCD(x, y);

    printf("%d", result);
}

int GCD(int x, int y){
    if(y == 0) {
        return x;// When y = 0 the GCD is x
    }
    else if(y > 0){
        GCD(y, x % y);// Find modulo of x using y and switch position
    }
}