import math
import pandas as pd

def diff_equation(x,y):
    """
    :param x: float type
    :param y: float type
    :return: Derivatives value(float type)
    """
    return x**2-y

def function_true(x):
    """
    :param x: float type
    :return: float type
    """
    return x**2-2*x+2-math.exp(-x)

def euler_method(bounds,h,diff_equation,y0,function_true):
    """
    :param bounds: lower and upper bounds(double type)
    :param h: interval(double type)
    :param diff_equation: differential equaltion used for caculate y'
    :param y0: given y value
    :param function_true: actual function
    :return: no return
    """
    xi=[bounds[0]]
    yi_a=[y0]
    yi_t=[function_true(xi[0])]
    error=[yi_t[0]-yi_a[0]]
    relative_err=[error[0]/yi_t[0]]
    n=int((bounds[1]-bounds[0])/h)
    for i in range(1,n+1):
        xi.append(bounds[0]+h*i)     # add xi[i]
        yi_a.append(yi_a[i-1]+h*diff_equation(xi[i-1], yi_a[i-1]))    # add yi_a[i]
        yi_t.append(function_true(xi[i]))    # add yi_t[i]
        error.append(yi_t[i]-yi_a[i])
        relative_err.append(error[i]/yi_t[i])
    #print(yi_a[::int(0.25/h)])
    #print(yi_t[::int(0.25/h)])
    #print(error[::int(0.25/h)])
    #print(relative_err[::int(0.25/h)])

h_seq=[0.25,0.125,0.0625]
bounds=[0,4]
y0=1
for h in h_seq:
    euler_method(bounds,h,diff_equation,y0,function_true)

def diff_equation_a(x,y):
    """
    param x: float type
    :param y: float type
    :return: Derivatives value(float type)
    """
    return -y**2

def diff_equation_b(x,y):
    """
    param x: float type
    :param y: float type
    :return: Derivatives value(float type)
    """
    return y/4*(1-y/20)

def diff_equation_c(x,y):
    """
    param x: float type
    :param y: float type
    :return: Derivatives value(float type)
    """
    return -y+2*math.cos(x)

def diff_equation_d(x,y):
    """
    param x: float type
    :param y: float type
    :return: Derivatives value(float type)
    """
    return y-2*math.sin(x)

def function_true_a(x):
    """
    :param x: float type
    :return: float type
    """
    return 1/(1+x)

def function_true_b(x):
    """
    :param x: float type
    :return: float type
    """
    return 20/(1+19*math.exp(-x/4))

def function_true_c(x):
    """
    :param x: float type
    :return: float type
    """
    return math.cos(x)+math.sin(x)

function_true_d=function_true_c

def midpoint_rule(bounds,h,diff_equation,y0,function_true):
    """
    :param bounds: lower and upper bounds(double type)
    :param h: interval(double type)
    :param diff_equation: differential equaltion used for caculate y'
    :param y0: given y value
    :param function_true: actual function
    :return: yi_a,error(list type)
    """
    xi=[bounds[0],bounds[0]+h]
    yi_a=[y0,y0+h*diff_equation(xi[0],y0)]
    yi_t=[function_true(xi[0]),function_true(xi[1])]
    error=[yi_t[0]-yi_a[0],yi_t[1]-yi_a[1]]
    relative_err=[error[0]/yi_t[0],error[1]/yi_t[1]]
    n=int((bounds[1]-bounds[0])/h)
    for i in range(2,n+1):
        xi.append(bounds[0]+h*i)     # add xi[i]
        yi_a.append(yi_a[i-2]+2*h*diff_equation(xi[i-1], yi_a[i-1]))    # add yi_a[i]
        yi_t.append(function_true(xi[i]))    # add yi_t[i]
        error.append(yi_t[i]-yi_a[i])    # add error[i]
        relative_err.append(error[i]/yi_t[i])    # add relative_err[i]
    # print("yi_a(h=%*.*f)="%(3,2,h),yi_a)
    # print("yi_t(h=%*.*f)="%(3,2,h),yi_t)
    # print("error(h=%*.*f)="%(3,2,h),error)
    # print("relative_err(h=%*.*f)="%(3,2,h),relative_err)
    return yi_a,error

function_seq=[function_true_a,function_true_b,function_true_c,function_true_d]
diff_seq=[diff_equation_a,diff_equation_b,diff_equation_c,diff_equation_d]
h_seq=[0.5,0.25]
bounds=[0,5]
y0=1
res_tmp=[]
for function,diff in zip(function_seq,diff_seq):
    for h in h_seq:
        tmp_yi,tmp_error=midpoint_rule(bounds,h,diff,y0,function)
        res_tmp+=[tmp_yi,tmp_error]
res1=[]
for c,d,g,h,k,l,o,p in zip(res_tmp[2],res_tmp[3],res_tmp[6],res_tmp[7],
                           res_tmp[10],res_tmp[11],res_tmp[14],res_tmp[15]):
    res1.append([c,d,g,h,k,l,o,p])
name1=["yi_a(h=0.25)", "err_a(h=0.25)",
      "yi_b(h=0.25)", "err_b(h=0.25)",
      "yi_c(h=0.25)", "err_c(h=0.25)",
      "yi_d(h=0.25)", "err_d(h=0.25)"]
answer=pd.DataFrame(columns=name1,data=res1)
answer.to_csv("0.25_answer.csv")
res2=[]
for a,b,e,f,i,j,m,n in zip(res_tmp[0],res_tmp[1],res_tmp[4],res_tmp[5],
                           res_tmp[8],res_tmp[9],res_tmp[12],res_tmp[13]):
    res2.append([a,b,e,f,i,j,m,n])
name2=["yi_a(h=0.5)", "err_a(h=0.5)",
      "yi_b(h=0.5)", "err_b(h=0.5)",
      "yi_c(h=0.5)", "err_c(h=0.5)",
      "yi_d(h=0.5)", "err_d(h=0.5)"]
answer=pd.DataFrame(columns=name2,data=res2)
answer.to_csv("0.5_answer.csv")