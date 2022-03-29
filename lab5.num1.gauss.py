import math
print("Введите размерность матрицы:")
n = int(input())
a=[]
for i in range (n):
    print("Введите коэффиценты переменных " + str(i+1) + " строки через пробел:")
    num = list(map(int,input().split()))
    a.append (num)
print("Введите результаты уравнений через пробел:")
x = list(map(int,input().split()))
for k in range (n-1):
    am=math.fabs(a[k][k])
    im=k
    for i in range(k+1,n):
        if math.fabs(a[i][k])>am:
            am=math.fabs(a[i][k])
            im=i
    if k!=im:
        c=x[k]
        x[k]=x[im]
        x[im]=c
        for j in range (k,n):
            c=a[k][j]
            a[k][j]=a[im][j]
            a[im][j]=c
    for j in range(k+1,n):
        c=a[j][k]
        for i in range(k,n):
            a[j][i]=(a[j][i]*a[k][k]-a[k][i]*c)/c
        x[j]=(x[j]*a[k][k]-x[k]*c)/c
x[n-1]=x[n-1]/a[n-1][n-1]
i=n-2
while i>=0:
    for j in range(i+1,n):
        x[i]=x[i]-x[j]*a[i][j]
    x[i]=x[i]/a[i][i]
    i=i-1
for i in range(n):
    print("x"+str(i+1)+"="+str(x[i]))