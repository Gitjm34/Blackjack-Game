#ifndef USERSCOREINFO_H
#define USERSCOREINFO_H

#include "User.h"

class UserScoreInfo {
public:
    UserScoreInfo(User* user, int score);

    User* getUser() const;
    int getScore() const;
    bool operator<(const UserScoreInfo& other) const;

private:
    User* user;
    int score;
};

#endif // USERSCOREINFO_H
