/**
 * file: sort_compare.cpp
 * type: plain-text
 * date: 03_JUNE_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output, file open, file close
#include <stdio.h> // NULL macro
#include <stdlib.h> // srand(), rand()
#include <time.h> // time() 
#include <chrono> // for calculating sorting algorithm runtimes
#define MAXIMUM_S 1000 // constant which represents the maximum value for S
#define MAXIMUM_T 1000 // constant which represents the maximum value for T

/** function prototypes */
void copy_array(int * source_array, int * target_array, int S);
void populate_array(int * A, int S, int T);
void bubble_sort(int * A, int S);
void merge_sort(int * A, int S);
void merge_sort(int * A, int left, int right);
void merge(int * A, int left, int mid, int right);

/** program entry point */
int main()
{
    /***********************************************************************************
     * INITIALIZE VARIABLES
     ***********************************************************************************/

    // Declare three int type variables and set each of their initial values to 0.
    int S = 0, T = 0, i = 0;

    // Declare two pointer-to-int type variables.
    int * A, * A_copy_0;

    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If the file named sort_compare_output.txt does not already exist 
     * inside of the same file directory as the file named arrays.cpp, 
     * create a new file named arrays_output.txt in that directory.
     * 
     * Open the plain-text file named sort_compare_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("sort_compare_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    /***********************************************************************************
     * SET S
     ***********************************************************************************/

    // Prompt the user to enter an input value for S.
    std::cout << "\n\nEnter a natural number value to store in the value S which is no larger than " << MAXIMUM_S << ": ";
    file << "\n\nEnter a natural number value to store in the value S which is no larger than " << MAXIMUM_S << ": ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in S.
    std::cin >> S;

    // Print "The value which was entered for S is {S}." to the command line terminal.
    std::cout << "\nThe value which was entered for S is " << S << ".";

    // Print "The value which was entered for S is {S}." to the file output stream.
    file << "\n\nThe value which was entered for S is " << S << ".";

    // If S is smaller than 1 or if S is larger than MAXIMUM_S, set S to 10.
    S = ((S < 1) || (S > MAXIMUM_S)) ? 10 : S; 

    // Print "S := {S}. // number of consecutive int-sized chunks of memory to allocate to a one-dimensional array of S integers named A." to the command line terminal.
    std::cout << "\n\nS := " << S << ". // number of consecutive int-sized chunks of memory to allocate to a one-dimensional array of S integers named A.";

    // Print "S := {S}. // number of consecutive int-sized chunks of memory to allocate to a one-dimensional array of S integers named A." to the file output stream.
    file << "\n\nS := " << S << ". // number of consecutive int-sized chunks of memory to allocate to a one-dimensional array of S integers named A.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the file output stream.
    file << "\n\n--------------------------------";

    /***********************************************************************************
     * SET T
     ***********************************************************************************/

    // Prompt the user to enter an input value for T.
    std::cout << "\n\nEnter a natural number value to store in the value T which is no larger than " << MAXIMUM_T << ": ";
    file << "\n\nEnter a natural number value to store in the value T which is no larger than " << MAXIMUM_T << ": ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in T.
    std::cin >> T;

    // Print "The value which was entered for T is {T}." to the command line terminal.
    std::cout << "\nThe value which was entered for T is " << S << ".";

    // Print "The value which was entered for T is {T}." to the file output stream.
    file << "\n\nThe value which was entered for T is " << T << ".";

    // If S is smaller than 1 or if S is larger than MAXIMUM_S, set S to 10.
    T = ((T < 1) || (T > MAXIMUM_T)) ? 10 : T; 

    // Print "T := {T}. // number of unique states each element of A can represent exactly one of." to the command line terminal.
    std::cout << "\n\nT := " << T << ". // number of unique states each element of A can represent exactly one of.";

    // Print "T := {T}. // number of unique states each element of A can represent exactly one of." to the file output stream.
    file << "\n\nT := " << T << ". // number of unique states each element of A can represent exactly one of.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the file output stream.
    file << "\n\n--------------------------------";

    /***********************************************************************************
     * GENERATE ARRAYS
     ***********************************************************************************/

    // Print "UNSORTED ARRAY A" to the command line terminal.
    std::cout << "\n\nUNSORTED ARRAY A";

    // Print "UNSORTED ARRAY A" to the file outpur stream.
    file << "\n\nUNSORTED ARRAY A";

    /**
     * Allocate S contiguous int-sized chunks of memory 
     * and store the memory address of the first int-sized chunk 
     * of memory, A[0]. inside the pointer-to-int type variable named A.
     * 
     * A is a dynamically-allocated array (which means that the array size 
     * was determined during progam runtime instead of during program 
     * compile time).
     */
    A = new int [S];
    A_copy_0 = new int [S];

    // Populate A with random integer values.
    populate_array(A,S,T);

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA := " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA := " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] := " << A[i] << ". \t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
        file << "\nA[" << i << "] := " << A[i] << ". \t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the file output stream.
    file << "\n\n--------------------------------";

    // Populate A_copy_0 with the values of A such that both arrays appear to house identical data contents.
    copy_array(A,A_copy_0,S);

    // Print "UNSORTED ARRAY A_copy_0" to the command line terminal.
    std::cout << "\n\nUNSORTED ARRAY A_copy_0";

    // Print "UNSORTED ARRAY A_copy_0" to the file output stream.
    file << "\n\nUNSORTED ARRAY A_copy_0";

    // Print the contents of A_copy_0 to the command line terminal.
    std::cout << "\n\nA_copy_0 := " << A_copy_0 << ". // memory address of A_copy_0[0]\n";

    // Print the contents of A_copy_0 to the file output stream.
    file << "\n\nA_copy_0 := " << A_copy_0 << ". // memory address of A_copy_0[0]\n";

    /**
     * For each element, i, of the array represented by A_copy_0, 
     * print the contents of the ith element of the array, A_copy_0[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA_copy_0[" << i << "] := " << A_copy_0[i] << ". \t// &A_copy_0[" << i << "] = " << &A_copy_0[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A_copy_0[" << i << "]).";
        file << "\nA_copy_0[" << i << "] := " << A_copy_0[i] << ". \t// &A_copy_0[" << i << "] = " << &A_copy_0[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A_copy_0[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the file output stream.
    file << "\n\n--------------------------------";

    /***********************************************************************************
     * BUBBLE SORT
     ***********************************************************************************/

    // Print "SORTED ARRAY A (USING BUBBLE_SORT)" to the command line terminal.
    std::cout << "\n\nSORTED ARRAY A (USING BUBBLE_SORT)";

    // Print "SORTED ARRAY A (USING BUBBLE_SORT)" to the file output stream.
    file << "\n\nSORTED ARRAY A (USING BUBBLE_SORT)";

    // Get the start time.
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the integer values stored in array A to be in ascending order using the Bubble Sort algorithm.
    bubble_sort(A, S);

    // Get the end time.
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration of time betweem start and end time.
    std::chrono::duration<double> duration = end - start;

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA := " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA := " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] := " << A[i] << ". \t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
        file << "\nA[" << i << "] := " << A[i] << ". \t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
    }

    // Print the duration in seconds
    std::cout << "\n\nElapsed time for bubble_sort(A, S): " << duration.count() << " seconds.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the file output stream.
    file << "\n\n--------------------------------";

    /***********************************************************************************
     * MERGE SORT
     ***********************************************************************************/

    // Print "SORTED ARRAY A_copy_0 (USING MERGE_SORT)" to the command line terminal.
    std::cout << "\n\nSORTED ARRAY A_copy_0 (USING MERGE_SORT)";

    // Print "SORTED ARRAY A_copy_0 (USING MERGE_SORT)" to the file output stream.
    file << "\n\nSORTED ARRAY A_copy_0 (USING MERGE_SORT)";

    // Get the start time.
    start = std::chrono::high_resolution_clock::now();

    // Sort the integer values stored in array A to be in ascending order using the Merge Sort algorithm.
    merge_sort(A_copy_0, S);

    // Get the end time.
    end = std::chrono::high_resolution_clock::now();

    // Calculate the duration of time betweem start and end time.
    duration = end - start;

    // Print the contents of A_copy_0 to the command line terminal.
    std::cout << "\n\nA_copy_0 := " << A_copy_0 << ". // memory address of A_copy_0[0]\n";

    // Print the contents of A_copy_0 to the file output stream.
    file << "\n\nA_copy_0 := " << A_copy_0 << ". // memory address of A_copy_0[0]\n";

    /**
     * For each element, i, of the array represented by A_copy_0, 
     * print the contents of the ith element of the array, A_copy_0[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA_copy_0[" << i << "] := " << A_copy_0[i] << ". \t// &A_copy_0[" << i << "] = " << &A_copy_0[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A_copy_0[" << i << "]).";
        file << "\nA_copy_0[" << i << "] := " << A_copy_0[i] << ". \t// &A_copy_0[" << i << "] = " << &A_copy_0[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A_copy_0[" << i << "]).";
    }

    // Print the duration in seconds
    std::cout << "\n\nElapsed time for merge_sort(A_copy_0, S): " << duration.count() << " seconds.";

    /***********************************************************************************
     * DELETE ARRAYS
     ***********************************************************************************/

    // De-allocate memory which was assigned to the dynamically-allocated array of S int type values named A.
    delete [] A;

    // De-allocate memory which was assigned to the dynamically-allocated array of S int type values named A_copy_0.
    delete [] A_copy_0;

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0; 
} 

