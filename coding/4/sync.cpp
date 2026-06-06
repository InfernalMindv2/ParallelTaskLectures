#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
	//define a thread num and global variable related to #pragma
	const int THREAD_SIZE = 5;
	int globalth=0;
	// At first , let's make an array represent for the thread id storage
	int ar[THREAD_SIZE] = {0};
	//Let's set the number of threads
	omp_set_num_threads(THREAD_SIZE);
	#pragma omp parallel
	{
		//Retrieve your thread id
		int id=omp_get_thread_num();
		//Check if the id == 0 , set the actual thread runtime in global variable
		if(!id)
			globalth = omp_get_num_threads();
		//Apply simple equation  ax+b such that a=3,b=2,x=id;
		ar[id]=3*id+2;
		//TO MAKE ALL THREADS WAIT EACH OTHER , USE BARRIER.
		cout << "HERE I'm thread NUMBER : " << id << "Waiting my friends threads.\n";
		#pragma omp barrier
	}
	//Iterate all over your threads array
	for(int i=0;i<THREAD_SIZE;i++)
		cout << ar[i] << " ";
return 0;
}
