#include"iostream"
using namespace std;
int main()
{
	float A,B,C;
	cin>>A>>B>>C;
	if((A<=B)&&(B<=C)&&(A<=C))
	{
		A=C;
		B=B;
		C=A;		
	}
	else if((A<=B)&&(C<=B)&&(C<=A))
	{
		A=B;
		B=A;
		C=C;
	}
	else
	{
		A=A;
		B=B;
		C=C;
	}
	
	float D=A*A;
	
	if(A>=(B+C))
	{
		cout<<"NAO FORMA TRIANGULO";
	}	
	if(D=(B*B)+(C*C))
	{
		cout<<"TRIANGULO RETANGULO";
	}
	if(D>(B*B)+(C*C))
	{
		cout<<"TRIANGULO OBTUSANGULO";
	}
	if(D<(B*B)-(C*C))
	{
		cout<<"TRIANGULO ACUTANGULO";
	}
	if(A==B==C)
	{
		cout<<"TRIANGULO EQUILATERO";
	}
	if(((A=B)&&(A!=C))||((B=C)&&(B!=A))||((C=A)&&(C!=B)))
	{
		cout<<"TRIANGULO ISOSCELES";
	}
}
