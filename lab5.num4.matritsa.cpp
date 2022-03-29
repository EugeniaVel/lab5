#include <iostream>
using namespace std;
void nolik(int **m,int **nov,int i,int j,int n)
{
	int ii,jj;
	int ip=0;
	int jp=0;
	for(ii=0;ii<n-1;ii++)
	{
		if(ii==i)
		{
			ip=1;
		}
		for(jj=0;jj<n-1;jj++)
		{
			if(jj==j)
			{
				jp=1;
			}
			nov[ii][jj]=m[ii+ip][jj+jp];
		}
		jp=0;
	}
}
void vvod(int **a,int *x,int n)
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
int d(int **m)
{
	int det;
	det=m[0][0]*m[1][1]-m[0][1]*m[1][0];
	return det;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i,j,det,c,S,n;
	int *x;
	int **a,**nov;
	cout<<"¬ведите размерность матрицы:";
	cin>>n;
	int om[n][n];
	x=new int [n];
	a=new int*[n];
	nov=new int*[n-1];
	for(i = 0; i < n; i++)
	{
		a[i] = new int [n];
	}
	for(i = 0; i < n-1; i++)
	{
		nov[i] = new int [n-1];
	}
	vvod(a,x,n);
	det=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]);
	if (det==0)
	{
		cout<<"ќбратной матрицы нет, так как данна€ матрица вырожденна€.";
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			c=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=c;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			nolik(a,nov,i,j,n);
			if((i+j)%2==0)
			{
				om[i][j]=d(nov);
			}
			else
			{
				om[i][j]=-d(nov);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			om[i][j]*=x[j];
		}
	}
	for(i=0;i<n;i++)
	{
		S=0;
		for(j=0;j<n;j++)
		{
			S=S+om[i][j];
		}
		x[i]=S/det;
		cout<<"X"<<i+1<<" = "<<x[i]<<"\n";
	}
	return 0;
}