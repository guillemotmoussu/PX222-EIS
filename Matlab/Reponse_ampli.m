clear
close all
clc

% Définition des paramètres du signal
f = 1/0.2;      % Fréquence (1/période)
t = 0:0.001:1;  % Temps d'échantillonnage (0,001 s)
V1 = 5/2 * square(2 * pi * f * t) + 5/2;  % Signal carré 1 de 0 V à 5 V
V2 = 30/2 * square(2 * pi * f * t) + 30/2; % Signal carré 2 de 0 V à 30 V

% Tracé des signaux
figure;
plot(t, V2, 'b', 'LineWidth', 2);
hold on;
plot(t, V1, 'r', 'LineWidth', 2);
xlabel('Temps (s)');
ylabel('Tension (V)');
title('Entrée et sortie de l''amplificateur');
legend('Sortie (0V-30V)','Entrée (0V-5V)');
grid on;
