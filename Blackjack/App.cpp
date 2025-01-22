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
        std::cout << "        <���� ���α׷�>\n";
        std::cout << "����� ������ �ݰ����ϴ�!\n";
        std::cout << "�ִ� �÷��̾� ��: 6\n";
        std::cout << "���� �÷��̾� ��: " << loggedInUsers.size() << "\n";
        std::cout << "-----------------------------\n";
        std::cout << "1. �α���\n";
        std::cout << "2. ȸ������\n";
        std::cout << "3. ���� ����\n";
        std::cout << "4. ���÷��� ����\n";
        std::cout << "5. ���� ���� ����\n";
        std::cout << "6. �α׾ƿ�\n";
        std::cout << "0. ���α׷� ����\n";
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
            std::cout << "�ùٸ� ������ �ϼ���.\n";
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
    std::cout << "����� �̸��� �Է��ϼ���: ";
    std::cin >> username;
    std::cout << "��й�ȣ�� �Է��ϼ���: ";
    std::cin >> password;

    for (auto& user : allUsers) {
        if (user.getName() == username && user.getPassword() == password) {
            loggedInUsers.push_back(user);
            std::cout << "�α��� ����!\n";
            return;
        }
    }
    std::cout << "�߸��� ����� �̸� �Ǵ� ��й�ȣ�Դϴ�.\n";
}

void App::signUp() {
    int id = allUsers.size() + 1;
    std::string username, password;
    std::cout << "����� �̸��� �Է��ϼ���: ";
    std::cin >> username;
    std::cout << "��й�ȣ�� �Է��ϼ���: ";
    std::cin >> password;
    allUsers.emplace_back(id, password, username, 10000);
    std::cout << "ȸ������ ����!\n";
}

void App::logout() {
    loggedInUsers.clear();
    std::cout << "�α׾ƿ� ����!\n";
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
    std::cout << user.getName() << "�� ���� ����: " << score << "\n";
}

void App::displayUserInfo() {
    for (const auto& user : allUsers) {
        std::cout << "ID: " << user.getId() << ", �̸�: " << user.getName() << ", ���� ����: " << user.getRemainingScore() << "\n";
    }
}

int App::calculateScore(const std::vector<Card>& cards) const {
    int score = 0;
    for (const auto& card : cards) {
        score += card.getNumber();
    }
    return score;
}
