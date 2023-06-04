#include "driver.h"

#include "Factory/classics_factory.h"
#include "Factory/comedy_factory.h"
#include "Factory/customer_factory.h"
#include "Factory/drama_factory.h"
#include "Factory/media_factory.h"
#include "Factory/movie_factory.h"
using namespace std;

void readInventory(string fileName, Store &store) {
  ifstream infile(fileName);

  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }

  char movieType;
  string line;
  ComedyFactory comedyFactory;
  DramaFactory dramaFactory;
  ClassicsFactory classicsFactory;
  Media *media = nullptr;
  while (!infile.eof()) {
    infile >> movieType;
    switch (movieType) {
    case 'C':
      //", 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942"
      infile.ignore(2);            // ignore the ", "
      getline(infile, line, '\n'); // read the rest of line until '\n'
      // line = "10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942"
      media = classicsFactory.createMedia(line);
      store.addMedia(media);
      break;
    case 'D':
      //", 10, Barry Levinson, Good Morning Vietnam, 1988"
      infile.ignore(2);            // ignore the ", "
      getline(infile, line, '\n'); // read the rest of line until '\n'
      // line = "10, Barry Levinson, Good Morning Vietnam, 1988"
      media = dramaFactory.createMedia(line);
      store.addMedia(media);
      break;
    case 'F':
      //"F, 10, Gore Verbinski, Pirates of the Caribbean, 2003"
      infile.ignore(2);            // ignore the ", "
      getline(infile, line, '\n'); // read the rest of line until '\n'
      // line = "10, Gore Verbinski, Pirates of the Caribbean, 2003"
      media = comedyFactory.createMedia(line);
      store.addMedia(media);
      break;
    default:
      cerr << "Invalid movie type " << endl;
      getline(infile, line, '\n'); // discard the rest of the line
      break;
    }
  }
  infile.close();
}

// Reads customer data from a file
void readCustomers(string fileName,
                   Store &store) { // select ---> ctr + shift + L
  ifstream infile(fileName);

  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }

  string line;
  CustomerFactory customerFactory;
  Customer *customer = nullptr;
  while (!infile.eof()) {
    getline(infile, line, '\n');
    customer = customerFactory.createCustomer(line);
    store.addCustomer(customer);
  }
  infile.close();
}

