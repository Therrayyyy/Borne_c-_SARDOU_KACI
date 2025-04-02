# Borne_c-_SARDOU_KACI

## Project Overview
This project implements a system for managing electric vehicle charging using a card reader and various components such as buttons, LEDs, and sockets. The system authenticates users based on card numbers and manages the charging process accordingly.

## File Structure
- **src/**: Contains the implementation files for the project.
  - `baseclient.cpp`: Implements the `BaseClient` class for card authentication.
  - `bouton.cpp`: Implements the `Bouton` class for button management.
  - `generateur_save.cpp`: Implements the `GenerateurSave` class for handling the charging process.
  - `lecteurcarte.cpp`: Implements the `LecteurCarte` class for card reading and authentication.
  - `main.cpp`: Entry point of the application, initializes components and manages the main loop.
  - `prise.cpp`: Implements the `Prise` class for managing the charging socket.
  - `voyant.cpp`: Implements the `Voyant` class for managing LED indicators.

- **include/**: Contains header files that declare the classes used in the project.
  - `baseclient.h`: Declares the `BaseClient` class.
  - `bouton.h`: Declares the `Bouton` class.
  - `generateur_save.h`: Declares the `GenerateurSave` class.
  - `lecteurcarte.h`: Declares the `LecteurCarte` class.
  - `prise.h`: Declares the `Prise` class.
  - `voyant.h`: Declares the `Voyant` class.

- **Makefile**: Build configuration file that specifies how to compile and link the project.

## Setup Instructions
1. Clone the repository or download the project files.
2. Navigate to the project directory.
3. Run `make` to build the project. This will compile all source files and create the executable.

## Usage
- Run the compiled executable to start the application.
- Insert a card to authenticate and begin the charging process.
- Follow the on-screen instructions for interaction with the system.

## Dependencies
- Ensure that you have a C++ compiler installed (e.g., g++).
- Additional libraries may be required for specific functionalities (e.g., for handling hardware interactions).

## License
This project is licensed under the MIT License. See the LICENSE file for more details.