import math

def function_a(x):
    """
    :param x: x value(float)
    :return: f(x) value(float)
    """
    return math.exp(-x**2)

def function_b(x):
    """
    :param x: x value(float)
    :return: f(x) value(float)
    """
    return (x**2.5)

def function_c(x):
    """
    :param x: x value(float)
    :return: f(x) value(float)
    """
    return 1/(2+math.cos(x))

def intergral_by_trapezoidal_rule(lower,upper,n,f):
    """
    :param lower: lower bounds(float type)
    :param upper: upper bounds(float type)
    :param n: number of intervals(int type)
    :param f: f(x) function(function type)
    :return: integral(float type)
    """
    xi=[]
    h=(upper-lower)/n
    for i in range(n+1):
        xi.append(lower+i*h)
    yi=list(map(f,xi))
    integral = 0
    for i in range(n):
        integral+=(yi[i]+yi[i+1])*h/2
    return integral

def get_answer(f,bounds,integral_formula):
    """
    :param f: f(x) function(function type)
    :param bounds: lower and upper bounds(float type)
    :param integral_formula: function to caculate integral(function type)
    :return: no return, just print
    """
    interval_seq=[2,4,8,16,32,64,128,256,512]
    integral_seq=[]
    for n in interval_seq:
        integral_seq.append(integral_formula(bounds[0],bounds[1],n,f))
    print(integral_seq)
    rn=(integral_seq[7]-integral_seq[6])/(integral_seq[8]-integral_seq[7])
    print(rn)
    return

bounds_seq=[[0,1],[0,1],[0,2*math.pi]]
#bounds_seq=[[0,1],[0,2*math.pi]]
function_seq=[function_a,function_b,function_c]
#function_seq=[function_b,function_c]

for func,bounds in zip(function_seq,bounds_seq):
    pass
    # get_answer(func,bounds,intergral_by_trapezoidal_rule)

def intergral_by_simpson_rule(lower,upper,n,f):
    """
    :param lower: lower bounds(float type)
    :param upper: upper bounds(float type)
    :param n: number of intervals(int type)
    :param f: f(x) function(function type)
    :return: integral(float type)
    """
    xi=[]
    h=(upper-lower)/n
    for i in range(n+1):
        xi.append(lower+i*h)
    yi=list(map(f,xi))
    integral = 0
    for i in range(0,n,2):
        integral+=(yi[i]+4*yi[i+1]+yi[i+2])*h/3
    return integral

for func,bounds in zip(function_seq,bounds_seq):
    pass
    # get_answer(func,bounds,intergral_by_simpson_rule)

def intergral_by_gauss_legendre(lower,upper,n,f):
    """
    :param lower: lower bounds(float type)
    :param upper: upper bounds(float type)
    :param n: number of intervals(int type)
    :param f: f(x) function(function type)
    :return: integral(float type)
    """
    xi=[]
    h=(upper-lower)/n
    for i in range(n+1):
        xi.append(lower+i*h)
    integral = 0
    for i in range(n):
        x0=(xi[i+1]+xi[i])/2-0.861136311594052*h/2
        x1=(xi[i+1]+xi[i])/2-0.339981043584856*h/2
        x2=(xi[i+1]+xi[i])/2+0.339981043584856*h/2
        x3=(xi[i+1]+xi[i])/2+0.861136311594052*h/2
        x=[x0,x1,x2,x3]
        y=list(map(f,x))
        integral+=(0.347854845137454*y[0]+0.652145154862546*y[1]+0.652145154862546*y[2]+0.347854845137454*y[3])*h/2
    return integral
"""
for func,bounds in zip(function_seq,bounds_seq):
    get_answer(func,bounds,intergral_by_gauss_legendre)
"""
def intergral_by_romberg_integration(f,bounds,integral_formula):
    """
    :param f: f(x) function(function type)
    :param bounds: lower and upper bounds(float type)
    :param integral_formula: function to caculate integral(function type)
    :return: no return, just print
    """
    inn=[]
    inn.append([])
    interval_seq = [2, 4, 8, 16, 32, 64, 128, 256, 512]
    for n in interval_seq:
        inn[0].append(integral_formula(bounds[0], bounds[1], n, f))
    for i in range(1,20):
        if 9-i<=0: break
        inn.append([])
        for j in range(1,10-i):
            inn[i].append((inn[i-1][j]*2**(2*i)-inn[i-1][j-1])/(2**(2*i)-1))
    print(inn)

for func,bounds in zip(function_seq,bounds_seq):
    intergral_by_romberg_integration(func,bounds,intergral_by_gauss_legendre)