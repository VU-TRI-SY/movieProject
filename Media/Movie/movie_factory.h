/**
 * This class implements the createMedia API to create movie instances.
 */

#ifndef MOVIE_DESIGN_TEAM_MOVIE_FACTORY_H
#define MOVIE_DESIGN_TEAM_MOVIE_FACTORY_H

class MovieFactory : public MediaFactory {
public:
  Media* createMedia(const std::string &str) override;
};

#endif // MOVIE_DESIGN_TEAM_MOVIE_FACTORY_H
