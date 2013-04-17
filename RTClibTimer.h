/*
 * Copyright (c) - Avril 2013 by Xavier HINAULT - support@mon-club-elec.fr
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 3
 * or the GNU Lesser General Public License version 3, both as
 * published by the Free Software Foundation.
 */

/* Ma librairie RTCLibTimer est une surcouche à la librairie « temps-réel » RTCLib  (https://github.com/adafruit/RTClib) 
 * et permet d'implémenter facilement des objets « timers temps-réel » (ou « timers RTC »)
*/

#ifndef RTClibTimer_h
#define RTClibTimer_h

#include "Arduino.h"

//#include "RTClib.h"

#define ON 1
#define OFF 0


class RTClibTimer { 

  private : // variables internes
  
  public : // variables publiques de la classe 

  //String paramString; 
  boolean etat;  // variable d'état du timer - true/false actif/inactif
  long interval; // variable intervalle entre 2 événements en secondes 
  long maxCompt; // variable nombre événements max 
  long compt; // variable nombre événements survenus depuis début comptage
  long debut; // variable unixtime de debut
  long last; // variable unixtime dernier événement
  
  public : // fonctions publiques 
  // toutes les fonctions publiques de la librairie doivent être pré-déclarées ici 
  
    RTClibTimer(); // constructeur
  
	
	//---- fonctions de gestion des timers RTC 

	void start(long intervalIn, long maxComptIn); // initialisation timer avec limite 
	void start(long intervalIn); // initialisation timer sans fin 
	void start(); //----- démarre timer sans modifier les paramètres actuels --- 
	
	void stop();//----- stoppe le timer sans modifier les paramètres actuels --- 

	//void status(String strIn); //---- affiche infos sur l'état du timer - les infos sont mises dans le String passé en paramètre - marche pas
	void status(); //---- affiche infos sur l'état du timer - les infos sont affichées sur le port série 
	
	void service(long unixtimeIn, void (*userFunc)(int), int indexIn) ; // routine de gestion du timer, à placer dans loop 
	
  private : // fonctions internes
  // toutes les fonctions internes (ou privées) de la librairie doivent être pré-déclarées ici 
  

}; // fin classe 


#endif
