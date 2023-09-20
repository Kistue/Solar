function [Gon] = Gon(Gsc,n)
    
    Gon = Gsc*(1+0.033*cosd(360*n/365));  %Gon为一年中第n天在法向平面上测得的大气层外的辐照度，Gsc为太阳常数

end