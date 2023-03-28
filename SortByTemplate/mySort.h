#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class mySort
{
public:
	static void print(const vector<T>& arr);
	// ���һ����������飬max���ֵ��min��Сֵ��Ŀǰ��֧��char��int�ͣ�size�������С
	static void get_an_randrom_array(vector<T>& arr,int max,int min,int size);

	static void mergeSort(vector<T>& arr);

private:
	// end��С�ڵ���,[start,end];
	static void merge_recursive(vector<T>& arr,vector<T>& backup_arr,int start,int end);

};

template<class T>
void mySort<T>::get_an_randrom_array(vector<T>& arr, int maxValue, int minValue, int size)
{
	vector<T> result;
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		T randomValue = static_cast<T>(rand() % (maxValue - minValue + 1) + minValue);
		result.push_back(randomValue);
	}
	arr = result;
}

template<class T>
void mySort<T>::print(const vector<T>& arr)
{
	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout << endl;
}

template<class T>
void mySort<T>::mergeSort(vector<T>& arr)
{
	vector<T> back_arr(arr.size());
	merge_recursive(arr, back_arr, 0, arr.size() - 1);
}

template<class T>
void mySort<T>::merge_recursive(vector<T>& arr, vector<T>& backup_arr, int start, int end)
{
	if (start >= end) return;
	int mid = start + (end - start) / 2;
	int lstart = start, lend = mid;
	int rstart = mid + 1, rend = end;

	merge_recursive(arr, backup_arr, lstart, lend);
	merge_recursive(arr, backup_arr, rstart, rend);

	int k = lstart;
	while (lstart <= lend && rstart <= rend)
	{
		backup_arr[k++] = arr[lstart] > arr[rstart] ? arr[lstart++] : arr[rstart++];
	}
	while (lstart <= lend)
	{
		backup_arr[k++] = arr[lstart++];
	}
	while (rstart <= rend)
	{
		backup_arr[k++] = arr[rstart++];
	}
	copy(backup_arr.begin() + start, backup_arr.begin() + end + 1, arr.begin() + start);
}


