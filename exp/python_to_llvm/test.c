double calculate(double a, double* b){
    return a / (b[0] + b[1]);
}

int main(){
    volatile double a = 2;
    volatile double b[2] = {3, 5};
	return (int)(calculate(a, b));
}
