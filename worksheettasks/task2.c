#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];

    int count = 0;
    int total = 0;
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total = total + atoi(line_buffer);
        count++;
    }

    float avg = total/count;
    printf("Average of the numbers = %0.2f\n", avg);

    fclose(file);
    return 0;
}