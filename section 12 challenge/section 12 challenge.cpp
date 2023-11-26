#include <iostream>
using namespace std;

void print(const int* arr1, size_t size);
//void print(const int*, size_t);
int* apply_all(const int* const arr1, const size_t size_arr1, const int* const arr2, const size_t size_arr2);

int main() {
    const size_t array1_size{ 5 };
    const size_t array2_size{ 3 };

    int array1[]{ 1,2,3,4,5 };
    int array2[]{ 10,20,30 };

    cout << "Array 1: ";
    print(array1, array1_size);
    cout << endl;

    cout << "Array 2: ";
    print(array2, array2_size);
    cout << endl;

    int* results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{ array1_size * array2_size };

    cout << "Result: ";
    print(results, results_size);

    cout << endl;
    delete[] results;
    return 0;
}

void print(const int* arr1, size_t size) {
    cout << "[ ";
    for (size_t i{}; i < size; i++)
        cout << arr1[i] << " ";
    cout << "]";
}

int* apply_all(const int* const arr1, const size_t size_arr1,const int* const arr2, const size_t size_arr2) {
    size_t result_size{ size_arr1 * size_arr2 };
    int* result = new int[result_size];
    size_t position{};

    for (size_t i{}; i < size_arr2; i++) {
        for (size_t k{}; k < size_arr1; k++) {
            result[position] = arr2[i] * arr1[k];
            position++;
        }
    }
    return result;
}