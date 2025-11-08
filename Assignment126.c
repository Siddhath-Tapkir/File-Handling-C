// Program which accepts file name from user and read all the data and display on screen
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 1024
void FileRead(char *str)
{
    int fd = 0, iRet = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};
    fd = open(str,O_RDONLY);
    
    while(iRet = read(fd,Buffer,BUFFER_SIZE) != 0);
    {
        printf("%s",Buffer);
        memset(Buffer,'\0',BUFFER_SIZE);
    }
    close(fd);

}
int main()
{
    auto char Fname[20] = {'\0'};
    auto int iRet = 0;
    printf("Enter a file name\n");
    scanf("%[^'\n']s",Fname);
    FileRead(Fname);
    printf("\n");


    return 0;
}