// Program which accepts file name from user and display it's file size
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 1024
int FileSize(char *str)
{
    int fd = 0, iRet = 0, iSum = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};
    fd = open(str,O_RDONLY);
    
    while((iRet = read(fd,Buffer,BUFFER_SIZE)) != 0)
    {
        iSum = iSum + iRet;
    }
    close(fd);
    return iSum;
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto int iRet = 0;
    printf("Enter a file name\n");
    scanf("%[^'\n']s",Fname);
    iRet = FileSize(Fname);
    printf("Size of file is %d bytes\n",iRet);


    return 0;
}