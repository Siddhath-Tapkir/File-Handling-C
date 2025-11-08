// Program to accept file name from user and a number and display characters from that file
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 1024
void DisplayCharacters(char Arr[], int iSize)
{
    auto int fd = 0,iCnt = 0, iRd = 0, iSpace = 0;
    auto char Buffer[BUFFER_SIZE] = {'\0'};
    
    fd = open(Arr,O_RDONLY);
    if(-1 == fd)
    {
        printf("Unable to open file\n");
        return;
    }
    else
    {
        while((iRd = read(fd,Buffer,BUFFER_SIZE)) != 0)
        {
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                printf("%c ",Buffer[iCnt]);
            }
            memset(Buffer,'\0',BUFFER_SIZE);
        }
        close(fd);
    }
    printf("\n");
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto int iRet = 0, iValue = 0;
    printf("Enter file name\n");
    scanf("%s",Fname);
    printf("Enter number of characters\n");
    scanf("%d",&iValue);
    DisplayCharacters(Fname, iValue); 
  

    return 0;
}