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
#define MAXIMUM_S 1000 // constant which represents the maximum value for S
#define MAXIMUM_T 1000 // constant which represents the maximum value for T
#define MINIMUM_S 1 // constant which represents the minimum value for S
#define MINIMUM_T 1 // constant which represents the minimum value for T

/** function prototypes */
void generate_array(int * A, int S, int T);
void bubble_sort(int * A, int S);

/** program entry point */
int main()
{
    // Declare three int type variables and set each of their initial values to 0.
    int S = 0, T = 0, i = 0;

    // Declare one pointer-to-int type variable.
    int * A;

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
 * selected as (and that any element of A is a nonnegative integer 
 * no larger than T - 1).
 * 
 * This function returns no value (but it does update the array 
 * referred to as A if tbe elements of A are not already sorted in 
 * ascending order).
 */
void generate_array(int * A, int S, int T)
{
    /**
     * Seed the pseudo-random number generator with the number of seconds 
     * elapsed since some epoch such as the Unix Epoch (which is 
     * 01_JANUARY_1970).
     */
    std::srand(std::time(0));

    // Populate the array with random integer values in the range [0, T-1].
    for (int i = 0; i < S; i++) A[i] = std::rand() % T;
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
 * referred to as A if tbe elements of A are not already sorted in 
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