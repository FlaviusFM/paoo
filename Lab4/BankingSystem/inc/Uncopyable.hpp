#ifndef UNCOPYABLE_HPP
#define UNCOPYABLE_HPP

//  Orice clasa care mosteneste 'Uncopyable' privat 
//  nu va putea fi copiata
class Uncopyable {
protected:
    Uncopyable() {}
    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable&);            //    Doar declarat, neimplementat
    Uncopyable& operator=(const Uncopyable&); //    Doar declarat, neimplementat
};

#endif