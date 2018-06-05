/**
 * \file automatemanager.h
 * \brief Fichier d'en-tête de la classe AutomateManager
 * \author{Oubine Perrin, Guillaume Sabbagh, Adrien Thuau}
 * \version 1.0
 * \date 16 Juin 2018
 *
 * Fichier d'en-tête déclarant l'architecture du manager d'automate (design pattern Singleton).
 *
 */
#ifndef AUTOMATEMANAGER
#define AUTOMATEMANAGER

#include "automate1d.h"

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

