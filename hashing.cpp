#include <iostream>

class SortingService {
public:
	
static void bubbleSort(int arr[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Selection Sort
    static void selectionSort(int arr[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                std::swap(arr[i], arr[min_index]);
            }
        }
    }

    // Insertion Sort
    static void insertionSort(int arr[], int size) {
        for (int i = 1; i < size; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // New function: User-defined Sorting Algorithm
    static void sortArray(int arr[], int size, int choice) {
        switch (choice) {
            case 1:
                bubbleSort(arr, size);
                break;
            case 2:
                selectionSort(arr, size);
                break;
            case 3:
                insertionSort(arr, size);
                break;
            default:
                std::cout << "Invalid choice. Using Bubble Sort by default." << std::endl;
                bubbleSort(arr, size);
        }
    }
};

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int choice;
    std::cout << "Choose a sorting algorithm:" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;
    std::cout << "3. Insertion Sort" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Sorting the array using the user's chosen sorting algorithm
    SortingService::sortArray(arr, size, choice);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
