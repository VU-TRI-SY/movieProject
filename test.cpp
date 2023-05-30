#include <bits/stdc++.h>
#include "Media/media.h"
#include "Media/Movie/movie.h"
#include "Media/Movie/comedy.h"
#include "Media/Movie/drama.h"
#include "Media/Movie/classics.h"
#include "Factory/comedy_factory.h" //ctrl+click left mouse to see the file
#include "Factory/drama_factory.h"
#include "Factory/classics_factory.h"
#include "Factory/movie_factory.h"
using namespace std;

int main(){
    // Media* m = new Media('D', 10, "John S", "The Flash", 2023);
    // Movie* mv = new Movie('F', 10, "John S", "The Flash", 2023);
    // Comedy* c = new Comedy('F', 10, "John S", "The Flash", 2023);
    // Drama* d = new Drama('D', 10, "John S", "The Flash", 2023);
    // Classics* cl = new Classics('C', 10, "Michael Curtiz", "Casablanca", "Ingrid Bergman", 8, 1942);
    // cout << cl->getDetails() << endl;
    // cout << c->getDetails() << endl;
    // cout << d->getDetails() << endl;
    MediaFactory* factory = nullptr;
    //crete a ComedyFactory object to create Comedy objects
    factory = new ComedyFactory(); // factory is a pointer to ComedyFactory object to create Comedy objects

    Media* media = factory->createMedia("10, Rob Reiner, When Harry Met Sally, 1989");
    //create a Comedy object using the ComedyFactory object and that object is refered by Media pointer ~ polymorphism
    cout << media->getDetails() << endl;

    //create a DramaFactory object to create Drama objects
    factory = new DramaFactory();
    //factore is a pointer to DramaFactory object to create Drama objects to create Drama objects
    Media* media2 = factory->createMedia("10, Barry Levinson, Good Morning Vietnam, 1988");

    cout << media2->getDetails() << endl;

    //create a ClassicsFactory object to create Classics objects
    factory = new ClassicsFactory();
    Media* media3 = factory->createMedia("10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942");
    cout << media3->getDetails() << endl;
}

