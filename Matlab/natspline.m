function [yy,dy,d2] = natspline(x,y,xx)
% natspline: natural spline with differentiation
%   [yy,dy,d2] = natspline(x,y,xx): uses a natural cubic spline
%   interpolation to find yy, the values of the underlying function
%   y at the points in the vector xx. The vector x specifies the
%   points at which the data y is given.
% input:
%   x = vector of independent variables
%   y = vector of dependent variables
%   xx = vector of desired values of dependent variables
% output:
%   yy = interpolated values at xx
%   dy = first derivatives at xx
%   d2 = second derivatives at xx
n = length(x);
if length(y)~=n, error('x and y must be same length'); end
if any(diff(x)<=0),error('x not strictly ascending'),end
m = length(xx);
b = zeros(n,n);
aa(1,1) = 1; aa(n,n) = 1; %set up Eq. 18.27
bb(1)=0; bb(n)=0;
for i = 2:n-1
  aa(i,i-1) = h(x, i - 1);
  aa(i,i) = 2 * (h(x, i - 1) + h(x, i));
  aa(i,i+1) = h(x, i);
  bb(i) = 3 * (fd(i + 1, i, x, y) - fd(i, i - 1, x, y));
end
c=aa\bb'; %solve for c coefficients
for i = 1:n - 1 %solve for a, b and d coefficients
  a(i) = y(i);
  b(i) = fd(i + 1, i, x, y) - h(x, i) / 3 * (2 * c(i) + c(i + 1));
  d(i) = (c(i + 1) - c(i)) / 3 / h(x, i);
end
for i = 1:m %perform interpolations at desired values
  [yy(i),dy(i),d2(i)] = SplineInterp(x, n, a, b, c, d, xx(i));
end
end

function hh = h(x, i)
hh = x(i + 1) - x(i);
end

function fdd = fd(i, j, x, y)
  fdd = (y(i) - y(j)) / (x(i) - x(j));
end

function [yyy,dyy,d2y]=SplineInterp(x, n, a, b, c, d, xi)
for ii = 1:n - 1
  if xi >= x(ii) - 0.000001 & xi <= x(ii + 1) + 0.000001
    yyy=a(ii)+b(ii)*(xi-x(ii))+c(ii)*(xi-x(ii))^2+d(ii)...
          *(xi-x(ii))^3;
    dyy=b(ii)+2*c(ii)*(xi-x(ii))+3*d(ii)*(xi-x(ii))^2;
    d2y=2*c(ii)+6*d(ii)*(xi-x(ii));
    break
  end
end
end