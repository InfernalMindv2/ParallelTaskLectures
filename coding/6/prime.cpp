#include<iostream>
#include<omp.h>

using namespace std;

bool Prime(long long num)
{
if(num<2)
	return 0;
for(long long i=2;i*i<=num;i++)
{
	if(num%i==0)
		return 0;
}

	return 1;
}
int main()
{
//Let's first define our n for example [1,n]
const long long n = 1e4;
//we want a global variable represeting the answer
//Don't forget to set number of threads
omp_set_num_threads(5);
long long ans=0;
//Let's start our parallizm
#pragma omp parallel
{
//here we want to do a cyclic distribution automatic
//just use omp for
//We will use schedule static because approximately each thread has the same time
//chunk size = n/threads
//we will use reduction to do auto cyclic distribution
	#pragma omp for schedule(static) reduction(+:ans)
	for(int i=2;i<=n;i++)
	{
		//validation if i is prime or no
		//each thread has its own private ans
		if(Prime(i))
			ans++;
	}
}
cout << "Primes from 1 to " << n << "are : " << ans;
return 0;
}
