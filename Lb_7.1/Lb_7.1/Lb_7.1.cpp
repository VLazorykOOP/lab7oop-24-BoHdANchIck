#include <iostream>
#include <cstring> 

using namespace std;
//
//#1
template <typename T>
T MaxE(T arr[], int size) {
    T maxElement = arr[0]; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}

template <>
char* MaxE(char* arr[], int size) {
    char* maxLengthStr = arr[0]; 
    for (int i = 1; i < size; ++i) {
        if (strlen(arr[i]) > strlen(maxLengthStr)) {
            maxLengthStr = arr[i];
        }
    }

    return maxLengthStr;
}


//
// #2
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <>
void selectionSort(char* arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        char* temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

template <>
void printArray(char* arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int intArr[] = { 5, 10, 3, 8, 1 };
    double doubleArr[] = { 2.5, 4.7, 3.2, 6.1, 1.9 };
    char* strArr[] = { (char*)"apple", (char*)"banana", (char*)"orange", (char*)"grape", (char*)"pineapple" };

    cout << "Max element in intArr: " << MaxE(intArr, 5) << endl;
    cout << "Max element in doubleArr: " << MaxE(doubleArr, 5) << endl;
    cout << "Longest string in strArr: " << MaxE(strArr, 5) << endl;

    int intArr2[] = { 5, 2, 8, 1, 9 };
    double doubleArr2[] = { 3.5, 1.2, 4.8, 2.1, 5.9 };
    char* strArr2[] = { (char*)"orange", (char*)"banana", (char*)"apple", (char*)"grape", (char*)"pineapple" };

    selectionSort(intArr2, 5);
    selectionSort(doubleArr2, 5);
    selectionSort(strArr2, 5);

    cout << "Sorted intArr2: ";
    printArray(intArr2, 5);
    cout << "Sorted doubleArr2: ";
    printArray(doubleArr2, 5);
    cout << "Sorted strArr2: ";
    printArray(strArr2, 5);

    return 0;
}
