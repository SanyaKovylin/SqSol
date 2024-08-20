#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "sq_sol.h"

/// equation of the form a*x^2 + b*x + c = 0
int tester (void);

int main (void)
{
    assert (tester ());

    double a_coef = 0, b_coef = 0, c_coef = 0;  // coefficients of the equation
    input (&a_coef, &b_coef, &c_coef);

    double sol1 = 0, sol2 = 0;
    int num_roots = Solve (a_coef, b_coef, c_coef , &sol1, &sol2);

    return output (sol1, sol2, num_roots);
}

//=============================================================================

int tester(void){

    struct test {

        double a;
        double b;
        double c;
        int nroots;
        double sol1;
        double sol2;
    };

    struct test tests[] = {

        0, 0, 0, INFINITE,  0,  0,
        0, 1, 0,        1,  0,  0,
        0, 0, 1,        0,  0,  0,
        0, 1, 1,        1, -1, -1,
        1, 0, 0,        1,  0,  0,
        1, 0, 1,        0,  0,  0,
        1, 1, 0,        2,  0, -1,
        1, 1, 1,        0,  0,  0,
    };

    int t_nroots = TOXIC;
    double t1 = TOXIC, t2 = TOXIC;

    for (int i = 0; i < sizeof (tests) / sizeof (tests[0]); i++){

        t_nroots = Solve(tests[i].a, tests[i].b, tests[i].c, &t1, &t2);

        if ((compare2 (tests[i].sol1, t1) &&
             compare2 (tests[i].sol2, t2) &&
             tests[i].nroots == t_nroots) == false) {

            printf ("Test Error Test_id: %d \n", i);

            return 0;
        }
    }

    return 1;
}













