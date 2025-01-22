#include "UserScoreInfo.h"
#include "User.h"

UserScoreInfo::UserScoreInfo(User* user, int score)
    : user(user), score(score) {}

User* UserScoreInfo::getUser() const {
    return user;
}

int UserScoreInfo::getScore() const {
    return score;
}

bool UserScoreInfo::operator<(const UserScoreInfo& other) const {
    return score < other.score;
}
