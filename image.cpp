//
// Created by Arthur Mathis on 12/09/2023.
//

#include "image.h"
#include <fstream>

#include <iostream>

using std::endl;

image::image(std::string source):d_source{source}
{
}

std::string image::getSource() const
{
    return d_source;
}

void image::setSource(std::string source)
{
    d_source = source;
}

void image::NiveauxDeGris(std::string source) const
{
    // Initialisation du téléchargement
    std::ifstream fin(d_source);
    if(!fin){
        std::cout<<"erreur";
        return;
    }

    std::string mem;
    unsigned hauteur, largeur;
    fin>>mem>>largeur>>hauteur>>mem;

    // Initialisation de l'exportation
    std::ofstream fout(source);
    fout<<"P3"<<endl<<largeur<<endl<<hauteur<<endl<<mem<<endl;

    // Traitement
    for(unsigned i{0}; i < largeur; i++){
        for(unsigned j{0}; j < hauteur; j++){
            pixel p;
            fin>>p.r>>p.g>>p.b;
            p.r = static_cast<unsigned>(0.2126 * p.r + 0.7152 * p.g + 0.0722 * p.b);
            for(int a = 0; a < 3; a++) fout<<p.r<<" ";
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}