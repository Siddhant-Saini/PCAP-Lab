/*3. Write a program in MPI to simulate simple calculator. Perform each operation using dif-
ferent process in parallel.*/

#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
	int rank, size;
	int a=10, b=4;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0){
		printf("process %d : %d + %d = %d\n",rank,a,b,a+b);
	}
	if(rank==1){
		printf("process %d : %d - %d = %d\n",rank,a,b,a-b);
	}
	if(rank==2){
		printf("process %d : %d / %d = %d\n",rank,a,b,a/b);
	}
	if(rank==3){
		printf("process %d : %d * %d = %d\n",rank,a,b,a*b);
	}
	else{
		printf("process %d : %d mod %d = %d\n",rank,a,b,a%b);
	}
	MPI_Finalize();
	return 0;
}