#include <stdio.h>
#include <string.h>

void reverseR(int length, char *str);

int main(){

    char str[50];

    printf("Plz input a string: ");
    scanf("%s", str);

    reverseR(strlen(str), str);// Call the function
    printf("%s", str);// Print the reversed string

    return 0;
}

void reverseR(int length, char *str){
    char temp;

    if(length >= 2) {
        // Swap the position of the first index and the last index
        temp = str[0];
        str[0] = str[length - 1];
        str[length - 1] = temp;
        // Recursion
        reverseR(length - 2, str + 1);
    }
}