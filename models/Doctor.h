/*************************************************************************
                           Doctor  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Doctor> (fichier Doctor.h) ----------------
#if ! defined ( Doctor_H )
#define Doctor_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Doctor>
//
//
//------------------------------------------------------------------------

class Doctor
{
//----------------------------------------------------------------- PUBLIC

public:
    
    //------------------------------------------------- Surcharge d'opérateurs
    
    friend ostream & operator << (ostream &, const Doctor &);

//----------------------------------------------------- Méthodes publiques
    
    unsigned int getDoctorId() const;

//-------------------------------------------- Constructeurs - destructeur
	Doctor (const Doctor & unDoctor);
	// Mode d'emploi :
	//
	// Contrat :
	//

    Doctor (string name, string firstName, string speciality);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Doctor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    unsigned int AutoNumber();

//----------------------------------------------------- Attributs protégés
	unsigned int id;
	string name;
	string firstName;
	string speciality;

};

//-------------------------------- Autres définitions dépendantes de <Doctor>

#endif // Doctor_H

