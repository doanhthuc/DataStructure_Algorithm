const allWaySum = (n) => {
    if (n === 0) return 0;
    if (n === 1) return 1;
    const arr = Array(1000).fill(0);
    arr[0] = 0;
    arr[1] = 1;
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j < i; j++) {
            arr[i] += arr[i - j];
        }
    }
    return arr[n];
};

const a = allWaySum(6);
console.log(a);
