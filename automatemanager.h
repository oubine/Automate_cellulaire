#ifndef AUTOMATEMANAGER
#define AUTOMATEMANAGER

#include "automate.h"

class AutomateManager {
    Automate1D* automates[256];
    AutomateManager();
    ~AutomateManager();
    AutomateManager(const AutomateManager& a);
    AutomateManager& operator=(const AutomateManager& a);
    struct Handler {
        AutomateManager* instance;
        Handler():instance(nullptr) {}
        ~Handler() { delete instance;  }
    };
    static Handler handler;
public:
    const Automate1D& getAutomate(unsigned long int num);
    const Automate1D& getAutomate(const std::string& num);
    static AutomateManager& getAutomateManager();
    static void libererAutomateManager();
};

#endif // AUTOMATEMANAGER

