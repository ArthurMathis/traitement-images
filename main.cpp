#include <iostream>
#include "image.h"

int main() {
    image img{"src/Bouquet.ppm"};
    img.NiveauxDeGris("src/BouquetGris.ppm");
}
