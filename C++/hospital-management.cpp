#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Patient {
public:
    int id;
    string name;
    bool isEmergency;

    Patient(int i, string n, bool e) : id(i), name(n), isEmergency(e) {}
};

class Doctor {
public:
    int id;
    string name;
    map<string, bool> schedule; 

    Doctor(int i, string n) : id(i), name(n) {}
};

class Appointment {
public:
    int patientId;
    int doctorId;
    string time;

    Appointment(int pId, int dId, string t) : patientId(pId), doctorId(dId), time(t) {}
};

class HospitalSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    const vector<string> workingHours = {
        "09:00 AM", "10:00 AM", "11:00 AM", "12:00 PM", 
        "02:00 PM", "03:00 PM", "04:00 PM"
    };

public:
    void addPatient(int id, string name, bool emergency) {
        auto pIt = find_if(patients.begin(), patients.end(), 
                          [id](const Patient& p) { return p.id == id; });
        if (pIt != patients.end()) {
            cout << "-> Error: A patient with ID " << id << " already exists!\n";
            return;
        }

        patients.emplace_back(id, name, emergency);
        cout << "-> Patient '" << name << "' added successfully.\n";
    }

    void addDoctor(int id, string name) {
        auto dIt = find_if(doctors.begin(), doctors.end(), 
                          [id](const Doctor& d) { return d.id == id; });
        if (dIt != doctors.end()) {
            cout << "-> Error: A doctor with ID " << id << " already exists!\n";
            return;
        }

        doctors.emplace_back(id, name);
        cout << "-> Doctor '" << name << "' added successfully.\n";
    }

    void displayAll() {
        cout << "\n--- REGISTERED DOCTORS ---\n";
        for (const auto& d : doctors) {
            cout << "ID: " << d.id << " | Name: " << d.name << "\n";
        }
        cout << "\n--- REGISTERED PATIENTS ---\n";
        for (const auto& p : patients) {
            cout << "ID: " << p.id << " | Name: " << p.name 
                 << " | Emergency: " << (p.isEmergency ? "Yes" : "No") << "\n";
        }
    }

    bool displayAvailableSlots(int doctorId) {
        auto dIt = find_if(doctors.begin(), doctors.end(), 
                          [doctorId](const Doctor& d) { return d.id == doctorId; });
        
        if (dIt == doctors.end()) {
            cout << "Error: Doctor not found.\n";
            return false;
        }

        cout << "\n--- Select a Time Slot for " << dIt->name << " ---\n";
        for (size_t i = 0; i < workingHours.size(); ++i) {
            string status = dIt->schedule[workingHours[i]] ? "[Booked]" : "[Available]";
            cout << i + 1 << ". " << workingHours[i] << " " << status << "\n";
        }
        return true;
    }

    void bookAppointment(int patientId, int doctorId, int slotChoice) {
        if (slotChoice < 1 || slotChoice > workingHours.size()) {
            cout << "Error: Invalid slot choice.\n";
            return;
        }

        string selectedTime = workingHours[slotChoice - 1];

        auto pIt = find_if(patients.begin(), patients.end(), 
                          [patientId](const Patient& p) { return p.id == patientId; });
        
        auto dIt = find_if(doctors.begin(), doctors.end(), 
                          [doctorId](const Doctor& d) { return d.id == doctorId; });

        if (pIt != patients.end() && dIt != doctors.end()) {
            if (dIt->schedule[selectedTime]) {
                if (!pIt->isEmergency) {
                    cout << "\n-> Error: Already booked. Cannot overwrite unless emergency.\n";
                    return;
                } else {
                    cout << "\n[!] EMERGENCY OVERRIDE INITIATED [!]\n";
                    auto apptIt = find_if(appointments.begin(), appointments.end(), 
                        [&](const Appointment& a) { return a.doctorId == doctorId && a.time == selectedTime; });
                    
                    if (apptIt != appointments.end()) {
                        string newSlot = "";
                        for (const string& slot : workingHours) {
                            if (!dIt->schedule[slot]) {
                                newSlot = slot;
                                break;
                            }
                        }
                        
                        if (!newSlot.empty()) {
                            apptIt->time = newSlot;
                            dIt->schedule[newSlot] = true;
                            cout << "-> Standard Patient (ID: " << apptIt->patientId 
                                 << ") displaced and moved to next open slot: " << newSlot << ".\n";
                            
                            appointments.emplace_back(patientId, doctorId, selectedTime);
                            cout << "-> Emergency Appointment booked successfully for " << selectedTime << ".\n";
                        } else {
                            cout << "-> Override failed: No open slots left today to relocate the standard patient.\n";
                        }
                    }
                }
            } else {
                dIt->schedule[selectedTime] = true;
                appointments.emplace_back(patientId, doctorId, selectedTime);
                cout << "-> Appointment booked successfully for " << selectedTime << ".\n";
            }
        } else {
            cout << "Error: Patient not found.\n";
        }
    }

    void displayDoctorSchedule(int doctorId) {
        auto dIt = find_if(doctors.begin(), doctors.end(), 
                          [doctorId](const Doctor& d) { return d.id == doctorId; });
                          
        if (dIt != doctors.end()) {
            cout << "\n--- Daily Schedule for " << dIt->name << " ---\n";
            for (const auto& slot : workingHours) {
                string status = dIt->schedule[slot] ? "[BOOKED]" : "[Free]";
                cout << slot << " - " << status << "\n";
            }
        } else {
            cout << "Doctor not found.\n";
        }
    }
};

void clearBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    HospitalSystem sys;
    int choice;

    while (true) {
        cout << "\n=====================================";
        cout << "\n      HOSPITAL MANAGEMENT SYSTEM     ";
        cout << "\n=====================================\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Book Appointment\n";
        cout << "4. View Doctor Schedule\n";
        cout << "5. View All Doctors & Patients\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            clearBuffer();
            continue;
        }

        if (choice == 6) {
            cout << "Exiting system. Goodbye!\n";
            break;
        }

        int pId, dId, slotChoice;
        string name;
        int isEmergInt;
        bool isEmerg;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> pId;
                clearBuffer(); 
                
                cout << "Enter Patient Name: ";
                getline(cin, name);
                
                cout << "Is Emergency? (1 for Yes, 0 for No): ";
                cin >> isEmergInt;
                isEmerg = (isEmergInt == 1);
                sys.addPatient(pId, name, isEmerg);
                break;
                
            case 2:
                cout << "Enter Doctor ID: ";
                cin >> dId;
                clearBuffer(); 
                
                cout << "Enter Doctor Name: ";
                getline(cin, name);
                sys.addDoctor(dId, name);
                break;
                
            case 3:
                cout << "Enter Patient ID: ";
                cin >> pId;
                cout << "Enter Doctor ID: ";
                cin >> dId;
                
                if (sys.displayAvailableSlots(dId)) {
                    cout << "Enter your choice (1-7): ";
                    if (!(cin >> slotChoice)) {
                        cin.clear();
                        clearBuffer();
                        cout << "Invalid input.\n";
                    } else {
                        sys.bookAppointment(pId, dId, slotChoice);
                    }
                }
                break;
                
            case 4:
                cout << "Enter Doctor ID: ";
                cin >> dId;
                sys.displayDoctorSchedule(dId);
                break;

            case 5:
                sys.displayAll();
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
