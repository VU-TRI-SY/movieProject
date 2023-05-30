/**
 * This class represents a customer.
 */

#ifndef MOVIE_DESIGN_TEAM_CUSTOMER_H
#define MOVIE_DESIGN_TEAM_CUSTOMER_H

class Customer {
private:
  int customerId;
  std::string firstName;
  std::string lastName;
  vector<Media *> borrowedMedia;

public:
  void borrowMedia(Media *media);
  Media *returnMedia(const string &mediaDescription);
};
#endif // MOVIE_DESIGN_TEAM_CUSTOMER_H
