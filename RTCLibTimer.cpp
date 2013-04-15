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

#include "Arduino.h"
//#include "RTClib.h"
#include "RTClibTimer.h"

//#define ON 1
//#define OFF 0

  RTClibTimer::RTClibTimer(){ // constructeur par défaut
  
 
  }
  
//////////// fonctions membre de la classe //////////////

// ------ routine de gestion du timer ---- à placer dans loop --- 
void RTClibTimer::service(long unixtimeIn, void (*userFunc)(int), int indexIn) {
	
      if (this->etat==ON) { // si le timer est actif
      
        //if (timer[compt][i]==0) { // si premier passage  
        if (compt==0) { // si premier passage  
          this->debut=unixtimeIn; // mémorise début
          this->last=unixtimeIn; // initialise last
          this->compt=1; // incrémente compteur
          
          userFunc(indexIn); // appelle la fonction passée en pointeur avec l'argument voulu 
          
          //timerEvent(i); // appelle fonction voulue
          
        } // fin si premier passage 
        else { // si compt >=1 = passages suivants
          
          if (unixtimeIn-this->last>=this->interval) { // si l'intervalle du timer s'est écoulé
          
           Serial.print("\nIntervalle timer ");
           Serial.print(indexIn), 
           Serial.print (" ecoule."); 
           
           this->compt=this->compt+1; // incrémente compteur
           this->last=unixtimeIn; // RAZ last          

          userFunc(indexIn); // appelle la fonction passée en pointeur avec l'argument voulu 

          //timerEvent(i); // appelle fonction voulue
  
           if ( (maxCompt!=0) && (compt>=maxCompt) ) {
             Serial.println("\n>>>>>>>>>>>>>>>>>< Desactivation timer <<<<<<<<<<<<<<<<"); 
             this->etat=0; // stoppe le timer si nombre max atteint et si pas infini (timer[maxCompt]!=0)
           } // fin si comptMax atteint
           
          } // fin if intervalle écoulé
            
        } // fin else compt>=1
      
      } // fin si timer ON 
	
} // fin service()

//---- initialisation Timer avec intervalle et limite ------ 
void RTClibTimer::start(long intervalIn, long maxComptIn) {
    
    this->interval=intervalIn; // intervalle EN SECONDES !!
    this->maxCompt=maxComptIn; // nombre d'évènements voulus - durée = (n-1) x delai
    this->compt=0; // initialise comptage au démarrage
    this->etat=ON; // active le timer

} // fin start

//---- initialisation Timer avec intervalle et sans limite------ 
void RTClibTimer::start(long intervalIn) {
    
    this->interval=intervalIn; // intervalle EN SECONDES !!
    this->maxCompt=0; // nombre d'évènements voulus - 0 = sans fin
    this->compt=0; // initialise comptage au démarrage
    this->etat=ON; // active le timer

} // fin start

//----- démarre timer sans modifier les paramètres actuels --- 
void RTClibTimer::start() {
  
    this->etat=ON; // active le Timer sans modifier les paramètres courants

} // fin start 

//----- stoppe le timer sans modifier les paramètres actuels --- 
void RTClibTimer::stop() {
  
    this->etat=OFF; // désactive le Timer sans modifier les paramètres courants

} // fin stop timer

//---- info timer ---------
//void RTClibTimer::status(String strIn){ // la fonction met les infos dans le String passé en paramètre // marche pas
 void RTClibTimer::status(){ // la fonction affiche les infos sur le port série 

	
      // affiche état Timer
	
      if (this->etat==1)Serial.println("Timer actif"); else Serial.println("Timer inactif");
      Serial.print("intervalle="), Serial.println(this->interval); 
      Serial.print("limite comptage="), Serial.println(this->maxCompt); 
      Serial.print("comptage actuel="), Serial.println(this->compt); 
      Serial.print("debut="), Serial.println(this->debut); 
      Serial.print("dernier="), Serial.println(this->last);     
	

	/*
	  strIn=""; 
      if (this->etat==1)strIn=strIn+"Timer actif\n"; else strIn=strIn+"Timer inactif\n";
      strIn=strIn+"intervalle="+String(this->interval); 
      strIn=strIn+"limite comptage="+String(this->maxCompt); 
      strIn=strIn+"comptage actuel="+String(this->compt); 
	  strIn=strIn+"debut="+String(this->debut); 
      strIn=strIn+"dernier="+String(this->last);     
	*/
	
} // fin info Timer 