/**
 * Copy the elements of source_array into tartet_array such that both arrays 
 * appear to have the same permutation of int type values.
 * 
 * Assume that the value which is passed into this function as source_array 
 * is the memory address of the first element of a one-dimensional 
 * array of exactly S int type values.
 * 
 * Assume that the value which is passed into this function as target_array 
 * is the memory address of the first element of a one-dimensional 
 * array of exactly S int type values.
 * 
 * Assume that the value which is passed into this function as S 
 * is the total number of elements which comprise the array 
 * represented by A.
 * 
 * This function returns no value (but it does update the array 
 * referred to as A if the elements of A are not already sorted in 
 * ascending order).
 */
void copy_array(int * source_array, int * target_array, int S)
{
    for (int i = 0; i < S; i++) target_array[i] = source_array[i];
}

/**
 * Populate an array of int type values with randomized integer values.
 * 
 * Assume that the value which is passed into this function as A 
 * is the memory address of the first element of a one-dimensional 
 * array of int type values.
 * 
 * Assume that the value which is passed into this function as S 
 * is the total number of elements which comprise the array 
 * represented by A.
 * 
 * Assume that the value which is passed into this function as T 
 * is the total number of states which each element of A can be 
 * selected as (and that any element of A is a natural number 
 * no larger than T).
 * 
 * This function returns no value (but it does update the array 
 * referred to as A if the elements of A are not already sorted in 
 * ascending order).
 */
