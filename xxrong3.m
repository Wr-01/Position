x0;
t=bdxyz(7,:);
plot(t,x0);
hold on;%等着
xx0;
plot(t,xx0);
hold on;%等着
legend('原始值', 'EKF后验估计值');%图例
hold on
title("时间与坐标变化量对比");
ylabel('坐标变化量');

tt=bdxyz(:,7);
xxx=bdxyz(:,1);
plot(tt,xxx);
hold on;%等着
plot(tt,x11,'c-');
hold on;%等着
plot(tt,x111,'r-');
hold on;
legend('原始值', 'EKF后验估计值','改进的EKF融合值');%图例
xlabel('时间戳(s)');
ylabel('x轴坐标(mm)');

tt=bdxyz(:,7);
xxx=bdxyz(:,1);
plot(tt,xxx,'b--');
hold on;%等着
plot(tt,x11,'c+-');
hold on;%等着
plot(tt,x111,'r.-');
hold on;
legend('原始值', 'EKF后验估计值','改进的EKF融合值');%图例
xlabel('时间戳(s)');
ylabel('x轴坐标(mm)');


tt=bdxyz(:,7);
xxx=bdxyz(:,1);
plot(tt,xxx);
hold on;%等着
title("The change in the X-axis of the target over time");
% plot(tt,x11,'c-');
% hold on;%等着
% plot(tt,x111,'r-');
% hold on;
% legend('Original value','EKF algorithm update value','Estimated value of fusion scheme');%图例
xlabel('Time stamp(s)');
ylabel('X-axis coordinate(mm)');

tt=bdxyz(:,7);
plot(tt,x1);
hold on;%等着
plot(tt,x11,'c-');
hold on;%等着
plot(tt,x111,'r-');
legend('原始值', 'EKF后验估计值','改进的EKF融合值');%图例
xlabel('时间戳(s)');
ylabel('x轴坐标(mm)');

fyj;
t1=1:1:4576;
plot(t1,fyj);
hold on;%等着
fff;
plot(t1,fff);
hold on;%等着
legend('原始值', 'EKF后验估计值');%图例
hold on
title("俯仰角处理结果");
ylabel('俯仰角角度');

x;y;z;
% scatter3(x,y,z);
plot3(x,y,z,'k+');
hold on;
xx;yy;zz;
plot3(xx,yy,zz,'bp');
hold on;
legend('Original value', 'Estimated value of fusion scheme');
hold on;
% x 轴标签legend('X-axis', 'Y-axis','Z-axis');%图例
xlabel('X-axis coordinate(mm)');
% y 轴标签
ylabel('Y-axis coordinate(mm)')
% z 轴标签
zlabel('Z-axis coordinate(mm)')

x=Untitled(1,:);
y=Untitled(2,:);
z=Untitled(3,:);
plot3(x,y,z);
hold on
% 设置标题
title('初始数据轨迹图')
% x 轴标签
xlabel('x');
% y 轴标签
ylabel('y')
% z 轴标签
zlabel('z')