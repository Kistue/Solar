function[a0,a1,k0,Tb,Td] = yixieshuju(A,sitaz)
% a0_ = 0.4237-0.00821*(6-A)^2  ;        %A为海拔
% a1_ = 0.5055+0.00595*(6.5-A)^2;
% k_ = 0.2711+0.01858*(2.5-A)^2;
a0 = 0.95*(0.4237-0.00821*(6-A)^2);
a1 = 0.98*(0.5055+0.00595*(6.5-A)^2);
k0 = 1.02*(0.2711+0.01858*(2.5-A)^2);
Tb = a0 + a1*exp(-1.02/cos(sitaz));
Td = 0.2710-0.2939*Tb;

