/*Additional 1
Write a program in MPI to reverse the digits of the following integer array of size 9 with 9
processes. Initialize the array to the following values.
Input array : 18, 523, 301, 1234, 2, 14, 108, 150, 1928
Output array: 81, 325, 103, 4321, 2, 41, 801, 51, 8291*/


#include <stdio.h>
#include <mpi.h>

#define ARRAY_SIZE 9

// Function to reverse the digits of a number
int reverseDigits(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main(int argc, char** argv) {
    int rank, size;
    int inputArray[ARRAY_SIZE];
    int outputArray[ARRAY_SIZE];
    int localArraySize;
    int localArray[ARRAY_SIZE];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Initialize the input array
        int initialArray[ARRAY_SIZE] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
        for (int i = 0; i < ARRAY_SIZE; i++) {
            inputArray[i] = initialArray[i];
        }
    }

    // Scatter the input array among processes
    localArraySize = ARRAY_SIZE / size;
    MPI_Scatter(inputArray, localArraySize, MPI_INT, localArray, localArraySize, MPI_INT, 0, MPI_COMM_WORLD);

    // Reverse the digits of the elements in the local array
    for (int i = 0; i < localArraySize; i++) {
        localArray[i] = reverseDigits(localArray[i]);
    }

    // Gather the reversed elements back into the output array
    MPI_Gather(localArray, localArraySize, MPI_INT, outputArray, localArraySize, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Print the output array
        printf("Input array : ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d, ", inputArray[i]);
        }
        printf("\n");

        printf("Output array: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d, ", outputArray[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
