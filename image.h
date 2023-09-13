//
// Created by Arthur Mathis on 12/09/2023.
//

#ifndef TRAITEMENT_IMAGES_IMAGE_H
#define TRAITEMENT_IMAGES_IMAGE_H

#include <string>

/**
 * @brief Structure représentant un pixel
 */
struct pixel{
    unsigned red, green, blue;
};

/**
 * @brief Class représentant une image de format .ppm
 */
class image {
public:
    image(std::string source);

    /**
     * @brief Méthode récupérerant la source de l'image
     * @return
     */
    std::string getSource() const;
    /*
     * @brief Méthode changeant la source d'une image
     */
    void setSource(std::string source);

    /**
     * @brief Méthode générant depuis  l'image, une image en noir et blanc
     * @param source
     */
    void NiveauxDeGris(std::string source) const;
    /**
     * @brief Méthode générant depuis l'image, une image en rouge et gris
     * @param source
     */
    void RougeEtGris(std::string source) const;

private:
    std::string d_source;
};


#endif //TRAITEMENT_IMAGES_IMAGE_H
