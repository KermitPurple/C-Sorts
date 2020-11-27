#include<functional>
#include<iostream>
#include<time.h>

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

template<class T, class Compare = std::less<T>>
void bubblesort(T* arr, const int& size){ // sort using bubble method
    for(int i = size; i >= 1; i--) // cycle through indicies starting at size and ending at 1
        for(int j = 1; j < i; j++) // cylce through indicies starting at 1 and ending at i
            if(Compare()(arr[j], arr[j - 1])) // if the previous element is greather than the current
                swap(arr[j - 1], arr[j]); // swap them
}

template<class T, class Compare = std::less<T>>
void selectionsort(T* arr, const int& size){ // sort using selection method
    for(int i = 0; i < size; i++){ // cycle through indicies
        int smallest_largest_index = i; // smallest/largest index starts at current index
        for(int j = i + 1; j < size; j++) // cycle through indicies starting at 1 after i
            if(Compare()(arr[j],arr[smallest_largest_index])) // if the current index does not represent the smallest/largest value
                smallest_largest_index = j; // change smallest index to current
        swap(arr[smallest_largest_index], arr[i]); // swap the i with the smallest value
    }
}

template<class T, class Compare = std::less<T>>
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
            if(Compare()(left[li], right[ri])) // if first item in left list is greater than first item in right list
                arr[i] = left[li++]; // copy item into main array and increment index
            else // left is greater than or equal to right
                arr[i] = right[ri++]; // copy item into main array and increment index
        }
    }
    delete[] left; // delete values in left array
    delete[] right; // delete values in right array
}

template<class T, class Compare = std::less<T>>
void mergesort(T* arr, const int& start, const int& end){ // sort using mergesort method
    if((end - start) <= 1) return; // if the size is less than or equal to 1, the list is sorted so exit
    int middle = (end + start) / 2; // the first index of the 'right' half
    mergesort<T, Compare>(arr, start, middle); // call merge sort on left half of list
    mergesort<T, Compare>(arr, middle, end); // call merge sort on right half of list
    merge<T, Compare>(arr, start, middle, end); // merge the two sorted sublists into a sorted list
}

template<class T, class Compare = std::less<T>>
void mergesort(T* arr, const int& size){ // use size instead of start and end
    mergesort<T, Compare>(arr, 0, size); // call start and end merge sort
}

template<class T, class Compare = std::less<T>>
void insertionsort(T* arr, const int& size){ // sort using insertion method
    for(int i = 0; i < size; i++) // cycle through list
        for(int j = i; j > 0; j--) // cycle through starting at i and going backwords
            if(Compare()(arr[j], arr[j - 1])) // if the current is bigger than the previous
                swap(arr[j], arr[j - 1]); // swap them
}

void randomize_arr(int* arr, const int& size){ // randomize array
    for(int i = 0; i < size; i++) // cycle through array
        arr[i] = rand() % 100; // set current element in array to a random number between 0 and 99
}

void display_sort_test(int* arr, const int& size, const char* sort_name, void(*custom_sort)(int*, const int&)){
    randomize_arr(arr, size); // randomize array
    std::cout << sort_name << " Sort:\n\tBefore sort: ";
    print_arr(arr, size); // print array
    custom_sort(arr, size); // works
    std::cout << "\tAfter sort: ";
    print_arr(arr, size); // print array
}

int main(){
    srand(time(NULL)); // get random seed for rand function
    const int SIZE = 20; // size of array
    int arr[SIZE]; // create array

    display_sort_test(arr, SIZE, "Bubble", bubblesort);

    randomize_arr(arr, SIZE); // randomize array
    std::cout <<"Selection Sort:\n\tBefore sort: ";
    print_arr(arr, SIZE); // print array
    selectionsort(arr, SIZE); // works
    std::cout << "\tAfter sort: ";
    print_arr(arr, SIZE); // print array

    randomize_arr(arr, SIZE); // randomize array
    std::cout <<"Merge Sort:\n\tBefore sort: ";
    print_arr(arr, SIZE); // print array
    mergesort(arr, 0, SIZE); // works
    std::cout << "\tAfter sort: ";
    print_arr(arr, SIZE); // print array

    randomize_arr(arr, SIZE); // randomize array
    std::cout <<"Insertion Sort:\n\tBefore sort: ";
    print_arr(arr, SIZE); // print array
    insertionsort(arr, SIZE); // works
    std::cout << "\tAfter sort: ";
    print_arr(arr, SIZE); // print array
    return 0;
}