void populate_array(int * A, int S, int T)
{
    /**
     * Seed the pseudo-random number generator with the number of seconds 
     * elapsed since some epoch such as the Unix Epoch (which is 
     * 01_JANUARY_1970).
     */
    srand(time(NULL));

    // Populate the array with random integer values in the range [1, T].
    for (int i = 0; i < S; i++) A[i] = 1 + std::rand() % T;
}

/**
 * Use the Bubble Sort algorithm to arrange the elements of an int type array, 
 * A, in ascending order.
 * 
 * Assume that the value which is passed into this function as A is the memory 
 * address of the first element of a one-dimensional array of int type values.
 * 
 * Assume that the value which is passed into this function as S is the total 
 * number of elements which comprise the array represented by A.
 * 
 * This function returns no value (but it does update the array 
 * referred to as A if the elements of A are not already sorted in 
 * ascending order). 
 */
void bubble_sort(int * A, int S)
{
    int i = 0, placeholder = 0; 
    bool array_is_sorted = false, adjacent_elements_were_swapped = false;
    while (!array_is_sorted)
    {
        adjacent_elements_were_swapped = false;
        for (i = 1; i < S; i += 1)
        {
            if (A[i] < A[i - 1])
            {
                placeholder = A[i];
                A[i] = A[i - 1];
                A[i - 1] = placeholder;
                adjacent_elements_were_swapped = true;
            }
        }
        if (!adjacent_elements_were_swapped) array_is_sorted = true;
    }
}

/**
 * Merges two subarrays of A[].
 * First subarray is A[left..mid]
 * Second subarray is A[mid+1..right]
 * The merged result will be sorted in ascending order.
 */
void merge(int * A, int left, int mid, int right) 
{
    // Initialize the indexes of the subarrays and merged array.
    int i = 0, j = 0, k = left;

    // Set n0 to store the number of elements in the left subarray.
    int n0 = mid - left + 1; 

    // Set n0 to store the number of elements in the right subarray.
    int n1 = right - mid; 

    // Dynamically allocate arrays, L and R, to store the elements of the subarrays.
    int * L = new int[n0];
    int * R = new int[n1];

    // Copy the elements of the left subarray into L.
    for (i = 0; i < n0; i++) L[i] = A[left + i];

    // Copy the elements of the right subarray into R.
    for (j = 0; j < n1; j++) R[j] = A[mid + 1 + j];

    // Merge arrays L and R back into the segment of array A which starts at A[left] and which ends at A[right].
    i = 0, j = 0;
    while (i < n0 && j < n1) 
    {
        if (L[i] <= R[j]) 
        {
            A[k] = L[i];
            i++;
        } 
        else 
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L (if there are any) into A.
    while (i < n0) 
    {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R (if there are any) into A.
    while (j < n1) 
    {
        A[k] = R[j];
        j++;
        k++;
    }

    // Deallocate the memory which was allocated to the arrays which were dynamically created in this function.
    delete[] L;
    delete[] R;
}

/**
 * This function sorts the segment of array A which starts at A[left] 
 * and which ends at A[right] using the Merge Sort algorithm
 * by recursively dividing that array into halves, sorting each half,
 * and merging those sorted halves.
 * 
 * This function returns no value (but it does update the segment of 
 * array A which starts at A[left] and which ends at A[right] if 
 * that segment is not already sorted in ascending order). 
 */
void merge_sort(int * A, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

/**
 * Use the Merge Sort algorithm to arrange the elements of an int type array, 
 * A, in ascending order.
 * 
 * This function is the wrapper function for merge_sort.
 * This function sorts the entire array named A (which is comprised of 
 * exactly S int type elements).
 *
 * Assume that the value which is passed into this function as A is the memory 
 * address of the first element of a one-dimensional array of int type values.
 * 
 * Assume that the value which is passed into this function as S is the total 
 * number of elements which comprise the array represented by A.
 * 
 * This function returns no value (but it does update the array 
 * referred to as A if the elements of A are not already sorted in 
 * ascending order). 
 */
void merge_sort(int * A, int S) 
{
    merge_sort(A, 0, S - 1);
}