#include<iostream>

template<class T>
void print_arr(T* arr, const int& size){ // print an array
    std::cout << *arr; // print the first element
    for(int i = 1; i < size; i++) // cycle through array starting at 1
        std::cout << ", " << arr[i]; // print comment and then an element
    std::cout << std::endl; // print newline
}

template<class T>
void swap(T& x, T& y){ // swap two values
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
void bubblesort(T* arr, const int& size){
    for(int i = size; i >= 1; i--)
        for(int j = 1; j < i; j++)
            if(arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}

template<class T>
void selectionsort(T* arr, const int& size){
    for(int i = 0; i < size; i++){
        int smallest_index = i;
        for(int j = i + 1; j < size; j++)
            if(arr[j] < arr[smallest_index])
                smallest_index = j;
        swap(arr[smallest_index], arr[i]);
    }
}

template<class T>
void merge(T* arr, const int& start, const int& middle, const int& end){ // merge two sorted lists into one sorted list
    T* left = new T[middle - start]; // create the left array
    for(int i = start; i < middle; i++) // copy the left half of the values into the left array
        left[i - start] = arr[i];
    T* right = new T[end - middle]; // create the right array
    for(int i = middle; i < end; i++) // copy the right half of the values into the right array
        right[i - middle] = arr[i];
    int li = 0; // left index
    int ri = 0; // right index
    for(int i = start; i < end; i++){ // cycle through indicies in the main array
        if(li < middle - start && ri >= end - middle) // if only items are in the left
            arr[i] = left[li++]; // copy item into main array and increment index
        else if(ri < end - middle && li >= middle - start) // if only items are in the right
            arr[i] = right[ri++]; // copy item into main array and increment index
        else if(li < middle - start && ri < end - middle){ // if items are in right and left
            if(left[li] < right[ri]) // if first item in left list is greather than first item in right list
                arr[i] = left[li++]; // copy item into main array and increment index
            else // left is greater than or equal to right
                arr[i] = right[ri++]; // copy item into main array and increment index
        }
    }
    delete[] left; // delete values in left array
    delete[] right; // delete values in right array
}

template<class T>
void mergesort(T* arr, const int& start, const int& end){ // sort using mergesort method
    if((end - start) <= 1) return; // if the size is less than or equal to 1, the list is sorted so exit
    int middle = (end + start) / 2; // the first index of the 'right' half
    mergesort(arr, start, middle); // call merge sort on left half of list
    mergesort(arr, middle, end); // call merge sort on right half of list
    merge(arr, start, middle, end); // merge the two sorted sublists into a sorted list
}

int main(){

    const int SIZE = 9;
    int arr[SIZE] = {10, 5, 3, 8, 9, 4, 11, 6, -1};
    print_arr(arr, SIZE);
    // bubblesort(arr, SIZE); // works
    // selectionsort(arr, SIZE); // works
    mergesort(arr, 0, SIZE); // works
    print_arr(arr, SIZE);

    return 0;
}
