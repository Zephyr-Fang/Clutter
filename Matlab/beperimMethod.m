function beperimMethod()
I = imread('0.9_ANSYS.jpg');
H=rgb2gray(I);    %灰度化
BWI = im2bw(I,0.24);    %imbinarize将灰度图像I转变成二级制图像BW,level：阈值等级，取值范围[0,1]，I*level大，则该值变为1，否则为0
BWI1 = bwperim(BWI,8);    %8领域提取边缘
J = imread('0.9_REAL.jpg');
BWJ = im2bw(J,0.23);    %imbinarize将灰度图像I转变成二级制图像BW,level：阈值等级，取值范围[0,1]，I*level大，则该值变为1，否则为0
BWJ1 = bwperim(BWJ,4);    %8领域提取边缘
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