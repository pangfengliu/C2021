#include <stdio.h>
#include <math.h>
 
double distance(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
} 
 
double computeX(double a1, double b1, double c1,
		double a2, double b2, double c2)
{
  return -(c1 * b2 - b1 * c2)/(a1 * b2 - b1 * a2);
}
 
double computeY(double a1, double b1, double c1,
		double a2, double b2, double c2)
{
  return -(a1 * c2 - c1 * a2)/(a1 * b2 - b1 * a2);
}
 
int main()
{
  int n;
  scanf("%d", &n);
  double a[n], b[n], c[n]; 
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%lf", &a[i], &b[i], &c[i]); 
#ifdef DEBUG
    printf("%f %f %f\n", a[i], b[i], c[i]); 
#endif
  }
 
  double x[n], y[n];
  for (int i = 0; i < n; i++) {                        
    int next = (i + 1) % n;
    x[i] = computeX(a[i], b[i], c[i], a[next], b[next], c[next]);
    y[i] = computeY(a[i], b[i], c[i], a[next], b[next], c[next]);
  }
 
  double totalDistance = 0.0;
  for (int i = 0; i < n; i++) {                        
    int next = (i + 1) % n;
    totalDistance += distance(x[i], y[i], x[next], y[next]);
  }
  printf("%.3lf\n", totalDistance);
 
#ifdef DEBUG
  printf("%f\n", distance(3.0, -1.0, 6.0, 3.0));
  printf("x = %f\n", computeX(1, 1, -5, 1, -1, -1));
  printf("y = %f\n", computeY(1, 1, -5, 1, -1, -1));
#endif
  return 0;
}
