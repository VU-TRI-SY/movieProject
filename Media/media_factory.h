/**
* This factory class define the interface to create media instances.
*/

#ifndef MOVIE_DESIGN_TEAM_MEDIA_FACTORY_H
#define MOVIE_DESIGN_TEAM_MEDIA_FACTORY_H

class MediaFactory {
public:
  // str is the text of each line in data4movie.txt
  Media* createMedia(const std::string &str) = 0;
};

#endif // MOVIE_DESIGN_TEAM_MEDIA_FACTORY_H
