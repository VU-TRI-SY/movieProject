/**
 * This class implements the createMedia API to create movie instances.
 */

#ifndef DRAMA_FACTORY_H //macro guard
#define DRAMA_FACTORY_H
#include <fstream>
#include <iostream>
#include <string>

#include "movie_factory.h"
#include "media_factory.h"
#include "../Media/Movie/drama.h"
class DramaFactory : public MovieFactory {
public:
  Media* createMedia(const std::string &str) override;
};

#endif 
