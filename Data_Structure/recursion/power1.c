//반복
double slow_power(double x, int n){
    int i;
    double result=1.0;

    for(i=0;i<n;i++)
        result*=x;

    return result;
}