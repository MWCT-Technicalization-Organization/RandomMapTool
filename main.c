#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAPS 8

char* mapL[MAX_MAPS] = {"绿地", "风暴", "未开发岩石区", "北极圈", "失落之城", "冰岛", "维京湾", "岩峰"};

typedef struct {
    char** maps;
    int size;
} MapArray;

MapArray getMap(int num, char** limit) {
    MapArray result;
    char** maps = malloc(sizeof(char*) * num);
    int mapsIndex = 0;
    int limitUsed[MAX_MAPS] = {0};
    int mapLSize = MAX_MAPS;

    result.size = 0;

    if (num > MAX_MAPS) {
        result.maps = NULL;
        return result;
    }

    if (limit != NULL) {
        while (*limit != NULL) {
            for (int i = 0; i < MAX_MAPS; i++) {
                if (strcmp(*limit, mapL[i]) == 0) {
                    limitUsed[i] = 1;
                    break;
                }
            }
            limit++;
        }
    }

    for (int i = 0; i < MAX_MAPS; i++) {
        if (!limitUsed[i]) {
            mapL[mapLSize++] = mapL[i];
        }
    }

    for (int i = 0; i < num; i++) {
        int index = rand() % mapLSize;
        maps[mapsIndex] = mapL[index];
        mapsIndex++;

        // 移除已选择的地图
        for (int j = index; j < mapLSize - 1; j++) {
            mapL[j] = mapL[j + 1];
        }
        mapLSize--;
    }

    result.maps = maps;
    result.size = num;
    return result;
}

int main() {
    int num = 5; // 随机次数
    char* limit[] = { "绿地", "失落之城", NULL }; // 禁用的地图列表

    MapArray result = getMap(num, limit); // 获取随机地图

    for (int i = 0; i < result.size; i++) {
        printf("%s\n", result.maps[i]); // 输出随机地图
    }

    free(result.maps);

    return 0;
}