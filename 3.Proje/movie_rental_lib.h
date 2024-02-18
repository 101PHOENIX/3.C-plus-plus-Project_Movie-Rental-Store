/*
@movie_rental_lib.h
@film kiralama mağazamız adında classımız ve onun özelliklerini oluşturduk. Bu oluşturduğumuz özellikleri kullanmak için,
@ilgili fonksiyonların prototiplerini oluşturduk.
@Diğer h dosyalarında oluşturduğumuz (movie_lib.h ve customer_lib.h)'ın özelliklerini bu h dosyasında kullancağımız için,
@Buraya include ettik.
@3.Proje
@07/01/2023
@Şerafettin Doruk SEZER/ sdoruksezer@gmail.com
*/

#ifndef MATRIXLIB_C_MOVIE_RENTAL_LIB_H
#define MATRIXLIB_C_MOVIE_RENTAL_LIB_H

#include <iostream>
#include <cstring>
#include "movie_lib.h"
#include "customer_lib.h"

using namespace std;

class movie_rental_shop{
private:
   static int shop_number_of_movies;
   static string movie_list;
    static Movie rental_movie_list;
    static customer customer_list;
    static float earn;
public:
    movie_rental_shop(int earn);

    int set_add_movie(Movie movie);

    static int set_eject_movie(int number);

    static int get_shop_number_of_movies();
    static int set_shop_number_of_movie(int shop_number_of_movie);

    static string get_movie_list();
    static string set_movie_lis(Movie movie_list);

    static Movie get_rental_movie_list();
    static  Movie set_rental_movie_list(Movie rental_movie_list);

    static customer get_customer_list();
    static customer set_customer_list(customer customer_list);

    static float get_earn();
    static float set_won_earn(float earn);

    void print();

};




#endif //MATRIXLIB_C_MOVIE_RENTAL_LIB_H
