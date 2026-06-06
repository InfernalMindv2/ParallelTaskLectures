#include<iostream>
#include<omp.h>
using namespace std;
int main()
{
	//define a thread num and global variable related to #pragma
	const int THREAD_SIZE = 5,steps=100000;
	int globalth=0;
	// At first , let's make an array represent for the thread id storage "Distribution cyclic
	// for pi problem manually !"
	long double ar[THREAD_SIZE] = {0.0};
	//We define variables pi : our answer , sum as we need to calculate the pi = sum*step
	long double pi=0.0,sum=0.0,step =1.0/(long double)steps;
	// we should set the THREAD_SIZE before starting
	omp_set_num_threads(THREAD_SIZE);
	//Let's go in parallel side!
	#pragma omp parallel
	{
		//Each thread has its own i and id 
		int i,id;
		id = omp_get_thread_num();
		if(!id)
			globalth = omp_get_num_threads();
		int total = omp_get_num_threads();
		for(i=id;i<steps;i+=total)
		{
			long double x= (i+0.5)*step;
			ar[id]+=4.0/(1.0+x*x);
		}
		#pragma omp critical
		{
			pi+=ar[id]*step;
		}

	}
	cout << pi ;
	return 0;
}
