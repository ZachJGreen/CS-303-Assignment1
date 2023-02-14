#include <string>

int lsearch(int number, int* arr, int arr_size);
int modify(int new_number, int index, int* arr, int arr_size);
void addNumber(int number, int*& arr, int& arr_size);
void removeNumber(int index, int*& arr, int& arr_size);
void printArray(int* arr, int arr_size);
bool menu(int* arr, int arr_size);