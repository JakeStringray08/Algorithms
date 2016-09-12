#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void printArray(T array[], int arraySize);

class Sortings {
	public:
		template<typename T>
		void bubbleSort(T array[], int arraySize) {
			bool swapped = true;
			int j = 0;
			while(swapped) {
				swapped = false;
				j++;
				for(int i = 0; i < arraySize-j; i++) {
					if (array[i] > array[i+1]) {
						swap(array[i], array[i+1]);
						swapped = true;
					}
				}
			}
		}
		
		template<typename T>
		void insertionSort(T array[], int arraySize) {
			T insert; 
			int pos;
			for (int next = 1; next < arraySize; next++) {
				insert = array[next];
				pos = next;
				while (pos > 0 && array[pos-1] > insert) {
					array[pos] = array[pos-1];
					pos--;
				}
				array[pos] = insert;
			}
		}
		
		template<typename T>
		void selectionSort(T array[], int arraySize) {
			for(int i = 0; i < arraySize-1; i++) {
				swap(array[i], array[minimum(array, i, arraySize)]);
			}
		}
		
	private:
		template<typename T>
		int minimum(T array[], int start, int stop) {
			int m = start;
			for (int i = start; i < stop; i++) {
				if (array[i] < array[m]) {
					m = i;
				}
			}
			return m;
		}
};

template<typename T>
void printArray(T array[], int arraySize) {
	cout << "\n";
	for (int i = 0; i < arraySize; i++) {
		cout << setw(3) << array[i];
	}
	cout << "\n" << endl;
}

int main(int argc, char** argv) {
	srand(time(0));
	const int arraySize = 10;
	int arr[arraySize];
	Sortings sort;
	
	for (int i = 0; i < arraySize; i++) {
		arr[i] = 1 + rand() % 9;
	}
	
	cout << "Initial array: " << endl;
	printArray(arr, arraySize);
	
	sort.selectionSort(arr, arraySize);
	
	cout << "Sorted array: " << endl;
	printArray(arr, arraySize);
	

	return 0;
}
