/*
 * Created Date: Thursday April 11th 2019
 * Author: Gurubalan Harikrishnan
 * Email-ID: gurubalan.work@gmail.com
 * -----
 * Copyright (c) 2019 Gurubalan Harikrishnan
 */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
char lead[100];
char * Leading(char ele, char prod[][20], int n)
{
    if(!isalpha(ele)) lead[strlen(lead)] = ele;
    else if(islower(ele)) lead[strlen(lead)] = ele;
    else
        for(int i = 0; i < n; i ++)
            if(ele == prod[i][0])
                    for(int j = 0; prod[i][j] != '\0'; j ++)
                    {
                        if((prod[i][j] == '>' || prod[i][j] == '|')  && isupper(prod[i][j+1])  && (islower(prod[i][j+2]) || !isalpha(prod[i][j+2]))&& isupper(prod[i][j+3]))
                            Leading(prod[i][j+2], prod, n);
                        if((prod[i][j] == '>' || prod[i][j] == '|')  && isupper(prod[i][j+1])  && (islower(prod[i][j+2]) || !isalpha(prod[i][j+2])))
                            Leading(prod[i][j+1], prod, n);
                        else if((prod[i][j] == '>' || prod[i][j] == '|')  && (islower(prod[i][j+1])||!isalpha(prod[i][j+1])) && isupper(prod[i][j+2]))
                            Leading(prod[i][j+1], prod, n);
                        else if((prod[i][j] == '>' || prod[i][j] == '|') && (islower(prod[i][j+1]) || !isalpha(prod[i][j+1])))
                            Leading(prod[i][j+1], prod, n);
                        else if((prod[i][j] == '>' || prod[i][j] == '|')  && isupper(prod[i][j+1]))
                            Leading(prod[i][j+1], prod, n);
                    }
    return lead;
}
char trail[100];
char * Trailing(char ele, char prod[][20], int n)
{
    if(!isalpha(ele)) trail[strlen(trail)] = ele;
    else if(islower(ele)) trail[strlen(trail)] = ele;
    else
        for(int i = 0; i < n; i ++)
            if(ele == prod[i][0])
                    for(int j = strlen(prod[i]); prod[i][j] != '>'; j --)
                    {
                        if((prod[i][j] == '\0' || prod[i][j] == '|')  && isupper(prod[i][j-1])  && islower(prod[i][j-2]) && isupper(prod[i][j-3]))
                            Trailing(prod[i][j-2], prod, n);
                        if((prod[i][j] == '\0' || prod[i][j] == '|')  && isupper(prod[i][j-1])  && (islower(prod[i][j-2]) || !isalpha(prod[i][j-2])))
                            Trailing(prod[i][j-1], prod, n);
                        else if((prod[i][j] == '\0' || prod[i][j] == '|')  && isupper(prod[i][j-1])  && !isalpha(prod[i][j-2]) && isupper(prod[i][j-3]))
                            Trailing(prod[i][j-2], prod, n);
                        else if((prod[i][j] == '\0' || prod[i][j] == '|')  && (islower(prod[i][j-11])||!isalpha(prod[i][j-11])) && isupper(prod[i][j+2]))
                            Trailing(prod[i][j-1], prod, n);
                        else if((prod[i][j] == '\0' || prod[i][j] == '|') && (islower(prod[i][j-1]) || !isalpha(prod[i][j-1])))
                            Trailing(prod[i][j-1], prod, n);
                        else if((prod[i][j] == '\0' || prod[i][j] == '|')  && isupper(prod[i][j-1]))
                            Trailing(prod[i][j-1], prod, n);
                    }
return trail;
}
int main()
{
    cout<<"Enter the number of productions : "<<endl;
    int n; cin>>n;
    cout<<"Enter the productions : "<<endl;
    char prod[n][20];
    char ele;
    for(int i = 0; i < n; i ++) cin>>prod[i];
    cout<<"Enter the element for which leading & trailing is to be found : "<<endl;
    cin>>ele;
    strcpy(lead, "");
    cout<<"Leading : "<<Leading(ele, prod, n)<<endl;
    strcpy(trail, "");
    cout<<"Trailing : "<<Trailing(ele, prod, n)<<endl;
    return 0;
}