// Reads command data from a file
void readCommands(string fileName, Store &store) {
  ifstream infile(fileName);

  if (!infile) {
    cout << "File could not be opened." << endl;
    return;
  }
  string line;
  char commandType;
  int customerID;
  char mediaType;
  char movieType;
  int month;
  int year;
  string actor, title, director;
  Media *media = nullptr;
  while (!infile.eof()) {
    infile >> commandType;
    switch (commandType) {
    case 'I':
      store.printInventory();
      break; // break out of switch
    case 'H':
      infile >> customerID;
      infile.ignore(1000, '\n'); // ignore the "\n"
      if (store.getCustomer(customerID) == nullptr) {
        cerr << "Invalid customer ID" << endl;
      } else {
        store.displayHistory(customerID);
      }
      break;
    case 'B':
      infile >> customerID;
      if (store.getCustomer(customerID) == nullptr) {
        cerr << "Invalid customer ID" << endl;
        getline(infile, line, '\n'); // discard the rest of the line
        break;                       // break out of switch
      }

      infile >> mediaType;
      if (mediaType != 'D') {
        cerr << "Invalid media type" << endl;
        getline(infile, line, '\n'); // discard the rest of the line
        break;                       // break out of switch
      }

      infile >> movieType;
      if (movieType == 'F') {
        // input: " When Harry Met Sally, 1989"
        infile.ignore(1); // ignore the " "
        ////input: "When Harry Met Sally, 1989"
        getline(infile, title, ',');
        // input: " 1989"
        infile >> year;
        infile.ignore(1000, '\n'); // ignore the "\n"
        media = store.getMedia('F', title, year);
        if (media == nullptr) {
          cerr << "Invalid movie" << endl;
          break; // break out of switch
        } else {
          if (media->getStock() >= 1) {
            store.borrowMedia(store.getCustomer(customerID), media);
            // B 8888 D F When Harry Met Sally, 1989
            string command = "B " + to_string(customerID) + " " +
                             string(1, mediaType) + " " + string(1, movieType) +
                             " " + title + ", " + to_string(year);
            store.addTransactionHistory(customerID, command);
          }else{
            cerr << "Not enough stock" << endl;
          }
          { break; } // break out of switch
        }

      } else if (movieType == 'D') {
        // input: " Barry Levinson, Good Morning Vietnam,"
        infile.ignore(1); // ignore the " "
        // input: "Barry Levinson, Good Morning Vietnam,"
        getline(infile, director, ',');
        // input: " Good Morning Vietnam,"
        infile.ignore(1); // ignore the " "
        // input: "Good Morning Vietnam,"
        getline(infile, title, ',');
        infile.ignore(1000, '\n'); // ignore the "\n"
        Media *media = store.getMedia('D', director, title);
        if (media == nullptr) {
          cerr << "Invalid movie" << endl;
          break; // break out of switch
        } else {
          if (media->getStock() >= 1) {
            store.borrowMedia(store.getCustomer(customerID), media);
            // B 1000 D D Barry Levinson, Good Morning Vietnam,
            string command = "B " + to_string(customerID) + " " +
                             string(1, mediaType) + " " + string(1, movieType) +
                             " " + director + ", " + title + ",";
            store.addTransactionHistory(customerID, command);
          }else{
            cerr << "Not enough stock" << endl;
          }
          break; // break out of switch
        }
      } else if (movieType == 'C') {
        // input: " 5 1940 Katherine Hepburn"
        infile >> month;
        infile >> year;

        // input: " Katherine Hepburn"
        infile.ignore(1); // ignore the " "
        // input: "Katherine Hepburn"
        getline(infile, actor, '\n');
        Media *media = store.getMedia('C', month, year, actor);
        if (media == nullptr) {
          cerr << "Invalid movie" << endl;
          { break; } // break out of switch
        } else {
          if (media->getStock() >= 1) {
            store.borrowMedia(store.getCustomer(customerID), media);
            // B 1000 D C 5 1940 Katherine Hepburn
            string command = "B " + to_string(customerID) + " " +
                             string(1, mediaType) + " " + string(1, movieType) +
                             " " + to_string(month) + " " + to_string(year) +
                             " " + actor;
            store.addTransactionHistory(customerID, command);
          }else{
            cerr << "Not enough stock" << endl;
          }
          break; // break out of switch
        }
      } else {
        cerr << "Invalid movie type " << endl;
        getline(infile, line, '\n'); // discard the rest of the line
        break;                       // break out of switch
      }
    case 'R':
      infile >> customerID;
      if (store.getCustomer(customerID) == nullptr) {
        cerr << "Invalid customer ID" << endl;
        getline(infile, line, '\n'); // discard the rest of the line
        break;                       // break out of switch
      }

      infile >> mediaType;
      if (mediaType != 'D') {
        cerr << "Invalid media type" << endl;
        getline(infile, line, '\n'); // discard the rest of the line
        break;                       // break out of switch
      }

      infile >> movieType;
      if (movieType == 'F') {
        // input: " When Harry Met Sally, 1989"
        infile.ignore(1); // ignore the " "
        ////input: "When Harry Met Sally, 1989"
        getline(infile, title, ',');
        // input: " 1989"
        infile >> year;
        infile.ignore(1000, '\n'); // ignore the "\n"
        media = store.getMedia('F', title, year);
        if (media == nullptr) {
          cerr << "Invalid movie" << endl;
          break; // break out of switch
        } else {
          if (store.getCustomer(customerID)->getBorrowedMedia(media) !=
              nullptr) { // check that media is borrowed by customer
            store.returnMedia(store.getCustomer(customerID), media);
            // R 8888 D F When Harry Met Sally, 1989
            string command = "R " + to_string(customerID) + " " +
                             string(1, mediaType) + " " + string(1, movieType) +
                             " " + title + ", " + to_string(year);
            store.addTransactionHistory(customerID, command);
          }else{
            cerr << "The movie is not borrowed by this customer" << endl;
          }
          break; // break out of switch
        }

      } else if (movieType == 'D') {
        // input: " Barry Levinson, Good Morning Vietnam,"
        infile.ignore(1); // ignore the " "
        // input: "Barry Levinson, Good Morning Vietnam,"
        getline(infile, director, ',');
        // input: " Good Morning Vietnam,"
        infile.ignore(1); // ignore the " "
        // input: "Good Morning Vietnam,"
        getline(infile, title, ',');
        infile.ignore(1000, '\n'); // ignore the "\n"
        Media *media = store.getMedia('D', director, title);
        if (media == nullptr) {
          cerr << "Invalid movie" << endl;
          break; // break out of switch
        } else {
          if (store.getCustomer(customerID)->getBorrowedMedia(media) !=
              nullptr) {
            store.returnMedia(store.getCustomer(customerID), media);
            // R 1000 D D Barry Levinson, Good Morning Vietnam,
            string command = "R " + to_string(customerID) + " " +
                             string(1, mediaType) + " " + string(1, movieType) +
                             " " + director + ", " + title + ",";
            store.addTransactionHistory(customerID, command);
          }
          break; // break out of switch
        }
      } else if (movieType == 'C') {
        // input: " 5 1940 Katherine Hepburn"
        infile >> month;
        infile >> year;

        // input: " Katherine Hepburn"
        infile.ignore(1); // ignore the " "
        // input: "Katherine Hepburn"
        getline(infile, actor, '\n');
        Media *media = store.getMedia('C', month, year, actor);
        if (media == nullptr) {
          cerr << "Invalid movie" << endl;
          break; // break out of switch
        } else {
          if (store.getCustomer(customerID)->getBorrowedMedia(media) !=
              nullptr) {
            store.returnMedia(store.getCustomer(customerID), media);
            // R 1000 D C 5 1940 Katherine Hepburn
            string command = "R " + to_string(customerID) + " " +
                             string(1, mediaType) + " " + string(1, movieType) +
                             " " + to_string(month) + " " + to_string(year) +
                             " " + actor;
            store.addTransactionHistory(customerID, command);
          }
          break; // break out of switch
        }
      } else {
        cerr << "Invalid movie type " << endl;
        getline(infile, line, '\n'); // discard the rest of the line
        break;                       // break out of switch
      }
      break;
    default:
      cerr << "Invalid command code" << endl;
      getline(infile, line, '\n'); // discard the rest of the line
      break;
    }
  }
}
