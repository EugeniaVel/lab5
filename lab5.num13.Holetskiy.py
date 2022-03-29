def si(m,i):
    s=0
    for k in range(i):
        s=s+m[i][k]**2
    return s
def sj(m,i,j):
    s=0
    for k in range(j):
        s=s+m[i][k]*m[j][k]
    return s
def sy(m,y,i):
    s=0
    for j in range(i):
        s=s+m[i][j]*y[j]
    return s
def sx(m,x,i,n):
    s=0
    for j in range(i+1,n):
        s=s+m[j][i]*x[j]
    return s
print("Введите размерность матрицы:")
n = int(input())
a=[]
for i in range (n):
    print("Введите коэффиценты переменных " + str(i+1) + " строки через пробел:")
    num = list(map(int,input().split()))
    a.append (num)
b=[]
for j in range (n):
    print("Введите результат "+str(j+1)+" уравнения:")
    numb = int(input())
    b.append(numb)
l=[]
for i in range(n):
    num=[]
    for j in range(n):
        num.append(0)
    l.append(num)
for j in range(n):
    if j==0:
        l[j][0]=(a[0][0])**0.5
    else:
        l[j][0]=a[j][0]/l[0][0]
for j in range(1,n):
    for i in range(j,n):
        if i==j:
            s=si(l,i)
            l[i][j]=(a[i][j]-s)**0.5
        else:
            s=sj(l,i,j)
            l[i][j]=(a[i][j]-s)/l[j][j]
y=[]
prom=b[0]/l[0][0]
y.append(prom)
for i in range(1,n):
    prom=(b[i]-sy(l,y,i))/l[i][i]
    y.append(prom)
x=[]
for i in range(n):
    x.append(0)
x[n-1]=y[n-1]/l[n-1][n-1]
i=n-2
while i>=0:
    x[i]=(y[i]-sx(l,x,i,n))/l[i][i]
    i=i-1
for i in range(n):
    print("x"+str(i+1)+"="+str(x[i]))