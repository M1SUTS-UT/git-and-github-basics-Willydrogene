#include <stdio.h>
#include <math.h>


double f(double y_point) {
	double dy_dt = y_point;
	return dy_dt;
}

double f2(double y, double y_point, double omega, double epsilon) {
	double dy_point_dt = - ((omega * omega) * y) - (2 * omega * epsilon * y_point);
	return dy_point_dt;
}



void RK4(double *y, double *y_point, double *t, double dt, int Nt, double omega, double epsilon) {
	double k1, k2, k3, k4;
	double k1_point, k2_point, k3_point, k4_point;
	for (int i=0; i<Nt; i++) {
		k1 = f(y_point[i]) * dt;
		k1_point = f2(y[i], y_point[i], omega, epsilon) * dt;
		
		k2 = f(y_point[i] + k1/2) * dt;
		k2_point = f2(y[i] + k1_point/2, y_point[i] + k1_point/2, omega, epsilon) * dt;
		
		k3 = f(y_point[i] + k2/2) * dt;
		k3_point = f2(y[i] + k2_point/2, y_point[i] + k2_point/2, omega, epsilon) * dt;
		
		k4 = f(y_point[i] + k3) * dt;
		k4_point = f2(y[i] + k3_point, y_point[i] + k3_point/2, omega, epsilon) * dt;
		
		y[i+1] = y[i] + (k1 + 2*k2 + 2*k3 + k4)/6;
		y_point[i+1] = y_point[i] + (k1_point + 2*k2_point + 2*k3_point + k4_point)/6;
	}
}
int main() {
	double tmax=50.0, tmin=0.0, dt=0.001;
	int Nt = (tmax-tmin)/dt;
	double t[Nt], y[Nt], y_point[Nt];
	
	double omega = 1.0, epsilon = 0.05;
	t[0] = tmin;
	y[0] = 1.0;
	y_point[0] = 0.0;
	
	for (int a=0; a<Nt+1; a++) t[a+1] = t[a] + dt; 

	RK4(y, y_point, t, dt, Nt, omega, epsilon);
	
	FILE *file = fopen("oscillateur.txt", "w");
	fprintf(file, "\t t \t\t\t y \t\t\t y_point\n");
	for (int i=0; i<Nt+1; i++) {
		fprintf(file, "%e \t\t\t %e \t\t\t %e\n", t[i], y[i], y_point[i]);
	}
	
	fclose(file);

	return 0;
}





/*

1. Résoudre l’équation différentielle ordinaire du second ordre y′′+ω20y=0 avec y(0)=1, y′(0)=0

. Comparer à la solution théorique.

2. Ajouter un terme d'amortissement de la forme 2ϵω0y′
. Etudier le portrait de phase (y′(t) en fonction de y(t)).

*/
