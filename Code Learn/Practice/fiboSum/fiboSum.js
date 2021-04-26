function fiboSum(n){
    let total = 3;
    let fibo = [1, 2];
    
    while(total < n) {
        fibo.push(fibo[fibo.length - 2] + fibo[fibo.length - 1])
        total += fibo[fibo.length - 1]
    }

    let index = fibo.length - 1
    while(total != n) {
        if ((total - fibo[index]) >= n) {
            total -= fibo[index];
            fibo.splice(index, 1);
        }
        index--
    }
    return fibo.length == 0 ? [-1] : fibo
}

console.log(fiboSum(8));