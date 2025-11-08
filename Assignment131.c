//// Program to accept file name from user and count number of white spaces in that file
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 1024
int CheckSpaces(char Arr[])
{
    auto int fd = 0,iCnt = 0, iRd = 0, iSpace = 0;
    auto char Buffer[BUFFER_SIZE] = {'\0'};
    
    fd = open(Arr,O_RDONLY);
    if(-1 == fd)
    {
        return fd;
    }
    else
    {
        while((iRd = read(fd,Buffer,BUFFER_SIZE)) != 0)
        {
            for(iCnt = 0; iCnt < iRd; iCnt++)
            {
                if(' ' == Buffer[iCnt])
                {
                    iSpace++;
                }
            }
            memset(Buffer,'\0',BUFFER_SIZE);
        }
        close(fd);
    }
    return iSpace;
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto int iRet = 0;
    printf("Enter file name\n");
    scanf("%s",Fname);
    iRet = CheckSpaces(Fname); 
    if(-1 == iRet)
    {
        printf("there is an issue\n");
    }
    else
    {
        printf("Number of white spaces are :%d\n",iRet);
    }   


    return 0;
}