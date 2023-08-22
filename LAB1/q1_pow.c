/*Write a simple MPI program to find out pow (x, rank) for all the processes where ‘x’ is the integer constant and ‘rank’ 
is the rank of the process.*/

#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char *argv[]){
	int rank, size;
	int x=2;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int ans= pow(x, rank);
	printf("Process %d power of %d : %d\n",rank, x, ans);
	MPI_Finalize();
	return 0;
}