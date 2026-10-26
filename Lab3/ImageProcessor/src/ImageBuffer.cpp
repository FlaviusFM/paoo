#include "ImageBuffer.hpp"
#include <algorithm>

ImageBuffer::ImageBuffer(int imgId, int w, int h, unsigned char defaultVal)
    : id(imgId), width(w), height(h), pixels(nullptr) {
    
    if (width > 0 && height > 0) {
        pixels = new unsigned char[width * height];
        std::fill(pixels, pixels + (width * height), defaultVal);
    }
    std::cout << "[Constructor] Imagine ID: " << id << " creata la adresa heap: " 
              << static_cast<void*>(pixels) << std::endl;
}

ImageBuffer::~ImageBuffer() {
    std::cout << "[Destructor] Distrugere Imagine ID: " << id 
              << ", eliberare buffer heap: " << static_cast<void*>(pixels) << std::endl;
    delete[] pixels;
    pixels = nullptr;
}

ImageBuffer::ImageBuffer(const ImageBuffer& other)
    : id(other.id + 100), width(other.width), height(other.height), pixels(nullptr) {
    
    if (other.pixels != nullptr) {
        pixels = new unsigned char[width * height];
        std::copy(other.pixels, other.pixels + (width * height), pixels);
    }
    std::cout << "[Copy Constructor] Copie profunda creata (ID nou: " << id 
              << ") la o adresa NOUA pe heap: " << static_cast<void*>(pixels) 
              << " din sursa: " << static_cast<void*>(other.pixels) << std::endl;
}

ImageBuffer::ImageBuffer(ImageBuffer&& other) noexcept
    : id(other.id), width(other.width), height(other.height), pixels(other.pixels) {
    
    other.pixels = nullptr;
    other.width = 0;
    other.height = 0;

    std::cout << "[Move Constructor] Resursa preluata (ID: " << id 
              << ") de la adresa heap: " << static_cast<void*>(pixels) << std::endl;
}

int ImageBuffer::getId() const { return id; }
int ImageBuffer::getWidth() const { return width; }
int ImageBuffer::getHeight() const { return height; }
const unsigned char* ImageBuffer::getPixels() const { return pixels; }

void ImageBuffer::setPixel(int x, int y, unsigned char value) {
    if (x >= 0 && x < width && y >= 0 && y < height && pixels != nullptr) {
        pixels[y * width + x] = value;
    }
}

unsigned char ImageBuffer::getPixel(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height && pixels != nullptr) {
        return pixels[y * width + x];
    }
    return 0;
}

void ImageBuffer::printDetails(const char* label) const {
    std::cout << label << " -> ID: " << id << ", Dimensiuni: " << width << "x" << height
              << ", Heap Addr: " << static_cast<void*>(pixels);
    if (pixels != nullptr && width > 0 && height > 0) {
        std::cout << ", Pixel[0,0]=" << static_cast<int>(pixels[0]);
    }
    std::cout << std::endl;
}