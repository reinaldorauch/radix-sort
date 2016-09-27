#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int getWidth(int number) {
    int width = 0;

    while (number > 0) {
        number /= 10;
        width++;
    }

    return width;
}

int getMaxWidthFromInput(int *input, int length) {
    int maxLength = 0;
    int currentLength;

    for (int i = 0; i < length; ++i)
    {
        currentLength = getWidth(input[i]);

        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int getInputHash(int input, int radix) {
    return (input / radix) % 10;
}

void applyRadix(int *input, int length, int width) {
    int radix = pow(10.0, (double) width);
    int buckets[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int inputHash, i;
    int output[length];

    // Counting hash occurencies
    for (i = 0; i < length; ++i)
    {
        inputHash = getInputHash(input[i], radix);
        buckets[inputHash]++;
    }

    // Adding offsets
    for (i = 1; i < 10; i++)
    {
        buckets[i] += buckets[i - 1];
    }

    // Reorganizing elements sorted by the current hash
    for (i = (length - 1); i >= 0; i--)
    {
        inputHash = getInputHash(input[i], radix);
        buckets[inputHash]--;

        output[buckets[inputHash]] = input[i];
    }

    // Outputting
    for (int i = 0; i < length; ++i)
    {
        input[i] = output[i];
    }
}

void radix (int *input, int length) {
    int maxWidth = getMaxWidthFromInput(input, length);

    for (int i = 0; i < 10; i++)
    {
        applyRadix(input, length, i);
    }
}

void printArrayElements(int *arr, int length) {
    for (int i = 0; i < length; i++)
    {
        printf("%3d", arr[i]);
    }
    putchar('\n');
}

int main (int argc, char **argv) {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *sorted;

    printArrayElements(arr, 10);

    radix(arr, 10);

    assert(getWidth(1) == 1);
    assert(getWidth(2) == 1);
    assert(getWidth(10) == 2);
    assert(getWidth(100) == 3);
    assert(getWidth(1003) == 4);
    assert(getMaxWidthFromInput(arr, 10) == 2);
    assert(arr[9] == 10);
    assert(arr[0] == 1);

    printArrayElements(arr, 10);
    return 0;
}
