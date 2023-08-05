#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<std::string> getMap(int num, std::vector<std::string> limit) {
    std::vector<std::string> mapL = { "绿地", "风暴", "未开发岩石区", "北极圈", "失落之城", "冰岛", "维京湾", "岩峰" };
    std::vector<std::string> maps;

    if (num > 13) {
        return { -1 }; // 返回值为-1表示随机次数超过限制
    }
    else {
        if (!limit.empty()) {
            for (const std::string& i : limit) {
                auto it = std::find(mapL.begin(), mapL.end(), i);
                if (it != mapL.end()) {
                    mapL.erase(it); // 删除禁用的地图
                }
            }
        }

        if (mapL.size() > num) {
            std::random_device rd;
            std::mt19937 gen(rd());

            for (int i = 0; i < num; ++i) {
                std::uniform_int_distribution<> dis(0, mapL.size() - 1);
                int index = dis(gen);
                std::string rdMap = mapL[index]; // 从剩余地图中随机选择
                maps.push_back(rdMap);
                mapL.erase(mapL.begin() + index); // 删除已选择的地图，避免重复
                std::shuffle(mapL.begin(), mapL.end(), gen); // 打乱地图顺序
            }

            return maps;
        }
        else {
            std::random_device rd;
            std::mt19937 gen(rd());

            for (int i = 0; i < num; ++i) {
                std::uniform_int_distribution<> dis(0, mapL.size() - 1);
                int index = dis(gen);
                maps.push_back(mapL[index]); // 从剩余地图中随机选择
                std::shuffle(mapL.begin(), mapL.end(), gen); // 打乱地图顺序
            }

            return maps;
        }
    }
}

int main() {
    int num = 5; // 随机次数
    std::vector<std::string> limit = { "绿地", "失落之城" }; // 禁用的地图列表

    std::vector<std::string> result = getMap(num, limit); // 获取随机地图

    for (const std::string& map : result) {
        std::cout << map << std::endl; // 输出随机地图
    }

    return 0;
}