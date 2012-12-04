#include <iostream>
using namespace std;
int main() {
	double begin = 0, end = 2, step = 0.001;
	double phi1_1 = 1.0, phi2_2 = 0.25, phi3_3 = 1.0 / 18;
	for( double x = 0; x <= 2; x += step ) {
		double phi4 = 0, phi3, phi2, phi1;
		for( double k = 1; k <= 1500; ++k )
			phi4 += 1.0 / (k * (k + 1) * (k + 2) * (k + 3) * (k + x));
		phi3 = phi4 * (3 - x) + phi3_3;
		phi2 = phi3 * (2 - x) + phi2_2;
		phi1 = phi2 * (1 - x) + phi1_1;
		//if(x == 0)
		//	printf("%16.12lf %16.12lf %16.12lf %16.12lf\n", phi3_3, phi2_2, phi1_1, phi4);
		printf("%5.3lf %16.12lf\n", x, phi1);
	}
	return 0;
}
