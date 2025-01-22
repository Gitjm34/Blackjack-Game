#ifndef APP_H
#define APP_H

#include "User.h"
#include "AIUser.h"
#include "CommandFactory.h"
#include "ReplayCommand.h"
#include "UserScoreInfo.h"
#include <vector>
#include <queue>

class App {
public:
    App();
    ~App();

    void run();

private:
    void displayMainMenu();
    void readUserData();
    void writeUserData();
    void login();
    void signUp();
    void logout();
    void createAndShuffleDeck();
    void playGame();
    void replayGame();
    void displayCurrentScore(const User& user);
    void displayUserInfo();
    int calculateScore(const std::vector<Card>& cards) const;

    std::vector<User> allUsers;
    std::vector<User> loggedInUsers;
    std::queue<Card> deck;
    std::priority_queue<UserScoreInfo> rankQueue;
    CommandFactory& commandFactory;
    ReplayCommand replayCommand;
};

#endif // APP_H
