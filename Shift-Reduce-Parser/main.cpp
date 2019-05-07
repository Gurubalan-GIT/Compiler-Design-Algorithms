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
int k = 0,z = 0,i = 0,j = 0,c = 0;
char a[20], ac[20], act[20], stk[20];
void check();
int main()
{
    cout<<"Grammar is : \nE->E+E\nE->E*E\nE->(id)\nE->id"<<endl;
    cout<<"Enter the input string : "; gets(a);
    c = strlen(a);
    cout<<"Stack\tInput\tAction"<<endl;
    strcpy(act,"SHIFT->Symbols");
    for(i = 0, k = 0; j < c; j++,i++,k++)
    {
        if(a[j] == 'i' && a[j+1] == 'd')
        {
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            cout<<"$"<<stk<<"\t"<<a<<"$\t"<<act<<endl;
            check();
        }
        else
        {
            stk[i] = a[j];
            stk[i+1] = '\0';
            a[j] =' ';
            cout<<"$"<<stk<<"\t"<<a<<"$\t"<<act<<endl;
            check();
        }
    }
    return 0;
}
void check()
{
    strcpy(ac,"Reduce to E");
    for(z =0; z < c; z++)
    {
        if(stk[z] == 'i' && stk[z+1] == 'd')
        {
            stk[z] = 'E';
            stk[z+1] = '\0';
            cout<<"$"<<stk<<"\t"<<a<<"$\t"<<ac<<endl;
            j++;
        }
    }
    for(z =0; z < c; z++)
    {
        if(stk[z] == 'E' && (stk[z+1] == '+' || stk[z+1] == '*') && stk[z+2] == 'E')
        {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            cout<<"$"<<stk<<"\t"<<a<<"$\t"<<ac<<endl;
            i-=2;
        }
    }
    for(z = 0; z < c; z ++)
    {
        if(stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')')
        {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            cout<<"$"<<stk<<"\t"<<a<<"$\t"<<act<<endl;
            i-=2;
        }
    }
}
