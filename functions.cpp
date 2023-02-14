#include <string>
#include <iostream>
#include "functions.h"

using namespace std;

//Linear Search Function
int lsearch(int number, int* arr, int arr_size){
    //Iterate through entire array
    for(int i = 0; i < arr_size; i++){
        //Return first index that given number occurs
        if(arr[i] == number)
            return i;
    }
    //Given number never occurs within the array
    return -1;
}

//Edit Value at given Index function
int modify(int new_number, int index, int* arr, int arr_size){
    int old_number;
    try{
        //Save value of previous number
        old_number = arr[index];
        //Set value at given index to value of given number
        arr[index] = new_number;
    }
    //Given index is out of bounds of the array
    catch(out_of_range e){
        cout << e.what() << endl;
        return -1;
    }
    //return value of number that was modified
    return old_number;
}

//Push new value to end of array
void addNumber(int number, int*& arr, int& arr_size){
    //create new array pointer that is 1 larger than the given array
    int* newArr = new int[arr_size + 1];

    //iterate through old array
    int i;
    for(i = 0; i < arr_size; ++i){
        //duplicate values leading up to end of the old array
        newArr[i] = arr[i];
    }
        //set value at the end of the new array to the given number
        newArr[arr_size] = number;

    //delete previous array data
    delete [] arr;

    //point to the new array
    arr = newArr;

    //set the temp array to a nullpointer
    newArr = nullptr;

    //increase size of the current array
    arr_size++;
}

//Remove value at given index
void removeNumber(int index, int*& arr, int& arr_size){
    //create new array pointer that is 1 smaller than the given array
    int* newArr = new int[arr_size - 1];
    int i = 0, k = 0;
    //iterate through the old array
    while(i < arr_size){
        //Duplicate values and increment new array only when i is not the same value as the index to be removed
        if(i != index){
            newArr[k] = arr[i];
            k++;
        }
        //increment through old array
        i++;
    }

    //delete old array data
    delete [] arr;
    //point to new array
    arr = newArr;
    //set temp pointer to nullpointer
    newArr = nullptr;
    //decrement size of current array
    arr_size--;
} 

//Output current state of array
void printArray(int* arr, int arr_size){

    //Increment through every element in array
    for(int i = 0; i < arr_size; i++){
        //print value at index i
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool menu(int* array, int arr_size){
    bool cont = true;
    char menuInput;
    int valueInput1, valueInput2, numIndex;
    while(cont){
        
        cout << "Choose a matching letter to select an option " << endl
             << "A.) Search for a number within the array" << endl
             << "B.) Modify an index within the array" << endl
             << "C.) Add a number to the end of the array" << endl
             << "D.) Remove a number at an index from the array" << endl
             << "E.) Print the current state of the array" << endl
             << "Q.) Quit the program" << endl << endl;

             cin >> menuInput;
             menuInput = toupper(menuInput);

             switch(menuInput){
                case 'A':
                    cout << "What number would you like to find?" << endl;
                    cin >> valueInput1;
                    numIndex = lsearch(valueInput1, array, arr_size);
                    (numIndex < 0) ? cout << "That number is not found within the array." << endl : cout << valueInput1 << " found at index " << numIndex << endl;
                    printArray(array, arr_size);
                    break;

                case 'B':
                    cout << "Which index would you like to edit?" << endl;
                    cin >> valueInput1;

                    cout << "What number would you like to change this to?" << endl;
                    cin >> valueInput2;

                    cout << "Changing value at index " << valueInput1 << " to " << valueInput2 << endl;
                    modify(valueInput2, valueInput1, array, arr_size);
                    printArray(array, arr_size);
                    break;

                case 'C':
                    cout << "What value would you like to add to the end of the array?" << endl;
                    cin >> valueInput1;

                    addNumber(valueInput1, array, arr_size);
                    cout << "Adding value " << valueInput1 << " to end of array" << endl;
                    break;

                case 'D':
                    cout << "Which index would you like to remove?" << endl;
                    cin >> valueInput1;

                    removeNumber(valueInput1, array, arr_size);
                    printArray(array, arr_size);
                    break;

                case 'E':
                    printArray(array, arr_size);
                    break;

                case 'Q':
                    cont = false;
                    break;

                default:
                    cout << "Invalid option selected. Try again." << endl;
                }
    }
    return false;
}