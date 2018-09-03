#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_SIZE 256

int main()
{
    unsigned lineCount = 0, charCount = 0;
    FILE* source;
    int n;

    char sourceFilename[100];
    char destFilename[100];
    char line[MAX_LINE_SIZE];

    do
    {
        printf("Please enter the source file name >");
        scanf("%99s", sourceFilename);

        source = fopen (sourceFilename,"r" );
        if (source==NULL)
            printf("I couldn't find the file! please try again!\n");
    }
    while (source == NULL);
    printf("I successfully opened %s for reading", sourceFilename);

    // get the length of the file
    while (fgets(line, MAX_LINE_SIZE,source)!=NULL)
    {
        lineCount ++;
        charCount += strlen(line);
    }

    fclose(source);

    printf("\nPlease enter how many files you want to divided: ");
    scanf("%d", &n);

    int maxLenPerFile = charCount / n;
    printf("total len: %d\n", charCount);
    printf("split into %d files.\n", n);
    printf("each file has maximum %d characters\n", maxLenPerFile);

    source = fopen (sourceFilename,"r" );


    for (int i = 1; i <= n; i++)
    {
        char fileName [16];
        sprintf(fileName, "file%d", i);
        FILE* target = fopen (fileName, "w" );

        int numCopied = 0; // the number of characters that are copied so far

        while(numCopied < maxLenPerFile && (fgets(line, maxLenPerFile - numCopied + 1, source) != NULL))
        {
            printf("attempt to copy up to %d characters\n", maxLenPerFile - numCopied);
            printf("copying %s into file %s\n", line, fileName);

            printf("line: %s, count of line: %d\n", line, strlen(line));
            fprintf(target, "%s", line);

            numCopied = numCopied + strlen(line);
            printf("copied: %d, remaining: %d\n", numCopied, maxLenPerFile - numCopied);
        }
        fclose(target);
    }
    fclose(source);
}









