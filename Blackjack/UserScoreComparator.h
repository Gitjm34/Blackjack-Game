#ifndef USER_SCORE_COMPARATOR_H
#define USER_SCORE_COMPARATOR_H

#include "User.h"

struct UserScoreComparator {
    bool operator()(const User* lhs, const User* rhs) const {
        return lhs->getScore() > rhs->getScore();  // �ּ� �� ����
    }
};

#endif // USER_SCORE_COMPARATOR_H
