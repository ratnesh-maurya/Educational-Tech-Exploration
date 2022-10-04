// The rest operator (…) allows us to call a function with any number of arguments and then access those excess arguments as an array. 
function fun(...input) {
    let sum = 0;
    for (let i of input) {
        sum += i;
    }
    return sum;
}
console.log(fun(1, 2)); //3
console.log(fun(1, 2, 3)); //6
console.log(fun(1, 2, 3, 4, 5)); //15                

// The spread operator (…) allows us to expand an iterable like array into its individual elements.
var array1 = [10, 20, 30, 40, 50];
var array2 = [60, 70, 80, 90, 100];
var array3 = [...array1, ...array2];
console.log(array3); //[10, 20, 30, 40, 50, 60, 70, 80, 90, 100] 

//appending an element
var array1 = [10, 20, 30, 40, 50];
var array2 = [...array1, 60];
console.log(array2);
