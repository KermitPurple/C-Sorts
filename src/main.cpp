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

int main(){
    const int SIZE = 8;
    int arr[SIZE] = {10, 5, 3, 8, 9, 4, 11, 6};
    print_arr(arr, SIZE);
    // bubblesort(arr, SIZE); // works
    selectionsort(arr, SIZE);
    print_arr(arr, SIZE);
    return 0;
}
