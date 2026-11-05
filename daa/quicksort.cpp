
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// ---------------- DETERMINISTIC QUICK SORT ----------------

// Partition using last element as pivot
int partition(vector<int>& arr, int low, int high,
              long long& comparisons, long long& swaps) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        comparisons++;

        if (arr[j] < pivot) {
            i++;

            if (i != j) {
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
    }

    if (i + 1 != high) {
        swap(arr[i + 1], arr[high]);
        swaps++;
    }

    return i + 1;
}

// Deterministic Quick Sort
void quickSort(vector<int>& arr, int low, int high,
               long long& comparisons, long long& swaps) {

    if (low < high) {

        int pi = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pi - 1, comparisons, swaps);

        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

// ---------------- RANDOMIZED QUICK SORT ----------------

// Randomized partition
int randomizedPartition(vector<int>& arr, int low, int high,
                        long long& comparisons, long long& swaps) {

    int randomIndex = low + rand() % (high - low + 1);

    if (randomIndex != high) {
        swap(arr[randomIndex], arr[high]);
        swaps++;
    }

    return partition(arr, low, high, comparisons, swaps);
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high,
                         long long& comparisons, long long& swaps) {

    if (low < high) {

        int pi = randomizedPartition(
            arr, low, high, comparisons, swaps
        );

        randomizedQuickSort(arr, low, pi - 1, comparisons, swaps);

        randomizedQuickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

// ---------------- PRINT ARRAY ----------------

void printArray(const vector<int>& arr) {

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;
}

// ---------------- MAIN FUNCTION ----------------

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create separate copies
    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    // Initialize random seed
    srand(time(0));

    // Counters
    long long comparisonsDet = 0, swapsDet = 0;
    long long comparisonsRand = 0, swapsRand = 0;

    // -------- DETERMINISTIC QUICK SORT --------

    quickSort(arr1, 0, n - 1, comparisonsDet, swapsDet);

    cout << "\nDeterministic Quick Sort:" << endl;

    printArray(arr1);

    cout << "Comparisons: " << comparisonsDet << endl;
    cout << "Swaps: " << swapsDet << endl;

    // -------- RANDOMIZED QUICK SORT --------

    randomizedQuickSort(arr2, 0, n - 1, comparisonsRand, swapsRand);

    cout << "\nRandomized Quick Sort:" << endl;

    printArray(arr2);

    cout << "Comparisons: " << comparisonsRand << endl;
    cout << "Swaps: " << swapsRand << endl;

    return 0;
}



























// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include <iostream>
// #include <vector>

// using namespace std;

// // Common Partition Function
// int partition(vector<int>& arr, int low, int high,
//               int& comparisons, int& swaps, bool randomized) {

//     int pivotIndex = low;

//     // Select pivot
//     if (randomized) {
//         pivotIndex = low + rand() % (high - low + 1);
//     }

//     // Move selected pivot to the first position
//     if (pivotIndex != low) {
//         swap(arr[low], arr[pivotIndex]);
//         swaps++;
//     }

//     int pivot = arr[low];
//     int left = low + 1;
//     int right = high;

//     while (true) {

//         while (left <= right) {
//             comparisons++;

//             if (arr[left] <= pivot)
//                 left++;
//             else
//                 break;
//         }

//         while (left <= right) {
//             comparisons++;

//             if (arr[right] >= pivot)
//                 right--;
//             else
//                 break;
//         }

//         if (left > right)
//             break;

//         swap(arr[left], arr[right]);
//         swaps++;
//     }

//     // Place pivot in its correct position
//     if (low != right) {
//         swap(arr[low], arr[right]);
//         swaps++;
//     }

//     return right;
// }

// // Common Quick Sort Function
// void quickSort(vector<int>& arr, int low, int high,
//                int& comparisons, int& swaps, bool randomized) {

//     if (low < high) {

//         int pivotIndex = partition(
//             arr, low, high, comparisons, swaps, randomized
//         );

//         quickSort(arr, low, pivotIndex - 1,
//                   comparisons, swaps, randomized);

//         quickSort(arr, pivotIndex + 1, high,
//                   comparisons, swaps, randomized);
//     }
// }

// // Deterministic Quick Sort
// void deterministicQuickSort(vector<int>& arr, int low, int high,
//                             int& comparisons, int& swaps) {

//     quickSort(arr, low, high, comparisons, swaps, false);
// }

// // Randomized Quick Sort
// void randomizedQuickSort(vector<int>& arr, int low, int high,
//                          int& comparisons, int& swaps) {

//     quickSort(arr, low, high, comparisons, swaps, true);
// }

// // Function to print the array
// void printArray(const vector<int>& arr) {

//     for (int num : arr) {
//         cout << num << " ";
//     }

//     cout << endl;
// }

// int main() {

//     srand(time(0));

//     int n;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     if (n <= 0) {
//         cout << "Invalid number of elements." << endl;
//         return 0;
//     }

//     vector<int> original(n);

//     cout << "Enter elements: " << endl;

//     for (int i = 0; i < n; i++) {
//         cin >> original[i];
//     }

//     int ch;

//     while (true) {

//         int comparisonsDet = 0, swapsDet = 0;
//         int comparisonsRand = 0, swapsRand = 0;

//         cout << "\n1. Deterministic Quick Sort";
//         cout << "\n2. Randomized Quick Sort";
//         cout << "\n3. Exit";
//         cout << "\nEnter your choice: ";

//         cin >> ch;

//         switch (ch) {

//         case 1: {
//             vector<int> arr = original;

//             cout << "\nOriginal array for deterministic quick sort:\n";
//             printArray(arr);

//             deterministicQuickSort(
//                 arr, 0, n - 1, comparisonsDet, swapsDet
//             );

//             cout << "Sorted array (Deterministic):\n";
//             printArray(arr);

//             cout << "Deterministic Quick Sort Comparisons: "
//                  << comparisonsDet << endl;

//             cout << "Deterministic Quick Sort Swaps: "
//                  << swapsDet << endl;

//             break;
//         }

//         case 2: {
//             vector<int> arr = original;

//             cout << "\nOriginal array for randomized quick sort:\n";
//             printArray(arr);

//             randomizedQuickSort(
//                 arr, 0, n - 1, comparisonsRand, swapsRand
//             );

//             cout << "Sorted array (Randomized):\n";
//             printArray(arr);

//             cout << "Randomized Quick Sort Comparisons: "
//                  << comparisonsRand << endl;

//             cout << "Randomized Quick Sort Swaps: "
//                  << swapsRand << endl;

//             break;
//         }

//         case 3:
//             return 0;

//         default:
//             cout << "Invalid choice. Try again." << endl;
//         }
//     }

//     return 0;
// }



























// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to perform deterministic Quick Sort
// int deterministicPartition(vector<int> &arr, int low, int high,
//                            int &comparisons, int &swaps) {
//     int pivot = arr[low]; // Pivot is the first element
//     int left = low + 1;
//     int right = high;

//     while (true) {
//         while (left <= right) {
//             comparisons++; // Count an element-to-pivot comparison
//             if (arr[left] <= pivot)
//                 left++;
//             else
//                 break;
//         }

//         while (left <= right) {
//             comparisons++; // Count an element-to-pivot comparison
//             if (arr[right] >= pivot)
//                 right--;
//             else
//                 break;
//         }

//         if (left > right) {
//             break;
//         }

//         swap(arr[left], arr[right]);
//         swaps++;
//     }

//     if (low != right) {
//         swap(arr[low], arr[right]);
//         swaps++;
//     }
//     return right;
// }

// void deterministicQuickSort(vector<int> &arr, int low, int high,
//                             int &comparisons, int &swaps) {
//     if (low < high) {
//         int pivotIndex = deterministicPartition(arr, low, high, comparisons, swaps);

//         deterministicQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
//         deterministicQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
//     }
// }

// // Function to perform randomized Quick Sort
// int randomizedPartition(vector<int> &arr, int low, int high,
//                         int &comparisons, int &swaps) {
//     int pivotIndex = low + rand() % (high - low + 1);
//     if (pivotIndex != low) {
//         swap(arr[low], arr[pivotIndex]); // Swap pivot with the first element
//         swaps++;
//     }

//     int pivot = arr[low];
//     int left = low + 1;
//     int right = high;

//     while (true) {
//         while (left <= right) {
//             comparisons++; // Count an element-to-pivot comparison
//             if (arr[left] <= pivot)
//                 left++;
//             else
//                 break;
//         }

//         while (left <= right) {
//             comparisons++; // Count an element-to-pivot comparison
//             if (arr[right] >= pivot)
//                 right--;
//             else
//                 break;
//         }

//         if (left > right) {
//             break;
//         }

//         swap(arr[left], arr[right]);
//         swaps++;
//     }

//     if (low != right) {
//         swap(arr[low], arr[right]);
//         swaps++;
//     }
//     return right;
// }

// void randomizedQuickSort(vector<int> &arr, int low, int high,
//                          int &comparisons, int &swaps) {
//     if (low < high) {
//         int pivotIndex = randomizedPartition(arr, low, high, comparisons, swaps);

//         randomizedQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
//         randomizedQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
//     }
// }

// // Function to print the array
// void printArray(const vector<int> &arr) {
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// int main() {
//     srand(time(0)); // Seed for random number generation

//     int n;
//     cout << "Enter the number of elements: ";
//     if (!(cin >> n) || n <= 0) {
//         cout << "Invalid number of elements." << endl;
//         return 1;
//     }

//     vector<int> original(n);
//     cout << "Enter elements: \n";
//     for (int i = 0; i < n; i++) {
//         cin >> original[i];
//     }

//     int ch;
//     while (1) {
//         int comparisonsDet = 0, swapsDet = 0;
//         int comparisonsRand = 0, swapsRand = 0;

//         cout << "1.Deterministic Quick Sort\n2.Randomized Quick Sort\n3.Exit\n";
//         cout << "Enter your choice: ";
//         cin >> ch;

//         switch (ch) {
//         case 1: {
//             vector<int> arr1 = original; // Start with the original input every time

//             cout << "Original array for deterministic quick sort:\n";
//             printArray(arr1);

//             deterministicQuickSort(arr1, 0, static_cast<int>(arr1.size()) - 1,
//                                    comparisonsDet, swapsDet);

//             cout << "Sorted array (Deterministic):\n";
//             printArray(arr1);
//             cout << "Deterministic Quick Sort Comparisons: " << comparisonsDet << endl;
//             cout << "Deterministic Quick Sort Swaps: " << swapsDet << endl;
//             break;
//         }
//         case 2: {
//             vector<int> arr2 = original; // Start with the original input every time

//             cout << "\nOriginal array for randomized quick sort:\n";
//             printArray(arr2);

//             randomizedQuickSort(arr2, 0, static_cast<int>(arr2.size()) - 1,
//                                 comparisonsRand, swapsRand);

//             cout << "Sorted array (Randomized):\n";
//             printArray(arr2);
//             cout << "Randomized Quick Sort Comparisons: " << comparisonsRand << endl;
//             cout << "Randomized Quick Sort Swaps: " << swapsRand << endl;
//             break;
//         }
//         case 3:
//             return 0;
//         default:
//             cout << "Invalid choice. Try again.\n";
//         }
//     }

//     return 0;
// }
