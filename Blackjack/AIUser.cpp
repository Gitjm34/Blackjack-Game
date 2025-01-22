#include "AIUser.h"

AIUser::AIUser(int id, std::string pw, std::string name, int remainScore)
    : User(id, std::move(pw), std::move(name), remainScore) {}

bool AIUser::shouldHit(int currentScore) const {
    return currentScore < 17;
}
