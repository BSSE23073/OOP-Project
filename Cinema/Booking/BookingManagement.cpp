//
// Created by Dell on 27/04/2024.
//

#include "BookingManagement.h"

BookingManagement *BookingManagement::instance = nullptr;

int BookingManagement::userCount = 0;

//getter
BookingManagement *BookingManagement::getInstance() {
    if (!instance) {
        instance = new BookingManagement;
    }
    return instance;
}

// Adds a new customer to the system.
void BookingManagement::addCustomer(Customer &customer1) {
    customer.push_back(customer1);
}

// Registers a new customer with basic details.
void BookingManagement::signUp(std::string name, std::string gender, int age) {
    string username, emailId, password;
    input:
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Email Address: ";
    cin >> emailId;
    cout << "Enter Password For SignUp: ";
    cin >> password;
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName() == username) {
            cout << "Username Already Exists enter again\n";
            goto input;
        }
        if (onlineUser[i].getEmailId() == emailId) {
            cout << "Email Already Exists enter again\n";
            goto input;
        }
    }
    OnlineUser user(name, gender, age, username, emailId, password);
    onlineUser.push_back(user);
}

// Authenticates a user with their email and password.
bool BookingManagement::login(string email, string password) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getEmailId() == email && onlineUser[i].getPassword() == password) {
            return true;
        }
    }
    return false;
}

// Activates membership for a specified user.
void BookingManagement::membershipForUser(string userID) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName() == userID) {
            Membership membership;
            string date, memberId;
            double price,discount;
            cout << "Enter Membership Subscription Price: ";
            cin>>price;
            membership.setSubscriptionRate(price);
            membership.membershipInvoice();
            cout<<" Is amount Payed : (yes/no)";
            string choose;
            cin>>choose;
            if (choose == "yes"|| choose == "Yes") {
                cout << "Enter Membership discount for User:";
                cin >> discount;
                membership.setMembershipDiscount(discount);
                cout << "Expiry Date For Membership (DD/MM/YY):";
                cin >> date;
                membership.setExpiryDate(date);
                memberId = onlineUser[i].getUserName();
                membership.setMembershipID(memberId);
                onlineUser[i].activateMembership(membership);
                return;
            }
            else{
                cout<<"Membership Not Activated\n";
                return;
            }
        }
    }
    cout<<"User Not Found ! \nCreate an account\n";
}

// Cancels the membership for a specified user.
void BookingManagement::cancelMembershipForUser(string userID) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName() == userID) {
            onlineUser[i].cancelMembership();
            return;
        }
    }
    cout<<"User not Found!!\n";
}

// Generates an invoice for a customer based on their name and age.
void BookingManagement::generateInvoiceForCustomer(string name, int age) {
    for (int i = 0; i < customer.size(); ++i) {
        if (customer[i].getName()==name&&customer[i].getAge()==age){
            string bookingId;
            customer[i].displayDetails();
            cout<<"Enter Booking ID for which you want invoice:";
            cin>>bookingId;
            customer[i].invoiceForBooking(bookingId);
            for (int j = 0; j < booking.size(); ++j) {
                if (booking[j].getBookingID()==bookingId){
                    booking[j].setPaymentStatus(true);
                }
            }
            customer.erase(customer.begin()+i);
            return;
        }
    }
    cout<<"Customer not Found!!\n";
}

// Generates an invoice for a user identified by userID.
void BookingManagement::generateInvoiceForUser(string userID) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName() == userID) {
            string bookingId;
            onlineUser[i].displayUserBooking();
            cout<<"Enter Booking ID for which you want invoice:";
            cin>>bookingId;
            onlineUser[i].invoiceForBooking(bookingId);
            return;
        }
    }
    cout<<"User not Found!!\n";
}

// Cancels a booking based on the booking ID.
void BookingManagement::cancelBooking(string bookingID) {
    for (int i = 0; i < booking.size(); ++i) {
        if (booking[i].getBookingID()==bookingID){
            booking.erase(booking.begin()+i);
        }
    }
    for (int i = 0; i < customer.size(); ++i) {
        customer[i].removeBooking(bookingID);
    }
    for (int i = 0; i < onlineUser.size(); ++i) {
        onlineUser[i].removeBooking(bookingID);
    }
}

