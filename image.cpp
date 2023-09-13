//
// Created by Arthur Mathis on 12/09/2023.
//

#include "image.h"
#include <fstream>

#include <iostream>

using std::endl;

using std::cout;

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
            fin>>p.red>>p.green>>p.blue;
            p.red = static_cast<unsigned>(0.2126 * p.red + 0.7152 * p.green + 0.0722 * p.blue);
            for(int a = 0; a < 3; a++) fout<<p.red<<" ";
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}

bool estRouge(const pixel& p)
{
    return ((p.red / 1.3) >= p.green && (p.red / 1.3) >= p.blue);
}

void image::RougeEtGris(std::string source) const
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

    pixel p;
    for(unsigned i{0}; i < largeur; i++){
        for(unsigned j{0}; j < hauteur; j++){
            fin>>p.red>>p.green>>p.blue;
            if(estRouge(p)){
                fout<<p.red<<' '<<p.green<<' '<<p.blue<<' ';
            } else{
                unsigned gris = static_cast<unsigned>((0.2126 * p.red) + (0.7152 * p.green) + (0.0722 * p.blue));
                fout<<gris<<" "<<gris<<" "<<gris<<" ";
            }
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}

void image::reduction(std::string source) const
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

    // DOWNLOAD
    std::vector<std::vector<pixel> > object(hauteur, std::vector<pixel>(largeur));
    for(unsigned i = 0; i < hauteur; i++){
        for(unsigned j = 0; j < largeur; j++){
            fin>>object[i][j].red;
            fin>>object[i][j].green;
            fin>>object[i][j].blue;
        }
    }
    fin.close();

    unsigned dimh = static_cast<unsigned>(hauteur / 2);
    unsigned diml = static_cast<unsigned>(largeur / 2);
    if(dimh % 2 != 0) dimh++;
    if(diml % 2 != 0) diml++;

    cout<<diml<<" "<<diml<<endl;

    for(unsigned i{0}; i < diml; i++) {
        for (unsigned j{0}; j < dimh; j++) {
            object[i][j].red = object[2 * i][2 * j].red;
            object[i][j].green = object[2 * i][2 * j].green;
            object[i][j].blue = object[2 * i][2 * j].blue;
        }
    }
    object.resize(dimh,std::vector<pixel>(diml));

    // Initialisation de l'exportation
    std::ofstream fout(source);
    fout<<"P3"<<endl<<diml<<endl<<dimh<<endl<<mem<<endl;

    // EXPORTATION
    for(int i= 0; i < dimh; i++){
        for(int y = 0; y < diml; y++) {
            fout<<object[i][y].red<<" "
            <<object[i][y].green<<" "
            <<object[i][y].blue<<" ";
        }
        fout<<endl;
    }
    fout.close();
}