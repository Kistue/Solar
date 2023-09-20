function[H0] = H0(Gsc,n,Latitude,deta,ws)
   H0 = (24*3600*Gsc/pi)*(1+0.033*cosd(360*n/365))*(cosd(Latitude)*cosd(deta)*sind(abs(ws))+sind(Latitude)*sind(deta)*((2*pi*abs(ws))/360));

end