#pragma once
class sort{
private:
	void swap(int&a, int&b){
	a = a + b;
	b = a - b;
	a = a - b;
}
	void merge(int arr[], int l, int m, int r, bool ascending){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1], *R = new int[n2];
	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = j = 0;
	k = l;
	bool condition;
	while(i < n1 && j < n2){
		ascending? condition = L[i] < R[j] : condition = L[i] > R[j];
		if(condition)
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}
	while(i < n1)
		arr[k++] = L[i++];
	while(j < n2)
		arr[k++] = R[j++];
}
	int partition(int arr[], int start, int end, bool ascending){
	int pivot = start;
	bool con1, con2;
	while(start < end){
		if(ascending){
			con1 = arr[end] < arr[pivot];
			con2 = arr[start] > arr[pivot];
		}else{
			con1 = arr[end] > arr[pivot];
			con2 = arr[start] < arr[pivot];
		}
		if(con1 && pivot != end){
			swap(arr[end], arr[pivot]);
			pivot = end;
			start++;
		}else if(con2 && pivot != start){
			swap(arr[start], arr[pivot]);
			pivot = start;
			end--;
		}else
			pivot != end ? end-- : start++;
	}
	// Another solution ↓
	/*while(true){
		while(arr[pivot] <= arr[end] && pivot != end) end--;
		if(pivot == end) break;
		else if(arr[pivot] > arr[end]){
			swap(arr[end], arr[pivot]);
			pivot = end;
		}
		while(arr[pivot] >= arr[start] && pivot != start) start++;
		if(pivot == start) break;
		else if(arr[pivot] < arr[start]){
			swap(arr[start], arr[pivot]);
			pivot = start;
		}
	}*/
	return pivot;
}
	void quickSort(int arr[], int startIndex, int endIndex, bool ascending){
	int pivot = 0;
	if(startIndex < endIndex){
		pivot = partition(arr, startIndex, endIndex, ascending);
		quickSort(arr, startIndex, pivot - 1, ascending);
		quickSort(arr, pivot + 1, endIndex,ascending);
	}
}
	void heapify(int arr[], int n, int i, bool ascending){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	if(ascending){
		if(l < n && arr[l] > arr[max]) max = l;
		if(r < n && arr[r] > arr[max]) max = r;
	}else{
		if(l < n && arr[l] < arr[max]) max = l;
		if(r < n && arr[r] < arr[max]) max = r;
	}
	if(max != i){
		swap(arr[i], arr[max]);
		heapify(arr, n, max, ascending);
	}
}
	void buildHeap(int arr[], int size, bool ascending){
	for(int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i, ascending);
}
	void mergeSort(int arr[], int startIndex, int endIndex, bool ascending){
	if(startIndex < endIndex){
		int m = startIndex + (endIndex - startIndex) / 2;
		mergeSort(arr, startIndex, m, ascending);
		mergeSort(arr, m + 1, endIndex, ascending);
		merge(arr, startIndex, m, endIndex, ascending);
	}
}
public:

	sort(void)
	{
	}

	~sort(void)
	{
	}

	void selectionSort(int arr[], int size, bool ascending){
	/*
		space complexity = O(1)
		time complexity = O(n^2) -> worst case
	*/
	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if(ascending){
				if(arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}else
				if(arr[i] < arr[j])
					swap(arr[i], arr[j]);
		}
	}
}
	void bubbleSort(int arr[], int size, bool ascending){
	/*
		space complexity = O(1)
		time complexity = O(n^2) -> worst case
		It's fast with sorted arrays
	*/
	bool swapped = false;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(ascending){
				if(arr[j] > arr[j + 1]){
					swap(arr[j], arr[j + 1]);
					swapped = true;
				}
			}else
				if(arr[j] < arr[j + 1]){
					swap(arr[j], arr[j + 1]);
					swapped = true;
				}
		}
		if(!swapped && i == 0) return;
	}
}
	void insertionSort(int arr[], int size, bool ascending){
	/*
		space complexity = O(1)
		time complexity = O(n^2) -> worst case, average case
						  O(n)   -> best case
	*/
	int key, j;
	for(int i = 1; i < size; i++){
		key = arr[i];
		j = i - 1;
		bool condition;
		ascending? condition = key < arr[j] : condition = key > arr[j];
		for(; j >= 0 && condition; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}
	void mergeSort(int arr[], int size, bool ascending){
	/*
		space complexity = O(n)
		time complexity = O(n log(n))
	*/
		mergeSort(arr, 0, size - 1, ascending);
	}
	void quickSort(int arr[], int size, bool ascending){
	/*
		space complexity = O(1)
		time complexity = O(n log(n))
	*/
		quickSort(arr, 0, size - 1, ascending);
	}
	void heapSort(int arr[], int size, bool ascending){
	/*
		space complexity = O(1)
		time complexity = O(n log(n))
	*/
	buildHeap(arr, size, ascending);
	for(int i = size - 1; i > 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, ascending);
	}
}
};

