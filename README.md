This is a hotel management system, handling reservations, billing, and customer inquiries. Below is a summary of the key components and their functionalities:

***********Classes and Vriables*************
Hotel Class: Represents a hotel with attributes such as name, address, and phone number.
Provides methods to retrieve these attributes.

Room Class: Manages room availability and details, including room type, rate, and room number.
Static variables keep track of room availability for different types of rooms (Single, Double, Triple, Master).
Methods include checking room availability, setting/getting room rate and type.

Reservation Class: Handles reservation details such as stay duration, car rental options, meal costs, check-in/check-out dates, and reservation ID.
Contains methods for displaying room choices, calculating the length of stay, handling meal options, and generating unique reservation IDs.

Guest Class: Stores guest information like name, email, phone number, and special requests.
Associates a reservation with a guest.

Billing Class (Abstract): Manages the billing process. This class is abstract, with a pure virtual function billing().
Stores billing details like bill amount, date of issue, and payment method.
Also calculates total hotel revenue.

FrequentVisitor Class (Inherits from Billing): Represents frequent visitors who get discounted rates.
Implements the billing() method with discounts applied based on room type.

NonFreqVisitor Class (Inherits from Billing): Represents non-frequent visitors.
Implements the billing() method without discounts.

Agent Class: Handles queries related to the hotel, such as room types, discounts, smoking policies, and transportation.

Static Variables: Static variables in the room and reservation classes are used to manage counts of room availability and reservation IDs of all instances.
File Handling: The program reads and writes to text files for handling guest data, reservation IDs, and revenue.
