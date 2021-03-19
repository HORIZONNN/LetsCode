#include <stdio.h>
#include <stdlib.h>

#define INIT_STACK_SIZE 100
#define INCREMENTSIZE 10

typedef struct
{
    char *base;
    char *top;
    int size;
}CharStack;

CharStack initStack()
{
    CharStack stack;
    stack.base = (char*)malloc(INIT_STACK_SIZE*sizeof(char));
    if(!(stack.base))
        exit(1);
    stack.top = stack.base;
    stack.size = INIT_STACK_SIZE;
    return stack;
}


void push(CharStack *stack, char elem)
{
    if(stack->top - stack->base >= stack->size)
    {
        stack->base = (char*)realloc(stack->base, (stack->size+INCREMENTSIZE) * sizeof(char));
        if(!(stack->base))
            exit(1);
        stack->top = stack->base + stack->size;
        stack->size += INCREMENTSIZE;
    }
    *(stack->top) = elem;
    (stack->top)++;
}

char pop(CharStack *stack)
{
    if(stack->top == stack->base)
        exit(1);
    return *--(stack->top);
}

int isEmpty(CharStack *stack)
{
    if(stack->base == stack->top)
        return 1;
    else
        return 0;
}

int main()
{
    //用一个括号匹配的例子测试一下
    char c;
    CharStack parStack = initStack();
    while((c = getchar()) != EOF)
    {
        if(c == '(' || c == '[' || c == '{')
        {
           push(&parStack, c);
        }else
        {
            switch(c)
            {
            case ')':
                if(pop(&parStack) != '(')
                    printf("match fail");
                break;
            case ']':
                if(pop(&parStack) != '[')
                    printf("match fail");
                break;
            case '}':
                if(pop(&parStack) != '{')
                    printf("match fail");
                break;
            }
        }
    }
    if(!isEmpty(&parStack))
    {
        printf("match fail");
        return 0;
    }
    printf("match success");
    return 0;
}
