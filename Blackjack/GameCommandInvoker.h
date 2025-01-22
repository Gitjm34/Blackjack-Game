#ifndef GAME_COMMAND_INVOKER_H
#define GAME_COMMAND_INVOKER_H

#include "Command.h"

class GameCommandInvoker {
private:
    Command* currentCommand;  // ���� ������ Ŀ�ǵ� ��ü�� ����

public:
    // ������
    GameCommandInvoker() : currentCommand(nullptr) {}

    // �Ҹ���
    ~GameCommandInvoker() {
        // �����ϴ� Ŀ�ǵ� ��ü�� ���� �Ҹ� ó���� �ʿ��ϴٸ� ���⿡ �߰�
    }

    // ������ Ŀ�ǵ带 �����ϴ� �޼���
    void setCommand(Command* command) {
        currentCommand = command;
    }

    // ������ Ŀ�ǵ带 �����ϴ� �޼���
    void executeCommand() {
        if (currentCommand) {
            currentCommand->execute();
        }
    }
};

#endif // GAME_COMMAND_INVOKER_H


