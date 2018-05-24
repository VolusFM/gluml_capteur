/*************************************************************************
 fileReader  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <fileReader> (fichier fileReader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "fileReader.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
list<Attribute *> fileReader::descriptionFile(ifstream & fi)
// Algorithme :
//
{
    list<Attribute *> res;
    int ligne1 = 1;
    while(fi.good()) {
        string line;
        getline ( fi, line);
        if (ligne1 == 0) {
            if (line.size() != 0){
                stringstream ss (line);
                res.push_back(this->attrFromFile(ss));
            }
        }
        else {
            ligne1 = 0;
        }
    }
    return res;
} //----- Fin de Méthode

Attribute * fileReader::attrFromFile(istream & is)
// Algorithme :
//
{
    Attribute * attr;
    string nom;
    string type;
    getline(is, nom, ';');
    getline(is, type, '\r');
    if (! type.compare("string") ) {
        attr = new QualitativeAttribute(nom);
    }
    else {
        attr = new QuantitativeAttribute(nom);
    }
    return attr;
}

void fileReader::etalonFile(ifstream & fi, PrintManager & pm, list<Attribute *> & la)
// Algorithme :
//
{
    int ligne1 = 1;
    list<Attribute *>::const_iterator itAtt;
    for (itAtt = la.begin(); itAtt != la.end(); itAtt++){
        (*itAtt)->description();
    }
    while(fi.good()){
        string line;
        getline ( fi, line);
        if (ligne1 == 0) {
            if (line.size() != 0){
                stringstream ss (line);
            }
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*fileReader::fileReader ( const fileReader & unfileReader )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <fileReader>" << endl;
#endif
} //----- Fin de fileReader (constructeur de copie)*/


fileReader::fileReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <fileReader>" << endl;
#endif
} //----- Fin de fileReader


fileReader::~fileReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <fileReader>" << endl;
#endif
} //----- Fin de ~fileReader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
