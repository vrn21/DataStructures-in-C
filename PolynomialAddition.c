// #include <stdio.h>
// #include <math.h>

// typedef struct Polynomial{
// 	int exp;
// 	int coeff;
// };

// void polyCreate (int n, struct Polynomial poly[], int *start, int *finish){
//     for(int i = *start; i < n + *start; i++){
//         printf("Enter degree of term in the polynomial: ");
//         scanf("%d", &poly[i].exp);
//         printf("Enter coefficient for it: ");
//         scanf("%d", &poly[i].coeff);
//     }
//     *finish = *start + n;
// }

// void printPoly(struct Polynomial poly[], int start, int finish){
// 	for(int i = start;i<finish;i++){
// 		if (poly[i].coeff){
// 		printf(" %dX%d ",poly[i].coeff,poly[i].exp);
// 		}
// 	}

// }

// void polyAdd(struct Polynomial poly[], int starta, int finisha, int startb, int finishb, int startc, int finishc){
// 	//startc = finishb+1;
// 	//finishc = startc-starta+finisha;
// 	for(int i = starta;i<finisha;i++){
// 		for(int j = startb;j<finishb;j++){
// 			if (poly[i].exp == poly[j].exp){
// 				int sum = poly[i].coeff + poly[j].coeff;
// 				poly[j+i].exp = poly[i].exp;
// 				poly[j+i].coeff = poly[i].coeff + poly[j].coeff;

// 			}
// 		}
// 	}

// }


// void polyEval(struct Polynomial poly[], int start, int finish, int x ){
// 	int val = 0;
// 	int power,coef;
// 	for(int i = start;i<finish;i++){
// 		power = poly[i].exp;
// 		coef = poly[i].coeff;
// 		val += (coef* (int)(pow(x,power)));

// 	}
// 	printf("THe final value is %d",val);
// }

// void main(){
// 	struct Polynomial poly[100];
// 	int n1, starta = 0 ,finisha = 0;

// 	//polynomial1
// 	printf("Enter details of your polynomial 1 \n");
// 	printf("Enter number of terms in polynomial ");
// 	scanf("%d",&n1);
// 	polyCreate(n1,&poly,&starta,&finisha);
// 	int x;
// 	printf("ENter value of x ");
// 	scanf("%d",&x);
// 	polyEval(poly,starta,finisha,x);

// 	//polynomial2

// 	int n2,startb,finishb;
// 	startb = finisha+1;
// 	finishb = startb;
// 	printf("Enter details of polynomial 2 \n ");
// 	printf("Enter number of terms in polynmial ");
// 	scanf("%d",&n2);
// 	polyCreate(n2, poly,&startb,&finishb);

// 	printf("The first polynomial is  \n");
// 	printPoly(poly, starta,finisha);
// 	printf("\n");
// 	printf("The second polynomial is \n");
// 	printPoly(poly,startb,finishb);
// 	int startc,finishc;
// 	startc = finishb+1;
// 	finishc = startc + finisha - starta + finishb - startb;
// 	polyAdd(&poly,starta,finisha,startb,finishb,startc,finishc);
// 	printf("The added polynomial is \n");
// 	printf("\n");
// 	printPoly(poly,startc,finishc);

// }


#include <stdio.h>
#include <math.h>

typedef struct Polynomial {
    int exp;
    int coeff;
} Polynomial;

void polyCreate(int n, Polynomial poly[], int *start, int *finish) {
    for (int i = *start; i < n + *start; i++) {
        printf("Enter degree of term in the polynomial: ");
        scanf("%d", &poly[i].exp);
        printf("Enter coefficient for it: ");
        scanf("%d", &poly[i].coeff);
    }
    *finish = *start + n;
}

void printPoly(Polynomial poly[], int start, int finish) {
    for (int i = start; i < finish; i++) {
        if (poly[i].coeff) {
            printf(" %dX%d ", poly[i].coeff, poly[i].exp);
        }
    }
}

void polyAdd(Polynomial poly[], int starta, int finisha, int startb, int finishb, int startc, int finishc) {
    for (int i = starta; i < finisha; i++) {
        for (int j = startb; j < finishb; j++) {
            if (poly[i].exp == poly[j].exp) {
                int sum = poly[i].coeff + poly[j].coeff;
                poly[i].exp = poly[i].exp;  // Corrected index and assignment
                poly[i].coeff = sum;        // Corrected index and assignment
            }
        }
    }
}

void polyEval(Polynomial poly[], int start, int finish, int x) {
    int val = 0;
    int power, coef;
    for (int i = start; i < finish; i++) {
        power = poly[i].exp;
        coef = poly[i].coeff;
        val += (coef * (int)pow(x, power));  // Cast to int for pow function
    }
    printf("The final value is %d", val);
}

int main() {
    Polynomial poly[100];
    int n1, starta = 0, finisha = 0;

    // Polynomial 1
    printf("Enter details of your polynomial 1 \n");
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n1);
    polyCreate(n1, poly, &starta, &finisha);
    int x;
    printf("Enter value of x: ");
    scanf("%d", &x);
    polyEval(poly, starta, finisha, x);

    // Polynomial 2
    int n2, startb, finishb;
    startb = finisha + 1;
    finishb = startb;
    printf("\nEnter details of polynomial 2 \n");
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n2);
    polyCreate(n2, poly, &startb, &finishb);

    printf("\nThe first polynomial is:\n");
    printPoly(poly, starta, finisha);
    printf("\n");
    printf("The second polynomial is:\n");
    printPoly(poly, startb, finishb);

    int startc, finishc;
    startc = finishb + 1;
    finishc = startc + finisha - starta + finishb - startb;
    polyAdd(poly, starta, finisha, startb, finishb, startc, finishc);
    printf("\nThe added polynomial is:\n");
    printPoly(poly, startc, finishc);

    return 0;
}


