/**
 * This class represents a customer.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Media/media.h"
#include <string>
#include <vector>
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
  int getId() const;
  int getBorrowedStock();
  Media* getBorrowedMedia(Media* media);
};
#endif // CUSTOMER_H
