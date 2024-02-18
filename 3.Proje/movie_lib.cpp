/*
@movie_lib.cpp
@Bütün h dosyalarındaki tanımladığımız fonksiyonların gövdeleri, aynı zamanda main dosyasından,
@çalıştırdığımız fonksiyonları ana gövdeleri.
@Oluşturduğumuz sınıfları burada kullanacağımız için buraya include işlemini yapıyoruz.
@3.Proje
@07/01/2023
@Şerafettin Doruk SEZER/ sdoruksezer@gmail.com
*/

#include <iostream>
#include <cstring>
#include "movie_lib.h"
#include "customer_lib.h"
#include "movie_rental_lib.h"
using namespace std;
// Customer sınıfıın yapıcı metodu.
customer::customer(string name, int age, float money, char kind,int rental_limit) {

    this->name = name;
    this->age = age;
    this->money = money;
    if (kind == 'k' || kind == 'e'){
        this->kind = kind;
    }else{
        this->kind = 'b';
    }
    this->rental_limit = rental_limit;

}
// Name özelliğinin değerini almamıza yarayan get metodu.
string customer::get_Adi() {
    return name;
}
// Name özelliğinin değerini değiştirmemizi sağlayan set metodu.
string customer::set_Adi(string new_name) {
    return name += new_name + "," ;
}
// Age özelliğinin değerini almamıza yarayan get metodu.
int customer::get_age(){
    return age;
}
// Age özelliğinin değerini değiştirmemizi sağlayan set metodu.
int customer::set_age(int age) {
    return this->age = age;
}
// Money özelliğinin değerini almamıza yarayan get metodu.
float customer::get_money() {
    return money;
}
// Money özelliğinin değerini değiştirmemizi sağlayan set metodu.
float customer::set_money(float money) {
    return this->money = money;
}
// Kind özelliğinin değerini almamıza yarayan get metodu.
char customer::get_kind() {
    return kind;
}
// Kind özelliğinin değerini değiştirmemizi sağlayan set metodu.
char customer::set_kind(char new_kind) {
    return kind = new_kind;
}
// Kiralama limiti özelliğinin değerini almamıza yarayan get metodu.
int customer::get_rental_limit() {
    return this->rental_limit;
}
// Kiralama limiti özelliğinin değerini değiştirmemizi sağlayan set metodu.
int customer::set_rental_limit(int rental_limit) {
    return this->rental_limit = rental_limit;
}

// **************************************************
// Movie sınıfıın yapıcı metodu.
Movie::Movie(string movie_name, float movie_price,int age_limit,int number_of_movies,string release_date) {
    this->movie_name = std::move(movie_name);
    this->movie_price = movie_price;
    this->age_limit = age_limit;
    this->number_of_movies = number_of_movies;
    this->release_date = release_date;

}
// filmin adı özelliğinin değerini almamıza yarayan get metodu.
string Movie::get_movie_name() {
    return movie_name;
}
// filmin adı özelliğinin değerini değiştirmemizi sağlayan set metodu.
string Movie::set_movie_name(string new_name) {
    return movie_name += new_name + ",";
}
// filmin fiyatı özelliğinin değerini almamıza yarayan get metodu.
float Movie::get_movie_price() {
    return movie_price;
}
// filmin fiyatı özelliğinin değerini değiştirmemizi sağlayan set metodu.
float Movie::set_movie_price(float movie_price) {
    return this->movie_price = movie_price;
}

// filmin çıkış tarihini özelliğinin değerini almamıza yarayan get metodu.
string Movie::get_release_date() {
    return release_date;
}
// filmin çıkış tarihi özelliğinin değerini değiştirmemizi sağlayan set metodu.
string Movie::set_release_date(string new_release_date) {
    return release_date += new_release_date + ",";
}
// filmin yaş sınırı özelliğinin değerini almamıza yarayan get metodu.
int Movie::get_age_limit() {
    return age_limit;
}
// Kiralama limiti özelliğinin değerini değiştirmemizi sağlayan set metodu.
int Movie::set_age_limit(int limit) {
    return age_limit = limit;
}
// filmin ne kadar olduğunu  almamıza yarayan get metodu.
int Movie::get_number_of_movies() {
    return Movie::number_of_movies;
}
// filmin ne kadar olduğu özelliğinin değerini değiştirmemizi sağlayan set metodu.
int Movie::set_number_of_movies(int number_of_movies) {
    return Movie::number_of_movies = number_of_movies;
}

// *********************************************************

// film kiralama mağazası sınıfıın yapıcı metodu.
movie_rental_shop::movie_rental_shop(int earn) {


    this->earn = earn;
}

