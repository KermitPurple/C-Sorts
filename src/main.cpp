#include<iostream>

template<class T>
void print_arr(T* arr, const int& size){
    std::cout << *arr;
    for(int i = 1; i < size; i++)
        std::cout << ", " << arr[i];
    std::cout << std::endl;
}

template<class T>
void swap(T& x, T& y){
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
void merge(T* arr, const int& start, const int& middle, const int& end){
    T* left = new T[middle - start];
    for(int i = start; i < middle; i++){
        left[i - start] = arr[i];
    }
    T* right = new T[end - middle];
    for(int i = middle; i < end; i++){
        right[i - middle] = arr[i];
    }
    int li = 0; // left index
    int ri = 0; // right index
    for(int i = start; i < end; i++){
        if(li < middle - start && ri >= end - middle) // if only items are in the left
            arr[i] = left[li++];
        else if(ri < end - middle && li >= middle - start) // if only items are in the right
            arr[i] = right[ri++];
        else if(li < middle - start && ri < end - middle){ // if items are in right and left
            if(left[li] < right[ri])
                arr[i] = left[li++];
            else
                arr[i] = right[ri++];
        }
    }
    delete[] left;
    delete[] right;
}

template<class T>
void mergesort(T* arr, const int& start, const int& end){
    if((end - start) <= 1) return;
    int middle = (end + start) / 2;
    mergesort(arr, start, middle);
    mergesort(arr, middle, end);
    merge(arr, start, middle, end);
}

int main(){

    const int SIZE = 8;
    int arr[SIZE] = {10, 5, 3, 8, 9, 4, 11, 6};
    print_arr(arr, SIZE);
    // bubblesort(arr, SIZE); // works
    // selectionsort(arr, SIZE); // works
    mergesort(arr, 0, SIZE); // works
    print_arr(arr, SIZE);

    return 0;
}
