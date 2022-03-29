#include <iostream>
#include <cmath>
using namespace std;
float norma(float *x,float *y,int n)
{
	int i;
	float m;
	float xm[n];
	for(i=0;i<n;i++)
	{
		xm[i]=abs(x[i]-y[i]);
	}
	for(i=0;i<n-1;i++)
	{
		if(xm[i]>xm[i+1])
		{
			m=xm[i];
		}
		else
		{
			m=xm[i+1];
		}
	}
	return m;
}
float s(float **a,float *x,int n,int i)
{
	int j;
	float sa=0;
	for (j=0;j<n;j++)
	{
		if(j==i)
		{
			sa=sa+0;
		}
		else
		{
			sa=sa+a[i][j]*x[j];
		}
	}
	return sa;
}
void ya(float **a,float *x0,float *x,float *b,float eps,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				a[i][j]/=a[i][i];
			}
		}
		b[i]/=a[i][i];
		a[i][i]=1;
	}
	for(i=0;i<n;i++)
	{
		x[i]=b[i];
	}
	do
	{
		for(i=0;i<n;i++)
		{
			x0[i]=x[i];
		}
		for(i=0;i<n;i++)
		{
			x[i]=b[i]-s(a,x0,n,i);
		}
	}
	while(norma(x,x0,n)>eps);
}
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
int main()
{
	setlocale(LC_ALL, "Russian");
	int i,n;
	float eps;
	float **a;
	float *b,*x,*x0;
	cout<<"¬ведите размерность матрицы:\n";
	cin>>n;
	cout<<"¬ведите точность вычислений:\n";
	cin>>eps;
	x=new float [n];
	x0=new float [n];
	b=new float [n];
	a=new float *[n];
	for(i = 0; i < n; i++)
	{
		a[i] = new float [n];
	}
	vvod(a,b,n);
	ya(a,x0,x,b,eps,n);
	for(i=0;i<n;i++)
	{
		cout<<"X"<<i+1<<" = "<<x[i]<<"\n";
	}
}