#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double x) {
	return sin(x);
}

double rectangle_gauche(double x) {
	return 0;
}


int main() {
	double pas=0.1, a=0, b=M_PI/2;
	int taille = (b-a)/pas;
	printf("%d\n", taille);
	double *tab = malloc(taille * sizeof *tab);
	
	for (int i=0; i<taille; i++) {
		tab[i] = i*pas;
		printf("Suis là %d\n", i);
	}	
	
	for (int i=0; i<taille; i++) printf("%lf ", tab[i]);
  
	free(tab);
  
	return 0;
}
