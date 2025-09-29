#include <stdio.h>

int main() {
	
	double a=0.31, b=1.0, x0=12.0, y0=0;
	double xn=x0, yn=y0, xn_temp;
	int n; 
	printf("Donne une valeur de n le nombre de tours de boucle: "); 
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "Erreur: entrée invalide.\n");
		return 1;
	}
	
	FILE * file = fopen("Mira.txt", "w");
	
	fprintf(file, "%lf \t\t\t %lf\n", xn, yn);
	for (int i=0; i<n; i++) {
		xn_temp = xn;
		xn = b * yn + a * xn + (1-a) * (2 * xn * xn)/(1 + (xn * xn));
		yn = -xn_temp + a * xn + (1-a) * (2 * xn * xn)/(1 + (xn * xn));
		
		//printf("x(%d) = %lf , y(%d) = %lf\n", i, xn, i, yn);
		fprintf(file, "%lf \t\t\t %lf\n", xn, yn);
	}
	
	fclose(file);

	return 0;
}
