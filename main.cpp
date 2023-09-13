#include <iostream>
#include "image.h"

int main() {
    image img{"src/Bouquet.ppm"};
    //img.NiveauxDeGris("src/BouquetGris.ppm");
    //img.RougeEtGris("src/BouquetRougeEtGris.ppm");
    img.reduction("src/BouquetPetit.ppm");
}
