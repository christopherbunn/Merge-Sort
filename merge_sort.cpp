/**
 * Threaded merge-sort
 * Christopher Bunn
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <pthread.h>
#include <chrono>
#include <math.h>

using namespace::std;
using namespace::chrono;

struct mergesort_args
{
    int size;
    int num_of_threads;
    int* unsorted_array;
};

void print_array(int *array_to_print, int size)
;

int* basic_mergesort(int* unsorted_array, int size)
;

int* merge (int* sorted_left, int* sorted_right, int size)
;

int* generate_rand_array(int size, int largest_number)
;

bool check_if_works(int* input, int size)
;

void * run_and_time()
;

void *parallel_mergesort(void *curr_args ) {
    mergesort_args* args = (mergesort_args*)curr_args;
    if (args->num_of_threads == 1)
    {
        int *unsorted_array = basic_mergesort(args->unsorted_array, args ->size);
        return (void*) unsorted_array;
    }
    else
    {
        int *unsorted_left =  new int[(args->size) / 2];
        int *unsorted_right = new int[(args->size) / 2];
        for (int i = 0; i < args->size / 2; i++) {
            unsorted_left[i] = args->unsorted_array[i];
        }
        for (int j = args->size / 2; j < args ->size; j++) {
            unsorted_right[j- args->size/2] = args->unsorted_array[j];
        }
        pthread_t thread_id[2];
        int **return_vals = (int **) malloc(sizeof(unsorted_left) + sizeof(unsorted_right));
        //start thread for left
        mergesort_args left;
        left.size = args->size / 2;
        left.num_of_threads = args->num_of_threads / 2;
        left.unsorted_array = unsorted_left;
        pthread_create(&thread_id[0], NULL, &parallel_mergesort, &left);
        //start thread for right
        mergesort_args right;
        right.size = args->size / 2;
        right.num_of_threads = args->num_of_threads / 2;
        right.unsorted_array = unsorted_right;
        pthread_create(&thread_id[1], NULL, &parallel_mergesort, &right);
        //join thread (void **) &return_vals[0]) (void **) &return_vals[1]
        pthread_join(thread_id[0],(void**)&return_vals[0]);
        pthread_join(thread_id[1],(void**)&return_vals[1]);
        int* ret_val = merge(return_vals[0], return_vals[1], args->size);
        return (void*)ret_val;
    }
}
int* basic_mergesort(int* unsorted_array, int size)
{
    int* sorted_array =  new int[size];
    int* unsorted_left = new int [size/2];
    int* unsorted_right = new int [size/2];
    for (int i = 0; i < size / 2; i++) {
        unsorted_left[i] = unsorted_array[i];
    }
    for (int j = size / 2; j < size; j++) {
        unsorted_right[j - size/2] = unsorted_array[j];
    }
    if (size != 2){
        unsorted_left = basic_mergesort(unsorted_left, size / 2);
        unsorted_right = basic_mergesort(unsorted_right, size / 2);
    }
    int left_pos = 0;
    int right_pos = 0;
    for (int i = 0; i < size; i++)
    {
        if (unsorted_left[left_pos] < unsorted_right[right_pos])
        {
            if (left_pos < size/2)
            {
                sorted_array[i] = unsorted_left[left_pos];
                left_pos++;
            }
            else
            {
                sorted_array[i] = unsorted_right[right_pos];
                right_pos++;
            }
        }
        else if (unsorted_right[right_pos] < unsorted_left[left_pos])
        {
            if (right_pos < size/2)
            {
                sorted_array[i] = unsorted_right[right_pos];
                right_pos++;
            } else
            {
                sorted_array[i] = unsorted_left[left_pos];
                left_pos++;
            }
        }
        else if (unsorted_left[left_pos] == unsorted_right[right_pos])
        {
            sorted_array[i] = unsorted_right[right_pos];
            right_pos++;
        }
    }
    return sorted_array;
}

int* merge (int* sorted_left, int* sorted_right, int size)
{
    int* sorted_array = new int[size];
    int left_pos = 0;
    int right_pos = 0;
    for (int i = 0; i < size; i++)
    {
        if (sorted_left[left_pos] < sorted_right[right_pos])
        {
            if (left_pos < size/2)
            {
                sorted_array[i] = sorted_left[left_pos];
                left_pos++;
            }
            else
            {
                sorted_array[i] = sorted_right[right_pos];
                right_pos++;
            }
        }
        else if (sorted_right[right_pos] < sorted_left[left_pos])
        {
            if (right_pos < size/2)
            {
                sorted_array[i] = sorted_right[right_pos];
                right_pos++;
            } else
            {
                sorted_array[i] = sorted_left[left_pos];
                left_pos++;
            }
        }
        else if (sorted_left[left_pos] == sorted_right[right_pos])
        {
            sorted_array[i] = sorted_right[right_pos];
            right_pos++;
        }
    }
    return sorted_array;
}


void print_array(int *array_to_print, int size)
{
    cout << "[";
    for (int i=0; i < size; i++)
    {
        cout << " " << array_to_print[i] << ",";
    }
    cout << "]" << endl;
}

void entrypoint(int size, int largest_number, int num_of_threads)
{
    struct timespec start, finish;
    mergesort_args initial_args;
    initial_args.size = size;
    initial_args.num_of_threads = num_of_threads;
    int* unsorted_array = generate_rand_array(initial_args.size,largest_number);
    initial_args.unsorted_array = unsorted_array;
    //print_array(unsorted_array, size);
    pthread_t thread[1];
    void *return_val = malloc(sizeof(unsorted_array));
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    pthread_create(&thread[0], NULL, parallel_mergesort, &initial_args);
    pthread_join(thread[0],&return_val);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //print_array((int *) return_val, size);
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << (long)duration << endl;
}

int* generate_rand_array(int size, int largest_number)
{
    srand(time(NULL));
    int *return_array = new int[size];
    for (int i = 0; i < size; i++)
    {
        return_array[i] = (rand() % largest_number) + 1;
    }
    return return_array;
}

int main()
{
    run_and_time();
}
void * run_and_time()
{
    int size = 1048576;
    int largest_number = 10000000;
    for (int j=10; j < 30; j++) {
        for (int i = 0; i < 10; i++) {
            cout << (int) pow(2, j) << "," << (int) pow(2, i) << ",";
            entrypoint((int) pow(2, j), largest_number, (int) pow(2, i));
        }
    }
}