#include "App.h"
#include "User.h"
#include "AIUser.h"
#include "UserScoreInfo.h"
#include "InitialCardDistribution.h"
#include "PersonalHitRequest.h"
#include "CheckLoser.h"
#include "CheckWinner.h"
#include "CommandFactory.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

App::App() : commandFactory(CommandFactory::getInstance()) {
    readUserData();
}

App::~App() {
    writeUserData();
}

void App::run() {
    displayMainMenu();
}

void App::displayMainMenu() {
    int choice;
    do {
        std::cout << "-----------------------------\n";
        std::cout << "        <블랙잭 프로그램>\n";
        std::cout << "사용자 여러분 반갑습니다!\n";
        std::cout << "최대 플레이어 수: 6\n";
        std::cout << "현재 플레이어 수: " << loggedInUsers.size() << "\n";
        std::cout << "-----------------------------\n";
        std::cout << "1. 로그인\n";
        std::cout << "2. 회원가입\n";
        std::cout << "3. 게임 시작\n";
        std::cout << "4. 리플레이 보기\n";
        std::cout << "5. 유저 정보 보기\n";
        std::cout << "6. 로그아웃\n";
        std::cout << "0. 프로그램 종료\n";
        std::cout << "-----------------------------\n";
        std::cout << "-> ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            login();
            break;
        case 2:
            signUp();
            break;
        case 3:
            playGame();
            break;
        case 4:
            replayGame();
            break;
        case 5:
            displayUserInfo();
            break;
        case 6:
            logout();
            break;
        case 0:
            writeUserData();
            break;
        default:
            std::cout << "올바른 선택을 하세요.\n";
            break;
        }
    } while (choice != 0);
}

void App::readUserData() {
    std::ifstream userFile("users.txt");
    if (userFile.is_open()) {
        int id, score;
        std::string pw, name;
        while (userFile >> id >> pw >> name >> score) {
            allUsers.emplace_back(id, pw, name, score);
        }
        userFile.close();
    }
}

void App::writeUserData() {
    std::ofstream userFile("users.txt");
    if (userFile.is_open()) {
        for (const auto& user : allUsers) {
            userFile << user.getId() << " " << user.getPassword() << " " << user.getName() << " " << user.getRemainingScore() << "\n";
        }
        userFile.close();
    }
}

void App::login() {
    std::string username, password;
    std::cout << "사용자 이름을 입력하세요: ";
    std::cin >> username;
    std::cout << "비밀번호를 입력하세요: ";
    std::cin >> password;

    for (auto& user : allUsers) {
        if (user.getName() == username && user.getPassword() == password) {
            loggedInUsers.push_back(user);
            std::cout << "로그인 성공!\n";
            return;
        }
    }
    std::cout << "잘못된 사용자 이름 또는 비밀번호입니다.\n";
}

void App::signUp() {
    int id = allUsers.size() + 1;
    std::string username, password;
    std::cout << "사용자 이름을 입력하세요: ";
    std::cin >> username;
    std::cout << "비밀번호를 입력하세요: ";
    std::cin >> password;
    allUsers.emplace_back(id, password, username, 10000);
    std::cout << "회원가입 성공!\n";
}

void App::logout() {
    loggedInUsers.clear();
    std::cout << "로그아웃 성공!\n";
}

void App::createAndShuffleDeck() {
    deck = std::queue<Card>();
    std::vector<Card> cards;
    for (int suit = 1; suit <= 4; ++suit) {
        for (int number = 1; number <= 13; ++number) {
            cards.emplace_back(suit, number);
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
    for (const auto& card : cards) {
        deck.push(card);
    }
}

void App::playGame() {
    createAndShuffleDeck();

    auto initialCommand = commandFactory.createCommand("InitialCardDistribution", loggedInUsers, deck);
    initialCommand->execute();
    replayCommand.addCommand(std::move(initialCommand));

    for (int i = 0; i < loggedInUsers.size(); ++i) {
        auto hitCommand = commandFactory.createCommand("PersonalHitRequest", loggedInUsers, deck, i);
        hitCommand->execute();
        replayCommand.addCommand(std::move(hitCommand));
    }

    auto loserCommand = commandFactory.createCommand("CheckLoser", loggedInUsers, rankQueue);
    loserCommand->execute();
    replayCommand.addCommand(std::move(loserCommand));

    auto winnerCommand = commandFactory.createCommand("CheckWinner", loggedInUsers, rankQueue);
    winnerCommand->execute();
    replayCommand.addCommand(std::move(winnerCommand));

    writeUserData();
}

void App::replayGame() {
    replayCommand.execute();
}

void App::displayCurrentScore(const User& user) {
    int score = calculateScore(user.getCardsInHand());
    std::cout << user.getName() << "의 현재 점수: " << score << "\n";
}

void App::displayUserInfo() {
    for (const auto& user : allUsers) {
        std::cout << "ID: " << user.getId() << ", 이름: " << user.getName() << ", 남은 점수: " << user.getRemainingScore() << "\n";
    }
}

int App::calculateScore(const std::vector<Card>& cards) const {
    int score = 0;
    for (const auto& card : cards) {
        score += card.getNumber();
    }
    return score;
}
