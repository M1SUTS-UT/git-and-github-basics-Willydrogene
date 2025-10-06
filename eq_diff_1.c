#include <stdio.h> 
#include <math.h>

//Résolution pour y'(x) + y(x) = 0, intervalle [0,10] avec y(0)=1, Euleur, Heun, RK


double f(double y) {
	return -y;
}


void euleur(double *y_e, double dy, double *t, double dt, int Nt) {
	for (int i=0; i<Nt; i++) {
		dy = f(y_e[i]) * dt;
		y_e[i+1] = y_e[i] + dy;
		t[i+1] = t[i] + dt;
	}
}


void heun(double *y_h, double dy, double *t, double dt, int Nt) {
	double k1=dy, k2;
	for (int i=0; i<Nt; i++) {
		k1 = f(y_h[i]) * dt;  //k1=dy
		double y_pred = y_h[i] + k1;  //Euler normal (prédiction de correction)
		k2 = f(y_pred) * dt;
		
		y_h[i+1] = y_h[i] + (k1+k2)/2;
		t[i+1] = t[i] + dt;
	}

}


int main(){
	FILE* file = fopen("eq_diff_1.txt", "w");
	double tmax=10.0; double tmin=0.0;
	double dt=0.01;
	int Nt = (tmax-tmin)/dt;
	double t[Nt], y_e[Nt], y_h[Nt]; 
	double dy=0.0; //y(0)=1 et vy(0)=0
	t[0] = tmin;
	y_e[0] = 1.0;
	y_h[0] = 1.0;
	 
	euleur(y_e, dy, t, dt, Nt);
	t[0] = tmin;
	heun(y_h, dy, t, dt, Nt);
	
	fprintf(file, "t \t\t\t y_euler \t\t\t y_heun\n");
	for (int i=0; i<Nt; i++) {
		fprintf(file, "%lf \t\t %lf \t\t %lf\n", t[i], y_e[i], y_h[i]);
	}
	
	fclose(file);
	
	
		
	return 0;
}