//**************************************************************************
// shop_number_of_movies değerini static olarak oluşturduğumuz için ilk değerini atamamız gerekiyor.
// Bunu h dosyasında yapmamamızın nedeni h dosyasını 4 veya 5 kere çağıracağımız için.
// bu altta yazdığımız değeride 4 veya 5 kere çağıracağız, buda sistemde (multiple definition),
// problemini almamıza neden olacak.
int movie_rental_shop ::shop_number_of_movies = 0;

// movie_list,rental_movie_list ve customer_list static listelerimizi calloc'la boş dinamik diziler oluşturuyoruz.
string movie_rental_shop ::movie_list = *static_cast<string *>(calloc(150, sizeof(string)));

Movie movie_rental_shop ::rental_movie_list = *static_cast<Movie *>(calloc(150, sizeof(Movie)));

customer movie_rental_shop ::customer_list = *static_cast<customer *>(calloc(150, sizeof(customer)));

// dükkandaki film sayıları değerini almamıza yarayan get metodu.
 int movie_rental_shop::get_shop_number_of_movies() {
    return shop_number_of_movies;
}

// dükkandaki film sayıları değerini değiştirmemizi sağlayan set metodu.
int movie_rental_shop::set_shop_number_of_movie(int shop_number_of_movie) {
    return movie_rental_shop::shop_number_of_movies = shop_number_of_movie;
}


// Oluşturduğumuz filmleri shop_number_of_movies static değişkenine eklyoruz.
  int movie_rental_shop::set_add_movie(Movie movie) {
    return movie_rental_shop::shop_number_of_movies += movie.get_number_of_movies();

}
// Bu aşağıda ki eject fonksiyonu bizim movie_rental fonksiyonunda işimize yarıyor,
// kiralanan film kadar shop_number_of_movies değerinden filmleri düşüyor.
// Oluşturduğumuz filmleri shop_number_of_movies static değişkeninden çıkartıyor..
int movie_rental_shop::set_eject_movie(int number) {
    return movie_rental_shop::shop_number_of_movies -= number;
}

// Burada film listesini geri döndürüyor. Bunu kullanmamamın nedeni ise print fonksiyonundan,
// çağırdığımda & adres operatörünüyle çağırdığımda sistem kendisi 1 olarak atıyor,
// & adres operatörünü kullanmasamda 1 atıyor nasıl çağıracağımı bulamadım.
// o yüzden kullanmadım.
string movie_rental_shop::get_movie_list() {
    return movie_rental_shop::movie_list;
}

// Burada film listesinin içine ilgili filmin adını atıp bir liste haline getiriyor.
string movie_rental_shop::set_movie_lis(Movie list) {
    return movie_list += list.get_movie_name() + ",";
}

// Burada kiralanan film listesini geri döndürüyor. Bunu kullanmamamın nedeni ise print fonksiyonundan,
// burada da film listesiyle karşılaştığım sorun çıktı command line da gene 1 değerine rastladım,
// Nasıl çözeceğimi bulamadım.
Movie movie_rental_shop::get_rental_movie_list() {
   cout<<
    "\nmovie_name:"<< rental_movie_list.get_movie_name()<<
    "\nmovie_price:"<< rental_movie_list.get_movie_price()<<
    "\nage_limit:"<< rental_movie_list.get_age_limit()<<
    "\nnumber_of_movies"<< rental_movie_list.get_number_of_movies()<<
    "\nrelease_date:"<< rental_movie_list.get_release_date()
    <<endl;

    return movie_rental_shop::rental_movie_list;
}
// Burada kiralanan film listesini film sınıfından oluşturduğumuz için ilgili özelliklerini,
// movie_rental fonksiyonundan aldığımız film ile dolduruyoruz.
Movie movie_rental_shop::set_rental_movie_list(Movie R_list) {

   // Burada filmin adını dolduruyor.
    cout<<"\n"<<"movie_name: "<< rental_movie_list.set_movie_name(R_list.get_movie_name())<<endl;

   // Burada filmin fiyatını dolduruyor.
    cout<<"\n"<<"movie_price: "<<rental_movie_list.set_movie_price(R_list.get_movie_price())<<endl;

    // Burada filmin yaş sınırını dolduruyor.
    cout<<"\n"<<"age_limit: "<< rental_movie_list.set_age_limit(R_list.get_age_limit())<<endl;

    // Burada filmin sayısını dolduruyor.
    cout<<"\n"<<"number_of_movies: "<<rental_movie_list.set_number_of_movies(R_list.get_number_of_movies())<<endl;

    // Burada filmin çıkış tarihini dolduruyor.
    cout<<"\n"<<"set_release_date: "<< rental_movie_list.set_release_date(R_list.get_release_date())<<endl;

    // doldurduğumuz diziyi geri döndürüyoruz.
   return movie_rental_shop::rental_movie_list;
}

