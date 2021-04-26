const fibo = (n, memo = []) => {
    if (n in memo) return memo[n];
    if (n < 2) return 1;
    memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
    return memo[n];
}

const sum = (n, s = 0) => {
    if (n === 1 || n === 2) return s + 1;
    return s + fibo(n);
}

const convert = (n) => {
    n = parseInt(n, 10);
    if (n > 0) {
        let r = n % 2;
        convert(Number(n/2));
        console.log(r);
    }
}

const thapHN = (n, ng, tg, d) => {
    if (n === 1) console.log('Chuyển 1 đĩa tu '+ ng + '-->' + d);
    else { // Nhiều hơn 1 dia
        thapHN(n-1, ng, d, tg);
        thapHN(1, ng, tg, d);
        thapHN(n-1, tg, ng, d);
    }
}

const f =  (str1, str2) => {
    let s = new Set();
    let res1 = str1.split('');

    for(i in str1.length - 1) {
        console.log(res1[i]);
        if (!s.has(i)) {
            res1[i] = str2[i];
            s.add(i);
        }
        for(let j = i + 1; j < str1.length; i++) {
            if (!s.has(j)) {
                res1[j] = str2[i];
                s.add(j);
            }
        }
    }
    console.log(s);
    res1[0] = 'd';
    console.log(res1);
}

const lcs = (x, y) => {
    const table = Array(x.length + 1).fill()
    .map(() => Array(y.length + 1));

    let res = 0;

    for (let i = 0; i <= x.length; i++) {
        for (let j = 0; j <= y.length; j++) {
            if (i === 0 || j === 0) {
                table[i][j] = 0;
            } else if (x[i-1] == y[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                res = Math.max(res, table[i][j])
            } else {
                table[i][j] = 0
            } 
        }
    }
    return res;
}

var x = 'MoxQjMNMWhLAcmbObhOIK9j O NMIIaASbOQIoSp BIQv  mmIvrsbQbnNwonoNSaK LFB OMnIhAJcJIM NSXMnBMjOjsMJKF O'
var y = 'cIjAbAnonPvuqIABNIaNbMQyQrwN  io jFAOqLIaOhbaNB QnOni yAABvpAWaFhphXjaxMyEcILAnLEIoSICLLA AiZBhinqOB'



// console.log(fibo(5));
// console.log(sum(8));
// convert(8)
// thapHN(3, 'A', 'B', 'C');
// f('aba', 'cdc');

const lcs = (key1, key2) => {
    const table = Array(key1.length + 1).fill()
    .map(() => Array(key2.length + 1));

    let res = 0;

    for (let i = 0; i <= key1.length; i++) {
        for (let j = 0; j <= key2.length; j++) {
            if (i === 0 || j === 0) {
                table[i][j] = 0;
            } else if (key1[i-1] == key2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                res = Math.max(res, table[i][j])
            } else {
                table[i][j] = 0
            } 
        }
    }
    return res;
}



console.log(lcs(x, y));