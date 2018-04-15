//Reference: https://blog.csdn.net/daguairen/article/details/52611874
#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

class MySort {
public:
	MySort(){};
	~MySort(){};
	void InsertionSort(int [], int n);
	void ShellSort(int [], int n);
	void SelectionSort(int [], int n);
	void HeapSort(int [], int n);
	void HeapAjust(int [], int n);
	void BubbleSort(int [], int n);
	void QuickSort(int [], int low, int up);
	void MergeSort(int [], int low, int up);
	void MergeArray(int [], int low, int mid, int up);
	void CountSort(int [], int n);
	void Swap(int [], int , int);
	int QuickPartition(int [], int low, int end);
//RadixSort: https://zh.wikipedia.org/wiki/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F
//BucketSort: http://bubkoo.com/2014/01/15/sort-algorithm/bucket-sort/
}; 

void MySort::Swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void MySort::InsertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (arr[j] > arr[j+1])
				Swap(arr, j, j+1);
		}
	}
}

void MySort::ShellSort(int arr[], int n){
	for(int d = n/2; d >= 1; d = d/2){
		for(int i = d; i < n; ++i){
			for(int j = i -d; j > 0; j = j - d){
				if(arr[j] < arr[j+d])
					Swap(arr, j, j+d);
			}
		}
	}
}

void MySort::SelectionSort(int arr[], int n){
	for(int i = 0; i < n; ++i){
		int index = i;
		for(int j = i + 1; j < n; ++j)
			if(arr[j] < arr[index])
				index = j;
		Swap(arr, i, index);
	}
}

void MySort::HeapAjust(int arr[], int n) {
	for (int parentNode = n / 2 - 1; parentNode >= 0; --parentNode) {
		int leftChild = parentNode * 2 + 1, idx = leftChild;
		if (leftChild + 1 < n-1 && arr[leftChild] < arr[leftChild + 1]) {
			idx = leftChild + 1;
		}
		if (arr[parentNode] < arr[idx]){
			Swap(arr, parentNode, idx);
		}
	}
}

void MySort::HeapSort(int arr[], int n) {
	for (int end = n; end > 0; --end) {
		HeapAjust(arr, end);
		Swap(arr, 0, end - 1);
	}
}

void MySort::BubbleSort(int arr[], int n){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-i-1; ++j) {
			if(arr[j] > arr[j+1])	
				Swap(arr, j, j+1);
		}
	}
}

int MySort::QuickPartition(int arr[], int low, int up){
	int pivot=arr[low];
	while(low < up){
		while(arr[up] > pivot) --up;
		if(low < up) arr[low++] = arr[up];
		while(arr[low] < pivot) ++low;
		if(low < up) arr[up--] =arr[low];
	}
	arr[low] = pivot;
	return low;
}

//https://blog.csdn.net/morewindows/article/details/6684558
void MySort::QuickSort(int arr[], int low, int up){
	if(low < up){
		int mid = QuickPartition(arr, low, up);
		QuickSort(arr, low, mid-1);
		QuickSort(arr, mid+1, up);
	}
}

void MySort::MergeSort(int arr[], int low, int up){
	if(low < up){
		int mid = (low + up)/2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, up);
		MergeArray(arr, low, mid, up);
	}
}

void MySort::MergeArray(int arr[], int low, int mid, int up){
	try{
		int i = low, j = mid, m = mid + 1, n = up, idx = 0;
		int temp[up - low + 1] = {0};
		while(i <= j && m <= n){
			if(arr[i] <= arr[m])
				temp[idx++] = arr[i++];
			else temp[idx++] = arr[m++];
		}
		while(m <= n) {             //my error while(i > j)
			temp[idx++] = arr[m++];
		}
		while(i <= j) {
			temp[idx++] = arr[i++];
		}
		for(int k = low; k <= up; ++k){
			arr[k] = temp[k-low];
		}
	}
	catch(int n){
		cout<<"out_of_range"<<endl;
	}
}

void MySort::CountSort(int arr[], int n) {
	if (n == 0) return;
	else {
		int min = INT_MAX, max = INT_MIN;
		//找最值
		for (int i = 0; i < n; ++i) {
			if(arr[i] < min) min = arr[i];
			if(arr[i] > max) max = arr[i];
		}
		int range = max - min + 1;
		int value[range] = {0};
		//计数
		for (int i = 0; i < n; ++i) {
			value[arr[i] - min]++;
		}
		//确定下标范围
		for (int i = 1; i < range; ++i)	{
			value[i] = value[i] + value[i - 1];
		}
		//赋值
		for (int i = 0; i < value[0]; ++i)  arr[i] = min;
		for (int i = 1; i < range; ++i){
			for (int j = value[i - 1]; j < value[i]; ++j){
				arr[j] = min + i;
			}
		}
	}
	
}

int main() {
	int ArrSize = 10;
	int Arr[ArrSize] = {0};
	clock_t start, end;  //https://www.cnblogs.com/dwdxdy/p/3214905.html
	
	//srand(time(0));
	//random_device rd; doesn't work here
	default_random_engine e(time(0));   //using time() as seed is acceptable
	uniform_int_distribution<unsigned> u(0, 1000);
	for (int i = 0; i < ArrSize; ++i)
	{
		//produce random number：use rand() and srand() in c and use class random in c++
		//https://blog.csdn.net/dcrmg/article/details/52074884
		Arr[i] = u(e);
	}

/*	for(auto item : Arr)  //Range-based for loop
			cout<<item<<' ';
	cout<<endl;*/

	cout<<"clocks:"<<CLOCKS_PER_SEC<<endl;
	start = clock(); 
	MySort MS;	
	//MS.QuickSort(Arr, 0, ArrSize-1);	
	MS.CountSort(Arr, ArrSize);
	end = clock();
	cout<<"TimeUsed:"<<double(end-start)/CLOCKS_PER_SEC<<endl;
	cout<<"this is my mistake!"<<sizeof(Arr)<<endl;
	for(auto item : Arr)  //Range-based for loop
		cout<<item<<' ';
	
	//system("pause");
	return 1;
}
