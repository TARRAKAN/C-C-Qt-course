#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qs(int *s_arr, int first, int last);

int main()
{
    int arr[1000] = {0};
    srand(time(NULL));
    for(int i = 0; i<1000; i++)
    {
        arr[i] = rand()%10000;
    }
    int arr2[1000] = {0};
    int arr3[1000] = {0};
    int arr4[1000] = {0};
    for(int i = 0; i<1000; i++)
    {
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }
    //bublesort
    clock_t t;
    t = clock();
    for(int i = 0 ; i < 1000; i++)
    { 
       for(int j = 0 ; j < 1000 - i; j++) {  
           if(arr[j] > arr[j+1]) {           
              int tmp = arr[j];
              arr[j] = arr[j+1] ;
              arr[j+1] = tmp; 
           }
        }
    }
    t = clock() - t;
    printf ("Bublesort took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    //selectsort
    t = clock();
    for (int i = 0; i < 1000 - 1; i++) 
    {
        int min = 0;
	    for (int j = i + 1; j < 1000; j++) 
        {
		    if (arr4[j] < arr4[min]) 
            {
			    min = j;
		    }
	    }
	    int temp = arr4[i];
	    arr4[i] = arr4[min];
	    arr4[min] = temp;
    }
    t = clock() - t;
    printf ("Selectsort took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    //Blocksort
    t = clock();
    int max = 1000;
    int block[10][max+1];
    for(int x = 0; x < 10; x++) block[x][max] = 0;
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        for(int i = 0; i < max; i++) {
            int dig = (arr3[i] / digit) % 10;
            block[dig][block[dig][max]++] = arr3[i];
        }
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < block[x][max]; y++) {
                arr3[idx++] = block[x][y];
            }
            block[x][max] = 0;
        }
    }
    t = clock() - t;
    printf ("Blocksort took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    //qsort
    t = clock();
    qs(arr2, 0, 999);
    t = clock() - t;
    printf ("Qsort took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    return 0;
}

void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}

