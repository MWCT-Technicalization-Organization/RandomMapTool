#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<std::string> getMap(int num, std::vector<std::string> limit) {
    std::vector<std::string> mapL = { "�̵�", "�籩", "δ������ʯ��", "����Ȧ", "ʧ��֮��", "����", "ά����", "�ҷ�" };
    std::vector<std::string> maps;

    if (num > 13) {
        return { -1 }; // ����ֵΪ-1��ʾ���������������
    }
    else {
        if (!limit.empty()) {
            for (const std::string& i : limit) {
                auto it = std::find(mapL.begin(), mapL.end(), i);
                if (it != mapL.end()) {
                    mapL.erase(it); // ɾ�����õĵ�ͼ
                }
            }
        }

        if (mapL.size() > num) {
            std::random_device rd;
            std::mt19937 gen(rd());

            for (int i = 0; i < num; ++i) {
                std::uniform_int_distribution<> dis(0, mapL.size() - 1);
                int index = dis(gen);
                std::string rdMap = mapL[index]; // ��ʣ���ͼ�����ѡ��
                maps.push_back(rdMap);
                mapL.erase(mapL.begin() + index); // ɾ����ѡ��ĵ�ͼ�������ظ�
                std::shuffle(mapL.begin(), mapL.end(), gen); // ���ҵ�ͼ˳��
            }

            return maps;
        }
        else {
            std::random_device rd;
            std::mt19937 gen(rd());

            for (int i = 0; i < num; ++i) {
                std::uniform_int_distribution<> dis(0, mapL.size() - 1);
                int index = dis(gen);
                maps.push_back(mapL[index]); // ��ʣ���ͼ�����ѡ��
                std::shuffle(mapL.begin(), mapL.end(), gen); // ���ҵ�ͼ˳��
            }

            return maps;
        }
    }
}

int main() {
    int num = 5; // �������
    std::vector<std::string> limit = { "�̵�", "ʧ��֮��" }; // ���õĵ�ͼ�б�

    std::vector<std::string> result = getMap(num, limit); // ��ȡ�����ͼ

    for (const std::string& map : result) {
        std::cout << map << std::endl; // ��������ͼ
    }

    return 0;
}