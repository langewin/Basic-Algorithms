#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
class Fun
{
public:
	Fun();
	~Fun();
	template<class E> 
	void fun_insertsort(E A[],int n);
	template<typename E>
	void fun_selectsort(E A[], int n);
	template<typename E>
	void fun_bubblesort(E A[], int n);
	template<typename E>
	void fun_mergesort(E A[], int n);
	template <typename E>
	void fun_quicksort(E A[], int n);
	int* fun_sieveOfEra(int n);
private:
	template<class E>
	void Merge(E B[], E C[], E A[], int p, int q);


private:

};

Fun::Fun()
{
}

Fun::~Fun()
{
}

 int * Fun::fun_sieveOfEra(int n)
{
	 list <int> L;
	 list<int>::iterator iter;
	 int *A = new int[n];
	 for (int i = 2; i < n; i++)
	 {
		 A[i] = i;
	 }
	 for (int i = 0; i < n; i++)
	 {
		 if (A[i]!=0)
		 {
			 int j = i*i;
			 while (j < n + 1)
			 {
				 A[j] = 0;
				 j += i;
			 }
		 }
	 }
	
	 for (int i = 2; i < n; i++)
	 {
		 if (A[i] != 0)
		 {
			 L.push_back(A[i]);
		  }
	 }
	 int p = L.size();
	 int *A1 = new int[p];
	 p = 0;
	 for ( iter = L.begin(); iter != L.end(); iter++)
	 {
		 A1[p] = *iter;
		 p++;
	 }
	 
	 delete[] A;
	 A = NULL;

	return A1;
}

template<class E>
void Fun::fun_insertsort(E A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		E v = A[i];
		int j = i;
		while (j > -1 && A[j-1] > v)
		{
			A[j] = A[j-1];
			j = j - 1;
		}
		A[j] = v;
		//cout << v<<"sa"<< A[j - 1];
	}
}

template<typename E>
 void Fun::fun_selectsort(E A[], int n)
{
	 for (int i = 0; i < n-1; i++)
	 {
		 int min = i;
		 for (int j = i+1; j < n; j++)
		 {
			 if (A[j] < A[min])
			 {
				 min = j;
			  }
		 }
		 E temp = A[i];
		 A[i] = A[min];
		 A[min] = temp;
	 }
}


 template<typename E>
void Fun::fun_bubblesort(E A[], int n)
 {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j <n-2-i; j++)
		{
			if (A[j] > A[j + 1])
			{
				E temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}

	}
 }
template<class E>
 void Fun::Merge(E B[], E C[], E A[], int p, int q)
{
	 int i = 0, j = 0, k = 0;
	 while (i < p&&j < q)
	 {
		 if (B[i] <= C[j])
		 {
			 A[k] = B[i];
			 i++;
		 }
		 else
		 {
			 A[k] = C[j];
			 j++;
		 }
		 k++;
	 }
	 if (i==p)
	 {
		 while (j != q)
		 {
			 A[k] = C[j];
			 k++;
			 j++;
		 }
	 }
	 else
	 {
		 while (i!=p)
		 {
			 A[k] = B[i];
			 k++;
			 i++;
		 }
	 }
}
template<typename E>
 void Fun::fun_mergesort(E A[], int n)
{
	 if (n > 1)
	 {
		 int cap = n / 2;
		 E B = new E(cap);
		 E C = new E(cap);
		 for (int i = 0; i < cap; i++)
		 {
			 B[i] = A[i];
			 C[i] = A[i + cap];
		 }
		 fun_mergesort(B, cap);
		 fun_mergesort(C, cap);
		 Merge(B, C, A, cap, cap);
	 }

}

template<typename E>
 void Fun::fun_quicksort(E A[], int n)
{
}

