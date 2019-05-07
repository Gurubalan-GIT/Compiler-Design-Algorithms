/*
 * Created Date: Tuesday May 7th 2019
 * Author: Gurubalan Harikrishnan
 * Email-ID: gurubalan.work@gmail.com
 * -----
 * Copyright (c) 2019 Gurubalan Harikrishnan
 */
#include<iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
char postfix[10] = "";
void Postfix(char exp[])
{
    char op1, op2, optr;
    char pfix[10];
    strcpy(pfix,"");
        for(int i = 0, flag = 1; exp[i] != '\0'; i ++)
        {
            if(isalnum(exp[i]))
            {
                if(flag == 1)
                {
                    op1 = exp[i];
                    flag++;
                }
                else op2 = exp[i];
            }
            else if(exp[i] != ' ')
                optr = exp[i];
        }
        pfix[0] = op1; pfix[1] = op2; pfix[2] = optr;pfix[3] = '\0';
        strcat(postfix,pfix);
}
void subexp(char exp[])
{
    char subexp[100] = "";
    char outerops[10] = "";
    int ops = 0;
    for(int i = 0; exp[i] != '\0'; i ++)
    {
        strcpy(subexp,"");
        if(exp[i] == '(')
        {
            int j,k;
            for(j = i+1,k = 0; exp[j]!= ')'; j ++)
                subexp[k++] = exp[j];
            Postfix(subexp);
            i = j;
        }
        else
            outerops[ops++] = exp[i];
    }
    outerops[ops] = '\0';
    strcat(postfix,outerops);
}
int main()
{
    char exp[10];
    strcpy(postfix,"");
    cout<<"Enter the expression :>"<<endl;
    gets(exp);
    subexp(exp);
    cout<<"Postfix is : "<<postfix<<endl;
    cout<<"Prefix is : "<<strrev(postfix)<<endl;
    return 0;
}