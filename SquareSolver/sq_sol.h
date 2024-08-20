#ifndef SQ_SOL_H_INCLUDED
#define SQ_SOL_H_INCLUDED


void input(double *a_coef,double *b_coef, double *c_coef);
int Solve(double a_coef,double b_coef, double c_coef, double *sol1, double *sol2);
int output(double sol1,double sol2, int num_roots);
int compare2(double dble1, double dble2);




#endif // SQ_SOL_H_INCLUDED