// Burada müşteri listesini geri döndürüyor. Bunu kullanmamamın nedeni ise print fonksiyonundan,
// burada da film listesiyle karşılaştığım sorun çıktı command line da gene 1 değerine rastladım,
// Nasıl çözeceğimi bulamadım.
customer movie_rental_shop::get_customer_list() {
   cout <<
    "\nCustomer list: "
    "\nNAME: "<< customer_list.get_Adi() <<
    "\nAGE: "<< customer_list.get_age()<<
    "\nMONEY: "<< customer_list.get_money() <<
    "\nKIND: "<< customer_list.get_kind()<<
    "\nRENTAL LIMIT: "<< customer_list.get_rental_limit()
    << get_earn()<<endl;

     return movie_rental_shop::customer_list;
}

// Burada müşteri listesini müşteri sınıfından oluşturduğumuz için ilgili özelliklerini,
// movie_rental fonksiyonundan aldığımız müşteri ile dolduruyoruz.
customer movie_rental_shop::set_customer_list(customer clist) {

    // Burada müşterinin adını dolduruyor.
    cout<<"\n"<<"NAME: "<< customer_list.set_Adi(clist.get_Adi())<<endl;

    // Burada müşterinin yaşını dolduruyor.
    cout<<"\n"<<"AGE: "<<customer_list.set_age(clist.get_age())<<endl;

    // Burada müşterinin parasını dolduruyor.
    cout<<"\n"<<"MONEY: "<< customer_list.set_money(clist.get_money())<<endl;

    // Burada müşterinin türünü (kız = k, Erkek = e) dolduruyor.
    cout<<"\n"<<"KİND: "<<customer_list.set_kind(clist.get_kind())<<endl;

    // Burada müşterinin kiralama limitini dolduruyor.
    cout<<"\n"<<"RENTAL LİMİT: "<< customer_list.set_rental_limit(clist.get_rental_limit())<<endl;

    // doldurduğumuz diziyi geri döndürüyoruz.
    return movie_rental_shop::customer_list;
}

// earn özelliğini static olarak oluşturduğumuz için buradan atamasını yapıyoruz.
float movie_rental_shop ::earn = 0;

 // Burada film kiralama mağazasının kazandığı parayı getiriyor.
float movie_rental_shop::get_earn()  {
    return movie_rental_shop::earn;
}

// Burada film kiralama mağazasının kazandığı parayı değiştiriyor.
float movie_rental_shop::set_won_earn(float earn) {
    return movie_rental_shop::earn += earn;
}

// Burada filmlerin kiralama işlemi gerçekleşiyor.
Movie customer::movie_rental(Movie movie,customer customer) {
    // Kiralama mağazasına bağlanmak için bir tane dinamik dizi oluşturuyoruz.
    movie_rental_shop *mvs;

    mvs = static_cast<movie_rental_shop *>(malloc(movie.get_number_of_movies() * sizeof(Movie)));

    // count sayıcı oluşturmamızın nedeni müşterimizin kirala limiti kadar
    // count değerini artırıyoruz ve bu sayıyı movie_rental_shop sınıfındaki shop_number_of_movies'den,
    // düşürmek için kullanıyoruz.
    int count = 0;

    // Müşterinin kiralama limiti kadar döngüyü döndürüyoruz.
    while (count < get_rental_limit()){
        // ilk önce kişinin para kontrolüne bakıyoruz sonra yaş kontrolüne bakıyoruz.
        // parası yetmiyorsa adını,parasını,filmin adını ve film parasını,
        // yaşı yetmiyorsa adını,yaşını,filmin adını ve filmin yaş sınırını,
        //komut satırına yazıyoruz.
        if (this->money >= movie.get_movie_price()){
            if (this->age >= movie.get_age_limit() ){
                // Burada hangi filmi kiraladığını ve özelliklerini teker teker komut satırına yazıyoruz.
                printf("\n*********MOVIE*********");
                movie.get_movie_name();
                cout<<"\n"<<movie.get_movie_name()<<endl;

                movie.get_movie_price();
                cout<<"\n"<<movie.get_movie_price()<<endl;

                movie.get_age_limit();
                cout<<"\n"<<movie.get_age_limit()<<endl;

                movie.get_release_date();
                cout<<"\n"<<movie.get_release_date()<<endl;

                // Burada film kiraladıktan sonraki anlık kazancı gösteriyor.
                mvs->set_won_earn(movie.get_movie_price());
                cout<<"\n"<<"get_earn: "<<mvs->get_earn()<<endl;

                //Buradada film sınıfındaki film sayısını ilgili filme göre teker teker
                // müşterinin kiralama limiti kadar azaltıyoruz.
                if (movie.get_movie_name() == "Red Tails"){
                    movie.set_number_of_movies(movie.get_number_of_movies() - 1);

                }else if (movie.get_movie_name() == "The Expendables 4"){
                    movie.set_number_of_movies(movie.get_number_of_movies() - 1);

                }else if(movie.get_movie_name() == "The Lego Movie"){
                    movie.set_number_of_movies(movie.get_number_of_movies() - 1);

                }else if(movie.get_movie_name() == "Shrek Forever"){
                    movie.set_number_of_movies(movie.get_number_of_movies() - 1);
                }

            } else{
                cout<<"\ncustomers name: "<< this->name <<"\ncustomers age: "<< this->age<<endl;
                cout<<"\nMovie name: "<< movie.get_movie_name() <<"\nMovie age limit: "<< movie.get_age_limit()<<endl;
                printf("\nyour age is not suitable");

                break;
            }
        } else{
            cout<<"\ncustomers name: "<< this->name <<"\ncustomers money: "<< this->money<<endl;
            cout<<"\nMovie name: "<< movie.get_movie_name() <<"\nMovie price: "<< movie.get_movie_price()<<endl;
            printf("\nyou don't have enough money");

            break;
        }

        count++;

    }

    // müşteriye filmi teslim ettikten sonra filmimizi, kiralanan filmler listesine ve,
    // müşterimizi, müşteri listesine atıyoruz.
    // Parası yetmiyorsa veya yaşı yetmiyorsa ilgili mesajımızı komut satırına yazıyoruz.
    if (this->money >= movie.get_movie_price()) {
        if (this->age >= movie.get_age_limit()) {
            mvs->set_rental_movie_list(movie);
            mvs->set_customer_list(customer);
        } else{
            printf("\nYou couldn't be added to the customer list because your age didn't enough the age limit.");

        }
    }else{
        printf("\nYou couldn't be added to the customer list because you didn't have enough money.");

    }
    // Burada count sayımız müşterinin kiralama limiti kadar artıyor,
    // ve biz bu sayıyı dükkandaki toplam film sayısından düşüyoruz.
    movie_rental_shop::set_eject_movie(count);

    // Burada print yapmamın nedeni anlık değişimi görebilmek için.
    mvs->print();
    // ilgili filmin kiralandıktan sonraki filmden ne kadar kaldığını gösteriyor.
    printf("\nThe remaining number from the movie: %d",movie.get_number_of_movies());

    // filmi return etmemizin nedeni filmin adedini değiştirdiğimiz için
    return movie;
}

