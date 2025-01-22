#ifndef GAME_COMMAND_INVOKER_H
#define GAME_COMMAND_INVOKER_H

#include "Command.h"

class GameCommandInvoker {
private:
    Command* currentCommand;  // 현재 실행할 커맨드 객체를 저장

public:
    // 생성자
    GameCommandInvoker() : currentCommand(nullptr) {}

    // 소멸자
    ~GameCommandInvoker() {
        // 관리하는 커맨드 객체에 대한 소멸 처리가 필요하다면 여기에 추가
    }

    // 실행할 커맨드를 설정하는 메서드
    void setCommand(Command* command) {
        currentCommand = command;
    }

    // 설정된 커맨드를 실행하는 메서드
    void executeCommand() {
        if (currentCommand) {
            currentCommand->execute();
        }
    }
};

#endif // GAME_COMMAND_INVOKER_H


