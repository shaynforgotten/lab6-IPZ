#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // TASK 6.1 
    double x = 6.8;     
    int n = 4;         
    double epsilon = 0.001;

    double y = x;
    double y_prev;

    for (int i = 0; i < 1000; i++) {
        y_prev = y;
        y = (1.0 / n) * ((x / pow(y, n - 1)) + (n - 1) * y);

        if (fabs(y - y_prev) <= epsilon) {
            cout << "Reached accuracy on iteration " << i + 1 << endl;
            break;
        }
    }

    cout << "Calculated root value: " << y << endl;

    // TASK 6.2 
    double x0 = 1; 
    double epsilon = 0.001;
    double x_prev = x0;
    double x_next;
    int iteration = 0;

    cout << "Iteration\tX_i\t\t\t|X_i+1 - X_i|" << endl;

    do {
        double f = x_prev + pow(3, x_prev) + 1;
        double f_prime = 1 + pow(3, x0) * log(3);
        x_next = x_prev - f / f_prime;
        iteration++;
        cout << iteration << "\t\t" << fixed << setprecision(6) << x_next << "\t\t" << fabs(x_next - x_prev) << endl;

        if (fabs(x_next - x_prev) < epsilon) {
            break;
        }
        x_prev = x_next;
    } while (true);

    cout << "\nRoot: " << x_next << " (accuracy: " << epsilon << ")" << endl;
    cout << "Number of iterations: " << iteration << endl;

    // TASK 6.3 
    double x = 0.2;
    double epsilon = 0.01;
    double a_k = 1.0;
    double f_x = a_k;
    int k = 0;
    int iterations = 1;

    while (abs(a_k) > epsilon) {
        k++;
        a_k *= (2 * k - 1) * x / ((2 * k) * (2 * k + 1));
        f_x += a_k;
        iterations++;
    }

    cout << "Computed f(" << x << ") = " << f_x << endl;
    cout << "Number of iterations: " << iterations << endl;
}
