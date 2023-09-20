clear ;
Year = input('请输入年份:');
Month = input('请输入月份:');
Date = input('请输入日期:');
i = input('请输入所在半球序号（东半球为-1，西半球为1）：');
Longitude = input('请输入经度：');
Stander_Longitude = input('请输入标准经度：');
Latitude = input('请输入纬度：');
Standertime = input('请输入标准时间：');
A = input('请输入海拔：');
j = input('请输入气候类型（亚热带为00，中等纬度夏天为10，高纬度夏天为20，中等纬度冬天为11）：');



n = rizishu(Month,Date);
deta = deta(n);
B = B(n);
E = E(B);
%Suntime = Suntime(Standertime,E,Stander_Longitude,Longitude,i);  %太阳时
w = -7.5;   
Suntime = w/15 + 12;

Theta = acosd(sind(deta)*sind(Latitude)+cosd(deta)*cosd(Latitude)*cosd(w)); %天顶角
Alpha = asind(sind(deta)*sind(Latitude)+cosd(deta)*cosd(Latitude)*cosd(w)); %太阳高度角
Gamma = asind( (cosd(deta)*sind(w)) / cosd(Alpha) );    %太阳方位角
Gsc = 1353;     
Gon = Gon(Gsc,n);
ws = acosd(-tand(Latitude)*tand(deta));
N = (2/15) * ws;  %一天中可能的日照时间
G0 = G0(Gsc,n,Theta);   %大气层外水平面上的太阳能辐照度
H0 = H0(Gsc,n,Latitude,deta,ws);
[a0,a1,k0, a0_,a1_,k_, r0,r1,k] = somedata(A,j);
Tb = a0 + a1*exp(-k0/cosd(Theta));  %晴天，直射辐射的大气透明度Tb
Td = 0.2710 - 0.2939*Tb;    %散射辐射的大气透明度Td
Gcnb = Gon * Tb;    %晴天，垂直于辐射方向上的直辐射照度Gcnb
Gcb = Gon * Tb * cosd(Theta);    %水平面上的直射辐照度Gcb
Icb = (3600 * Gcb);   %水平面上小时直射辐射量Icb
Gcd = Gon * Td * cosd(Theta);    
Icd = (3600 * Gcd);      %散射辐射部分计算
Ic = (Icb + Icd);     %水平面上的小时辐射量



fprintf('日子数n为：%d\n', n);
%fprintf('太阳时n为：%fmin\n', Suntime);
fprintf('赤纬角δ为：%f°\n', deta);
fprintf('天顶角cosθ为：%f°\n', cosd(Theta));
%fprintf('太阳高度角α为：%f°\n', Alpha);
%fprintf('太阳方位角γ为：%f°\n', Gamma);
%fprintf('一天中日照时间N为：%f \n', N);
fprintf('r0为：%f\n',r0);
fprintf('r1为：%f\n',r1);
fprintf('k为：%\n',k);
fprintf('直射辐射的大气透明度Tb为：%f\n', Tb);
fprintf('散射辐射的大气透明度Td为：%f\n', Td);
fprintf('Gcnb为：%fW/m²\n',Gcnb);
fprintf('Gcb为：%fW/m²\n',Gcb);
fprintf('Gcd为：%fW/m²\n',Gcd);
fprintf('水平面上小时直射辐射量Icb为：%fW/m²\n', Icb);
fprintf('水平面上小时散射辐射量Icd为：%fW/m²\n', Icd);
fprintf('水平面上的小时辐射量Ic：%fW/m²\n', Ic);





