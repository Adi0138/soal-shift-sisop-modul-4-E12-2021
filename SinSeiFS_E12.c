#define FUSE_USE_VERSION 28
#include <assert.h>
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
static const char *dirpath = "/home/adiperwira/Downloads";


int checkVersion(char path[])
{
    char temp[1000];
    char ver_1[6] = "AtoZ_";
    strcpy(temp, path);
    char *new_path = temp;
    while (strlen(new_path) > 0)
    {
        char *dir = getCurrentDir(new_path);
        printf("dir %s\n",dir);
        if (strncmp(dir, "AtoZ_",strlen("AtoZ_")) == 0)
        {
            return 1;
        }
        new_path[strlen(new_path) - strlen(dir)-1] = '\0';
    }
    return 0;
}

void *getCurrentDir(char *path)
{
    char *token;
    char *directory;
    size_t length;

    token = strrchr(path, '/');

    if (token == NULL)
    {
        printf("Error"); 
        exit(1);
    }

    length = strlen(token);
    directory = malloc(length);
    memcpy(directory, token + 1, length);

    return directory;
}

