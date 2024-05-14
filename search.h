#pragma once
#include "sort.h"
class search{
public:
	int linearSearch(int arr[], int size, int value, bool startToEnd){
		if(startToEnd){
			for(int i = 0; i < size; i++)
				if(value == arr[i])
					return i;
		}else{
			for(int i = size - 1; i > 0; i--)
				if(value == arr[i])
					return size - (i + 1);
		}
		return -1;
	}
	int binarySearch(int arr[], int size, int value){
		int *cpyArr = new int[size];
		for(int i = 0; i < size; i++){
			cpyArr[i] = arr[i];
		}
		sort s;
		s.heapSort(cpyArr, size, true);
		int l = 0, h = size - 1, m;
		while(l <= h){
			m = (l + h) / 2;
			if(cpyArr[m] == value) return m;
			if(cpyArr[m] < value) l = m + 1;
			else h = m - 1;
		}
		return -1;
	}

};
