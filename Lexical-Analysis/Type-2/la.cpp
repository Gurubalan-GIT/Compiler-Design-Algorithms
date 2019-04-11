/*
 * Created Date: Thursday April 11th 2019
 * Author: Gurubalan Harikrishnan
 * Email-ID: gurubalan.work@gmail.com
 * -----
 * Copyright (c) 2019 Gurubalan Harikrishnan
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <stdio.h>
using namespace std;
char ops[] = {'=','+','-','*','/'};
int in(char c, char arr[])
{
    for(int i = 0; arr[i] != '\0'; i ++)
        if(c == arr[i])
           return 1;
    return 0;
}
int all_ops(char arr[])
{
    for(int i = 0; arr[i] != '\0'; i ++)
        if(!in(arr[i],ops))
            return 0;
    return 1;
}
int all_alnum(char str[])
{
    for(int i = 0; str[i] != '\0'; i ++)
        if(!isalnum(str[i]))
            return 0;
    return 1;
}
int main()
{
    char arr[100]; cout<<"enter the simple expression (Properly seperated) :> ";
    gets(arr);
    int n = sizeof(arr)/sizeof(char);
    char tmp[100];
    strcpy(tmp," ");
    n = 0;
    for(n = 0; arr[n] != '\0'; n++);
    if(arr[n-1] != ';')
    {
        cout<<"Error! "<<arr[n-1]<<endl;
        return 0;
    }
    for(int i = 0, k = 0; arr[i] != '\0'; i ++)
    {
        if(arr[i] == ' ' || arr[i] == ';')
        {
            if(all_alnum(tmp))
            {
                cout<<"Keyword/Identifier : "<<tmp<<endl;
                strcpy(tmp," ");
                k = 0;
            }
            else if(all_ops(tmp))
            {
                cout<<"Operator : "<<tmp<<endl;
                strcpy(tmp," ");
                k=0;
            }
            else{
                cout<<"Error! tmp : "<<tmp<<" arr[i] : "<<arr[i]<<endl;
                return 0;
            }
        }
        else{
                tmp[k++]=arr[i];
                tmp[k] = '\0';
        }
    }
    cout<<"Punctuator  : "<<';'<<endl;
    return 0;
}