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

	void quickSort(vector<T>& arr)
	{
		quick_recursion(arr, 0, arr.size()-1);
	}


private:
	// �鲢���躯�� 
	// end��С�ڵ���,[start,end];
	static void merge_recursive(vector<T>& arr,vector<T>& backup_arr,int start,int end);
	
	// �������躯�� 
	void quick_recursion(vector<T>& arr, int low,int hign);
	// �����ŦԪ��λ��
	int get_pivot_location(vector<T>& arr, int low,int hign);
};

template<class T>
void mySort<T>::quick_recursion(vector<T>& arr,int low,int hign)
{
	if (low < hign)
	{
		int pivot_loc = get_pivot_location(arr, low, hign);
		quick_recursion(arr, low, pivot_loc - 1);
		quick_recursion(arr, pivot_loc + 1,hign );
	}
}

template<class T>
int mySort<T>::get_pivot_location(vector<T>& arr, int low, int hign)
{
	// ѡȡһ����ŦԪ��ֵ,����ѡ������ұ�
	int pivotValue = arr[hign];
	int leftValueLoc = low - 1;
	for (int i = low; i < hign; i++)
	{
		// �κ�С����ŦԪ��ֵ��Ԫ�ض�����Ū�����,���ڵĲ���
		if (arr[i] < pivotValue)
		{
			leftValueLoc++;
			swap(arr[leftValueLoc], arr[i]);
		}
	}
	// ����ŦԪ��Ū�����ڵ��м�,
	swap(arr[leftValueLoc + 1], arr[hign]);
	// ������ŦԪ��λ��
	return leftValueLoc + 1;
}

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


