#include "ImageBuffer.hpp"
#include <utility>

ImageBuffer createTemporaryFilter(int id, int w, int h) {
    ImageBuffer temp(id, w, h, 128);
    temp.setPixel(0, 0, 255);
    return temp;
}

int main() {
    ImageBuffer img1(1, 4, 4, 10);
    img1.printDetails("Imagine Originala (img1)");

    std::cout << "\n====================================================\n";
    std::cout << "COPY CONSTRUCTOR\n";
    std::cout << "====================================================\n";

    ImageBuffer imgCopy = img1; 

    imgCopy.setPixel(0, 0, 99);

    img1.printDetails("Originalul dupa modificare copie");
    imgCopy.printDetails("Copia modificata");



    img1.printDetails("img1 dupa iesirea copiei din scope");

    std::cout << "\n====================================================\n";
    std::cout << "MOVE CONSTRUCTOR\n";
    std::cout << "====================================================\n";
    std::cout << "\n--- Cazul A: Returnare din functie (primit prin Move) ---\n";
    ImageBuffer imgMoved = createTemporaryFilter(2, 8, 8);
    imgMoved.printDetails("imgMoved (obtinut din functie)");

    std::cout << "\n--- Cazul B: Transfer explicit prin std::move ---\n";
    ImageBuffer imgDonor(3, 2, 2, 50);
    imgDonor.printDetails("imgDonor (inainte de move)");

    ImageBuffer imgReceiver = std::move(imgDonor);
    imgReceiver.printDetails("imgReceiver (a furat resursa)");
    imgDonor.printDetails("imgDonor (dupa move, pointerul e null)");

    return 0;
}