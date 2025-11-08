// Program which accepts file name from user and open it in read mode
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int FileOpen(char *str)
{
    auto int fd = 0;
    fd = open(str, O_RDONLY);
    return fd;
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto int iRet = 0;
    printf("Enter a file name\n");
    scanf("%[^'\n']s",Fname);
    iRet = FileOpen(Fname);
    if(-1 == iRet)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File opened successfully\n");
    }


    return 0;
}