#include <stdio.h> 
#include <math.h>

//Résolution pour y'(x) + y(x) = 0, intervalle [0,10] avec y(0)=1, Euleur, Heun, RK


double f_exact(double tt){
	return exp(-tt);
}


double f(double y) {
	return -y;
}


void euleur(double *y_e, double *t, double dt, int Nt) {
	double dy;
	for (int i=0; i<Nt; i++) {
		dy = f(y_e[i]) * dt;
		y_e[i+1] = y_e[i] + dy;
	}
}


void heun(double *y_h, double *t, double dt, int Nt) {
	double k1, k2;
	for (int i=0; i<Nt; i++) {
		k1 = f(y_h[i]) * dt;  //k1=dy
		double y_pred = y_h[i] + k1;  //Euler normal (prédiction de correction)
		k2 = f(y_pred) * dt;
		
		y_h[i+1] = y_h[i] + (k1+k2)/2;
	}
}


void RK4(double *y_rk, double *t, double dt, int Nt) {
	double k1, k2, k3, k4;
	for (int i=0; i<Nt; i++) {
		k1 = f(y_rk[i]) * dt;
		k2 = f(y_rk[i] + k1/2) * dt;
		k3 = f(y_rk[i] + k2/2) * dt;
		k4 = f(y_rk[i] + k3) * dt;
		
		y_rk[i+1] = y_rk[i] + (k1 + 2*k2 + 2*k3 + k4)/6;
	}
}




int main(){
	FILE* file2 = fopen("eq_diff_1_erreur.txt", "w");
	double tmax=10.0, tmin=0.0;
	double dt_depart = 0.5, dt_end = 0.0001;
	
	fprintf(file2, "\t dt \t\t\t Err_e \t\t\t\t Err_h \t\t\t\t Err_RK4\n");
	
	for (double dt=dt_depart; dt>=dt_end; dt -= dt_end) {	
		FILE* file = fopen("eq_diff_1.txt", "w");
		int Nt = (tmax-tmin)/dt;
		double t[Nt+1], y_e[Nt+1], y_h[Nt+1], y_rk[Nt+1];
		
		t[0] = tmin;
		for (int i=0; i<Nt; i++) t[i+1]=t[i] + dt;
		
		y_e[0] = 1.0;
		y_h[0] = 1.0;
		y_rk[0] = 1.0;
		
		euleur(y_e, t, dt, Nt);
		heun(y_h, t, dt, Nt);
		RK4(y_rk, t, dt, Nt);
		
		fprintf(file, "\t t \t\t\t y_euler \t\t y_heun \t\t y_RK4\n");
		for (int i=0; i<Nt+1; i++) {
			fprintf(file, "%.15e \t\t %.15e \t\t %.15e \t\t %.15e\n", t[i], y_e[i], y_h[i], y_rk[i]);
		}
		fclose(file);
		
		fprintf(file2, "%.15e \t\t %.15e \t\t %.15e \t\t %.15e\n", dt, fabs(f_exact(t[Nt]) - y_e[Nt]), 
				fabs(f_exact(t[Nt]) - y_h[Nt]), fabs(f_exact(t[Nt]) - y_rk[Nt]));
	}
	
	
	
	fclose(file2);
		
	return 0;
}

