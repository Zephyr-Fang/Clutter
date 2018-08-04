function findEpsilon()
%created by FangZhenfang
tst_eps=1;
while((1+tst_eps)>1)
    tst_eps=tst_eps/2;
end
tst_eps=2*tst_eps
build_in_eps=eps(1)
end