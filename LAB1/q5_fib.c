/*5. Write a program in MPI where even ranked process prints factorial of the rank and odd
ranked process prints ranks Fibonacci number.*/

#include<stdio.h>
#include<mpi.h>

int fib(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return (fib(n-1)+fib(n-2));
	}
}
int main(int argc, char *argv[]){
	int rank, size;
	int fact=1;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank%2==0){
		for(int i=0; i<=rank;i++){
			fact=fact*i;
		}
		printf("Process %d: Factorial = %d\n",rank, fact);
	}
	else{
		printf("Process %d: Fibonacci = %d\n",rank,fib(rank));
	}
	MPI_Finalize();
	return 0;
}