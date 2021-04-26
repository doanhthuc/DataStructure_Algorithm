function getThePassword(key1, key2) {
    const table = Array(key1.length + 1)
        .fill()
        .map(() => Array(key2.length + 1));

    let res = 0;

    for (let i = 0; i <= key1.length; i++) {
        for (let j = 0; j <= key2.length; j++) {
            if (i === 0 || j === 0) {
                table[i][j] = 0;
            } else if (key1[i - 1] == key2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                res = Math.max(res, table[i][j]);
            } else {
                table[i][j] = 0;
            }
        }
    }
    if (res === 0) res = 6008009;
    return res;
}
