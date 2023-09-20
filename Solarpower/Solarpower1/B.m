function[B] = B(n)
B = (360 * (n-81))/364;
end




% deta = 23.45 * sin(360*(284+n)/365);  % n---所求日期在一年中的日子数
% suntime = standertime + E - 4*(120-Longitude);
% 
% E = 9.87*sin(2B) - 7.53cos(B) - 1.5sin(B);
% w = 15 * (suntime - 12);

%由地平坐标到时角坐标
% sin(deta) = sin(fhi)*cos(z) - cos(fhi)*sin(z)*cos(A);  
% 
% 
% cos(deta)*sin(t) = sin(z)*sin(A);
% cos(deta)*cos(t) = sin(fhi)*sin(z)*cos(A) + cos(z)*cos(fhi);

%由时角坐标到地平坐标
% cos(z) = sin(fhi)*sin(deta) + cos(fhi)*cos(deta)*cos(t);
% sin(z)*sin(A) = cos(deta) * sin(t);
% sin(z)*cos(A) = -sin(deta)*cos(fhi) + cos(deta)*sin(fhi)*cos(t)

%由赤道坐标到黄道坐标
% sin('beta')=sin('deta')*cos('e')-sin('e')*cos('deta')*sin('a')
% cos('beta')*cos('lmd') = cos('deta')*cos('a')
% cos('beta')*sin('lmd')=sin('e')*sin('deta') + cos('deta')*cos('e')*sin('a')


%由黄道坐标到赤道坐标
% sin('deta') = sin('beta')*cos('e') + sin('e')*cos('beta')*sin('lmd')
% cos('deta')*coa('a') = cos('beta')*cos('lmd')
% cos('deta')*sin('a') = -sin('e')*sin('beta') + cos('beta')*cos('e')*sin('lmd')


% sin('as') = sin('deta')*sin('fhi') + cos('deta')*cos('fhi')*cos('w')  %太阳高度角as计算
% sin('sitaz') = sin('deta')*sin('fhi') + cos('deta')*cos('fhi')*cos('w') %天顶角sitaz


% cos('gamas') = (sin('as')*sin('fhi')-sin('deta'))/cos('as')*cos('fhi')    
% sin('gamas') = (cos('deta')*sin('w'))/cos('as')



% cos('wsita') = -tan('fhi')*tan('deta')      %wsita为日出、日末时角，正为日末时角，负为日出时角


% 
% 
% 
% E0 = 1+0.033*cos('360*n/365')
% Gon = Gsc*(1+0.033*cos('360*n/365'))  %Gon为一年中第n天在法向平面上测得的大气层外的辐照度，Gsc为太阳常数
% Gsc = 1353    %太阳常数Gsc  W/m2
% G0 = Gsc(1+0.033*cos('360*n/365'))*cos('sitaz');  %大气层外水平面上的太阳能辐照度
% H0 = (24*3600*Gsc/pi)*(1+0.033cos('360*n/365'))*(cos('fhi')*cos('deta')*sin('ws')+sin('fhi')*sin('deta')*((2*pi*ws)/360))
% I0 = (12*3600/pi)*Gsc*(1+0.033*cos('360*n/365'))*( cos('fhi')*cos('deta')* (sin('w2')-sin('w1')) + sin('fhi')*sin('deta')*( (2*pi*(w2-w1))/360 ) )


% a0_ = 0.4237-0.00821*(6-A)^2          %A为海拔
% a1_ = 0.5055+0.00595*(6.5-A)^2
% k_ = 0.2711+0.01858*(2.5-A)^2
% a0 = 0.95*a0_
% a1 = 0.98*a1_
% k0 = 1.02*k_
% Tb = a0 + a1*exp(-1.02/cos('sitaz'))
% Td = 0.2710-0.2939Tb

% Gcnb = Gon*Tb     %晴天，垂直于辐射方向上的直射辐照度
% Gcb = Gon*Tb*cos('sitaz')  %水平面上的直射辐照度
% 
% Icb = 3600*Gcb  %水平面上小时直射辐照量
% Gcd = Gon*Td*cos('sitaz')
% Icd = 3600*Gcd  %散射辐射部分计算
% Ic = Icb + Icd  %水平面上的小时辐射量