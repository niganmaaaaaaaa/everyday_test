#include<iostream>
using namespace std;
double a, b, c, l, r;
int main()
{
    scanf("%lf%lf%lf", &a, &b, &c);
    l = 0;
    r = 1000;
    while (l < r)
    {
        double e, f, mid;
        mid = (l + r) / 2;
        e = mid / 100 + 1;
        f = 0;
        for (int i = 0; i < c; i++)
        {
            f += b / e;
            e = e * (mid / 100 + 1);
        }
        if (f > a)
            l = mid + 0.00001;
        else
            r = mid - 0.00001;
    }
    if (l <= 0)
        printf("0.0");
    else
        printf("%.1lf", r);
}