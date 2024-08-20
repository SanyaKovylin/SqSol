#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <sq_sol.h>

/// equation of the form a*x^2 + b*x + c = 0






int main(void)
{
    double a_coef = 0, b_coef = 0, c_coef = 0;  // coefficients of the equation
    input(&a_coef, &b_coef, &c_coef);

    double sol1 = 0, sol2 = 0;
    int num_roots = Solve(a_coef, b_coef, c_coef , &sol1, &sol2);
    return output(sol1, sol2, num_roots);

}












