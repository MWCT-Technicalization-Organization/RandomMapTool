import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class main {
    public static List<String> getMap(int num, List<String> limit) {
        List<String> mapL = new ArrayList<>();
        mapL.add("绿地");
        mapL.add("风暴");
        mapL.add("未开发岩石区");
        mapL.add("北极圈");
        mapL.add("失落之城");
        mapL.add("冰岛");
        mapL.add("维京湾");
        mapL.add("岩峰");

        List<String> maps = new ArrayList<>();

        if (num > 13) {
            maps.add("-1"); // 返回值为-1表示随机次数超过限制
            return maps;
        } else {
            if (limit != null && !limit.isEmpty()) {
                mapL.removeAll(limit); // 删除禁用的地图
            }

            Random rand = new Random();

            if (mapL.size() > num) {
                for (int i = 0; i < num; i++) {
                    int index = rand.nextInt(mapL.size());
                    String rdMap = mapL.get(index); // 从剩余地图中随机选择
                    maps.add(rdMap);
                    mapL.remove(index); // 删除已选择的地图，避免重复
                    shuffle(mapL); // 打乱地图顺序
                }
            } else {
                for (int i = 0; i < num; i++) {
                    int index = rand.nextInt(mapL.size());
                    maps.add(mapL.get(index)); // 从剩余地图中随机选择
                    shuffle(mapL); // 打乱地图顺序
                }
            }

            return maps;
        }
    }

    private static void shuffle(List<String> list) {
        Random rand = new Random();
        for (int i = list.size() - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            String temp = list.get(i);
            list.set(i, list.get(j));
            list.set(j, temp);
        }
    }

    public static void main(String[] args) {
        int num = 5; // 随机次数
        List<String> limit = new ArrayList<>();
        limit.add("绿地");
        limit.add("失落之城"); // 禁用的地图列表

        List<String> result = getMap(num, limit); // 获取随机地图

        for (String map : result) {
            System.out.println(map); // 输出随机地图
        }
    }
}