// Displays details for a specified user.
void BookingManagement::displayUserDetails(string userID) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName() == userID) {
            onlineUser[i].displayDetails();
            return;
        }
    }
    cout<<"User not Found!!\n";
}

// Displays all bookings across the cinema.
void BookingManagement::displayBookingsOfCinema() {
    cout<<"\n----------------------------------\n"
    <<"\n-----------Cinema Bookings-------------\n";
    for (int i = 0; i < booking.size(); ++i) {
        booking[i].bookingDetails();
    }
}

// Creates a booking for a user identified by userID.
void BookingManagement::makeBookingForUser(string userID) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName()==userID){
            string book;
            book = userID;
            book+=to_string(userCount);
            Booking booking1(book);
            ShowtimeManagement::getInstance()->displayAllShowtime();
            string id,day;
            cout << "Enter The Showtime Id :";
            cin >> id;
            cout << "and Day for Which you want to book ticket";
            cin >> day;

            char x;
            do {
                auto ticket = ShowtimeManagement::getInstance()->bookTicketInShowtime(day, id);
                if (ticket->vipTicketStatus){
                    VIPTicket *ptr = dynamic_cast<VIPTicket*>(ticket);
                    ptr->displayTicket();
                    booking1.addTicketToBooking(*ptr);
                }
                else {
                    booking1.addTicketToBooking(*ticket);
                }
                cout << "want to book more tickets? (y/n)";
                cin >> x;
            } while (x=='Y'||x=='y');
            booking.push_back(booking1);
            onlineUser[i].addBooking(booking1);
            userCount++;
        }
    }
}

// Creates a booking for a specified customer.
void BookingManagement::makeBooking(Customer &customer1) {
    string book;
    cout<<"Enter Booking ID For Generating Booking: ";
    cin>>book;
    Booking booking1(book);
    ShowtimeManagement::getInstance()->displayAllShowtime();
    string id,day;
    cout << "Enter The Showtime Id :";
    cin >> id;
    cout << "and Day for Which you want to book ticket";
    cin >> day;
    char x;
    while (true){

        Ticket* ticket = ShowtimeManagement::getInstance()->bookTicketInShowtime(day, id);
        if (ticket->vipTicketStatus){
            VIPTicket *ptr = dynamic_cast<VIPTicket*>(ticket);
            ptr->displayTicket();
            booking1.addTicketToBooking(*ptr);
        }
        else {
            booking1.addTicketToBooking(*ticket);
        }
        cout << "want to book more tickets? (y/n)";
        cout.flush();
        cin >> x;
        if(x=='N'||x=='n'){
            break;
        }
    }
    booking.push_back(booking1);
    customer1.addBooking(booking1);
    customer.push_back(customer1);
}

// Displays the login menu.


