#include <stdio.h>
#include <math.h>

// equation of the form a*x^2 + b*x + c = 0


int main(void)
{
    float a, b, c;  // coefficients of the equation
    double discr, sqrt_dis; // The discriminant of equation and its square root

    printf("Please, enter the coefficients of your equation of the form a*x^2 + b*x + c = 0 \n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f ", &c);      // input of the coefficients

    if (a == 0)
        printf("Your equation has one root: %f", -b/c);
    else {
        discr = b*b - 4*a*c;

        if (discr == 0)
            printf("Your equation has one root: %f", -b/2/a);
        else
            if (discr > 0){
                sqrt_dis = sqrt(discr);
                printf("Your equation has two roots: %f and %f", (-b + sqrt_dis)/2/a,(-b - sqrt_dis)/2/a);
            }
            else
                printf("Your equation doesn't have any real roots");

    }

}









