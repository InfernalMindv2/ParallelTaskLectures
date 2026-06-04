#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
	//This is our firstParallelVersion of PI
	//In the beginning, we define our constants (Nsteps and the number of threads needed to calculate our PI)
	const int MAX_steps = 100000,threadSize=3;
	//Here our variable actualth is a global variable for (#pragma omg parallel) to keep track if our os set 
	//what we need or no !
	int actualth=0;
	//Defining step,array that will store  each iteration of i fro, 0 to n-1
	//Here we used the technique of manually SPMD (In next code we will explain)
	// but for now we make each thread to keep track of its own indexes
	long double step=1.0/(long double)MAX_steps,sum[threadSize]=  {0};
	omp_set_num_threads(threadSize);
	
	#pragma omp parallel
	{
		//Retrieving our id , total number of actual running threads
		int id = omp_get_thread_num();
		int total=omp_get_num_threads();
		//in condition we keep tracking of actual threads and update to global variable
		if(!id)
			actualth = total;
		// (Manually SPMD)do cyclic distribution to each thread
		for(int i=id;i<MAX_steps;i+=total)
		{
			long double x=(i+0.5)*step;
			sum[id]+=4.0/(1.0+x*x);
		}
	}
	// collecting each iteration 
	long double pi=0;
	for(int i=0;i<actualth;i++)
		pi+=sum[i]*step;
	cout << pi;

	
	return 0;
}
