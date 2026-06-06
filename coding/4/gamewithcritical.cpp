#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
//Define a account bank with a specific amount of money.
long double money = 5000.75;
//Let's see 3 threads to simulate them as people wants to get percentage of money.
const int THREAD_MAX = 3;
// create an array for threads'deposit,status of operation
long double  ar[THREAD_MAX]={2000,3000,1000};
bool  success[THREAD_MAX];
//set the number of threads in #pragma construct
omp_set_num_threads(THREAD_MAX);

#pragma omp parallel
{
	int id =  omp_get_thread_num();
	//This area ,ONLY ONE THREAD ENTER IT !.
	#pragma omp critical
	{
		//Validation of enough money for each thread.
		if(money-ar[id]>=0)
		{
			money-=ar[id];
			success[id]=1;
		}
		else
		{
			success[id]=0;
		}
	}
}
//Iterating all over all threads
for(int i=0;i<THREAD_MAX;i++)
{
	string x;
	if(success[i])
		x="Successfully";
	else
		x="Failed";
	cout << "The status of Thread id " << i <<"is " << x << '\n';
}

}

