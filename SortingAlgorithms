#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void insertion_sort(int array[], int length, int & count_comp, int & count_move);
void merge_sort(int array[], int length, int & count_comp, int & count_move);
void heap_sort(int array[], int length, int & count_comp, int & count_move);
void quick_sort_sort(int array[], int length, int & count_comp, int & count_move);

void insertion_sort(int array[], int length, int & count_comp, int & count_move)
{
	int i, j, key;
	for(j = 1; j < length; j++)
	{
		key = array[j];
		i = j - 1;

		while( i >= 0 && array[i] > key)
		{
            count_comp ++;
            count_move ++;
			array[i + 1] = array[i];
			i = i -1;
		}
		array[i + 1] = key;
        count_move ++;
	}
}

void merge(int A[],int l, int m,int r, int & count_comp, int & count_move)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = A[l + i];
    for(j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while( i < n1 && j < n2)
    {
        count_comp ++;
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            count_move ++;
            i++;
        }
        else
        {
            A[k] = R[j];
            count_move ++;
            j++;
        }
        
        k++;
    }

    while (i < n1)
    {
        count_move ++;
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        count_move ++;
        A[k] = R[j];
        j++;
        k++;
        }
    }

void merge_sort(int array[], int length, int l, int r, int & count_comp, int & count_move)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        merge_sort(array, length, l, m, count_comp, count_move);
        merge_sort(array, length, m + 1, r, count_comp, count_move);

        merge(array, l, m, r, count_comp, count_move);    
    }
}

void merge_sort(int array[], int length, int & count_comp, int & count_move)
{
    merge_sort(array, length, 0, length - 1, count_comp, count_move);
}

void heapify(int arr[], int n, int i, int & count_comp, int & count_move)
{
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2;
  
    count_comp ++;
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
   
    count_comp ++;
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        count_move ++;
        swap(arr[i], arr[largest]); 

        heapify(arr, n, largest, count_comp, count_move); 
    } 
} 

void heap_sort(int array[], int n, int & count_comp, int & count_move)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(array, n, i, count_comp, count_move); 

    for (int i=n-1; i>=0; i--) 
    { 
        count_move ++;
        swap(array[0], array[i]); 

        heapify(array, i, 0, count_comp, count_move); 
    } 
}

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int arr[], int low, int high, int & count_comp, int & count_move)  
{  
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  
    {   
        count_comp ++;
        if (arr[j] < pivot)  
        {  
            i++;
            count_move ++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    count_move ++;
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quick_sort_sort(int array[], int length, int low, int high, int & count_comp, int & count_move)
{

    if (low < high)  
    {  
        int pi = partition(array, low, high, count_comp, count_move);  
        quick_sort_sort(array, length, low, pi - 1, count_comp, count_move);  
        quick_sort_sort(array, length,  pi + 1, high, count_comp, count_move);
    }  
} 

void quick_sort_sort(int array[], int length, int & count_comp, int & count_move)
{
    quick_sort_sort(array, length, 0, length - 1, count_comp, count_move);
}

typedef void (*sort_algo_type)(int array[], int length, int& count_comp, int & count_move);

void run_sort_algo(int array[], int length, sort_algo_type sorting, const char* algo_name, const char* data_file_name)
{
        int count_comparison = 0;
        int count_move = 0;
        clock_t start,end;
        start = clock();
        sorting(array, length, count_comparison, count_move);
        end=clock();
        //double duration = (double)(end - start) *1000 / CLOCKS_PER_SEC;
	long duration = end - start; // Just use clock cycles
        printf("Sorting algo summary, %s, %s, data size %d, count_comp %d, count_move %d, time %ld cycles\n", algo_name, data_file_name, length, count_comparison, count_move, duration);
	printf("Showing sorted result");
	for(int i = 0; i < length; i++)
	  printf(", %d", array[i]);
	printf("\n");
}

int main(int argc, char** argv)
{
    // read the data
    if(argc < 2) //
    {
      printf("Usage: %s data_file_1 data_file_2 ...\n", argv[0]);
      exit(1);
    }

    const int num_files = argc - 1;
    std::vector<int> raw_data;

    for(int i=0; i < num_files; i++)
    {
        const char* data_filename = argv[i+1];
	std::ifstream infile(data_filename);
	// clear raw_data
	raw_data.clear();
        // assume one number per line
 	int d;
	while(infile.good())
	{
	  infile >> d;
          raw_data.push_back(d);
	}
	// Now run different sorting algos
	std::vector<int> tmp_data(raw_data.begin(), raw_data.end());
      run_sort_algo(&tmp_data[0], raw_data.size(), insertion_sort, "InsertionSort", data_filename);
        //overwrite tmp_data for another sorting
	 tmp_data.assign(raw_data.begin(), raw_data.end());
      run_sort_algo(&tmp_data[0], raw_data.size(), merge_sort, "MergeSort", data_filename);
        // overwrite tmp_data for another sorting
      tmp_data.assign(raw_data.begin(), raw_data.end());
      run_sort_algo(&tmp_data[0], raw_data.size(), heap_sort, "HeapSort", data_filename);
        // overwrite tmp_data for another sorting
	  tmp_data.assign(raw_data.begin(), raw_data.end());
        run_sort_algo(&tmp_data[0], raw_data.size(), quick_sort_sort, "QuickSort", data_filename);
    }
}
