/**
 * This class implements the createMedia API to create movie instances.
 */

#ifndef CLASSICS_FACTORY_H
#define CLASSICS_FACTORY_H
#include <fstream>
#include <iostream>
#include <string>

#include "movie_factory.h"
#include "media_factory.h"
#include "../Media/Movie/classics.h"
class ClassicsFactory : public MovieFactory {
public:
  Media* createMedia(const std::string &str) override;
};

#endif 
