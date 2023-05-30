/**
* This factory class define the interface to create media instances.
*/

#ifndef MEDIA_FACTORY_H
#define MEDIA_FACTORY_H
#include <fstream>
#include <iostream>
#include <string>

#include "../Media/media.h"

class MediaFactory {
public:
  // str is the text of each line in data4movie.txt
  virtual Media* createMedia(const string &str);
};

#endif // MOVIE_DESIGN_TEAM_MEDIA_FACTORY_H
