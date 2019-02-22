

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;




struct Vehicle{
    
    std::string type;
    std::string colour;
    std::string plate;
    int problem;
    
};


struct Mechanic{
    
    std::string name;
    char gender;
    int quality;
    
};


struct Problem{
    
    std::string name;
    int prob_comp;
    int treat_comp;
    int fix;
    
};

struct Treatment{
    
    std::string name;
    
};

struct currentVehicleWork {
    Treatment fix;
    Problem diagnosedProblem;
    bool diagnosis;
    bool fixResult;
    Problem vehicleProblem;
    Mechanic assignedMechanic;
    Vehicle currentVehicle;
};

int stringToInt(string stringToChange)
{
    stringstream ss(stringToChange);
    
    int integerValue = -1;
    
    ss >> integerValue;
    
    return integerValue;
}

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

vector<Treatment> createFixes(vector<string> allFixesStringVector) {

    vector<Treatment> createdFixesVector;
    
    for(int i = 0; i < allFixesStringVector.size(); i++){
        
        
        Treatment newFix;
        
        newFix.name = allFixesStringVector[i];
        createdFixesVector.push_back(newFix);
        
    }
    
    return createdFixesVector;
    
    
}

vector<string> readFixes(string fixesFile){
    
    vector<string> allFixesStringVector ={};
    static const size_t notFound = -1;
    ifstream inDataStream;
    string buffer;
    char delimiter = '.';
    string unfinishedData;
    
    
    inDataStream.open(fixesFile);

    inDataStream >> buffer;
        
        
    while(buffer.find(delimiter) == notFound)
    {
        if(unfinishedData.empty())
        {
            unfinishedData = buffer;
            buffer.clear();
        } else
        {
            unfinishedData = unfinishedData + " " + buffer;
            buffer.clear();
        }
        
        inDataStream >> buffer;
    }
    
            string finishedData = unfinishedData + " " + buffer;
            allFixesStringVector.push_back(finishedData);
            finishedData.clear();
            unfinishedData.clear();
    
    
  
            allFixesStringVector.pop_back();
    
   
    return allFixesStringVector;
    
}

vector<Mechanic> createMechanics(vector<string> allMechanicsStringVector)
{
    char delimiter = ',';
    char endCharacter = '.';
    vector<Mechanic> createdMechanicsVector;
    for (int counter = 0; counter < allMechanicsStringVector.size(); counter++)
    {
        
        vector<string> individualMechanic = split(allMechanicsStringVector[counter], delimiter);
        
        string name = individualMechanic[0];
        assert(individualMechanic[1].size() == 1);
        char gender = individualMechanic[1][0];
        string qualityString = individualMechanic[2];
        
        vector<string> qualityVector = split(qualityString, endCharacter);
        
        int qualityNumber = stringToInt(qualityVector[0]);
        
        
        
        Mechanic newMechanic;
        
        newMechanic.name = name;
        newMechanic.gender = gender;
        newMechanic.quality = qualityNumber;
        createdMechanicsVector.push_back(newMechanic);
    
    }
   
    return createdMechanicsVector;
    
}

vector<string> readMechanics(string mechanicsFile){
    
    vector<string> allMechanicsStringVector ={};
    static const size_t notFound = -1;
    ifstream inDataStream;
    string buffer = "";
    char delimiter = '.';
    string unfinishedData = "";
    
    inDataStream.open(mechanicsFile);
    
    inDataStream >> buffer;
    
    while(buffer.find(delimiter) == notFound)
    {
        if(unfinishedData.empty())
        {
            unfinishedData = buffer;
            buffer.clear();
        } else {
            unfinishedData = unfinishedData + " " + buffer;
            buffer.clear();
        }
        inDataStream >> buffer;
    }
        string finishedData = unfinishedData + " " + buffer;
        allMechanicsStringVector.push_back(finishedData);
        finishedData.clear();
        unfinishedData.clear();
        
  
    return allMechanicsStringVector;
}



vector<Vehicle> createVehicles(vector<string> allVehiclesStringVector)
{
    char delimiter = ',';
    char vehicleEndPoint = '.';
    vector<Vehicle> createdVehiclesVector;
    for (int counter = 0; counter < allVehiclesStringVector.size(); counter++) {
       
            vector<string> individualVehicle = split(allVehiclesStringVector[counter], delimiter);
        
            string type = individualVehicle[0];
            string colour = individualVehicle[1];
            string plate = individualVehicle[2];
            string unsplitProblemString = individualVehicle[3];
            
            vector<string> problemVector = split(unsplitProblemString, vehicleEndPoint);
            
            string splitProblemString = problemVector[0];
            
            int problemNumber = stringToInt(splitProblemString);
        
            Vehicle newVehicle;
        
            newVehicle.type = type;
            newVehicle.colour = colour;
            newVehicle.plate = plate;
            newVehicle.problem = problemNumber;
        
            createdVehiclesVector.push_back(newVehicle);
        
    }
    
    return createdVehiclesVector;
    
}


vector<string> readVehicles(string vehiclesFile) {
    
    vector<string> allVehiclesStringVector ={};
    static const size_t notFound = -1;
    ifstream inDataStream;
    string buffer;
    char delimiter = '.';
    inDataStream.open(vehiclesFile);
        
    inDataStream >> buffer;
    
    while(inDataStream.good()){
        if(buffer.find(delimiter) == notFound)
        {
            cerr << "Error in Data";
            
        } else {
            
           
            allVehiclesStringVector.push_back(buffer);
            
        }
     
        inDataStream >> buffer;
    }
        
    return allVehiclesStringVector;
}



