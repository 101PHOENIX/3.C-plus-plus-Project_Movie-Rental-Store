/*
@movie_main.cpp
@Burada müşterilerimizi ve filmlerimizi oluşturuyoruz.
@Film ekleme işlemleri gerçekleşiyor.
@Hangi müşterinin hangi filmi aldığını görebiliyoruz.
@3.Proje
@07/01/2023
@Şerafettin Doruk SEZER/ sdoruksezer@gmail.com
*/

#include <iostream>
#include "movie_lib.h"
#include "customer_lib.h"
#include "movie_rental_lib.h"
#include <cstring>
using namespace std;

int main(){

    // Müşterilerimizi oluşturuyoruz.
    customer customer1("Ali",25,15000,'e',5);
    customer customer2("Zeynep",23,17000,'k',5);
    customer customer3("Mehmet",19,250,'e',3);
    customer customer4("Peach",12,600,'k',3);

    // Müşterileri ve özelliklerini komut satırına yazıyoruz.
    customer1.print();
    customer2.print();
    customer3.print();
    customer4.print();

    // Filmlerimizi oluşturuyoruz.
    Movie movie1("Red Tails", 500.50, 18, 10, "20/6/2012");
    Movie movie2("The Expendables 4",550,18,2,"8/5/2016");
    Movie movie3("The Lego Movie",245.75,15,8,"16/8/2010");
    Movie movie4("Shrek Forever",150,7,10,"20/9/2010");

    // Filmlerimizi ve özelliklerini komut satırına yazıyoruz.
    movie1.print();
    movie2.print();
    movie3.print();
    movie4.print();

    // Mağazamızı oluşturuyoruz. Burada sadece kazancı yazmamızın sebebi,
    // Diğer özelliklerini static olarak oluşturduğumuz için.
    movie_rental_shop shop(0);

    // Mağazamıza filmlerimizi ve film listesini dolduruyoruz.
    shop.set_add_movie(movie1);
    shop.set_movie_lis(movie1);

    shop.set_add_movie(movie2);
    shop.set_movie_lis(movie2);

    shop.set_add_movie(movie3);
    shop.set_movie_lis(movie3);

    shop.set_add_movie(movie4);
    shop.set_movie_lis(movie4);

    // Mağazamızı ve özelliklerini komut satırına yazıyoruz
    shop.print();

    // İlgili müşterilerimize seçtikleri filmi ekliyoruz.
    // movie_rental fonksiyonunda müşteriyi almamızın sebebi
    // film kiralama mağazası klasımızın içindeki müşteri_listesi özelliğimizi
    // doldurmak için ihtiyacımız var.
    customer1.movie_rental(movie1,customer1);
    customer2.movie_rental(movie4,customer2);
    customer3.movie_rental(movie1,customer3);
    customer4.movie_rental(movie3,customer4);

    // Mağazamızı ve özelliklerini komut satırına yazıyoruz
    shop.print();



    return 0;
}


