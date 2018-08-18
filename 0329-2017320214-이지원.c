#include<stdio.h>
//0이 아닌 항들만 배열에 저장.(계수, 차수)형식으로 배열에 저장.
#define MAX_TERMS 100 //배열 terms의 크기.
typedef struct {
	float coef;//계수
	int expon;//차수
}polynomial;

polynomial terms[MAX_TERMS]
= { { 3,5 },{ 2,2 },{ 4,0 },{ 1,4 },{ 10,3 },{ 3,2 },{ 1,0 } };//구조체 이용해서 (계수, 차수)형식으로 배열에 저장.
int avail = 0;
polynomial terms[MAX_TERMS];
int COMPARE(float a, float b);
void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd);
void attach(float a, int b);


int main() {

	int i = 0;

	int fina = 0;
	int finb = 0;
	int strd = 0;
	int find = 0;
	//다항식 A
	fina = 2;
	finb = 6;

	printf("A(X) = 3X^5 + 2X^2 + 4\n");
	printf("B(X) = X^4 + 10X^3 + 3X^2 + 1\n");
	avail = finb + 1;
	padd(0, fina, fina + 1, finb, &strd, &find);
	printf("Result = ");
	for (i = strd; i <= find; i++)
	{	
		if (terms[i].coef == 0)
			continue;
		else if (terms[i].expon == 0)
			printf("%d", (int)terms[i].coef);
		else if (terms[i].coef ==1 && terms[i].expon!=0)
			printf("X^%d", terms[i].expon);
		else printf("%dX^%d", (int)terms[i].coef,terms[i].expon);
		if (i != find)
			printf(" + ");
	}
	printf("\n");
	return 0;
}

int COMPARE(float a, float b) {
	if (a < b)
		return -1;
	else if (a == b)
		return 0;
	else return 1;
}

void attach(float a, int b)
{
	terms[avail].coef = a;
	terms[avail].expon = b;
	avail++;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
	float coefficient;
	*startd = avail; //d는 결과에 대해.
	while (starta <= finisha && startb <= finishb)
	{
		switch (COMPARE(terms[starta].expon, terms[startb].expon)) {
		case -1:
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case 0:
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient) //coefficient 가 0이 아닐 때 시행하라는 말?
				attach(coefficient, terms[starta].expon);
			starta++;
			startb++;
			break;
		case 1:
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
			break;

		}
	}
	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expon);
	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expon);
	*finishd = avail - 1;

}