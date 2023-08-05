const getRandomMaps = (num, limit) => {
    const mapL = ["�̵�", "�籩", "δ������ʯ��", "����Ȧ", "ʧ��֮��", "����", "ά����", "�ҷ�"];
    const maps = [];

    if (num > 13) {
        maps.push("-1"); // ����ֵΪ-1��ʾ���������������
        return maps;
    } else {
        if (limit.length !== 0) {
            limit.forEach((l) => {
                const index = mapL.indexOf(l);
                if (index !== -1) {
                    mapL.splice(index, 1); // ɾ�����õĵ�ͼ
                }
            });
        }

        if (mapL.length > num) {
            for (let i = 0; i < num; i++) {
                const index = Math.floor(Math.random() * mapL.length);
                const rdMap = mapL[index]; // ��ʣ���ͼ�����ѡ��
                maps.push(rdMap);
                mapL.splice(index, 1); // ɾ����ѡ��ĵ�ͼ�������ظ�
                shuffle(mapL); // ���ҵ�ͼ˳��
            }
        } else {
            for (let i = 0; i < num; i++) {
                const index = Math.floor(Math.random() * mapL.length);
                maps.push(mapL[index]); // ��ʣ���ͼ�����ѡ��
                shuffle(mapL); // ���ҵ�ͼ˳��
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

const num = 5; // �������
const limit = ["�̵�", "ʧ��֮��"]; // ���õĵ�ͼ�б�

const result = getRandomMaps(num, limit); // ��ȡ�����ͼ

result.forEach((mapName) => {
    console.log(mapName); // ��������ͼ
});