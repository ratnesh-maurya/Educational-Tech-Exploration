const array = [1, 2, 1, 3, 4, 3, 5];

const toFindDuplicates = array => array.filter((item, index) => array.indexOf(item) !== index)
const duplicateElement = toFindDuplicates(array);
console.log(duplicateElement); //[1,3]
