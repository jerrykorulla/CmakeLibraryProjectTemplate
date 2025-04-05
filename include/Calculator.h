#pragma once

#ifdef _WIN32
  #ifdef MATHLIBRARY_EXPORTS
    #define MATHLIB_API __declspec(dllexport)
  #else
    #define MATHLIB_API __declspec(dllimport)
  #endif
#else
  #define MATHLIB_API
#endif

class MATHLIB_API Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
};
