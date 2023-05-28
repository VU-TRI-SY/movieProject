# Movie_Design_Team_9
Created by Linh Ha Huynh, Johanna Vo, Minh Chau Vu, Hany Ghobrial
## UML Diagram
![Group9_Movie Design - Page 2](https://github.com/johannavo97/Movie_Design_Team/assets/100493934/3c687378-3d25-4861-af84-6b3a7ed03a56)
## Class interactions
For Return operation, the main function would call addMedia() in the Store class to add one media to the store and then call returnMedia() in the Customer class to show that the media has been add back to the store and return by the customer.

For History operation, the Customer class would call getTransactionHistory() which returns a vector of strings representing the transaction history of the customer. The Store class has a private member called transactionHistory, which is a vector of strings representing the overall transaction history of the store. Then the Store class will call getHistory(customerId), which takes a customerId as input and returns a map of integers to lists of strings representing the transaction history of a particular customer. The Driver class is not directly involved in the history operation. It mainly interacts with the Store class and other classes to perform operations like reading inventory, customers, and commands, and running the program.

For Inventory operation, it involves adding and removing Media objects from the Store's inventory by using methods like addMedia(Media*) and removeMedia(Media*) , as well as reading and displaying the inventory data. The Store class manages the inventory, and the Driver class interacts with the Store to perform inventory-related operations through the inventoryMedia() method to display the current inventory of the Store.

### Driver.cpp
This is the driver class of the program. Its main function will create an instance of the _Store class_ and will call the necessary functions to read in the movies, customers, and commands.

### Store.h
The _Store class_ manages the inventory of media items and the list of customers. It provides methods to read data from files to populate the inventory and customer list. It also allows to add or remove media from the inventory, add customers, and retrieve specific media or customer data.

### Media.h
The Media class is an abstract base class that represents a generic media item. This class contains methods and data members common to all media items such as the type of media (mediaType), the current stock, the director's name, the title, and the release year. This class also provides methods to get details about the media item and to borrow and return items.

### Movie.h
The Movie class is a subclass of the Media class, which adds a specific movie-type attribute. This class forms the basis for the specific movie types Comedy, Drama, and Classic.

#### Comedy.h, Drama.h, and Classic.h
These subclasses inherit from the Movie class. They represent specific types of movies. Each of these classes may contain additional attributes or methods specific to its type. For instance, the Classic class includes an additional attribute for the major actor and release date.

### MediaFactory.h
The MediaFactory class is a factory class responsible for creating instances of media objects. The factory takes in a string (which contains the necessary information), determines the type of media to create, and returns a new instance of that media type.

### MovieFactory.h
The MovieFactory class is a subclass of MediaFactory and specializes in creating instances of movie objects. Like its parent class, it takes a string with necessary information and creates a new instance of the appropriate movie type.

### Command.h
The Command class is an abstract base class that represents a command to be executed by the system. It provides a common interface for all command types.

#### Borrow.h, Return.h, History.h, and Inventory.h
These classes inherit from the Command class and represent specific commands that can be executed. They override the execute method from the Command class to perform their specific actions on the Store object.

### Use case 1: create a movie
main() calls MovieFactory.createMedia() method to create a movie.
main() calls Store.addMedia() 

### Use case 2: create a user
main() calls the constructor of User class to create a new user.
main() calls Store.addUser() 

### Use case 3: a customer borrow a movie
main() calls Store.borrowMedia() then Customer.borrowMedia() to complete the transaction.
