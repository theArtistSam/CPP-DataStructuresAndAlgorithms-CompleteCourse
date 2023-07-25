#include <iostream>
#include <string>
using namespace std;

struct rides{

    int ride_id;
    int ride_distance;
    int ride_charges;
    string rider_name;
    
    // Pointer for putting more values 
    rides *next = NULL;
    
};

struct registered_cars{

    int reg_number;
    int car_type;
    string driver_name;
    string car_name;
    
    // car pointers
    registered_cars *previous = NULL;
    registered_cars *next = NULL;
    rides *s_next = NULL;
    
};

registered_cars *front = NULL;
registered_cars *back = NULL;

// Student Methods
void front_id(){
    cout << "ID at front is: " << front -> reg_number << endl;
}
void back_id(){
    cout << "ID at back is: " << back -> reg_number << endl;
}
bool isEmpty(){
    if(front == NULL){
        return true;
    }
    else{
        return false;
    }
}

void insert_at_end(){

    registered_cars *current = new registered_cars;

    cout << "\nEnter Registration Number " << endl;
    cin >> current -> reg_number;
    
    cout << "\nEnter Driver Name" << endl;
    cin >> current -> driver_name;

    cout << "\nEnter Car Name" << endl;
    cin >> current -> car_name;

    cout << "\nEnter Car Type" << endl;
    cin >> current -> car_type;

    if(isEmpty()){
        front = back = current;
    }
    else{
        current -> previous = back;
        back -> next = current;
        back = current;
    }
}

void delete_specfic(int value){
    registered_cars *p = front;

    if(isEmpty()){
        cout << "Empty!" << endl;
    }
    else if(value == front -> reg_number){
        p = front -> next;
        p -> previous = NULL;
        delete front;
        front = p;
    }
    else if(value == back -> reg_number){
        p = back -> previous;
        p -> next = NULL;
        delete back;
        back = p;
    }
    else{
        while(p -> reg_number != value && p != NULL){
            p = p -> next;
        }
        p -> next -> previous = p -> previous;
        p -> previous -> next = p -> next;
        delete p;
    }   
}

void display(){
    registered_cars *p = front;

    if(isEmpty()){
        cout << "No record!" << endl;
    }
    else{
        while (p != NULL)
        {
            cout << "\n----------------- DISPLAY ------------------\n\nRegistration Number: " << p -> reg_number << endl;
            cout << "\nDriver Name:         " << p -> driver_name << endl;
            cout << "\nCar Name:            " << p -> car_name << endl;
            cout << "\nCar Type:            " << p -> car_type << endl;
            p = p -> next;

        }   
    }
}

void display_cars_type(int value){
    
    registered_cars *p = front;
    cout << "\n----------------- DISPLAY ------------------ " << endl;
    while (p != NULL){
        if(p -> car_type == 2){
            cout << "Type 2 car is: " << p -> car_name << endl;
        }
        p = p -> next;
    }
}    

void insert_rides(int value){
    registered_cars *p = front;
    rides *p3;
    rides *ride = new rides();

    cout << "\nEnter Ride ID" << endl;
    cin >> ride -> ride_id;

    cout << "\nEnter Ride Distance" << endl;
    cin >> ride -> ride_distance;
    
    cout << "\nEnter Ride Charges" << endl;
    cin >> ride -> ride_charges;
    
    cout << "\nEnter Rider Name" << endl;
    cin >> ride -> rider_name;

    while(p -> reg_number != value && p != NULL){
        p = p -> next;
    }
    
    if(p -> s_next == NULL){
        p -> s_next = ride;
    }
    else{
        rides *p2 = p -> s_next;
        while(p2 != NULL){
            p3 = p2;
            p2 = p2 -> next;
        }
        cout << "reached";
        p3 -> next = ride;
    }
    
}

