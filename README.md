# Movie_Design_Team_9
## UML Diagram
![Group9_Movie Design](https://github.com/johannavo97/Movie_Design_Team/assets/100493934/2403911d-fcbf-417a-80cd-245fd3faf9a3)
## Class interactions
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
