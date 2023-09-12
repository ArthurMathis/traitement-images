//
// Created by Arthur Mathis on 12/09/2023.
//

#ifndef TRAITEMENT_IMAGES_IMAGE_H
#define TRAITEMENT_IMAGES_IMAGE_H

#include <string>

struct pixel{
    unsigned r,g,b;
};

class image {
public:
    image(std::string source);

    std::string getSource() const;
    void setSource(std::string source);

    void NiveauxDeGris(std::string source) const;

private:
    std::string d_source;
};


#endif //TRAITEMENT_IMAGES_IMAGE_H
