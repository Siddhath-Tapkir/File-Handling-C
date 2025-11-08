// Program which accepts file name from user and create the file name
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int FileCreate(char *str)
{
    auto int fd = 0;
    fd = creat(str, 0777);
    return fd;
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto int iRet = 0;
    printf("Enter a file name\n");
    scanf("%[^'\n']s",Fname);
    iRet = FileCreate(Fname);
    if(-1 == iRet)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File created successfully\n");
    }


    return 0;
}