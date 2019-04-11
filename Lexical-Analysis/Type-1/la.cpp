/*
 * Created Date: Thursday April 11th 2019
 * Author: Gurubalan Harikrishnan
 * Email-ID: gurubalan.work@gmail.com
 * -----
 * Copyright (c) 2019 Gurubalan Harikrishnan
 */
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","include","long","main","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","while"};
	int i, flag = 0;
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}	
	return flag;
}
int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
	char spchar[] = "(){}[]!~";
	char foundkey[45][10], foundidf[45][10], foundop[45], foundspc[45];
	int key=0, idf=0, op=0, spc=0;
	ifstream fin("example.txt");
	int i,j=0,k;
	if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}
	while(!fin.eof()){
   		ch = fin.get();	
		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				foundop[op++]=ch;
   		}
   		for(i = 0; i < 8; ++i){
   			if(ch == spchar[i])
   				foundspc[spc++]=ch;
   		}
   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;		   				
   				if(isKeyword(buffer) == 1)
   					strcpy(foundkey[key++],buffer);
   				else
   					strcpy(foundidf[idf++],buffer);
   		}
	}
	int key2=key, spc2=spc, idf2=idf, op2=op;
	for(i=0; i<op; i++)
    {
        for(j=i+1; j<op; j++)
        {
            if(foundop[i] == foundop[j])
            {
                for(k=j; k<op; k++)
                {
                    foundop[k] = foundop[k + 1];
                }
                op--;
                j--;
            }
        }
    }
	for(i=0; i<spc; i++)
    {
        for(j=i+1; j<spc; j++)
        {
            if(foundspc[i] == foundspc[j])
            {
                for(k=j; k<spc; k++)
                {
                    foundspc[k] = foundspc[k + 1];
                }
                spc--;
                j--;
            }
        }
    }
	for(i=0; i<key; i++)
    {
        for(j=i+1; j<key; j++)
        {
            if(strcmp(foundkey[i], foundkey[j])==0)
            {
                for(k=j; k<key; k++)
                {
                    strcpy(foundkey[k], foundkey[k + 1]);
                }
                key--;
                j--;
            }
        }
    }
	for(i=0; i<idf; i++)
    {
        for(j=i+1; j<idf; j++)
        {
            if(strcmp(foundidf[i], foundidf[j])==0)
            {
                for(k=j; k<idf; k++)
                {
                    strcpy(foundidf[k], foundidf[k + 1]);
                }
                idf--;
                j--;
            }
        }
    }
    cout<<"Keywords in the program: ";
	for(i=0; i<key2; i++)
	{
		cout<<foundkey[i]<<" ";
	}
	cout<<"\nIdentifiers in the program: ";
	for(i=0; i<idf2; i++)
	{
		cout<<foundidf[i]<<" ";
	}
    cout<<"\nOperators in the program: ";
	for(i=0; i<op2; i++)
	{
		cout<<foundop[i]<<" ";
	}
	cout<<"\nSpecial Characters in the program: ";
	for(i=0; i<spc2; i++)
	{
		cout<<foundspc[i]<<" ";
	}
	fin.close();
	return 0;
}