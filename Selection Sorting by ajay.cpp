#include<iostream>
#include<conio.h>
#include<chrono>
using namespace std;
class selectionsort {
	static const int max = 5000;
	int a[max],size;
public:
	void iarray();
	void display();
	void sort();
	void ddisplay();
};
void selectionsort::iarray()
{
	cout << "Enter the size of the array :";
	cin >> size;
	srand(time(nullptr));
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 20;
	}
}
void selectionsort::display()
{
	cout << "The array contains : " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
void selectionsort::sort()
{
	int minindex;
	for (int i = 0; i < size - 1; i++)
	{
		minindex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[i])
			{
				minindex = j;
			}
		}
		if (minindex != i)
		{

			swap(a[i], a[minindex]);
		}
	}
}
void selectionsort::ddisplay()
{
	cout << "The sorted array is :" << "\t";
	for (int j = 0; j < size; j++)
	{
		cout << a[j] << "\t";
	}
	cout << endl;
}
int main()
{
	selectionsort s;
	s.iarray();
	s.display();
	auto start = chrono::high_resolution_clock::now();
	s.sort();
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);
	s.ddisplay();
	cout << "The amount of time taken is" << duration.count()<<"nanoseconds" << endl;
	return 0;
}