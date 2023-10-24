#include <stdio.h>
#include <stdlib.h>

int appendToFile(float avg){
    char* filename = "numbers.dat";
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fprintf(file, "%f\n", avg);
    fclose(file);
    return 0;
}

int main() {
    char* filename = "numbers.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];

    int count = 0;
    float total = 0;
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total = total + atof(line_buffer);
        count++;
    }

    float avg = total/count;

    fclose(file);
    appendToFile(avg);
    return 0;
}

