function[G0] = G0(Gsc,n,Theta)
    G0 = Gsc*(1+0.033*cosd(360*n/365))*cosd(Theta);  %大气层外水平面上的太阳能辐照度

end