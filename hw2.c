#include <stdio.h>
//girilen paranin, girilen zamanda, belirli fazilerle hesaplanmasi..

int main() {

	int P;         /* P=Amount of money */
	float t;       /* t=time */
	double I,r;    /* I=interest of a principal amount, r=interest rate  */
	double A;      /* A=Amount of money including interest */
	float n,T;   /* n=new money with interest, T=Total money after interest */
	printf("Enter the amount of money:");
	scanf("%d",&P);
	
	printf("Enter the time:");
	scanf("%f",&t);
	
	t=t/12;
	
	if (P<1000 || P>1000000) {
		printf("Out of range/amount of money.");
			if (t<0.50 || t>2.00){
		printf("Out of range/time.");
	}	
	}
	
	if (1000<=P<=9999){
		r=0.050;
		if (0.50<=t<1.00){
			I=P*t*r*(1-(1-t)*r);
		}
		else if (t=1.00){
			I=P*r;
			printf("%.3lf",P+I);
		}
		else{
			printf("You can not choose this time interval for this amount of money!");
		}
	}
	
	
	if (10000<=P<=99999){
		r=0.067;
		if (t==1.00){
			I=P*r;
		}
		else if (1.00<t<2.00){
			t=t-1.00;
			I=P*t*r*(1-(1-t)*r);
			I=I+(P*r);
		}
		else if (t==2.00){
			I=P*r;
			n=P+I;
			I=I+((P+I)*r);
		}
		else{
			printf("You can not choose this time interval for this amount of money!");
		}
	}
	

	if (100000<=P<=999999){
		r=0.075;
		if (0.50<=t<1.00){
			I=P*t*r*(1-(1-t)*r);
		}
		else if(t==1.00){
			I=P*r;
		}
		else {
			printf("You can not choose this time interval for this amount of money!");
		}
	}

	A=P+I;
	
	printf("Total money=%.3lf",A);

return 0;
}
