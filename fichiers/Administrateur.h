#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Pharmacien.h"

class Administrateur : public Pharmacien
{
	
	
	public:
		Administrateur(int,string,string ,string);
		void creerPharmacien();
		void supprimerPharmacien();
		void modifierPharmacien();
		void ajouterMedicament();
		void supprimerMedicament();
		void ModifierMedicament();
		void supprimerFacture();
		
		

};

#endif
