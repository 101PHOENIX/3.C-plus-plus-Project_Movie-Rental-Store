/*
@movie_lib.h
@Movie classımız ve onun özelliklerini oluşturduk. Bu oluşturduğumuz özellikleri kullanmak için,
@ilgili fonksiyonların prototiplerini oluşturduk.
@returVector ve printVector fonksiyonlarını kullanacağım için buraya prototiplerini ekledim.
@3.Proje
@07/01/2023
@Şerafettin Doruk SEZER/ sdoruksezer@gmail.com
*/

#ifndef MATRIXLIB_C_MOVIE_LIB_H
#define MATRIXLIB_C_MOVIE_LIB_H

#include <iostream>
#include <cstring>

using namespace std;

class Movie{
private:
    string movie_name;
    float movie_price;
    int age_limit;
    int number_of_movies;
    string release_date;
public:
    Movie(string movie_name,float movie_price, int age_limit,int number_of_movies,string release_date);

    string get_movie_name();
    string set_movie_name(string new_name);

    float get_movie_price();
    float set_movie_price(float movie_price);

    int get_age_limit();
    int set_age_limit(int limit);

    int get_number_of_movies();
    int set_number_of_movies(int number_of_movies);

    string get_release_date();
    string set_release_date(string new_release_date);
    void print();


};

  float *returnVector(int size);

  void printVector(float *dizi,int n);

#endif //MATRIXLIB_C_MOVIE_LIB_H
