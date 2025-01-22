#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    virtual void execute() = 0;
    virtual std::string getName() const = 0;
    virtual ~Command() = default;
};

#endif // COMMAND_H
