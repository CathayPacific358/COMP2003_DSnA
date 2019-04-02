#include <stdio.h>
#include "Stack.h"
#include <string.h>

bool ValidBrackets(char* str){
    Stack stack;
    char TopBracket, checker;

    //Return false when string is NULL
    if(str == NULL)
        return false;

    int len = strlen(str);//Find the length of the string

    //Return true when input is nothing
    if(len == 0)
        return true;

    //Create the stack
    CreateStack(&stack, len);

    //Use for loop as index
    for(int i = 0; i < len; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<'){//If is left brackets, push into the stack
            Push(&stack, str[i]);
        }else if(str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>'){//If is right brackets
            Top(&stack, &TopBracket);//Use Top to find the top bracket in the stack

            //Put into switch to find the corresponding left one
            switch (str[i]){
                case ')':
                    checker = '(';
                    break;
                case ']':
                    checker = '[';
                    break;
                case'}':
                    checker = '{';
                    break;
                case'>':
                    checker = '<';
                    break;
            }

            //Compare the one in stack with the counterpart of the right one
            if(checker != TopBracket){
                return false;//Not equal, return false
            }else{
                Pop(&stack);//Otherwise, pop it out
            }
        }
    }

    //When it is empty, shows all are valid
    if(IsEmpty(&stack))
        return true;
    else
        return false;
}

