import copy
def m(b,n,i,j):
    ip=0
    jp=0
    minor=[]
    for ii in range(n-1):
        oop=[]
        if ii==i:
            ip=1
        for jj in range(n-1):
            if jj==j:
                jp=1
            aaaa=b[ii+ip][jj+jp]
            oop.append(aaaa)
        minor.append(oop)
        jp=0
    return minor
def d(b):
    de=b[0][0]*b[1][1]-b[0][1]*b[1][0]
    return de
def d3(a,n):
    det=0
    for i in range(n):
        ad=m(a,n,0,i)
        dd=a[0][i]*d(ad)
        if (i+2)%2==0:
            det=det+dd
        else:
            det=det-dd
    return det


print("Введите размерность матрицы:")
n = int(input())
a=[]
for i in range (n):
    print("Введите коэффиценты переменных " + str(i+1) + " строки через пробел:")
    num = list(map(int,input().split()))
    a.append (num)
deta=d3(a,n)
if deta==0:
    print("Корней нет, так как определитель матрицы равен нулю.")
b=[]
for j in range (n):
    print("Введите результат "+str(j+1)+" уравнения:")
    numb = int(input())
    b.append(numb)
x=[]
for j in range(n):
    ax=copy.deepcopy(a)
    for i in range(n):
        ax[i][j]=b[i]
    xx=d3(ax,n)/deta
    x.append(xx)
for i in range(n):
    print("x"+str(i+1)+"="+str(x[i]))