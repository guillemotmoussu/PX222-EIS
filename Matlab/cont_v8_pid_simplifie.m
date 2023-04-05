function  [sSys,sCor,sRepFreq,sRepTemp] = cont_v8_pid_simplifie_exemple
% Fichier d'exemple de parametrage de l'utilitaire PIDcontSynth_v8_simplifie

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

%--------------------------------------------------------------------------
% Systeme
sSys = struct(...
        'sys',          sys,...	% Fonction de transfert du systeme en 's'
        'ARef',         10,...  % Amplitude de la consigne
        'APu',          3,... 	% Amplitude de l'entree de perturbation de commande
        'APutau',       1e-3,...% Constante de temps du 1er ordre de la perturbation
        'APb',          0.1,... % Amplitude du bruit de mesure
        'Nmax',         10,...	% Amplification max autorisee du bruit de mesure
        'MaxMeasCteTime', 2);	% Valeur max. de la cte de tps d'un filtre de mesure du 1er ordre
    
% Correcteur
sCor = struct(...
        'Gain',        1.8,...      % Gain proportionnel
        'Ti',          1.4,...      % Constante de temps de l'integrateur 
        'Int_on',      1,...        % Integrateur : on=1, off=0
        'Td',          0.47,...     % Constante de temps du derivateur
        'a' ,          4,...        % Coeff. de filtrage du derivateur
        'Der_on',      1,...        % Derivateur : on=1, off=0
        'Wref',        1,...        % Pulsation propre du Prefiltre
        'Wref_on',     1,...        % Prefiltre : on=1, off=0
        'Rmin',        0.01,...     % Valeur min pour les gains du correcteur
        'Rmax',        100  );     % Valeur max pour les gains du correcteur
       
% Parametres des Reponse frequentielles
sRepFreq = struct(...
        'Wmin',        1e-3,...    % pulsation min (rad/s)
        'Wmax',        1e3,...     % pulsation max (rad/s)
        'Gdbmax',      60,...      % Gain max en dB
        'Gdbmin',      -40,...     % Gain min en dB
        'Pmax',        90,...      % Phase max en degres
        'Pmin',        -225 );     % Phase min en degres
    
% Reponse temporelle
sRepTemp = struct(...
        'Tinit',    30,...      % Duree initiale de la simulation
        'Tmin',     0.1,...     % Duree minimale de la simulation
        'Tmax',     1000,...    % Duree maximale de la simulation
        'Ymax',     1.4*sSys.ARef,...     % Valeur max affichee pour Y
        'Ymin',    -0.2*sSys.ARef,...     % Valeur min affichee pour Y
        'Yticks', [-0.2 -0.05 0 0.05 0.95 1 1.05 1.2]*sSys.ARef,... % lignes pointilles
        'Umax',     20,...       % Valeur max affichee pour U
        'Umin',    0,...       % Valeur min affichee pour U
        'Uticks',[ 15 16 17 18 ]);
        %'Uticks',[ -8 -6 -2 0 2 4 6 8]); % lignes pointilles
%--------------------------------------------------------------------------