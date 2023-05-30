/**
 * This class implements the createMedia API to create movie instances.
 */

#ifndef COMEDY_FACTORY_H
#define COMEDY_FACTORY_H
#include <fstream>
#include <iostream>
#include <string>

#include "movie_factory.h"
#include "media_factory.h"
#include "../Media/Movie/comedy.h"
class ComedyFactory : public MovieFactory {
public:
  Media* createMedia(const std::string &str) override;
};

#endif 
