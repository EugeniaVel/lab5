import copy
print("Введите размерность матрицы:")
n = int(input())
a=[]
for i in range (n):
    print("Введите коэффиценты переменных " + str(i+1) + " строки через пробел:")
    num = list(map(int,input().split()))
    a.append (num)
print("Введите результаты уравнений через пробел:")
b = list(map(int,input().split()))
print("Введите приближённые значения переменных через пробел:")
x = list(map(int,input().split()))
print("Укажите точность вычислений:")
eps=float(input())
def norma(x,y,n):
    xm=[]
    for i in range(n):
        o=abs(x[i]-y[i])
        xm.append(o)
    for i in range(n-1):
        if xm[i]>xm[i+1]:
            m=xm[i]
        else:
            m=xm[i+1]
    return m
def s(a,x,i,n):
    si=0
    for j in range(n):
        if j==i:
            si=si
        else:
            si=si+a[i][j]*x[j]
    return si
for i in range(n):
    b[i]/=a[i][i]
    for j in range(n):
        if j!=i:
            a[i][j]=a[i][j]/a[i][i]
    a[i][i]=1
nor=1
while nor>eps:
    x0=copy.deepcopy(x)
    for i in range(n):
        x[i]=b[i]-s(a,x,i,n)
    nor=norma(x,x0,n)
for i in range(n):
    print("x"+str(i+1)+"="+str(x[i]))