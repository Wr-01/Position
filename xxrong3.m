x0;
t=bdxyz(7,:);
plot(t,x0);
hold on;%����
xx0;
plot(t,xx0);
hold on;%����
legend('ԭʼֵ', 'EKF�������ֵ');%ͼ��
hold on
title("ʱ��������仯���Ա�");
ylabel('����仯��');

tt=bdxyz(:,7);
xxx=bdxyz(:,1);
plot(tt,xxx);
hold on;%����
plot(tt,x11,'c-');
hold on;%����
plot(tt,x111,'r-');
hold on;
legend('ԭʼֵ', 'EKF�������ֵ','�Ľ���EKF�ں�ֵ');%ͼ��
xlabel('ʱ���(s)');
ylabel('x������(mm)');

tt=bdxyz(:,7);
xxx=bdxyz(:,1);
plot(tt,xxx,'b--');
hold on;%����
plot(tt,x11,'c+-');
hold on;%����
plot(tt,x111,'r.-');
hold on;
legend('ԭʼֵ', 'EKF�������ֵ','�Ľ���EKF�ں�ֵ');%ͼ��
xlabel('ʱ���(s)');
ylabel('x������(mm)');


tt=bdxyz(:,7);
xxx=bdxyz(:,1);
plot(tt,xxx);
hold on;%����
title("The change in the X-axis of the target over time");
% plot(tt,x11,'c-');
% hold on;%����
% plot(tt,x111,'r-');
% hold on;
% legend('Original value','EKF algorithm update value','Estimated value of fusion scheme');%ͼ��
xlabel('Time stamp(s)');
ylabel('X-axis coordinate(mm)');

tt=bdxyz(:,7);
plot(tt,x1);
hold on;%����
plot(tt,x11,'c-');
hold on;%����
plot(tt,x111,'r-');
legend('ԭʼֵ', 'EKF�������ֵ','�Ľ���EKF�ں�ֵ');%ͼ��
xlabel('ʱ���(s)');
ylabel('x������(mm)');

fyj;
t1=1:1:4576;
plot(t1,fyj);
hold on;%����
fff;
plot(t1,fff);
hold on;%����
legend('ԭʼֵ', 'EKF�������ֵ');%ͼ��
hold on
title("�����Ǵ�����");
ylabel('�����ǽǶ�');

x;y;z;
% scatter3(x,y,z);
plot3(x,y,z,'k+');
hold on;
xx;yy;zz;
plot3(xx,yy,zz,'bp');
hold on;
legend('Original value', 'Estimated value of fusion scheme');
hold on;
% x ���ǩlegend('X-axis', 'Y-axis','Z-axis');%ͼ��
xlabel('X-axis coordinate(mm)');
% y ���ǩ
ylabel('Y-axis coordinate(mm)')
% z ���ǩ
zlabel('Z-axis coordinate(mm)')

x=Untitled(1,:);
y=Untitled(2,:);
z=Untitled(3,:);
plot3(x,y,z);
hold on
% ���ñ���
title('��ʼ���ݹ켣ͼ')
% x ���ǩ
xlabel('x');
% y ���ǩ
ylabel('y')
% z ���ǩ
zlabel('z')