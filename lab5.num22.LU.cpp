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
float su(float **l,float **u,int i,int j)
{
	int k;
	float s=0;
	for(k=0;k<i;k++)
	{
		s=s+l[i][k]*u[k][j];
	}
	
	return s;
}
float sl(float **l,float **u,int i,int j)
{
	int k;
	float s=0;
	for(k=0;k<j;k++)
	{
		s=s+l[i][k]*u[k][j];
	}
	return s;
}
float sy(float **l,float *y,int i)
{
	int k;
	float s=0;
	for(k=0;k<i;k++)
	{
		s=s+l[i][k]*y[k];
	}
	return s;
}
float sx(float **u,float *x,int i,int n)
{
	int k;
	float s=0;
	for(k=i+1;k<n;k++)
	{
		s=s+u[i][k]*x[k];
	}
	return s;
}
void LU(float **m,float **l,float **u,float *x,float *b,int n)
{
	int i,j;
	float y[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			l[i][j]=0;
			u[i][j]=0;
		}
		l[i][i]=1;
	}
	for(i=0;i<n;i++)
	{
		l[i][0]=m[i][0]/m[0][0];
		u[0][i]=m[0][i];
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<=j)
			{
				u[i][j]=m[i][j]-su(l,u,i,j);
			}
			else
			{
				l[i][j]=(m[i][j]-sl(l,u,i,j))/u[j][j];
			}
		}
	}
	y[0]=b[0];
	for(i=1;i<n;i++)
	{
		y[i]=b[i]-sy(l,y,i);
	}
	x[n-1]=y[n-1]/u[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		x[i]=(y[i]-sx(u,x,i,n))/u[i][i];
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i,n;
	float *x,*b;
	float **a,**l,**u;
	cout<<"¬ведите размерность матрицы:";
	cin>>n;
	x=new float [n];
	b=new float [n];
	a=new float*[n];
	l=new float*[n];
	u=new float*[n];
	for(i = 0; i < n; i++)
	{
		a[i] = new float [n];
		l[i] = new float [n];
		u[i] = new float [n];
	}
	vvod(a,b,n);
	LU(a,l,u,x,b,n);
	for(i=0;i<n;i++)
	{
		cout<<"X"<<i+1<<" = "<<x[i]<<"\n";
	}
}