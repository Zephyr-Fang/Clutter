function edgeMethod()
H=imread('1.png');    %提取图像
I=rgb2gray(H);    %灰度化
BW1=edge(I,'sobel');    %用SOBEL算子进行边缘检测
figure;    %生成一张画布
subplot(4,2,1);
imshow(I);
title('original image');
subplot(4,2,2);
imshow(BW1);
title('sobel');

BW2=edge(I,'roberts');    %用Roberts算子进行边缘检测
subplot(4,2,3);
imshow(BW2);
title('roberts');

BW3=edge(I,'prewitt');    %用prewitt算子进行边缘检测
subplot(4,2,4);
imshow(BW3);
title('prewitt');

BW4=edge(I,'log');    %用log算子进行边缘检测
subplot(4,2,5);
imshow(BW4);
title('log');

BW5=edge(I,'canny');    %用canny算子进行边缘检测
subplot(4,2,6);
imshow(BW5);
title('canny');

h=fspecial('gaussian',5);    %加噪提取
BW6=edge(I,'canny');
subplot(4,2,7);
imshow(BW6);
title('gasussian&canny');
end