// Displays all rides info
void display_all_rides(int value){
    registered_cars *p = front;

    while(p -> reg_number != value && p != NULL){
        p = p -> next;
    }

    if(p -> s_next == NULL){
        cout << "No record!" << endl;
    }
    else{
        
        rides *p2 = p -> s_next;
        while (p2 != NULL)
        {    
            cout << "\n----------------- DISPLAY ------------------\n\nRide ID: " << p2 -> ride_id << endl;
            cout << "\nRide Distance: " << p2 -> ride_distance << endl;
            cout << "\nRide Charges: " << p2 -> ride_charges << endl;
            cout << "\nRider Name: " << p2 -> rider_name << endl;  
            
            // Moving forward  
            p2 = p2 -> next;
        }   
    }
}    

// Displays total earning of a specfic car
void calculate_specfic_earning(int value){
    registered_cars *p = front;

    int total_earning = 0;
    while(p -> reg_number != value && p != NULL){
        p = p -> next;
    }

    if(p -> s_next == NULL){
        cout << "No record!" << endl;
    }
    else{
        rides *p2 = p -> s_next;
        while (p2 != NULL)
        {    
            total_earning += p2 -> ride_charges;  
            // Moving forward  
            p2 = p2 -> next;
        }   
    }
    cout << "\n----------------- DISPLAY ------------------\n" << endl;
    cout << "Total earnings of this car is: " << total_earning << endl;
}

// Displays total earning of all cars
void calculate_total_earning(){
    registered_cars *p = front;

    int total_earning_singleCar = 0;
    int total_earnings = 0;
    while(p != NULL){
        rides *p2 = p -> s_next;
        if(p -> s_next == NULL){
            cout << "No record!" << endl;
        }
        else{
            while (p2 != NULL)
            {    
                total_earning_singleCar += p2 -> ride_charges;  
                // Moving forward  
                p2 = p2 -> next;
            }
        }
        total_earnings += total_earning_singleCar;
        total_earning_singleCar = 0;
        p = p -> next;
    }
    cout << "\n----------------- DISPLAY ------------------\n" << endl;
    cout << "Total earnings of all the cars is: " << total_earnings << endl;
}

int main(){
    int choice, value;
    do
    {
        cout << "\n------------ SELECT YOUR OPTION! -----------\n\nPress [0] to Exit." << endl;
        cout << "Press [1] to Add New Car." << endl;
        cout << "Press [2] to Display Details of All Cars." << endl;
        cout << "Press [3] to Display Type 2 Cars" << endl;
        cout << "Press [4] to Add new Ride" << endl;
        cout << "Press [5] to Display Ride with Details" << endl;
        cout << "Press [6] to Total Earnings of a Specfic Car" << endl;
        cout << "Press [7] to Total Earnings of all cars" << endl;
        cout << "Press [8] to Display Front ID" << endl;
        cout << "Press [9] to Display Back ID" << endl;
        cout << "Press [10] to Delete Any Specfic Car" << endl;
        
        cin >> choice;
        
        if(choice == 0){
            break;
        }
        else if(choice == 1){
            insert_at_end();
        }
        else if(choice == 10){
            cout << "\nEnter Car Registration Number" << endl;
            cin >> value;
            delete_specfic(value);
        }
        else if(choice == 2){
            display();
        }
        else if(choice == 3){
            display_cars_type(2);
        }
        else if(choice == 4){
            cout << "\nEnter Car Registration Number" << endl;
            cin >> value;
            insert_rides(value);
        }
        else if(choice == 5){
            cout << "\nEnter Car Registration Number" << endl;
            cin >> value;
            display_all_rides(value);
        }
        else if(choice == 6){
            cout << "\nEnter Car Registration Number" << endl;
            cin >> value;
            calculate_specfic_earning(value);
        }
        else if(choice == 7){
            calculate_total_earning();
        }
        else if(choice == 8){
            front_id();
        }
        else if(choice == 9){
            back_id();
        }

    } while (true);
    return 0;
}
