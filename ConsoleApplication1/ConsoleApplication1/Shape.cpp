#include "Shape.h"

//std::ostream& operator<< (std::ostream& out, Shape& shape)
//{
//    // Since operator<< is a friend of the Point class, we can access Point's members directly.
//    out << "Es ist ein " << shape.getType() << ".\n" << "Die Fläche ist: " << shape.getFlaeche() << "\nDer Umfang " << shape.getUmfang() << std::endl; // actual output done here
//
//    return out; // return std::ostream so we can chain calls to operator<<
//}