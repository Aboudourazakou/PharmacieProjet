#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H
#include "Pharmacien.h"
#include <Windows.h>

class Medicament;
class Administrateur : public Pharmacien
{
	
	
	public:
		
		Administrateur(int,string,string);
		void creerPharmacien();
		void supprimerPharmacien();
		bool modifierPharmacien(string);
		void modifierMedicament(string,Medicament &);
		void ajouterMedicament(Medicament &M);
		void supprimerMedicament();
		void ModifierMedicament();
		void supprimerFacture();
		void afficherPharmaciens();
		
		
		

};
#include"Medicament.h"

#endif

