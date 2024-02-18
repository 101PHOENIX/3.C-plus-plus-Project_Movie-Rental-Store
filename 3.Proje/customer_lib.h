/*
@customer_lib.h
@Müşteri classımız ve onun özelliklerini oluşturduk. Bu oluşturduğumuz özellikleri kullanmak için,
@ilgili fonksiyonların prototiplerini oluşturduk.
@3.Proje
@07/01/2023
@Şerafettin Doruk SEZER/ sdoruksezer@gmail.com
*/

#ifndef MATRIXLIB_C_CUSTOMER_LIB_H
#define MATRIXLIB_C_CUSTOMER_LIB_H
#include <iostream>
#include <cstring>

using namespace std;

class customer{
private:
    string name;
    int age;
    float money;
    char kind;
    int rental_limit;
public:
    customer(string name,int age, float money,char kind,int rental_limit);
    string get_Adi();
    string set_Adi(string new_name);

    int get_age();
    int set_age(int age);

    float get_money();
    float set_money(float money);

    char get_kind();
    char set_kind(char new_kind);
    void print();

    int get_rental_limit();
    int set_rental_limit(int rental_limit);


    Movie movie_rental(Movie movie,customer customer);

};
#endif //MATRIXLIB_C_CUSTOMER_LIB_H
