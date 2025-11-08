// Program to accept file name from user and a character and count how many times that character has occured in that file (case insensitive)
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 1024
int CheckCharacter(char Arr[], char ch)
{
    auto int fd = 0,iCnt = 0, iRd = 0, iChar = 0, iDis = 0;
    auto char Buffer[BUFFER_SIZE] = {'\0'};
    
    fd = open(Arr,O_RDONLY);
    if(-1 == fd)
    {
        return fd;
    }
    else
    {
        if(('A' <= ch) && ('Z' >= ch))
        {
            iDis = 32;
        }
        else if(('a' <= ch) && ('z' >= ch))
        {
            iDis = -32;
        }
        else
        {
            iDis = 0;
        }
        while((iRd = read(fd,Buffer,BUFFER_SIZE)) != 0)
        {
            for(iCnt = 0; iCnt < iRd; iCnt++)
            {
                if(Buffer[iCnt] == (ch + iDis))
                {
                    iChar++;
                }
                else if(Buffer[iCnt] == ch)
                {
                    iChar++;
                }
            }
            memset(Buffer,'\0',BUFFER_SIZE);
        }
        close(fd);
    }
    return iChar;
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto char cValue = '\0';
    auto int iRet = 0;
    printf("Enter file name\n");
    scanf("%s",Fname);
    printf("Enter charater\n");
    scanf(" %c",&cValue);
    iRet = CheckCharacter(Fname,cValue); 
    if(-1 == iRet)
    {
        printf("there is an issue\n");
    }
    else
    {
        printf("that character has occured :%d times\n",iRet);
    }   

    return 0;
}