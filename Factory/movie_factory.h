/**
 * This class implements the createMedia API to create movie instances.
 */

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H
#include <fstream>
#include <iostream>
#include <string>

#include "media_factory.h"
#include "../Media/Movie/movie.h"
class MovieFactory : public MediaFactory {
public:
  Media* createMedia(const std::string &str) override;
};

#endif // MOVIE_DESIGN_TEAM_MOVIE_FACTORY_H
