//
// Created by Uchenna on 5/30/22.
//

#ifndef SRC_PATIETPRIORITYQUEUEX_H
#define SRC_PATIETPRIORITYQUEUEX_H

#include <string>
#include <vector>
#include <sstream>
#include "Patient.h"
using namespace std;
/**
 * This PatientPriorityQueue class implements a Priority Queue ADT of Patients
 */
class PatientPriorityQueue{
public:
    /**
     * Default constructor
     */
    PatientPriorityQueue();

    /**
     * returns the next patient to fetch
     * @return
     */
    const Patient &peek() const;

    /**
     * Adds a new patient to the triage
     * @param newPatient
     */
    void add(const Patient &newPatient);

    /**
     * Removes the newt patient in queue
     * @return
     */
    Patient remove();
    /**
     * returns true or false if the patient is empty
     * @return
     */
    bool empty() const;
    /**
     * returns the number of patients
     * @return
     */
    int size() const;

    /**
     * To_string method
     * @return
     */
    std::string to_String();
    /**
     * changes a Patient's priority
     * @param arrivalID   the arrival number for the Patient
     * @param newPriority the new priority for the Patient
     * @return            the new patient
     */
    Patient change(int arrivalID, const std::string &newPriority);


private:
    /**
     * Vector of type patient
     */
    std::vector<Patient> data;
    /**
     * The value at data[index] may violate the heap invariants by being too low.
     * If so, fix it by swapping with ancestors as necessary.
     *
     * @param index of data that may be too low relative to parent (and further
     *              ancestors)
     */
    void siftUp(int index);
    /**
     * The value at data[index] may violate the heap invariants by being too
     * high. If so, fix it by swapping with descendants as necessary.
     *
     * @param index of data that may be too high relative to children (and
     *              further descendants)
     */
    void siftDown(int index);

    /**
     * Construct a heap from arbitrarily-ordered elements in the data array.
     */
    void heapify();
    /**
    * Get the index of the parent of a given node in this heap.
    * Does not check if parent index is the root (parent(0) returns 0).
    *
    * @param childIndex child address
    * @return index of the left child of parentIndex in the data array
    */
    static int parent ( int childIndex);
    /**
     * Check if the given node has a left child.
     *
     * @param parentIndex parent address
     * @return true if the left child of parentIndex is a current member of the
     *         heap
     */
    bool hasLeft(int parentIndex) const;
    /**
     * Check if the given node has a right child.
     *
     * @param parentIndex parent address
     * @return true if the right child of parentIndex is a current member of
     *         the heap
     */
    bool hasRight(int parentIndex) const;
    /**
     * Check if the given node has a right child.
     *
     * @param parentIndex parent address
     * @return true if the right child of parentIndex is a current member of
     *         the heap
     */
    static int left(int parentIndex);
    /**
     * Get the index of the right child of a given node in this heap.
     * Does not check if the child is a current member of this heap.
     *
     * @param parentIndex parent address
     * @return index of the right child of parentIndex in the data array
     */
    static int right(int parentIndex);
    /**
     * returns the level order of the heap
     * @param ss string stream to which the strings are returned
     * @return
     */
    std::string getLevelOrder(std::stringstream & ss);
    Patient removeByArrivalID(int arrivalID);
    int getArrivalOrder(){
        string s = data[i].to_string();
        stringstream ss(s);
        string num;
        ss >> num;
        num = trim(num);
        int arriveOrder = std::stoi(num);
    }

    const std::string WHITESPACE = " \n\r\t\f\v";

    std::string ltrim(const std::string &s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : s.substr(start);
    }

    std::string rtrim(const std::string &s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }
};

PatientPriorityQueue::PatientPriorityQueue() = default;


void PatientPriorityQueue::add(const Patient &newPatient) {
    data.push_back(newPatient);
    siftUp(data.size() -1);

}

Patient PatientPriorityQueue::remove() {
    Patient res = peek();
    data[0] = data[data.size() -1];
    data.pop_back();

    siftDown(0);
    return res;
}

bool PatientPriorityQueue::empty() const {
    return data.empty();
}

const Patient & PatientPriorityQueue::peek() const {
    if (empty())
        throw std::invalid_argument("empty queue");
    return data[0];
}


void PatientPriorityQueue::heapify() {
    for (int index = data.size() /2; index >=0;index--)
        siftDown(index);
}

void PatientPriorityQueue::siftUp(int index) {
    if (index > 0){
        int p = parent(index);
        if (data[p].compareTo(data[index])>0){
            std::swap(data[index], data[p]);
            siftUp(p);
        }
    }
}

void PatientPriorityQueue::siftDown(int index) {
    if (hasLeft(index)){
        int child = left(index);
        if (hasRight(index)){
            int r = right(index);
            if (data[r].compareTo(data[child]) < 0)
                child =r;
        }

        if (data[child].compareTo(data[index])<0){
            std::swap(data[index], data[child]);
            siftDown(child);
        }
    }
}

bool PatientPriorityQueue::hasLeft(int parentIndex) const {
    int sz = (int)data.size();
    return left(parentIndex) < sz;
}

bool PatientPriorityQueue::hasRight(int parentIndex) const {
    int sz = (int)data.size();
    return right(parentIndex) < sz;
}

int PatientPriorityQueue::parent(int childIndex) {
    return (childIndex -1)/2;
}

int PatientPriorityQueue::left(int parentIndex) {
    return parentIndex * 2 +1;
}

int PatientPriorityQueue::right(int parentIndex) {
    return left(parentIndex) +1;
}

int PatientPriorityQueue::size() const {
    return this->data.size();
}


std::string PatientPriorityQueue::to_String(){
    std::stringstream ss;
    return getLevelOrder(ss);
}


std::string PatientPriorityQueue::getLevelOrder(std::stringstream & ss){
    for (auto i : data){
        ss << i.to_string();
        ss << "\n";
    }
    return ss.str();
}

Patient PatientPriorityQueue::change(int arrivalID,
                                     const std::string &newPriority) {
    try {
        Patient oldPatient = removeByArrivalID(arrivalID);
        Patient newPatient(oldPatient.getName(), newPriority);
        add(newPatient);
        return newPatient;
    } catch (std::exception const &exc) {
        throw exc;
    }
}

Patient PatientPriorityQueue::removeByArrivalID(int arrivalID) {
    for (int i = 0; i < data.size(); i++) {

        string s = data[i].to_string();
        stringstream ss(s);
        string num;
        ss >> num;
        num = trim(num);
        int arriveOrder = std::stoi(num);
        if (arriveOrder == arrivalID) {
            Patient result = data[i];

            // remove the value at index i
            data[i] = data[data.size() - 1];
            data.pop_back();
            siftDown(i);
            return result;
        }
    }
    throw std::invalid_argument("Patient does not exist");
}

#endif //SRC_PATIETPRIORITYQUEUEX_H
