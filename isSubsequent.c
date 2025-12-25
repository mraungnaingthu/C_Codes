#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequent(char* firstStr, char* secondStr);

int main()
{
    char str[100] = "aeroplane";
    char substr[100] = "aop";

    bool result = isSubsequent(str, substr);

    if (result)
    {
        printf("'%s' is a subsequence of '%s'\n", substr, str);
    }
    else
    {
        printf("'%s' is NOT a subsequence of '%s'\n", substr, str);
    }

    return 0;
}

bool isSubsequent(char* firstStr, char* secondStr)
{
    int i = 0;
    int j = 0;

    while (firstStr[i] != '\0' && secondStr[j] != '\0')
    {
        if (firstStr[i] == secondStr[j])    //aeroplane - apn
        {
            j++;
        }
        i++;
    }

    return (secondStr[j] == '\0'?true:false);
}