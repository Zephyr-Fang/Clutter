function myBinsecFunction()
%created by FangZhenfang//exp(x0)-3*x0^2;//y0_derivative=exp(x0)-6*x0;
x0=1;
x1=4;
error=0.00001;
y0=exp(x0)-3*x0^2;
y1=exp(x1)-3*x1^2;
while(y0*y1<0)
    tmp_result=0.5*(x1+x0)
    x=0.5*(x0+x1);
    y=exp(x)-3*x^2;
    if(y*y0<0)
        x1=x;
    else
        x0=x;
    end
    if(abs(x1-x0)<error)
        break;
    end
end
result_x=0.5*(x1+x0)
end