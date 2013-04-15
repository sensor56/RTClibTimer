RTCLibTimer
===========

Ma librairie RTCLibTimer est une surcouche à la librairie « temps-réel » RTCLib et permet d'implémenter facilement des objets « timers temps-réel » (ou « timers RTC »)

Chaque objet timer RTC dispose des paramètres suivants : 
* boolean etat;  // variable d'état du timer - true/false actif/inactif
* long interval; // variable intervalle entre 2 événements en secondes 
* long maxCompt; // variable nombre événements max - comptage sans fin si =0
* long compt; // variable nombre événements survenus depuis début comptage
* long debut; // variable unixtime de debut
* long last; // variable unixtime dernier événement

Chaque objet timer dispose des fonctions suivantes : 
* void start(long intervalIn, long maxComptIn); // initialisation timer avec limite 
* void start(long intervalIn); // initialisation timer sans fin 
* void start(); //----- démarre timer sans modifier les paramètres actuels --- 
	
* void stop();//----- stoppe le timer sans modifier les paramètres actuels --- 

* void status(); //---- affiche infos sur l'état du timer - les infos sont affichées sur le port série 
	
* void service(long unixtimeIn, void (*userFunc)(int), int indexIn) ; // routine de gestion du timer, à placer dans loop 


Cette librairie est utilisée notamment dans mon projet "The Open Datalogger Project" : https://github.com/sensor56/TheOpenDataloggerProject
