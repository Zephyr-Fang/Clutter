function beperimMethod()
I = imread('0.9_ANSYS.jpg');
H=rgb2gray(I);    %�ҶȻ�
BWI = im2bw(I,0.24);    %imbinarize���Ҷ�ͼ��Iת��ɶ�����ͼ��BW,level����ֵ�ȼ���ȡֵ��Χ[0,1]��I*level�����ֵ��Ϊ1������Ϊ0
BWI1 = bwperim(BWI,8);    %8������ȡ��Ե
J = imread('0.9_REAL.jpg');
BWJ = im2bw(J,0.23);    %imbinarize���Ҷ�ͼ��Iת��ɶ�����ͼ��BW,level����ֵ�ȼ���ȡֵ��Χ[0,1]��I*level�����ֵ��Ϊ1������Ϊ0
BWJ1 = bwperim(BWJ,4);    %8������ȡ��Ե
figure;
subplot(2,2,1);
imshow(I);
title('ANSYS-original iamge');
subplot(2,2,2);
imshow(BWI1);
title('ANSYS-bwperim');
subplot(2,2,3);
imshow(J);
title('REAL-original iamge');
subplot(2,2,4);
imshow(BWJ1);
title('ANSYS-bwperim');
end