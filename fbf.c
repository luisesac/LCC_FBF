#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_char(int previous, int current)
{
    if((previous == 126 || previous == 40) && ((current >= 112 && current <= 116) || current == 40))
    {
        return 1;
    }
    else if(current == 41 && (previous >= 112 && previous <= 116))
    {
        return 1;
    }
    else if ((current == 42 || current == 43) && previous == 41)
    {
        return 1;
    }
    else if (current == 40 && (previous == 42 || previous == 43 || previous == 40))
    {
        return 1;
    }
    else if (current == 41 && previous == 41)
    {
        return 1;
    }
    return 0;
}

void check_fbf(char* fbf)
{
    //  Si la fórmula comienza con ~, o (, entonces es una FBF. De lo contrario, el programa se detiene.
    if(fbf[0] == 126 || fbf[0] == 40)
    {
        int prev_char = fbf[0];
        int unclosed_par = 0;

        //  Si la fórmula comienza con un paréntesis, automáticamente se aumenta en 1.
        if(prev_char == 40)
        {
            unclosed_par += 1;
        }


        for(int i = 1; i < strlen(fbf)-1; i++)
        {
            prev_char = fbf[i-1];
            if(check_char(prev_char, fbf[i]) == 0)
            {
                printf("No es una fbf.\n");
                break;
            }
            if(fbf[i] == 40)
            {
                unclosed_par += 1;
            }
            if(fbf[i] == 41)
            {
                unclosed_par -= 1;
            }
        }
        if(unclosed_par == 0)
        {
            printf("Es una fbf.\n");
        }
        else
        {
            printf("No es una fbf.\n");
        }
    }
    else
    {
        printf("%d", fbf[0]);
        printf("No es una fbf.\n");
        return;
    }    
}

int main()
{
    char fbf[50];
    printf("Introduzca la fbf \n -> ");
    fgets(fbf, sizeof(fbf), stdin);
    check_fbf(fbf);
    printf("\n________________________________\n");
    return 0;
}