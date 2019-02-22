

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
    
    bool fix;
    bool diagnosis;
    Problem vehicleProblem;
    Mechanic assignedMechanic;
    Vehicle currentVehicle;
    Problem diagnosedProblem;
};


std::vector<std::string> readMechanics(std::string mechanicsFile);
std::vector<std::string> readProblems(std::string vehiclesFile);
std::vector<std::string> readVehicles(std::string vehiclesFile);
std::vector<std::string> readFixes(std::string fixesFile);
std::vector<Treatment> createFixes(std::vector<std::string> allFixesStringVector);
std::vector<Vehicle> createVehicles(std::vector<std::string> allVehiclesStringVector);
std::vector<Problem> createProblems(std::vector<std::string> allProblemsStringVector);
std::vector<Mechanic> createMechanics(std::vector<std::string> allMechanicsStringVector);
Mechanic assignMechanic(std::vector<Mechanic> createdMechanicsVector);
Problem attemptDiagnosis(Mechanic assignedMechanic, std::vector<Problem> vehicleProblemsVector, Problem vehicleProblem);
bool checkDiagnosisStatus(Problem vehicleProblem, Problem diagnosedProblem);
bool attemptFix(bool diagnosis, Mechanic assingedMechanic, Problem vehicleProblem);