void BookingManagement::menuForLogin() {
    int choice;
    do {
        cout << "Welcome to Cinema\n\n";
        cout << "1. Make Booking\n";
        cout << "2. Display Showtime For a day\n";
        cout << "3. Show Movies By Filter\n";
        cout << "4. Get Movie Recommendation\n";
        cout << "5. Get Membership Details\n";
        cout << "6. Cancel Membership\n";
        cout << "7. Generate Invoice for Booking\n";
        cout << "8. Cancel Booking\n";
        cout << "9. Display Personal Details\n";
        cout << "10. Give Feedback For Movie\n";
        cout << "11. Display Feedback For Movie\n";
        cout << "12. Help Bot\n";
        cout << "13. Exit\n\n";
        cout << "Please enter your choice (1-13): ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                makeBookingForUser(ID);
                // Make Booking
                break;
            }
            case 2: {
                string day;
                cout<<"Enter day you want to display showtime of: ";
                cin >> day;
                ShowtimeManagement::getInstance()->displayShowtimeForDay(day);
                break;
            }
            case 3: {

                string day,id;
                cout<<"Enter day you want to display showtime of: ";
                cin >> day;
                ShowtimeManagement::getInstance()->displayShowtimeForDay(day);
                cout<<"Enter id of showtime you want to filter movies for: ";
                cin>>id;
                ShowtimeManagement::getInstance()->showMoviesByFilterInShowtime(day,id);
                break;
            }
            case 4: {
                string day,id;
                cout<<"Enter day you want to display showtime of: ";
                cin >> day;
                ShowtimeManagement::getInstance()->displayShowtimeForDay(day);
                cout<<"Enter id of showtime you want to get movie recommendation for: ";
                cin>>id;
                ShowtimeManagement::getInstance()->recommendMovieInShowtime(day,id);
                break;
            }
            case 5: {

                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                userMembershipDetails(ID);
                // Membership
                break;
            }
            case 6: {
                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                cancelMembershipForUser(ID);
                // Cancel Membership
                break;
            }
            case 7: {
                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                generateInvoiceForUser(ID);
                // Generate Invoice
                break;
            }
            case 8: {
                string ID;
                cout<<"Enter Booking ID: ";
                cin>>ID;
                cancelBooking(ID);
                // Cancel Booking functionality
                break;
            }
            case 9: {
                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                displayUserDetails(ID);
                //display details
                break;
            }
            case 10: {
                string movieName;
                cout<<"Enter Movie Name For Feedback\n";
                MovieRoaster::getInstance()->displayMovieList();
                cin.ignore();
                getline(cin,movieName);
                MovieRoaster::getInstance()->addFeedbackToMovie(movieName);
                //giving feedback
                break;
            }
            case 11: {
                string movieName;
                cout<<"Enter Movie Name For Feedback\n";
                MovieRoaster::getInstance()->displayMovieList();
                cin.ignore();
                getline(cin,movieName);
                MovieRoaster::getInstance()->displayFeedbacksForMovie(movieName);
                //display Feedbacks
                break;
            }
            case 12: {
                HelpBot::getInstance()->menuForHelpBot();
                break;
            }
            case 13: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 13.\n";
            }
        }
    } while (choice!=13);
}

// Displays the management menu
void BookingManagement::menuForManagement() {
    int choice;
    do {
        cout << "Welcome to Booking Management System\n\n";
        cout << "1. Sign Up\n";
        cout << "2. Make Booking For Customer\n";
        cout << "3. Login\n";
        cout << "4. Membership for User\n";
//        cout << ". Cancel Membership for User\n";
        cout << "5. Generate Invoice for Customer\n";
//        cout << "9. Generate Invoice for User\n";
        cout << "6. Cancel Booking\n";
        cout << "7. Display User Details\n";
        cout << "8. Display Bookings of Cinema\n";
        cout<<"9. Add Question & Answers To Manager\n";
        cout << "10. Exit\n\n";
        cout << "Please enter your choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name,gender;
                int age;
                cout<<"For Signup Enter Following Details:\n"
                    <<"Enter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter gender: ";
                getline(cin,gender);
                cout<<"Enter age: ";
                cin>>age;
                signUp(name,gender,age);
                // Sign Up functionality
                break;
            }
            case 2: {
                string name,gender;
                int age;
                cout<<"For Signup Enter Following Details:"
                    <<"Enter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter gender: ";
                getline(cin,gender);
                cout<<"Enter age: ";
                cin>>age;
                Customer customer1(name,gender,age);
                makeBooking(customer1);
// Sign Up functionality
                break;
            }
            case 3: {
                string email,pass;
                cout<<"Email address: ";
                cin>>email;
                cout<<"Password: ";
                cin>>pass;
                // Login functionality
                if (login(email,pass)){
                    menuForLogin();
                }
                break;
            }
            case 4: {
                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                membershipForUser(ID);
                break;
            }
            case 5: {
                string name;
                int age;
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter age: ";
                cin>>age;
                generateInvoiceForCustomer(name,age);
                // Make Booking for User functionality
                break;
            }
            case 6: {
                string ID;
                cout<<"Enter Booking iD for which you want to remove booking: ";
                cin>>ID;
                cancelBooking(ID);
                // Membership for User functionality
                break;
            }
            case 7: {
                string ID;
                cout<<"Enter Your User ID: ";
                cin>>ID;
                displayUserDetails(ID);
                // Cancel Membership for User functionality
                break;
            }
            case 8: {
                displayBookingsOfCinema();
                // Generate Invoice for Customer functionality
                break;
            }
            case 9: {
                cin.ignore(); // Ignore newline character from previous input
                string question, answer;
                cout << "Enter the question: ";
                getline(std::cin, question);
                cout << "Enter the answer: ";
                getline(std::cin, answer);
                HelpBot::getInstance()->addQuestionAndAnswer(question, answer);
                cout << "Question and answer added successfully.\n";
                break;
            }
            case 10: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 13.\n";
            }
        }
    } while (choice != 10);
}
// Displays membership details for a specified user.
void BookingManagement::userMembershipDetails(string userID) {
    for (int i = 0; i < onlineUser.size(); ++i) {
        if (onlineUser[i].getUserName() == userID) {
            onlineUser[i].displayUserMemberShipDetails();
            return;
        }
    }
    cout << "User not Found!!\n";
}

