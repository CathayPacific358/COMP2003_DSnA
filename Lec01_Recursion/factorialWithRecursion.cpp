#include <stdio.h>
int recurse(int n);

int main() {

    int num, result;

    printf("Please input a positive number: ");
    scanf("%ld", &num);

    result = recurse(num);// Call the function
    printf("The result is: %ld", result);
}

int recurse(int n){
    if(n == 1){
        return 1;// The base to end the recursion
    }
    else if(n > 1){
        return n * recurse(n - 1);// To multiply the next smaller number
    }
}