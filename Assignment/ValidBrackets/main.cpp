#include <stdio.h>
#include "ValidBrackets.h"

int main(){
    printf("%d\n", ValidBrackets("{()}"));//True, should print 1
    printf("%d\n", ValidBrackets("(<)>"));//False, should print 0
    printf("%d\n", ValidBrackets("{()}["));//False, should print 0
    printf("%d\n", ValidBrackets(""));//True, should print 1
    printf("%d\n", ValidBrackets(NULL));//False, should print 0
}