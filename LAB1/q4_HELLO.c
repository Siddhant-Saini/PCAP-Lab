/*2. Write a program in MPI to toggle the character of a given string indexed by the rank of the
process. Hint: Suppose the string is HELLO and there are 5 processes, then process 0 tog-
gle ‘H’ to ‘h’, process 1 toggle ‘E’ to ‘e’ and so on.*/


#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(int argc, char *argv[]){
	int rank, size;
	char str[]="HELLO";
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	str[rank]=str[rank]+32;
	printf("Process %d :%s\n",rank, str);
	MPI_Finalize();
	return 0;
}



