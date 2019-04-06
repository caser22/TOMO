m1=load('real_vel.dat');
s1=reshape(m1,400,300); 
m2=load('init_vel.dat');
s2=reshape(m2,500,300);
figure(1)
imagesc(s1)
colormap(gray)
figure(2)
imagesc(s2)
colormap(gray)

% text(500,80,'\fontsize{20}\fontname{宋体}V=1500m/s','color','b')
% text(500,300,'\fontsize{18}\fontname{宋体}V=2000m/s','color','b')
% text(500,510,'\fontsize{20}\fontname{宋体}V=2500m/s','color','r')
%text(300,300,'\fontsize{13}\fontname{宋体}V=2500m/s')
%text(300,500,'\fontsize{13}\fontname{宋体}V=1000m/s')
%title('\fontsize{15}\fontname{宋体}水平介质模型')
