function yy=PnByNewtonMethod(x,y,xx,n)
%created by FZF
%��divided difference����n����϶���ʽ������Ĭ����n+1�����ݵ㡣
l=length(xx);
f=zeros(n+1,n+1);
for m=1:n+1
    f(1,m)=y(m);
end
%to calculate the coefficients, with the first column represents f0[i]
for j=1:n
    for i=1:(n+1-j)
        f(j+1,i)=(f(j,i+1)-f(j,i))/(x(i+j)-x(i));
    end
end
%to form the polynomial
for m2=1:l
    yy(m2)=f(1,1);
    phi(m2)=1;
    for m1=2:n+1
        phi(m2)=phi(m2)*(xx(m2)-x(m1-1));
        yy(m2)=yy(m2)+f(m1,1)*phi(m2);
    end
end 