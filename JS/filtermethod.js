//filter method 

const numbers = [1,3,2,6,4,8];

//function expression
const isEven = function(number){
  return number%2 ===0; 
}

const evenNumbers = numbers.filter(isEven);

console.log(evenNumbers); 
