#include "App.h"
#include "Card.h"
#include "User.h"
#include "GameCommandInvoker.h"
#include "InitialCardDistribution.h"
#include "PersonalHitRequest.h"
#include "CheckLoser.h"
#include "CheckWinner.h"

class GameCommandInvoker {
private:
    Command* currentCommand;

public:
    void setCommand(Command* command) {
        currentCommand = command;
    }

    void executeCommand() {
        if (currentCommand) {
            currentCommand->execute();
        }
    }
};