// Reads customer information from file.
void BookingManagement::readCustomerFromFile() {
    ifstream readData("Cinema/Booking/CustomerData.json", ios::in);
    if (!readData.is_open()){
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json customerData;
    readData >> customerData;
    readData.close();
    for(auto i: customerData){
        customer.push_back(Customer::readCustomerFromJSON(i));
    }
}

// Writes customer information to file.
void BookingManagement::writeCustomerToFile() {
    json customerData;
    for (auto i: customer) {
        customerData.push_back(i.writeCustomerToJSON());
    }
    ofstream writeData("Cinema/Booking/CustomerData.json", ios::out);
    if (writeData.is_open()) {
        writeData << customerData.dump(2);
    }
    else {
        cerr << "file is not open " << endl;
    }
}

// Reads online user data from file.
void BookingManagement::readOnlineUserFromFile() {
    ifstream readData("Cinema/Booking/OnlineUserData.json", ios::in);
    if (!readData.is_open()){
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json userData;
    readData >> userData;
    readData.close();
    for(auto i: userData){
        onlineUser.push_back(OnlineUser ::readOnlineUserFromJSON(i) );
    }

}

// Reads booking information from file.
void BookingManagement::readBookingsFromFile() {
    ifstream readData("Cinema/Booking/BookingsData.json", ios::in);
    if (!readData.is_open()){
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json bookingsData;
    readData >> bookingsData;
    readData.close();
    for(auto i: bookingsData){
        booking.push_back(Booking ::readBookingFromJSON(i));
    }
}

// Writes booking information to a file.
void BookingManagement::writeBookingsToFile() {
    json bookingData;
    for (auto i: booking) {
        bookingData.push_back(i.writeBookingToJSON());
    }
    ofstream writeData("Cinema/Booking/BookingsData.json", ios::out);
    if (writeData.is_open()) {
        writeData << bookingData.dump(2);
    } else {
        cerr << "file is not open " << endl;
    }
}

//Writes online user data to file.
void BookingManagement::writeOnlineUserToFile() {
    json userData;
    for (auto i: onlineUser) {
        userData.push_back(i.writeOnlineUserToJSON());
    }
    ofstream writeData("Cinema/Booking/OnlineUserData.json", ios::out);
    if (writeData.is_open()) {
        writeData << userData.dump(2);
    } else {
        cerr << "file is not open " << endl;
    }
}

void BookingManagement::addOrderToCustomer(std::string name, int age,Order& order)
{
    for (int i = 0; i < customer.size(); ++i) {
        if (customer[i].getName()==name&&customer[i].getAge()==age){
            customer[i].addOrder(order);
        }
    }
}