#ifndef AUTOMATEMANAGER
#define AUTOMATEMANAGER

#include "automate.h"

class AutomateManager {
    AutomateElementaire* automates[256];
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
    AutomateElementaire& getAutomate(unsigned long int num);
    AutomateElementaire& getAutomate(const std::string& num);
    static AutomateManager& getAutomateManager();
    static void libererAutomateManager();
};

#endif // AUTOMATEMANAGER

