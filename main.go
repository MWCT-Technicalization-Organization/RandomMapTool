package main

import (
	"fmt"
	"math/rand"
	"time"
)

func getMap(num int, limit []string) []string {
	mapL := []string{"绿地", "风暴", "未开发岩石区", "北极圈", "失落之城", "冰岛", "维京湾", "岩峰"}

	maps := []string{}

	if num > 13 {
		maps = append(maps, "-1") // 返回值为-1表示随机次数超过限制
		return maps
	} else {
		if len(limit) != 0 {
			for _, l := range limit {
				for i := 0; i < len(mapL); i++ {
					if mapL[i] == l {
						mapL = append(mapL[:i], mapL[i+1:]...) // 删除禁用的地图
						break
					}
				}
			}
		}

		rand.Seed(time.Now().UnixNano())

		if len(mapL) > num {
			for i := 0; i < num; i++ {
				index := rand.Intn(len(mapL))
				rdMap := mapL[index] // 从剩余地图中随机选择
				maps = append(maps, rdMap)
				mapL = append(mapL[:index], mapL[index+1:]...) // 删除已选择的地图，避免重复
				shuffle(mapL) // 打乱地图顺序
			}
		} else {
			for i := 0; i < num; i++ {
				index := rand.Intn(len(mapL))
				maps = append(maps, mapL[index]) // 从剩余地图中随机选择
				shuffle(mapL) // 打乱地图顺序
			}
		}

		return maps
	}
}

func shuffle(list []string) {
	rand.Seed(time.Now().UnixNano())
	for i := len(list) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		list[i], list[j] = list[j], list[i]
	}
}

func main() {
	num := 5 // 随机次数
	limit := []string{"绿地", "失落之城"} // 禁用的地图列表

	result := getMap(num, limit) // 获取随机地图

	for _, mapName := range result {
		fmt.Println(mapName) // 输出随机地图
	}
}