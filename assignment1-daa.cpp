#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include <sys/time.h>
#include <cstdlib>

#define TRUE 1
#define FALSE 0

#define XDATASIZE 100000
#define MEANSIZE 100
#define INT 1000
#define HI 100000
#define LOW -9999

#define MAXSTACKSIZE 64



#ifdef _WIN32
#include <process.h>

FILE* gnuplotpipe = _popen("\"C:\\Program Files (x86)\\mingw\\gnuplot\\bin\\gnuplot\" -persistent", "w");
#elif
#include <sys/time.h>
FILE* gnuplotpipe = popen("gnuplot - persistent", "w");
#endif

static struct timeval time_start;
static struct timeval time_end;

void heapify(int* numbers_p, int i) {

}

void getsample(int* numbers_p, int size) {
    srand(time(NULL));
    int random = 0;
    int i = 0;
    for(; i < size ; i ++) {
        random = rand() % (HI - LOW) + LOW;
        numbers_p[i] = random;
    }
}

void heapsort_iterative(int* numbers, int size);

int main(int argc, char *argv[])
{
    int numbers[10];
    getsample(numbers, 10);
    heapsort_iterative(numbers, 10);
    return 0;
}
void solution_1() {
}
void solution_2() {
}
void solution_3() {
}
void solution_4() {

}
void solution_5() {
}

void heapsort_iterative(int* number, int size) {

    gettimeofday(&time_start, NULL);
    int heapsize = size;
    int i = heapsize / 2 - 1;
    int max_i, l, r, p;
    for(i = 0 ; i < heapsize / 2 ; i ++) {
        // heapify
        l = i * 2 + 1;
        r = i * 2 + 2;
        p = i;
        if((heapsize - 1) >= r) {
            if(number[l] > number[r]) {
                max_i = l;
            } else {
                max_i = r;
            }
            // Swap elements at index max_i andd p
            if(number[max_i] > number[p]) {
                number[max_i] = number[max_i] + number[p];
                number[p] = number[max_i] - number[p];
                number[max_i] = number[max_i] - number[p];
            }
        } else {
            if(number[l] > number[p]) {
                number[l] = number[l] + number[p];
                number[p] = number[l] - number[p];
                number[l] = number[l] - number[p];
            }
        }
    }
    int last, cl, cr;
    while(heapsize > 1) {

        last = heapsize - 1;

        number[last] = number[last] + number[0];
        number[0] = number[last] - number[0];
        number[last]  = number[last] - number[0];

        heapsize = heapsize - 1;
        p = 0;
        while(TRUE) {
            cl = 2 * p + 1;
            cr = 2 * p + 2;
            if(cr <= (heapsize - 1)) {
                if(number[p] < number[cl] || number[p] < number[cr]) {
                    if(number[cl] > number[cr]) {
                        max_i = cl;
                    }
                    else {
                        max_i = cr;
                    }
                    number[p] = number[max_i] + number[p];
                    number[max_i] = number[p] - number[max_i];
                    number[p] = number[p] - number[max_i];
                    p = max_i;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    gettimeofday(&time_end, NULL);
}
void heapsort_recursive(int* number, int size) {
    gettimeofday(&time_start, NULL);
    int heapsize = size;
    int i;
    for(i = heapsize / 2 - 1 ; i >= 0 ; i --) {
        heapify(number, i);
    }


    gettimeofday(&time_end, NULL);
}
void mergesort_iterative(int* number, int size) {
    gettimeofday(&time_start, NULL);

    int exp = 2;
    int v_size = size;
    int i = 0;
    int l,r;
    while(v_size > 1) {
        v_size = size / exp;
        for(i = 0; i < v_size ; i += exp) {
            l = i;
            r = exp / 2 + l;
            for(; l < r && r < size ; ) {
                if(number[l] > number[r]) {
                    number[l] = number[r] + number[l];
                    number[r] = number[l] - number[r];
                    number[l] = number[l] - number[r];
                    l ++;
                } else if(number[l] < number[r]) {
                    r ++;
                }
            }
        }
        exp = exp * 2;
    }
    gettimeofday(&time_end, NULL);
}

void mergesort_recursive(int* number, int size) {

}
void quicksort_iterative(int* number, int size) {
    gettimeofday(&time_start, NULL);

    typedef struct interval {
        int p;
        int q;
    } Interval;

    Interval* p_initInterval = (Interval*)(malloc(sizeof(Interval)));
    p_initInterval -> p = 0;
    p_initInterval -> q = size - 1;

    Interval** stack = (Interval**)(malloc(sizeof(Interval*) * MAXSTACKSIZE));
    stack[0] = p_initInterval;
    int top = 0;

    int min_s = HI, max_s = LOW;

    int pivot, l, r, i, j;

    Interval* p_interval1;
    Interval* p_interval2;

    while(min_s == 0 && max_s == (size - 1)) {
        Interval* p_interval = stack[top];
        if(p_interval -> p == (p_interval -> q - 1)) {
            if(p_interval -> p < min_s) {
                min_s = p_interval -> p;
            }
            if(p_interval -> q > max_s) {
                max_s = p_interval -> q;
            }
            top --;
        }
        else if(p_interval -> p >= min_s && p_interval -> q <= max_s) {
            top --;
        }
        else {
            l = p_interval -> p;
            r = p_interval -> q;
            pivot = number[l];
            i = l + 1;
            j = l;

            for(; i <= r; i ++) {
                if(number[i] <= pivot) {
                    if(j == (i - 1)) {
                        number[j] = number[j] + number[i];
                        number[i] = number[j] - number[i];
                        number[j] = number[j] - number[i];
                        j = j + 1;
                    }
                    else {
                        number[j] = number[j] + number[i];
                        number[i] = number[j] - number[i];
                        number[j] = number[j] - number[i];

                        number[i] = number[i] + number[j + 1];
                        number[j + 1] = number[i] - number[j + 1];
                        number[i] = number[i] - number[j + 1];

                        j = j + 1;
                    }
                }
            }

            p_interval1 = (Interval*)(malloc(sizeof(Interval)));
            p_interval1 -> p = p_interval -> p;
            p_interval1 -> q = j - 1;

            p_interval2 = (Interval*)(malloc(sizeof(Interval)));
            p_interval2 -> p = j + 1;
            p_interval2 -> q = p_interval -> q;

            stack[top ++] = p_interval1;
            stack[top ++] = p_interval2;
        }
    }
    gettimeofday(&time_end, NULL);
}
void quicksort_recursive(int* number, int size) {

}
