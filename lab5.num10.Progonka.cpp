#include <iostream>
using namespace std;
void vvod(float **a,float *x,int n)
{
	int i,j;
	for(i=0;i<n;i++)	
	{
		cout<<"¬ведите коэффициенты "<<i+1<<" уравнени€:\n";
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		cout<<"¬ведите результат "<<i+1<<" уравнени€:\n";
		cin>>x[i];
	}
}
void tom(float **m, float *x, float *y, float *al, float *be, int n)
{
	int i;
	float a,b,c,d;
	y[0]=m[0][0];
	al[0]=-m[0][1]/y[0];
	be[0]=x[0]/y[0];
	for(i=1;i<n-1;i++)
	{
		a=m[i][i-1];
		b=m[i][i];
		c=m[i][i+1];
		d=x[i];
		y[i]=b+a*al[i-1];
		al[i]=-c/y[i];
		be[i]=(d-a*be[i-1])/y[i];
	}
	y[n-1]=m[n-1][n-1]+m[n-1][n-2]*al[n-2];
	be[n-1]=(x[n-1]-m[n-1][n-2]*be[n-2])/y[n-1];
	x[n-1]=be[n-1];
	for(i=n-2;i>=0;i--)
	{
		x[i]=al[i]*x[i+1]+be[i];
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i,n;
	float **a;
	float *x,*y,*al,*be;
	cout<<"¬ведите размерность матрицы:\n";
	cin>>n;
	x=new float [n];
	y=new float [n];
	al=new float [n];
	be=new float [n];
	a=new float*[n];
	for(i = 0; i < n; i++)
	{
		a[i] = new float [n];
	}
	vvod(a,x,n);
	tom(a,x,y,al,be,n);
	for(i=0;i<n;i++)
		cout<<"X"<<i+1<<" = "<<x[i]<<"\n";
}