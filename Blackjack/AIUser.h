#ifndef AIUSER_H
#define AIUSER_H

#include "User.h"

class AIUser : public User {
public:
    AIUser(int id, std::string pw, std::string name, int remainScore);

    bool shouldHit(int currentScore) const;
};

#endif // AIUSER_H
