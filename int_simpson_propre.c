#include <stdio.h>
#include <math.h>

double f(double x) {
	return sin(x);
}



double simpson(double a, double b, int n) {
	if (n%2==1) n++;
	double dx = (b-a)/n, x;
	double integ = f(a) + f(b);
	
	for (int i=1; i<n; i++) {
		x = a + i * dx;
		if (i%2==0) {integ += 2 * f(x);}
		else {integ += 4 * f(x);}
	}
	return (dx/3) * integ;
 
}


int main() {
	
	double a=0, b=M_PI/5, res;
	int n=100000;
	
	res = simpson(a, b, n);
	
	printf("Le rés est %lf\n", res);
	
	
	return 0;
}

