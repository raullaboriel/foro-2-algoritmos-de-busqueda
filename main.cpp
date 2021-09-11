#include <iostream>
#include <cmath>

using namespace std;

int linearSearch(int list[], int start, int bounds, int key);
int binarySearch(int array[], int x, int low, int high);
int jumpSearch(int arr[], int x, int n);
int interpolationSearch(int arr[], int n, int x);

int main(void){
	return 0;
}

//Algoritmo de busqueda lineal
int linearSearch(int list[], int start, int bounds, int key){
    while(start < bounds){
        if(list[start]==key){
            return start;
        } else {
            start++;
        }        
    }
    //no match found
    return -1;
}

//Algorimo de busqueda binaria (para arreglos ordenados)
int binarySearch(int array[], int x, int low, int high) {
  
	// Repetir hasta que los punteros low y high se encuentren.
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

//Algoritmo de busqueda por salto (para arreglos ordenados)
int jumpSearch(int arr[], int x, int n){
	// Finding block size to be jumped
	int step = sqrt(n);

	// Finding the block where element is
	// present (if it is present)
	int prev = 0;
	while (arr[min(step, n)-1] < x){
		prev = step;
		step += sqrt(n);
		if (prev >= n)
				return -1;
	}

	// Doing a linear search for x in block
	// beginning with prev.
	while (arr[prev] < x){
		prev++;
		// If we reached next block or end of
		// array, element is not present.
		if (prev == min(step, n))
			return -1;
	}
	// If element is found
	if (arr[prev] == x)
		return prev;

	return -1;
}

//Algoritmo de busqueda por interpolacion (para arreglos ordenados y uniformes)
int interpolationSearch(int arr[], int n, int x){
	// Find indexes of two corners
	int lo = 0, hi = (n - 1);
	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x) return lo;
			return -1;
		}
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = lo + (((double)(hi - lo) /
			(arr[hi] - arr[lo])) * (x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in upper part
		if (arr[pos] < x)
			lo = pos + 1;

		// If x is smaller, x is in the lower part
		else
			hi = pos - 1;
	}
	return -1;
}