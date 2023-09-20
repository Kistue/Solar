function[Suntime] = Suntime(Standertime,E,Stander_Longitude,Longitude,i)

switch i
    case -1
        Suntime = Standertime + E - 4*(Stander_Longitude-Longitude);  %东半球太阳时
    case 1
        Suntime = Standertime + E + 4*(Stander_Longitude-Longitude);  %西半球太阳时
end