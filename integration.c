#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x);  // retourne un double
}

// Méthode des rectangles au milieu
double rectangle(double a, double b, int n) {
    double h = (b - a) / n, somme = 0.0;

    for (int k=0; k<n; ++k) {
        double xk = a + (k + 0.5) * h;
        somme += f(xk);
    }
    return somme * h;
}

int main() {
    FILE *file = fopen("fonction.txt", "w");

    double pas_de_temps = 0.001;
    double a = 0.0, b = M_PI / 2;


    for (double x=a; x<=b; x+=pas_de_temps){
        int n = (int)ceil( (x-a) / pas_de_temps);
        if (n<1) n = 1;
        double integ = rectangle(a, x, n);

        fprintf(file, "%.6f\t%.6f\t%.6f\n", x, f(x), integ);
    }
    int nn = (int)ceil( (b-a) / pas_de_temps);
    printf("Pour la fonction actuelle, on a une intégrale =%lf\n", rectangle(a,b,nn));

    fclose(file);
    return 0;
}

