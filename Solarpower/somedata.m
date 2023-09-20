function[a0,a1,k0, a0_,a1_,k_, r0,r1,k] = somedata(A,j)
  
    a0_ = 0.4237-0.00821*(6-A)^2;          %A为海拔
    a1_ = 0.5055+0.00595*(6.5-A)^2;        %A为海拔
    k_ = 0.2711+0.01858*(2.5-A)^2;         %A为海拔
    
  

  switch j
      case 00
          r0 = 0.95;
          r1 = 0.98;
          k  = 1.02;
      case 10
          r0 = 0.97;
          r1 = 0.99;
          k  = 1.02;
      case 20
          r0 = 0.99;
          r1 = 0.99;
          k  = 1.01;   
      case 11
          r0 = 1.03;
          r1 = 1.01;
          k  = 1.00;

  end


    a0 = r0 * a0_;
    a1 = r1 * a1_;
    k0 = k  * k_;

