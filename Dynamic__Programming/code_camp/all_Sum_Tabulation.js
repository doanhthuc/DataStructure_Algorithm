const bestSum = (targetSum, numbers) => {
    const table = Array(targetSum + 1).fill(null);
    table[0] = [];

    for (let i = 0; i <= targetSum; i++) {
        if (table[i] !== null) {
            for(let num of numbers) {
                const combination = [...table[i], num];
                // if this current combination is shorter that what is already stored
                if (!table[i + num] || table[i + num].length > combination.length) {
                    table[i + num] = combination;
                }
            }
        }
    }
    return table[targetSum];
}

console.log(bestSum(7, [2, 3]));         // [ 3, 2, 2 ]
console.log(bestSum(7, [5, 3, 4, 7]));   // [ 4, 3 ]
console.log(bestSum(7, [2, 4]));         // null
console.log(bestSum(8, [2, 3, 5]));      // [ 2, 2, 2, 2 ]
console.log(bestSum(300, [7, 14]));      // null