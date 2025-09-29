#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double x) {
	return sin(x);
}

double rectangle_gauche(double *tab, int n, double dx) {
	double integ = 0.0;
	for (int i=0; i<n-1; i++) {
		integ += f(tab[i]);
	}
	return integ * dx;
}


double rectangle_droite(double *tab, int n, double dx) {
	double integ = 0.0;
	for (int i=1; i<n; i++) {
		integ += f(tab[i]);
	}
	return integ * dx;
}


double rectangle_milieu(double *tab, int n, double dx) {
	double integ = 0.0;
	for (int i=0; i<n-1; i++) {
		integ += f((tab[i+1]+tab[i]) /2);
	}
	return integ * dx;
}


double trapeze(double *tab, int n, double dx) {
	double integ = 0.0;
	for (int i=0; i<n-1; i++) {
		integ += ( f(tab[i]) + f(tab[i+1]) )/2;
	}
	return integ * dx;
}


double simpson(double *tab, int n, double dx) {
	double integ = f(tab[0]) + f(tab[n-1]), integ_pair=0, integ_impair=0;
	for (int i=1; i<n-1; i++) {
		if (i%2==0) { integ_pair += 2 * f(tab[i]);}
		else { integ_impair += 4 * f(tab[i]);}	
	}
	return (dx/3) * (integ_pair + integ_impair + integ);
}







int main() {
	double a=0., b=M_PI/2, rec_gauche, rec_droite, rec_milieu, trap, simp=0, val_exacte=1.0;
	//printf("%d\n", n);
	
	FILE *file = fopen("erreur.txt", "w");
	
	
	for (int n=2; n<100; n++) {
		double dx = (b-a)/(n-1);
		//printf("dx=%lf, n=%d\n", dx, n);
		double *tab = malloc(n * sizeof *tab);
		
		for (int i=0; i<n; i++) {
		tab[i] = a + i*dx;  // tab = np.linspace(a,b,pas)
		//printf("tab[%d]=%lf\n", i, tab[i]);
		}	
		
		rec_gauche = rectangle_gauche(tab, n, dx);
		rec_droite = rectangle_droite(tab, n, dx);
		rec_milieu = rectangle_milieu(tab, n, dx);	
		trap = trapeze(tab, n, dx);
		if (n%2==1) simp = simpson(tab, n, dx);
		/*
		printf("Le résultat du rectangle à gauche est: %lf\n", rec_gauche);
		printf("Le résultat du rectangle à droite est: %lf\n", rec_droite);
		printf("Le résultat du rectangle au milieu est: %lf\n", rec_milieu);
		printf("\nErreur gauche : %e\n", fabs(rec_gauche - val_exacte));
		printf("Erreur droite : %e\n", fabs(rec_droite - val_exacte));
		printf("Erreur milieu : %e\n", fabs(rec_milieu - val_exacte));
		*/
		fprintf(file, "%d \t\t %e \t\t %e \t\t %e \t\t %e \t\t %e\n", n, fabs(rec_gauche - val_exacte), fabs(rec_droite - val_exacte), fabs(rec_milieu - val_exacte), fabs(trap - val_exacte), fabs(simp - val_exacte));
	  
		free(tab);
	}
	fclose(file);
	return 0;
}
