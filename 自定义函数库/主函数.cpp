#include<iostream>
#include<cstdlib>
#include"funº¯Êý¿â.h"
using namespace std;
int main(void)
{
	int a[5] = { 9,4,2,1,6 };
	Fun *fun = new Fun();
	fun->fun_bubblesort<int>(a, 5);
//	cout << endl;
//	
//	int *a = fun->fun_sieveOfEra(20);
	for (int i = 0; i<5; i++)
	{
		cout << a[i];

	}
//	delete a;
//	a = NULL;

	


	return 0;
}
