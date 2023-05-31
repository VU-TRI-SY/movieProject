/**
 * This class represents a customer.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Media/media.h"
class Customer {
private:
  int customerId;
  std::string firstName;
  std::string lastName;
  std::vector<Media *> borrowedMedia;

public:
  Customer();
  Customer(int customerId, std::string firstName, std::string lastName);
  void borrowMedia(Media *media);
  void returnMedia(Media* media);
  std::string getDetails();
  int getId();
};
#endif // CUSTOMER_H
