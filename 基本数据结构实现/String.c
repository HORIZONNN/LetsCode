#include <stdlib.h>
#include <stdio.h>

//#define NULL (void*)0

typedef struct
{
    char *head;
    int length;
}MyString;

int StrAssign(MyString *T, char *chars)
//字符串赋值，将chars中的字符串赋值给T
//前提条件：chars中的字符串需要以0结尾
{
    if(T->head)                //释放T中原来的内存空间
        free(T->head);
    int i = 0;
    for(char *c=chars; *c; i++, c++);              //获得chars的长度
    if(!i)
    {
        T->head = NULL;
        T->length = 0;
    }else                   //进行循环赋值
    {
        T->head = (char*)malloc(i*sizeof(char));
        for(int j = 0; j < i; j++)
            *(T->head + j) = *(chars + j);
        T->length = i;
    }
    return 1;
}

int StrLength(MyString T)
//计算字符串T的长度
{
    return T.length;
}

int StrCompare(MyString T, MyString S)
//字符串按字典序进行比较
{
    for(int i = 0; i < S.length && i < T.length; i++)              //字典序比较
        if(T.head[i] != S.head[i])
            return T.head[i] - S.head[i];
    return T.length - S.length;                  //长度比较
}

int ClearString(MyString *T)
//清空字符串
{
    if(T->head)
    {
        free(T->head);
        T->head = NULL;
    }
    T->length = 0;
    return 1;
}

int Concat(MyString *T, MyString S1, MyString S2)
//拼接字符串，将S1和S2进行字符串拼接并赋值给T
{
    if(T->head)              //释放原先的内存空间
        free(T->head);
    if(! (T->head = (char*)malloc((S1.length+S2.length + 1)*sizeof(char))) )
       exit(1);
    for(int i = 0; i < S1.length; i++)             //S1中字符串赋值
    {
        *(T->head+i) = *(S1.head+i);
    }
    for(int i = 0; i < S2.length; i++)              //S2中字符串赋值
    {
        *(T->head+S1.length+i) = *(S2.head+i);
    }
    *(T->head + S1.length + S2.length) = 0;            //确保字符串有结束符
    T->length = S1.length + S2.length;
    return 1;
}

int SubString(MyString T, MyString *S, int pos, int len)
//将T字符串中从pos位置开始长度为len的子字符串赋值给S
{
    if(pos < 1 || pos > T.length || len < 0 || len > T.length-pos+1)    //pos和len的合法性检验
        return 0;
    if(S->head)
    {
        free(S->head);
        S->length = 0;
    }
    if(!len)
    {
        S->head = NULL;
        S->length = 0;
    }else
    {
        S->head = (char*)malloc( (len+1)*sizeof(char));
        for(int i = 0; i < len; i++)                       //循环赋值
        {
            *(S->head + i) = *(T.head+pos-1+i);
        }
        *(S->head+len) = 0;           //确保符号有结束符
        S->length = len;
    }
    return 1;
}


int main()
{
    char chars1[5] = {"abc"};
    char chars2[10] = {"1234567"};
    MyString string1,string2,string3;
    StrAssign(&string1, chars1);
    StrAssign(&string2, chars2);
    printf("%s\n", string1.head);
    printf("%d\n", StrLength(string1));
    printf("%d\n", StrCompare(string1, string2));
    Concat(&string3, string1, string2);
    printf("%s\n", string3.head);
    SubString(string2, &string3, 2, 2);
    printf("%s\n", string3.head);
    return 0;
}
