// Program to accept file name from user and count number of capital letters in that file
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define BUFFER_SIZE 1024
int CheckCapital(char Arr[], int iNo)
{
    auto int iCnt = 0, iRd = 0, iCapCount = 0;
    auto char Buffer[BUFFER_SIZE] = {'\0'};
    while((iRd = read(iNo,Buffer,BUFFER_SIZE)) != 0)
    {
        for( ; iCnt < iRd; iCnt++)
        {
            if(('A' <= Buffer[iCnt]) && ('Z' >= Buffer[iCnt]))
            {
                iCapCount++;
            }
        }
    }
    return iCapCount;
}
int main()
{
    auto int fd = 0, iRet = 0;
    auto char Fname[20] = {'\0'};
    
    printf("Enter file name\n");
    scanf("%s",Fname);
    fd = open(Fname, O_RDONLY);
    if(-1 == fd)
    {
        printf("unable to open the file\n");
    }
    else
    {
        iRet = CheckCapital(Fname,fd);
        printf("capital letters are : %d\n",iRet);
        
    }
    
    close(fd);

    return 0;
}