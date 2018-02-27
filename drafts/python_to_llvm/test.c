double calculate(double a, double b){
    return a / b;
}

int main(){
    volatile double a = 2;
    volatile double b = 3;
	return (int)(calculate(a, b));
}
