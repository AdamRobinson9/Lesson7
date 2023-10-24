#include <stdio.h>

int main()
{
    char *filename = "squares.dat";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    int numSquares;
    printf("How many squares do you want? ");
    scanf("%d" , &numSquares);
    
    
    for (int i = 0; i < numSquares; i++)
    {
        fprintf(file, "%d\n", i*i);
    }

    fclose(file);
    return 0;
}