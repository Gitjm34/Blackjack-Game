#ifndef USER_SCORE_COMPARATOR_H
#define USER_SCORE_COMPARATOR_H

#include "User.h"

struct UserScoreComparator {
    bool operator()(const User* lhs, const User* rhs) const {
        return lhs->getScore() > rhs->getScore();  // 弥家 赛 备己
    }
};

#endif // USER_SCORE_COMPARATOR_H
