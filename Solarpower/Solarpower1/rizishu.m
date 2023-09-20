function[n] = rizishu(Month,Date)
switch Month
    case 1
        n = Date;
    case 2
        n = 31+Date;
    case 3
        n = 59+Date;
    case 4
        n = 90+Date;
    case 5
        n = 120+Date;
    case 6
        n = 151+Date;
    case 7
        n = 181+Date;
    case 8
        n = 212+Date;
    case 9
        n = 243+Date;
    case 10
        n = 273+Date;
    case 11
        n = 304+Date;
    case 12
        n = 334+Date;

end
