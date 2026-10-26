#ifndef IMAGE_BUFFER_HPP
#define IMAGE_BUFFER_HPP

#include <iostream>
#include <cstddef>

class ImageBuffer {
private:
    const int id;
    int width;
    int height;
    unsigned char* pixels;  //  dinamic

public:
    //  Constructor
    ImageBuffer(int imgId, int w, int h, unsigned char defaultVal = 0);

    //  Destructor
    ~ImageBuffer();

    //  Copy Constructor
    ImageBuffer(const ImageBuffer& other);

    //  Move Constructor
    ImageBuffer(ImageBuffer&& other) noexcept;

    int getId() const;
    int getWidth() const;
    int getHeight() const;
    const unsigned char* getPixels() const;

    void setPixel(int x, int y, unsigned char value);
    unsigned char getPixel(int x, int y) const;
    void printDetails(const char* label) const;
};

#endif