#include <stdio.h>
#include <math.h>


// equation of the form a*x^2 + b*x + c = 0

enum cases {TOXIC = -100, INFINITE = 100};


void get_input(float *a_coef,float *b_coef, float *c_coef);
int Solve(float a_coef,float b_coef, float c_coef, float *sol1, float *sol2);
int check_input(float a_coef,float b_coef, float c_coef);
int square_solve(float a_coef,float b_coef, float c_coef, float *sol1, float *sol2);
int linear_solve(float b_coef, float c_coef, float* sol1);
int special_case(float c_coef);
int output(float sol1,float sol2, int num_roots);




int main(void)
{
    float a_coef = 0, b_coef = 0, c_coef = 0;  // coefficients of the equation
    get_input(&a_coef, &b_coef, &c_coef);

    float sol1 = 0, sol2 = 0;
    int num_roots = Solve(a_coef, b_coef, c_coef , &sol1, &sol2);
    return output(sol1, sol2, num_roots);

}




void get_input(float *a_coef,float *b_coef, float *c_coef){

    printf("Please, enter the coefficients of your equation of the form a*x^2 + b*x + c = 0 \n");
    printf("a: ");
    scanf("%f", &(*a_coef));
    printf("b: ");
    scanf("%f", &(*b_coef));
    printf("c: ");
    scanf("%f", &(*c_coef));
}



int Solve(float a_coef,float b_coef, float c_coef, float *sol1, float *sol2){
    int num_roots = TOXIC;
    if (a_coef == 0)
        linear_solve(b_coef,c_coef,sol1);
    else if (b_coef == 0)
        special_case(c_coef);
    else
        num_roots = square_solve(a_coef, b_coef, c_coef, sol1, sol2);

    return num_roots;
}



int square_solve(float a_coef,float b_coef, float c_coef, float *sol1, float *sol2)
{
    float discr = 0, sqrt_dis = 0;  // The discriminant of equation and its square root
    float a_coefx2 = a_coef*2; // Due to inevitability of computation we take it once


    discr = b_coef * b_coef - 4*a_coef*c_coef;// compute the discriminant of equation


    if (discr == 0){
        *sol1 = -b_coef/a_coefx2;
        return 1;
    }
    else if (discr > 0){
        *sol1 = (-b_coef + sqrt_dis) / a_coefx2;
        *sol2 = (-b_coef - sqrt_dis) / a_coefx2;
        return 2;
    }
    else{
        //Complex case
        return -1;
    }

}




int linear_solve(float b_coef, float c_coef, float *sol1) {

    *sol1 = -b_coef/c_coef;
    return 1;
}


int special_case(float c_coef){

    if (c_coef == 0)
        return INFINITE;
    return 0;

}


int output(float sol1, float sol2, int num_roots){
    switch (num_roots){

    case 1 : {printf("Your equation has only one root: %g", sol1);
        return 0;}

    case 2 : {printf("Your equation has two roots: \nx1 = %g \nx2 = %g", sol1, sol2);
        return 0;}

    case -1 : {printf("Your equation has complex roots");
            return 1;

        return 1;}
    default : return 2;
    }


}








