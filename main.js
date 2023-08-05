const getRandomMaps = (num, limit) => {
    const mapL = ["绿地", "风暴", "未开发岩石区", "北极圈", "失落之城", "冰岛", "维京湾", "岩峰"];
    const maps = [];

    if (num > 13) {
        maps.push("-1"); // 返回值为-1表示随机次数超过限制
        return maps;
    } else {
        if (limit.length !== 0) {
            limit.forEach((l) => {
                const index = mapL.indexOf(l);
                if (index !== -1) {
                    mapL.splice(index, 1); // 删除禁用的地图
                }
            });
        }

        if (mapL.length > num) {
            for (let i = 0; i < num; i++) {
                const index = Math.floor(Math.random() * mapL.length);
                const rdMap = mapL[index]; // 从剩余地图中随机选择
                maps.push(rdMap);
                mapL.splice(index, 1); // 删除已选择的地图，避免重复
                shuffle(mapL); // 打乱地图顺序
            }
        } else {
            for (let i = 0; i < num; i++) {
                const index = Math.floor(Math.random() * mapL.length);
                maps.push(mapL[index]); // 从剩余地图中随机选择
                shuffle(mapL); // 打乱地图顺序
            }
        }

        return maps;
    }
};

const shuffle = (list) => {
    for (let i = list.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [list[i], list[j]] = [list[j], list[i]];
    }
};

const num = 5; // 随机次数
const limit = ["绿地", "失落之城"]; // 禁用的地图列表

const result = getRandomMaps(num, limit); // 获取随机地图

result.forEach((mapName) => {
    console.log(mapName); // 输出随机地图
});