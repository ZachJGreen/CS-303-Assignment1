// int lsearch(int number, int arr[]);
// int modify(int new_number, int index, int arr[]);
// void addNumber(int number, int arr[], int newArr[]);
// int removeNumber(int index, int arr[]);

// void readData(string fileName, int arr[])
#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;
int main(){

    ifstream fin;
    fin.open("integers.txt");

    int x, arr_size = 0;
    int* array = new int[arr_size], * temp_array;
    if(!fin.is_open()){
        cout << "File not Found.";
        return -1;
    }

    while(fin.good()){
        try{
            fin >> x;

            arr_size++;
            
            temp_array = new int[arr_size];
            for(int i = 0; i < arr_size - 1; ++i){
                temp_array[i] = array[i];
            }
            temp_array[arr_size - 1] = x;
            delete [] array;

            array = temp_array;

        }
        catch(invalid_argument &e){
            cout << "value at " << arr_size << " is not an int." << endl;
        }
    }

    while(menu(array, arr_size));

}