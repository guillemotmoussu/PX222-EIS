I0 = 2;  
Z0 = 22 * 10^-3; 
L1 = 6.73;
alpha = 2.06;

ki = (I0 * L1 * alpha) / (1 + alpha * Z0) ^2;
kz = -(I0 ^2 * L1 * alpha ^2) / (1 + alpha * Z0) ^3;
m = 35.8 % masse de la bille (par rapport à P = mg);


B = [ ki ]
A = [(-m) 0 kz]

sys = tf(B,A);


figure; hold on
bode(sys)
figure;
nyquist(sys)