vector<string> readProblems(string problemsFile){
    
    
    vector<string> allProblemsStringVector ={};
    static const size_t notFound = -1;
    ifstream inDataStream;
    string buffer = "";
    char delimiter = '.';
    string unfinishedData = "";
    
    inDataStream.open(problemsFile);
    
    inDataStream >> buffer;
    
    while (inDataStream.good())
    {
        while(buffer.find(delimiter) == notFound)
        {
            if(unfinishedData.empty())
            {
                unfinishedData = buffer;
                buffer.clear();
            } else {
                unfinishedData = unfinishedData + " " + buffer;
                buffer.clear();
            }
            inDataStream >> buffer;
        }
            string finishedData = unfinishedData + " " + buffer;
            allProblemsStringVector.push_back(finishedData);
            finishedData.clear();
            unfinishedData.clear();
            inDataStream >> buffer;
    }
    
        return allProblemsStringVector;
}

vector<Problem> createProblems(vector<string> allProblemsStringVector){
    
    char delimiter = ',';
    char problemsEndPoint = '.';
    vector<Problem> allCreatedProblems;

    vector<Problem> createdProblemsVector;
    for (int counter = 0; counter < allProblemsStringVector.size(); counter++) {
        
        
        vector<string> individualProblem = split(allProblemsStringVector[counter], delimiter);
        
        string name = individualProblem[0];
        string determinationComplexityString = individualProblem[1];
        string treatmentComplexityString = individualProblem[2];
        string untrimmedTreatmentNumberString = individualProblem[3];
        
        
        vector<string> trimmedTreatmentNumberString = split(untrimmedTreatmentNumberString, problemsEndPoint);
        
        string treatmentString = trimmedTreatmentNumberString[0];
      
        
        
        int treatmentComplexityNumber = stringToInt(determinationComplexityString);
        int treatmentNumber = stringToInt(treatmentString);
        int determinationComplexityNumber = stringToInt(determinationComplexityString);
        
        
        
        Problem newProblem;
        
        newProblem.name = name;
        newProblem.fix = treatmentNumber;
        newProblem.treat_comp = treatmentComplexityNumber;
        newProblem.prob_comp = determinationComplexityNumber;
        allCreatedProblems.push_back(newProblem);
        
    }
    
    return allCreatedProblems;
    
    
}


Mechanic assignMechanic(vector<Mechanic> createdMechanicsVector){
    
    int chance;
    chance = rand() % createdMechanicsVector.size();
    Mechanic chosenMechanic = createdMechanicsVector[chance];
    
    cout << "The Mechanic " << chosenMechanic.name << " has been asssigned to fix this vehicle. " << endl;
    return chosenMechanic;
    
}

Problem attemptDiagnosis(Mechanic assignedMechanic, vector<Problem> vehicleProblemsVector, Problem vehicleProblem){
    
    int chanceOfSuccess;
    int randomInt;
    
    
    chanceOfSuccess = assignedMechanic.quality * 2;
    chanceOfSuccess = chanceOfSuccess - vehicleProblem.prob_comp;
    chanceOfSuccess = chanceOfSuccess / 2;
   
    randomInt = rand() % 100;
    
    
    if(chanceOfSuccess > randomInt){
       
        return vehicleProblem;
        
    } else {
       
        Problem randomProblem;
        int randomProblemNumber;
        
        randomProblemNumber = rand() % vehicleProblemsVector.size();
        randomProblem= vehicleProblemsVector[randomProblemNumber];
       
        return randomProblem;
       
    }
}

bool checkDiagnosisStatus(Problem vehicleProblem, Problem diagnosedProblem)
{
    if (vehicleProblem.name == diagnosedProblem.name) {
        cout << "They were able to correctly diagnose the problem with the vehicle. " << endl;
        return true;
    } else {
    
        cout << "They were unable to correctly diagnose the problem with the vehicle" << endl;
        return false;
    }
    
}

    


bool attemptFix(bool diagnosisStatus, Mechanic assignedMechanic, Problem vehicleProblem){
   
    int skillGap;
    int chanceOfSuccess;
    int randomInt;
    
    if(diagnosisStatus)
    {
        skillGap = assignedMechanic.quality;
        skillGap = skillGap - vehicleProblem.treat_comp;
        if (skillGap >= 0) {
            chanceOfSuccess = 70 + skillGap;
        } else {
            
            chanceOfSuccess = 70 + (skillGap - 10);
        }
        
        randomInt = rand() * 100;
       
        if (chanceOfSuccess > randomInt) {
            cout << "They were able to successfully apply a fix. " << endl;
            return true;
        } else {
            cout << "They were not able to successfully apply a fix." << endl;
            return false;
        }
        
        
    } else {
       
        skillGap = assignedMechanic.quality;
        skillGap = skillGap - vehicleProblem.treat_comp;
        if (skillGap >= 0) {
            chanceOfSuccess = 70 + skillGap;
        } else {
            
            chanceOfSuccess = 70 + (skillGap - 10);
        }
        
        chanceOfSuccess = chanceOfSuccess * 0.25;
        randomInt = rand() * 100;
        
        if (chanceOfSuccess > randomInt) {
            cout << "They were able to successfully apply a fix. " << endl;
            return true;
        } else {
            cout << "They were not able to successfully apply a fix." << endl;
           
            return false;
        }
        
        
        
    }
    
   
    
    
    

}


void  reportResults(currentVehicleWork currentJob) {
    
    string report;
    
    report = "Vehicle: " + currentJob.currentVehicle.plate + " ";
    report = report + "Has the problem: " + currentJob.vehicleProblem.name;
    
    if(currentJob.diagnosis == true)
    {   report = report + " which was diagnosed ";
    
        report = report + "as: " + currentJob.diagnosedProblem.name;
        
 

    }
   
        
   
    
    
    
}
    
    



    
    
    
    
    

