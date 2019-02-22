#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#include "struct_def.h"
using namespace std;


int main(int argc, char const *argv[])
{
    
    srand((int)time(0));
    vector<string> allProblemStringsVector;
    vector<Vehicle> createdVehiclesVector;
    string vehiclesFile = argv[2];
    string problemsFile = argv[3];
    string mechanicsFile = argv[4];
    string fixesFile = argv[5];
    string fileArray[4] = {vehiclesFile, problemsFile, mechanicsFile, fixesFile};
    
    
    
    vector<string> allVehiclesStringVector = readVehicles(vehiclesFile);
    createdVehiclesVector = createVehicles(allVehiclesStringVector);
    
    allProblemStringsVector = readProblems(problemsFile);
    vector<Problem> createdProblemsVector = createProblems(allProblemStringsVector);
    
    vector<string> allMechaicsStringVector = readMechanics(mechanicsFile);
    vector<Mechanic> createdMechanicsVector = createMechanics(allMechaicsStringVector);
    
    vector<string> allFixesStringVector = readFixes(fixesFile);
    vector<Treatment> createdFixesVector = createFixes(allFixesStringVector);
    
    currentVehicleWork currentJob;
    
   
   
    
    for (int i = 0; i < createdVehiclesVector.size(); i++) {
        
        currentJob.currentVehicle = createdVehiclesVector[i];
        cout << "Vehicle: " << currentJob.currentVehicle.type << " Plate: " << currentJob.currentVehicle.plate << endl;
        
        currentJob.assignedMechanic = assignMechanic(createdMechanicsVector);
        currentJob.vehicleProblem = createdProblemsVector[createdVehiclesVector[i].problem - 1];
        currentJob.diagnosedProblem = attemptDiagnosis(currentJob.assignedMechanic, createdProblemsVector, currentJob.vehicleProblem);

        currentJob.diagnosis = checkDiagnosisStatus(currentJob.vehicleProblem, currentJob.diagnosedProblem);
        
        currentJob.fix = attemptFix(currentJob.diagnosis, currentJob.assignedMechanic, currentJob.vehicleProblem);
        
      
        cout << endl;
    }
    
    
   
   
    
    
    
    
    
    
    
    
    
    
   
    
    
    
    
    
    
    
    
    

   /*
    
    for (int i = 0; i < 4; ++i)
    {
        buffer = "";
        cout << fileArray[i] << endl;
        string newEntry = "";
        inDataStream.open(fileArray[i]);
       
        while(inDataStream.good())
        {
            buffer = "";
            inDataStream >> buffer;
            
            if(buffer.find(delimiter) != std::string::npos)
            {
                newEntry = newEntry + " " + buffer;
                arrangedTextArray.push_back(newEntry);
                newEntry.clear();
                buffer.clear();
               
            } else
            {
                newEntry = newEntry + " " + buffer;
                buffer.clear();
            }
        
         
        
        }
            buffer.clear();
            inDataStream.close();
        
        
        
       
    }
    
    
    for(int j = 0; j < arrangedTextArray.size(); j++){
        
      
    }
    */
    return 0;
}
