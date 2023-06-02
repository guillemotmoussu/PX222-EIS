clear
close all
clc

I0 = 1.8;
Z0 = 6.2 * 10^-3;
L1 = 1.296;
m = 37.6;
alpha = L1 / (2 * (45.8215)^2 * m * 9.81);
alpha2 = 1/1.0243;

ki = (I0 * L1 * alpha) / (1 + alpha * Z0) ^2;
kz = -(I0 ^2 * L1 * alpha ^2) / (1 + alpha * Z0) ^3;

num =  ki ;
den = [(-m) 0 kz];

sys = tf(num,den);

figure;
bode(sys)
grid on
figure;
nyquist(sys)
grid on