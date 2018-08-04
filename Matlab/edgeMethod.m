function edgeMethod()
H=imread('1.png');    %��ȡͼ��
I=rgb2gray(H);    %�ҶȻ�
BW1=edge(I,'sobel');    %��SOBEL���ӽ��б�Ե���
figure;    %����һ�Ż���
subplot(4,2,1);
imshow(I);
title('original image');
subplot(4,2,2);
imshow(BW1);
title('sobel');

BW2=edge(I,'roberts');    %��Roberts���ӽ��б�Ե���
subplot(4,2,3);
imshow(BW2);
title('roberts');

BW3=edge(I,'prewitt');    %��prewitt���ӽ��б�Ե���
subplot(4,2,4);
imshow(BW3);
title('prewitt');

BW4=edge(I,'log');    %��log���ӽ��б�Ե���
subplot(4,2,5);
imshow(BW4);
title('log');

BW5=edge(I,'canny');    %��canny���ӽ��б�Ե���
subplot(4,2,6);
imshow(BW5);
title('canny');

h=fspecial('gaussian',5);    %������ȡ
BW6=edge(I,'canny');
subplot(4,2,7);
imshow(BW6);
title('gasussian&canny');
end