// ilgili müşterimizin özelliklerini komut satırına yazıyor.
void customer::print() {

    cout<<"\nName: "<< name<<"\nAge: "<< age<<"\nMoney: "<< money<<"\nKind: "<< kind<<"\nrental limit: "<<rental_limit<<endl;
    cout<<"***************************"<<endl;
}

// ilgili filmin özelliklerini komut satırına yazıyor.
void Movie::print() {

    cout<<"\nMovie Name: "<< movie_name<<"\nMovie Price: "<< movie_price<<"\nAge Limit: "<< age_limit<<"\nNumber Of Movies: "<< number_of_movies<<"\nRelease Date: "<< release_date<<endl;
    cout<<"***************************"<<endl;
}

// Film kiralama mağazasının bütün özelliklerini komut satırına yazıyor.
void movie_rental_shop::print() {

    cout<<"\nShop Number of movies: "<< shop_number_of_movies<<"\nMovie list: "<< movie_list
    <<"\nRental movie list"<<
    "\nmovie_name: "<< rental_movie_list.get_movie_name() <<
    "\nmovie_price: "<< rental_movie_list.get_movie_price()<<
    "\nage_limit: "<< rental_movie_list.get_age_limit() <<
    "\nnumber_of_movies: "<< rental_movie_list.get_number_of_movies()<<
    "\nrelease_date: "<< rental_movie_list.get_release_date()
    <<"\n ****************************"<<
    "\nCustomer list: "
    "\nNAME: "<< customer_list.get_Adi() <<
    "\nAGE: "<< customer_list.get_age()<<
    "\nMONEY: "<< customer_list.get_money() <<
    "\nKIND: "<< customer_list.get_kind()<<
    "\nRENTAL LIMIT: "<< customer_list.get_rental_limit()
    <<"\n ****************************"<<"\nEarn: "<< get_earn()<<endl;
    cout<<"***************************"<<endl;
}

float *returnVector(int size){
    // Uzunluk değerine göre bir boyutlu bir vektör oluşturup içine random sayılar atıp,
    // bir boyutlu bir vektör döndürüyor.
    // srand(size);
    float *dizi1 = (float *) malloc(size*sizeof (float));
    for (int i = 0; i < size; ++i) {
        dizi1[i] = (float)(rand() % 10);
    }
    return dizi1;
}

void printVector(float *dizi1,int size){
    // bir boyutlu bir vektör ve boyutunu alıp, ekrana yazdırıyor.
    int i;
    for ( i = 0; i < size; ++i) {
        printf(" dizi[%d]: %.2f ", i,dizi1[i]);;
    }
};

