function myNewtonMethod(z0)
%Created by FangZhenfang
%z0=2.5+4.5i;
error=0.00001;
f0=z0^4-3*z0^3+20*z0^2+44*z0+54;
f0_derivative=4*z0^3-9*z0^2+40*z0+44;
z1=z0-f0/f0_derivative
abs(z1-z0)
while(abs(z1-z0)>=error)
    f1=z1^4-3*z1^3+20*z1^2+44*z1+54;
    f1_derivative=4*z1^3-9*z1^2+40*z1+44;
    z=z1-f1/f1_derivative;
    z0=z1;
    z1=z
    abs(z1-z0)
end
end