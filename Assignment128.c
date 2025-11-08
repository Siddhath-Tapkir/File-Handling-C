// Program which accepts file name from user and a string and write that string in the file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 1024
void FileWrite(char *str, char *str2)
{
    auto int fd = 0;
    fd = open(str,O_WRONLY | O_CREAT);
    if(-1 == fd)
    {
        printf("Unable to open file\n");
    }
    else
    {
        write(fd,str2,strlen(str2));
    }
    close(fd);
}
int main()
{
    auto char Fname[20] = {'\0'};
    auto char Arr[20] = {'\0'};
    auto int iRet = 0;
    printf("Enter a file name\n");
    scanf("%[^'\n']s",Fname);
    printf("Enter a string\n");
    scanf(" %[^'\n']s",Arr);
    FileWrite(Fname,Arr);
    


    return 0;
}