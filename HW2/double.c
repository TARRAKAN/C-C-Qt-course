#include <stdio.h>

#include <float.h>



int main()

{

    double x = DBL_MAX;

    printf ("At first I was like %lf,\n", x);

    x *= (1 + DBL_EPSILON);

    printf ("but then I was like %lf\n", x);

    return 0;

}
