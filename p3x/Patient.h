//
// Created by Uchenna on 5/30/22.
//

#ifndef SRC_P3_H
#define SRC_P3_H
#include <map>
/**
 * The Patient class represents patients that are awaiting help
 * in the emergency room triage.
 */
class Patient{
public:
    /**
     * Constructor
     */
    Patient();

    /**
     * Constructor that takes patient's name and priority
     * @param name name of the patient
     * @param priorityCode Priority of patient
     */
    Patient(const std::string &name, const std::string &priorityCode);

    /**
     * Compares two patients to see which is urgent
     * @param other the patient to compare
     * @return -1 if the patient is urgent
     *          1 if other is
     */
    int compareTo(const Patient &other) const;
    /**
     * Converts this Patient's info to a string format
     * @return string formating to display output
     */
    std::string to_string() const;
    /**
    * Get this Patient's name
    * @return the name of this Patient
    */
    std::string getName() const;

private:
    // The number of total Patient instances
    static int patientNumber;
    // Map of priorities to the integer's that represent their value
    std::map<std::string, int> priorMap = {
            {"immediate", 1},
            {"emergency", 2},
            {"urgent", 3},
            {"minimal", 4}
    };
    std::string name;
    std::string priorityCode;
    int arrivalOrder;
};

Patient::Patient() {
    this->name = "John Doe";
    this->priorityCode = "minimal";
    this->arrivalOrder = ++patientNumber;
}

Patient::Patient(const std::string &name, const std::string &priorityCode) {
    this->name = name;
    this->priorityCode = priorityCode;
    this->arrivalOrder = ++patientNumber;

}

int Patient::compareTo(const Patient &other) const {
    if (priorMap.at(this->priorityCode) < priorMap.at(other.priorityCode))
        return -1;
    else if (priorMap.at(this->priorityCode) > priorMap.at(other.priorityCode))
        return 1;
    else if (this->arrivalOrder <= other.arrivalOrder)
        return -1;
    else
        return 1;
}

std::string Patient::to_string() const{
    return "    " + std::to_string(arrivalOrder) + "         " +
           priorityCode + "       " + name ;
}

std::string Patient::getName() const {
    return name;
}


int Patient::patientNumber = 0;
#endif //SRC_P3_H

