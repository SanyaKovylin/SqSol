#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "sq_sol.h"

enum cases {TOXIC = -100, INFINITE = 100};

/// equation of the form a*x^2 + b*x + c = 0
int tester(void);


int main(void)
{
    assert(tester());

    double a_coef = 0, b_coef = 0, c_coef = 0;  // coefficients of the equation
    input(&a_coef, &b_coef, &c_coef);

    double sol1 = 0, sol2 = 0;
    int num_roots = Solve(a_coef, b_coef, c_coef , &sol1, &sol2);
    return output(sol1, sol2, num_roots);

}


int tester(void){
    struct test tests[] = {
    0,0,0,100,0,0,
    0,1,0,1,0,0,
    0,0,1,0,0,0,
    0,1,1,1,-1,-1,
    1,0,0,1,0,0,
    1,0,1,0,0,0,
    1,1,0,2,0,-1,
    1,1,1,0,0,0
    };


    int t_x1 = TOXIC, t_x2 = TOXIC,t_nroots = TOXIC;
    int i;
    for ( i = 0;i < 10;i++){
        t_nroots = Solve(tests[i].a, tests[i].b, tests[i].c, &t_x1, &t_x2);
        if ((compare2(tests[i].sol1, t_x1) && compare2(tests[i].sol2, t_x2)
                                                    && compare2(tests[i].nroots, t_nroots)) == 0) {
            printf("Test Error");
            return 1;
        }
    }

}













